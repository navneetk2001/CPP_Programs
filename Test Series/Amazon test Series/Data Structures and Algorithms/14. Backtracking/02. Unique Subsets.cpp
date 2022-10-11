https://practice.geeksforgeeks.org/problems/subsets-1587115621/1




//Solution Approach :-
class Solution{
public:
    void solve(vector<int> arr, int n, int index, vector<vector<int>> &ans, vector<int> &subset){
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
    vector<vector<int>> AllSubsets(vector<int> arr, int n){
        vector<vector<int>> ans;
        vector<int> subset;
        sort(arr.begin(),arr.end());
        
        solve(arr,n,0,ans,subset);
        return ans;
    }
};





//Second Solution :-
void solve(set<vector<int>> &us , vector<int> temp, vector<int> arr, int n, int k){
    us.insert(temp);
    if(k==n){
    	return;  
    }
    if(k<n){
        for(int i=k;i<n;i++){
        temp.push_back(arr[i]);
        solve(us, temp, arr, n, i+1);
        temp.pop_back();
        }
    }  
    return;
}

vector<vector<int> > AllSubsets(vector<int> arr, int n){
    set<vector<int>> us;
    sort(arr.begin() , arr.end());
    vector<int> temp;

    solve(us, temp, arr, n, 0);

    vector<vector<int> > ans(us.begin(),us.end());
    return ans;
}


