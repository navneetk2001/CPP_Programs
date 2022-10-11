https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1



//Solution Approach :- LeetCode
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        list<int> l;
        int i=0;
        int j=0;
        
        if(k > nums.size()){    // edge case
            ans.push_back(*max_element(l.begin(),l.end()));
            return ans;
        }
        
        while (j<nums.size()){
            while(l.size() > 0 && l.back() < nums[j]){
                l.pop_back();
            }
            l.push_back(nums[j]);
            if ((j-i+1)<k){
                j++;
            }
            else if (j-i+1==k){
                ans.push_back(l.front());
                if (l.front()==nums[i]){
                    l.pop_front();
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }
};




//GFG :-
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        vector<int> ans;
        list<int> l;
        int i=0;
        int j=0;
        
        if(k > n){    // edge case
            ans.push_back(*max_element(nums, nums+n));
            return ans;
        }
        
        while (j<n){
            while(l.size() > 0 && l.back() < nums[j]){
                l.pop_back();
            }
            l.push_back(nums[j]);
            if ((j-i+1)<k){
                j++;
            }
            else if (j-i+1==k){
                ans.push_back(l.front());
                if (l.front()==nums[i]){
                    l.pop_front();
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }
};



//Second Solution :-
vector<int> max_of_subarrays(int *arr, int n, int k){
    vector<int> v;
    int maxi=arr[0];
    for(int i=1;i<k;i++){
        maxi = max(maxi,arr[i]);
    }

    v.push_back(maxi);
    for(int i=k;i<n;i++){
        if(maxi != arr[i-k] && arr[i]<maxi){
            v.push_back(maxi);
        }
        else{
            maxi=arr[i];
            for(int j=i-k+1;j<i;j++){
                maxi=max(maxi,arr[j]);
            }
            v.push_back(maxi);
        }
    }
    return v;
}



//Third Solution :-
vector <int> max_of_subarrays(int *arr, int n, int k){
    vector<int>ans;
    //for 1st k elemets
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<k;i++){
        pq.push({arr[i],i});
    }

    ans.push_back(pq.top().first);      //for remaining elemnts
    for(int i=k;i<n;i++){
        pq.push({arr[i],i});     
     
        while(!pq.empty() and pq.top().second<=(i-k)){   //if top of pq goes out of range we have to pop it out
            pq.pop();
        }
       
        ans.push_back(pq.top().first);
    }
    return ans;
}



//Fourth Solution :- unoptimized solution
class Solution{
public:
   //Function to find maximum of each subarray of size k.
   vector <int> max_of_subarrays(int *arr, int n, int k)
   {
       vector<int> ans;
       int curr;
       for (int i=0; i<n-k+1; i++){
           curr=*max_element(arr+i, arr+i+k);
           // cout<<curr<<" ";
           ans.push_back(curr);
       }
       return ans;
   }
};