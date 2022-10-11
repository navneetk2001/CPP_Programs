// You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.
// Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: nums = [3,6,1,2,5], k = 2
// Output: 2
// Explanation:
// We can partition nums into the two subsequences [3,1,2] and [6,5].
// The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
// The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
// Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.

// Example 2:
// Input: nums = [1,2,3], k = 1
// Output: 2
// Explanation:
// We can partition nums into the two subsequences [1,2] and [3].
// The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
// The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
// Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].

// Example 3:
// Input: nums = [2,2,4,5], k = 0
// Output: 3
// Explanation:
// We can partition nums into the three subsequences [2,2], [4], and [5].
// The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
// The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
// The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
// Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.


//First Solution :-
// mn means the minimum number in the current sequence.
// mx means the maximum number in the current sequence.

// Iterate each element A[i] in the input array, and we try to add it into the current subsequence.
// We need to check if the differnce is still good. So we firstly update the value of mn and mx
// mn = min(mn, a)
// mx = max(mx, a).

// If mx - mn > k, this means the difference between the maximum and minimum values, is bigger than k in current subsequence,
// A[i] cannot be added to the subsequence,
// so we start a new subsequence with A[i] as the first element, thus increment res and update mn = mx = a.
// We continue doing this process and finally return result res.

// Then I notice it's subsequences instead of subarray, I added a sort at the beginning.....

int partitionArray(vector<int>& A, int k) {
    sort(A.begin(), A.end());
    int res = 1, mn = A[0], mx = A[0];
    for (int& a: A) {
        mn = min(mn, a);
        mx = max(mx, a);
        if (mx - mn > k) {
            res++;
            mn = mx = a;
        }
    }
    return res;
}


//Second Solution :- Two Pointers
//Sort, then use two pointers to track the current valid subsequence. Start a new subsequence if nums[i] cannot be added to the current one.
//As the second pointer, we use the last element of the subs array. This could be handy if we need to identify subarrays in the end, for some reason.

int partitionArray(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));
    vector<int> subs{nums[0]};
    for (int i = 1; i < nums.size(); ++i){
        if (nums[i] - subs.back() > k){
            subs.push_back(nums[i]);
        }
    }
    return subs.size();
}



//Thord Solution :- Max Heap / Priority Queue
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int last=-1;
        int count=0;
        
        while(pq.size()>0){
            int t=pq.top();
            pq.pop();
            if(last!=-1){
                if(last-t<=k){
                    continue;
                }
                else{
                    last=t;
                    count++;
                }
            }
            else{ 
            	count++;
                last=t;
            }
        }
        return count;
    }
};