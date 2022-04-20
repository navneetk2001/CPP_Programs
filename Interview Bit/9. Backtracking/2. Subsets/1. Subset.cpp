// Given a set of distinct integers, S, return all possible subsets.
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// Also, the subsets should be sorted in ascending ( lexicographic ) order.
// The list is not necessarily sorted.

// Example :
// If S = [1,2,3], a solution is:
// [
//   [],
//   [1],
//   [1, 2],
//   [1, 2, 3],
//   [1, 3],
//   [2],
//   [2, 3],
//   [3],
// ]

//Solution Approach :- 
For every element, you have 2 options. You may either include the element in your subset or you will not include the element in your subset.
Make the call for both the cases.

//First Solution :-
void subsets_comb(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
    subs.push_back(sub);
    for (int j = i; j < nums.size(); j++) {
        sub.push_back(nums[j]);
        subsets_comb(nums, j + 1, sub, subs);
        sub.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> subs;
    vector<int> sub;
    sort(A.begin(),A.end());
    subsets_comb(A, 0, sub, subs);
    return subs;
}


//Second Solution :-
// Time complexity : O(N*(2^N))    // Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> ans;
    
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        sub(nums, i+1, temp); //exclude the current element
        temp.push_back(nums[i]); //small work
        sub(nums, i+1, temp); //include the current element
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;       
        sub(nums, 0, temp); 
        return ans;
    }
};


//Third Solution :- Bit Manipulation 
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i=0; i<(1<<n); i++){
    	// i = 5 -> 101 -> [1,3]
        vector<int> sub;
        for(int j=0; j<n; j++){
            if(i & (1<<j)) //check which bit is set
            	sub.push_back(nums[j]);
        }
        ans.push_back(sub);
    }
    
    return ans;
}


//Fourth Solution :- Iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> output;
        int n = nums.size();
        
        output.push_back({});
        
        for(int i=0; i<n; i++)
        {
            int output_size = output.size();
            for(int j=0; j<output_size; j++)
            {
                vector<int> v = output[j];
                v.push_back(nums[i]);
                output.push_back(v);
            }
        }
        return output;
    }
};