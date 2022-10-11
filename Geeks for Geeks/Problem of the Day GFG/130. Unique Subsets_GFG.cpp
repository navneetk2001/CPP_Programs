// Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.
// Note: Each subset should be sorted.

// Example 1:
// Input: N = 3, arr[] = {2,1,2}
// Output:(),(1),(1 2),(1 2 2),(2),(2 2)
// Explanation: 
// All possible subsets = (),(2),(1),(1,2),(2),(2,2),(2,1),(2,1,2)
// After Sorting each subset = (),(2),(1),(1,2),(2),(2,2),(1,2),(1,2,2) 
// Unique Susbsets in Lexicographical order = (),(1),(1,2),(1,2,2),(2),(2,2)

// Example 2:
// Input: N = 4, arr[] = {1,2,3,3}
// Output: (),(1),(1 2),(1 2 3),(1 2 3 3),(1 3),(1 3 3),(2),(2 3),(2 3 3),(3),(3 3)




//Solution Approach :-
class Solution{
public:
    void solve(vector<int> arr, int n , int index, vector<vector<int>>&ans, vector<int>& subset){
        ans.push_back(subset);
        
        for(int i=index;i<n;i++){
            subset.push_back(arr[i]);
            solve(arr,n,i+1,ans,subset);
            subset.pop_back();
        
            while(i<n-1 && arr[i+1] == arr[i]){
                i++;
            }
        }
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> ans;
        vector<int>subset;
        sort(arr.begin(),arr.end());
        
        solve(arr,n,0,ans,subset);
        return ans;
    }
};



//Second Solution :-
vector<vector<int>> ans;
vector<int> t;

void subsets(vector<int> &a, int in,int n){
    if(in==n){
        ans.push_back(t);
        return;
    }
    
    if(t.empty() || t.back()!=a[in])
    	subsets(a,in+1,n);
    
    t.push_back(a[in]);
    subsets(a,in+1,n);
    t.pop_back();
}

//Function to find all possible unique subsets.
vector<vector<int> > AllSubsets(vector<int> a, int n){
    sort(a.begin(),a.end());
    subsets(a,0,n);
    sort(ans.begin(),ans.end());
    return ans;
}



//Third Solution :-
void solve(vector<int> &arr, int n, int idx, vector<int> &temp_ans, set<vector<int>> &ans){
    if(idx==n){
        ans.insert(temp_ans);
        return;
    }
    temp_ans.push_back(arr[idx]);
    solve(arr, n, idx+1, temp_ans, ans);
    temp_ans.pop_back();
    solve(arr, n, idx+1, temp_ans, ans);
}

vector<vector<int> > AllSubsets(vector<int> arr, int n){
    sort(arr.begin(),arr.end());
    vector<int> temp_ans;
    set<vector<int>> s;
    
    solve(arr,n,0,temp_ans,s);
    
    vector<vector<int>> ans;
    for(auto x: s){
        ans.push_back(x);
        
    }
    return ans;
}
