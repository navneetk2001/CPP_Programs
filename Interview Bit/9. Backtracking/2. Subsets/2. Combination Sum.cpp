// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The combinations themselves must be sorted in ascending order.
// CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
// The solution set must not contain duplicate combinations.
// Example, 
// Given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [2, 2, 3]
// [7]
// Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
// Example : itertools.combinations in python.
// If you do, we will disqualify your submission retroactively and give you penalty points.

//Solution Approach :- 
In every recursion run, you either include the element in the combination or you don’t. To account for multiple occurrences of an element, make sure you call the next function without incrementing the current index.

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
    solve(i, arr, temp, target - arr[i], sets); 
    temp.pop_back(); 
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int target) {
    vector<int> temp; 
    vector<vector<int>> ans;
    set<vector<int>> sets;

    sort(A.begin(), A.end());
    solve(0, A, temp, target,sets);

    for(auto st: sets)
        ans.push_back(st);

    sort(ans.begin(), ans.end());
    return ans; 
}



//Second Solution :-
void choose(const vector<int>& A, int index, int target, vector<int> current, vector<vector<int>>& ans) {
    if (target == 0) ans.push_back(current);
    
    for (auto i = index; i < A.size(); ++i) {
        if (A[i] > target) break;

        current.push_back(A[i]);
        choose(A, i, target - A[i], current, ans);
        current.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    
    vector<vector<int>> ans;
    choose(A, 0, B, {}, ans);
    return ans;
}

