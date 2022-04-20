// Given a collection of integers that might contain duplicates, S, return all possible subsets.
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// The subsets must be sorted lexicographically.
// Example :
// If S = [1,2,2], the solution is:
// [
// [],
// [1],
// [1,2],
// [1,2,2],
// [2],
// [2, 2]
// ]

//Solution Approach :- 
Think in terms of recursion.
This is very similar to the problem where you need to generate subsets for distinct integer. However, in this case, because of repetitions, things are not as simple as choosing or rejecting an element.
Now for the elements which are repeated you need to iterate over the count of elements you are going to include in your subset.


//First Solution :-
void fun(vector<int>& nums, vector<int> sol,vector<vector<int>>& ans, int i) {
    if(i == nums.size()) {
        ans.push_back(sol);
        return;
    }

    //All subsets that include nums[i]
    sol.push_back(nums[i]);
    fun(nums,sol,ans,i+1);
    sol.pop_back();

    //All subsets that don't include nums[i]
    while(i+1 < nums.size() and nums[i] == nums[i+1])
        i++;

    fun(nums,sol,ans,i+1);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    vector<int> v;
    fun(nums,v,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}



//Second Solution :-
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int len =  nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
   
    ///here intuition is using queue, we keep track of last elem in the subset in each level
    ///for computing next level we will consider only elements after last elem in each subset of
    ///prev level
    //we adds new valid Subsets to the res before pushing into queue
    
    //2 queues used
    // one for keeping subsets 
    // one for keeping thier last elem's pos in nums
    queue<int> lastIdx;
    queue<vector<int>> Level;
    
    ///initializion
        res.push_back({});
        Level.push({});
        lastIdx.push(-1);

    //we takes one by one subsets (pop from queue also)and appends new elem after last elem's pos (if possible)
    // and then pushes back to queue
    while(!Level.empty())
    {
        vector<int> curr_subset = Level.front();
        int curr_back   = lastIdx.front();
        Level.pop(); lastIdx.pop();
        
        for(int i = curr_back+1; i < len; i++)
        {
            vector<int> new_subset = curr_subset;
            new_subset.push_back(nums[i]);
            
            ///Since the result vector is sorted .. we can ignore duplicates by checking last elem in result
            if(new_subset == res.back())
                continue;
            
            res.push_back(new_subset);
            Level.push(new_subset);
            lastIdx.push(i);
        }
    }
    return res;
}


//Third Solution :- 
class Solution {
public:

void subsetGenerate(int ind,int n,vector<int>&nums,vector<int>v,vector<vector<int>>&ans)
{
    // here we are pushing v every time and not just when ind == n
    // because here every choice is a candidate for a subset and the for loop
    // guarantees it's going to be unique
    ans.push_back(v);

    for(int i = ind;i<n;i++){
        if(i > ind && nums[i-1] == nums[i]){  // avoiding duplicates
            continue;
        }
        
        v.push_back(nums[i]);
        subsetGenerate(i+1,n,nums,v,ans);
        v.pop_back();
        // after the current recurison call has finished,for all subsets starting from 
        // index i , for next one we need fresh vector so we do v.pop_back()
        // this works because vector is pass by value so v.pop_back() will worl
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int>v;
    vector<vector<int>>ans;
    subsetGenerate(0,n,nums,v,ans);
    return ans;
};


//Fourth Solution :- 
// if nums has 3 elements so one can select elements in 8 ways 
// 0 0 0
// 0 0 1
// 0 1 0
// 0 1 1
// 1 0 0
// 1 0 1
// 1 1 0
// 1 1 1

//so select only elements which is 1 , so this way we can create different subsets

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort the numbers for removing any duplicate set creation later
        //for eg. [1 2 3 4 4] & [3 2 4 4 1] are same only
        int mask = 1<<nums.size(); // 1<<num.size is equilvalent to pow(2,num.size()) in binary form
        vector<int> vec;
        set<vector<int>> s;//for storing unique set of elements 
        for(int i=0;i<mask;i++){
            
            for(int j=0;j<nums.size();j++){
                
                //convert j to binary and & with i if that is non zero then add it to vec
                if(1<<j & i){
                    vec.push_back(nums[j]);
                }
                
            }
            
            s.insert(vec);
            vec.clear();
        }
        vector<vector<int>> ans;//convert thr result to vector and return
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};