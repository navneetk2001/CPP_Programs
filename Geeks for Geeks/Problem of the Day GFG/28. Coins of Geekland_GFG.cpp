In Geekland there is a grid of coins of size N x N. You have to find the maximum sum of coins in any sub-grid of size K x K.
Note: Coins of the negative denomination are also possible at Geekland.

Example 1:
Input: N = 5, K = 3 
mat[[]] = {1, 1, 1, 1, 1} 
          {2, 2, 2, 2, 2} 
          {3, 8, 6, 7, 3} 
          {4, 4, 4, 4, 4} 
          {5, 5, 5, 5, 5}
Output: 48
Explanation: {8, 6, 7}
             {4, 4, 4}
             {5, 5, 5}
has the maximum sum

Example 2:
Input: N = 1, K = 1
mat[[]] = {{4}} 
Output: 4


//We will use concept of 2D prefix sum
//pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - a[i-1][j-1];

//Now if we want to have a sum of k*k matrix :-
//sum = pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k]

class Solution{
    public:
    int Maximum_Sum(vector<vector<int>> &a,int n,int k){
        int p[n+1][n+1];  //2d prefix matrix to store the sum like 1d prefix array
        for(int i=0;i<=n;i++){ //first row and column filled with 0
        	p[i][0]=0;
        	p[0][i]=0;
        }

        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
        	for(int j=1;j<=n;j++){
        		p[i][j]=a[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        		if(i>=k && j>=k){
        			mx=max(mx, p[i][j] - p[i-k][j] - p[i][j-k] + p[i-k][j-k]);
        		}
        	}
        }
        return mx;
    }   
};


