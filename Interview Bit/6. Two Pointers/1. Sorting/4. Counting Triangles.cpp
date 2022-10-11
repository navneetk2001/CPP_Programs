// You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
// Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.
// Notes:
// You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.
// Return answer modulo 109 + 7.
// For example,
// A = [1, 1, 1, 2, 2]
// Return: 4


//Hint 
// We know that for side lengths A, B and C where A < B < C, they form a triangle if they follow the triangle inequality i.e. A + B > C
// Suppose you are given a sorted array of side lengths in ascending order. How will you count the possible number of triangles ?

// //Solution Approach :-
// First we sort the array of side lengths. So since Ai < Aj < Ak where i < j < k, therefore it is sufficient to check Ai + Aj > Ak to prove they form a triangle.
// Thus for every i and j, we can find the maximum value of k such that the triangle inequality holds.
// Also we can also prove that for every such index i, we only have to increase the value of the k (satisfying the above condition) for every iteration of j from i+1 to n. Therefore, we get a O(n2) solution (Proof of this is left to the reader).

//First Solution Approach :-

//Sides of a triangle :-> a, b, c such that (a+b)>c
//fix c and try to find both a and b
//c+a>b and c+b>a satisfied by default when c is largest

const int mod = 1e9+7;
int Solution::nTriang(vector<int> &A) {
    long long int ans=0, n=A.size();
    sort(A.begin(),A.end());
    
    for(long long int c=n-1;c>=2;c--){
        int a=0, b=c-1;
        while(a<b){
            if(A[a] + A[b] > A[c]){
                ans+=(b-a)%mod;
                b--;
            }
            else{
                a++;
            }
        }
    }
    return ans%mod;
}


//Second Solution
int Solution::nTriang(vector<int> &A) {
    int n=A.size(),ans=0,m=1e9+7;
    sort(A.begin(),A.end());

    for(int i=0;i<n-2;i++){
        if(A[i]==0) {
            continue;
        }
        for(int j=i+1;j<n-1;j++)
            ans=(ans+((lower_bound(A.begin(),A.end(),A[i]+A[j]))-(A.begin()+j+1)))%m;
    }
    return ans;
}


//Third Solution
int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    int mod=1000000007;
    int n=A.size();
    int count=0;
    for(int i=n-1;i>1;i--)
    {
        int s=0;
        int e=i-1;
        if(A[i]==0){
            continue;
        }
            
        while(s<e)
        {
            if(A[s]+A[e]>A[i])
                count+=e-s,e--;
            else
                s++;
            
            count=count%mod;
        }
    }
    return count;
}
