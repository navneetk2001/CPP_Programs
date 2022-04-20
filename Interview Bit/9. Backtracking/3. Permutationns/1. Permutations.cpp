// Given a collection of numbers, return all possible permutations.

// Example:
// [1,2,3] will have the following permutations:

// [1,2,3]
// [1,3,2]
// [2,1,3] 
// [2,3,1] 
// [3,1,2] 
// [3,2,1]

// NOTE
// No two entries in the permutation sequence should be the same.
// For the purpose of this problem, assume that all the numbers in the collection are unique.
// Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.

// Example : next_permutations in C++ / itertools.permutations in python.
// If you do, we will disqualify your submission retroactively and give you penalty points.


//Hint :-
Again, what helps here is thinking in terms of recursion.
At each step you can keep any of the elements from the remaining one and permute remaining one excluding current one.

//Solution Approach :- 
Lets say we are at index start then we can swap element at this index with any index>start and permute the elements starting from start+1 using recursion. You can swap back the elements at start and index in order to maintain the order for next recursive call.

//First Solution :-
void fun(vector<int> &A, vector<vector<int>> &v, int i, int n){

    if(i==n-1){
        v.push_back(A); 
        return;
    }

    for(int j=i;j<n;j++){
        swap(A[i],A[j]);
        fun(A,v,i+1,n);
        swap(A[i],A[j]);   
    }

}

vector<vector<int>> Solution::permute(vector<int> &A) {
    int n=A.size();
    vector<vector<int>>v;
    fun(A,v,0,n);
    return v;
}



//Second Solution :-
class Solution {
public:
    void permute(vector<int> &num, int start, vector<vector<int>> &result) {
        if (start == num.size() - 1) {
            result.push_back(num);
            return;
        } 
        for (int i = start; i < num.size(); i++) {
            swap(num[start], num[i]);
            permute(num, start + 1, result);
            swap(num[start], num[i]);
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() == 0)
            return result;
        sort(num.begin(), num.end());
        permute(num, 0, result);
        return result;
    }
};


//Third Solution :- 
bool nextperm(vector<int> &arr)
{
    int i,j,flag=0,index,temp,min;
    if(arr.size() == 1)
        return 0;
    for(i=arr.size()-2;i>=0;i--)
    {
        index = -1;
        min = INT_MAX;
        for(j=i+1;j<arr.size();j++)
        {
            if(arr[j]>arr[i] && min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        if(index != -1)
        {
            swap(arr[i],arr[index]);
            sort(arr.begin()+i+1,arr.end());
            return 1;
        }
    }
    return 0;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int flag = 1;
    vector<vector<int> > ans;
    sort(A.begin(),A.end());
    ans.push_back(A);
    while(flag)
    {
        flag = nextperm(A);
        if(flag)
            ans.push_back(A);
    }
    return ans;
}


//Fourth Solution :- Use space complexity also
class Solution {
private: 
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds); 
            return; 
        }
        for(int i = 0;i<nums.size();i++) {
            if(!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1; 
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0; 
                ds.pop_back(); 
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        int freq[nums.size()]; 
        for(int i = 0;i<nums.size();i++) freq[i] = 0; 
        recurPermute(ds, nums, ans, freq); 
        return ans; 
    }
};
