// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// Each number in C may only be used once in the combination.
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.

// Example :
// Given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]
// Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
// Example : itertools.combinations in python.

//Hint :-
Think how can you use recursion with current index and target sum in order to generate all combinations.
Also, you will have to take special care of those elements which can be overcounted as they are repeated.

//Solution Approach :- 
Some elements can be repeated in the input set. Make sure you iterate over the number of occurrences of those elements to make sure you are not counting the same combinations again.
Once you do that, things are fairly straightforward. You make a recursive call with the remaining sum and make sure the indices are moving forward.

//First Solution :-
void solve(int i, vector<int>& arr, vector<int>& temp, int target, set<vector<int> > &sets){
    if(target == 0){
        sets.insert(temp); 
        return; 
    }
   
    if(i >= arr.size()  || target < 0)
        return;
    
    //not taking
    solve(i + 1, arr, temp, target, sets);
    
    temp.push_back(arr[i]); 
    solve(i+1, arr, temp, target - arr[i], sets); 
    temp.pop_back(); 
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<int> temp; 
    vector<vector<int>> ans;
    set<vector<int>> sets;

    sort(A.begin(), A.end());
    solve(0, A, temp, B, sets);

    for(auto st: sets)
        ans.push_back(st);

    return ans;
}


//Second Solution :-
class Solution {
public:
    void choose(const vector<int>& A, int index, int target, vector<int> current, set<vector<int>>& sets) {
        if (target == 0) {
            sets.insert(current);
            return;
        }

        for (auto i = index; i < A.size(); ++i) {
            if (A[i] > target) break;

            current.push_back(A[i]);
            choose(A, i+1, target - A[i], current, sets);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& A, int B) {
        sort(A.begin(), A.end());
        vector<vector<int>> ans;
        set<vector<int>> sets;
        
        choose(A, 0, B, {}, sets);
        
        for(auto st: sets)
            ans.push_back(st);
        
        return ans;
    }
};

//Third Solution :- 
class Solution {
public:
    set<vector<int>> s;
    vector<int> v;
    
    int find(vector<int>& candidates, int target,int temp_tar,int n,int index){
        if(temp_tar>target) 
            return 0;
        
        if(temp_tar==target){
            vector<int> temp;
            for(auto t: v){
                temp.push_back(t);
            }
            
            sort(temp.begin(),temp.end());
            if(s.find(temp)==s.end()){ 
                s.insert(v);
            }
            return 0;
        }
        
        for(int i=index; i<n; i++){
            v.push_back(candidates[i]);
            int num = find(candidates, target, temp_tar+candidates[i],n,i+1);
            v.pop_back();
            if(!num){
               break;
            }
            while(i<n-1 && candidates[i+1]==candidates[i]) i++;
        }
        
        return 1;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> res;
        
        sort(candidates.begin(),candidates.end());
        find(candidates,target,0,n,0);
        
        for(auto x: s){
            res.push_back(x);
        }
        return res;
    }
};
