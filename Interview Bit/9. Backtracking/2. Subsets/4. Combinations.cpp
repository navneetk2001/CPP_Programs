// Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
// Make sure the combinations are sorted.
// To elaborate,
// Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
// Entries should be sorted within themselves.
// Example :
// If n = 4 and k = 2, a solution is:
// [
//   [1,2],
//   [1,3],
//   [1,4],
//   [2,3],
//   [2,4],
//   [3,4],
// ]
// Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
// Example : itertools.combinations in python.

//Solution Approach :- 
For every element, you have 2 options. You may either include the element in your subset or you will not include the element in your subset.
Make the call for both the cases.

//First Solution :-
void comb(int n,int k,vector<int>&v,int i,vector<vector<int>>&ans)
{
    if(v.size()==k){
        ans.push_back(v);
        return;
    }
    if(i==(n+1))
        return;

    comb(n,k,v,i+1,ans); // call function before insertion of i

    v.push_back(i);
    comb(n,k,v,i+1,ans); // Call function after insertion of i
    v.pop_back(); // pop element which is inserted if vector is pass by reference
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>>ans;
    vector<int>v;
    int i=1;
    comb(A,B,v,i,ans);
    sort(ans.begin(),ans.end());
    return ans;
}


//Second Solution :-
class Solution {
public:
    int find_bits(int x)
    {
        int c = 0;
        while(x)
        {
            x&=(x-1);
            c++;
        }
        return c;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for(int i = 0;i<(1<<n);i++)
        {
            if(find_bits(i) != k)
                continue;
            vector<int> x;
            for(int j = 0;j<n;j++)
            {
                if((i>>j)&1)
                    x.push_back(j+1);
            }
            if(x.size() == k)
                ans.push_back(x);
        }
        return ans;
    }
};

//Third Solution :- Iterative
class Solution {
public:   
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp(k, 0);
        int itr = 0;
        while(itr > -1){
            temp[itr]++;
            if(temp[itr] > n) itr--;
            else if(itr == k-1) res.push_back(temp);
            else{                
                itr++;
                temp[itr] = temp[itr-1];
            }
        }
        return res;
    }
};


//Fourth Solution 
class Solution {
public:
    void findCombination(vector<vector<int>> &res, vector<int> temp, int index, int n, int k){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int itr = index; itr < n; itr++){
            temp.push_back(itr+1);
            findCombination(res, temp, itr+1, n, k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        findCombination(res, vector<int>(), 0, n, k);
        return res;
    }
};