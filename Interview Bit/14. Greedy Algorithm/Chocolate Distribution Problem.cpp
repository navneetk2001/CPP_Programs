https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1






//Solution Approach :- 
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        int mini = INT_MAX;
        
        for(int i=0;i+m-1<n;i++){
            int d = a[i+m-1] - a[i];
            
            if(d<mini){
                mini = d;
            }
        }
        return mini;
    }   
};


