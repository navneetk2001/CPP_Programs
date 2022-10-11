https://leetcode.com/problems/split-array-into-consecutive-subsequences/




//Solution Approach :- 
// The idea is , we scan the array for two times.
// In first pass we count the frequencies of all numbers and record them in cnt
// For the second pass, we are "building" our subsequences by the following rules:

// We use a hashmap called tails to record extra information, where tails[i] means the number of consecutive subsequences we've found so far, who are longer than 3 , and tailed by number i,
// When we meet number i, try to put it to the tail of one of found subsequences tailed by i-1. No need to worry that we might have a better choice to consider i as a brand new head for another subsequence, because we can always append the new subsequence to a previous one tailed by i-1.
// If we can't, it will cost one i+1 and one i+2 later to generate a new sequence. We just pay that right now by decrease cnt[i+1] and cnt[i+2]. Some one may worry that we make use of the numbers we haven't scanned so far. But actually we've already kept track of the numbers remained by cnt. Just imaging we grab the numbers needed from the very end of the string, and mark them as "used". If there is no such number available to pay, cnt will tell us by checking cnt[i+1] cnt[i+2] is positive or not

bool isPossible(vector<int>& nums) {
    unordered_map<int,int> cnt, tails;
    for(int &i : nums){
    	cnt[i]++;
    }

    for(int &i : nums){
        if(!cnt[i]){
        	continue;
        }

        cnt[i]--;
        if(tails[i-1] > 0){
            tails[i-1]--;
            tails[i]++;
        }
        else if(cnt[i+1] && cnt[i+2]){
            cnt[i+1]--;
            cnt[i+2]--;
            tails[i+2]++;
        }
        else{
        	return false;
        }
    }
    return true;
}




//Second Solution :- 
class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
           return (a.back()>b.back());
        }
    };

    bool isPossible(vector<int>& nums) {
       int n = nums.size();

       priority_queue<vector<int>, vector<vector<int>>, cmp> pq;         //the top element in pq has the smallest last element
       map<int,int> freq;
       vector<vector<int>> result;
       
        for(auto n: nums) {
            freq[n]++;
        }
        
        for(auto n : freq) {
            int x = n.first;
            while(freq[x]>0) { 
                //if the last element is not x-1 cannot add to this subsequence. So there is no use in having this subsequence anymore in the pq as the elements are in sorted order.
                
                while (!pq.empty() && pq.top().back() < x-1) {
                    result.push_back(pq.top());
                    pq.pop();
                }
                //if last element is x-1 add x to the same subsequence 
                if(!pq.empty() && pq.top().back()==x-1) {
                    vector<int> temp= pq.top();
                    temp.push_back(x);
                    pq.pop();
                    pq.push(temp);
                    freq[x]--;
                }
                //If priority queue is empyty or Cannot add to exisiting subsequence create a new subsequnce and check if the next 2 consecutive elements are present
                else if(freq[x+1]>0 && freq[x+2]>0) {
                    vector<int> temp = {x,x+1,x+2};
                    pq.push(temp);
                    freq[x]--;
                    freq[x+1]--;
                    freq[x+2]--;
                }
                else {
                    return 0; 
                }
            }
        }
        //print the subsequences 
        for(int i=0;i<result.size();i++) {
            for(int j=0;j<result[i].size();j++) {
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return true;
    }
};