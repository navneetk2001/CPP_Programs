// Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
// Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.


// Example 1:
// Input:
// n = 2
// keys = {10, 12}
// freq = {34, 50}
// Output: 118
// Explaination:
// There can be following two possible BSTs 
//         10                       12
//           \                     / 
//            12                 10
                              
// The cost of tree I is 34*1 + 50*2 = 134
// The cost of tree II is 50*1 + 34*2 = 118 

// Example 2:
// Input:
// N = 3
// keys = {10, 12, 20}
// freq = {34, 8, 50}
// Output: 142
// Explaination: There can be many possible BSTs
//      20
//     /
//    10  
//     \
//      12  
     
// Among all possible BSTs, cost of this BST is minimum.  
// Cost of this BST is 1*50 + 2*34 + 3*8 = 142



//Solution Approach :-
const int INF = 1e9;
class Solution{
    public:
    int solve(int i, int j, int freq[], vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != INF) return dp[i][j];
        
        int sum = 0;
        for(int k=i; k<=j; k++) sum += freq[k];
        
        for(int k=i; k<=j; k++)
            dp[i][j] = min(dp[i][j], sum+solve(i,k-1,freq,dp)+solve(k+1,j,freq,dp));
        
        return dp[i][j];
    }
    
    int optimalSearchTree(int keys[], int freq[], int n) {
        vector<vector<int>> dp(n, vector<int>(n,INF));
        
        for(int i=0; i<n; i++)
            dp[i][i] = freq[i];
        
        return solve(0,n-1,freq,dp);
    }
};



//Second Solution :- Gap strategy+prefix sum+Basics of 2D dp
int optimalSearchTree(int keys[], int freq[], int n)
{
   int sum=0;
   vector<int> pre(n+1);
   pre[0]=0;
   for(int i=1;i<=n;i++)
   {
       pre[i]=pre[i-1]+freq[i-1];
   }
    int dp[n][n];
   //   memset(dp,0,sizeof(dp));
     for(int g=0;g<n;g++)
     {
         for(int i=0,j=g;j<n;i++,j++)
         {
             if(g==0)
             {
                 dp[i][j]=freq[i];
             }
             else if(g==1)
             {
                 dp[i][j]=min(freq[i]*1+freq[j]*2,freq[i]*2+freq[j]*1);
             }
             else{
                 int ans=INT_MAX;
                 for(int k=i;k<=j;k++)
                 {
                     int left,right;
                     if(k==i)       
                     left=0;
                     else left=dp[i][k-1];
                     
                     if(k==j)
                     {
                         right=0;
                     }
                     else right=dp[k+1][j];
                     ans=min(ans,left+right);
                 }
                 dp[i][j]=ans+pre[j+1]-pre[i];
             }
         }
     }
     return dp[0][n-1];
   }


//Third Solution :-
class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        pair<int,int> f[n];
        for(int i=0;i<n;i++){
        	f[i] = {keys[i], freq[i]};
        }
        sort(f,f+n);

        int P[n]; //Prefix Sum
        P[0]=f[0].second;
        for(int i=0;i<n;i++){
        	P[i] = P[i-1] + f[i].second;
        }

        int dp[n][n];
        for(int i=0;i<n;i++){
        	dp[i][i]=f[i].second;
        }

        for(int i=n-1;i>=0;i--){
        	for(int j=i+1;j<n;j++){
        		dp[i][j]=INT_MAX;
        		for(int k=i;k<=j;k++){
        			int leftSubtree = (k>i ? dp[i][k-1] : 0);
        			int rightSubtree = (k<j ? dp[k+1][j] : 0);
        			dp[i][j]=min(dp[i][j], leftSubtree+rightSubtree+P[j] - (i>0?P[i-1]:0));
        		}
        	}
        }
        return dp[0][n-1];
    }
};