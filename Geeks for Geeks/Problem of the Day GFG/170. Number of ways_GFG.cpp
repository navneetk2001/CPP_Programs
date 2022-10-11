// Given a value N. In how many ways you can construct a grid of size N x 4 using tiles of size 1 x 4.

// Example 1:
// Input: N = 1
// Output: 1
// Explaination: We can arrange the tiles horizontally and this is the only way.

// Example 2:
// Input: N = 4
// Output: 2
// Explaination: The first way can be when all the 1 x 4 tiles are arranged horizontally. Second way can be when all the 1 x 4 tiles are arranged vertically.





//Solution Approach :- Recursion 
class Solution{
public:
   	long long int arrangeTiles(int N){
   		if(N<4) return 1;
       	return arrangeTiles(N-1) + arrangeTiles(N-4);
   	}
};



//Solution Approach :- Memoization
class Solution{
public:
   	long long dp[81];
   	long long F(int N){
       	if(N<4){  //Base Case
       		return 1;
       	}
       	if(dp[N]!=-1){
       		return dp[N];
       	}
       	return dp[N]= F(N-4)+F(N-1);
   	}
   	
   	long long int arrangeTiles(int N){
       	memset(dp,-1,sizeof(dp));
       	return F(N);
   	}
};


//Solution Approach :- Tabulation
long long int arrangeTiles(int N){   
   	if(N <= 3){
   		return 1;
   	}
   	vector<long long> dp(N + 1, 0);
   	for(int i = 0; i <= 3; i++){    //Base Case
   		dp[i] = 1;
   	}

   	for(int i = 4; i <= N; i++){
   		dp[i] = dp[i - 1] + dp[i - 4];
   	}
   	return dp[N];
}
