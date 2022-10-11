// Given a string str consisting of digits, one may group these digits into sub-groups while maintaining their original order.
// The task is to count number of groupings such that for every sub-group except the last one, sum of digits in a sub-group is less than or equal to sum of the digits in the sub-group immediately on its right.
// For example, a valid grouping of digits of number 1119 is (1-11-9). Sum of digits in first subgroup is 1, next subgroup is 2, and last subgroup is 9. Sum of every subgroup is less than or equal to its immediate right.
 
// Example 1: 
// Input: str = "1119"
// Output: 7
// Explanation: [1-119], [1-1-19], [1-11-9], [1-1-1-9], [11-19], [111-9] and [1119] are seven sub-groups.

// Example 2:
// Input: str = "12"
// Output: 2
// Explanation: [1-2] and [12] are two sub-groups.




//Solution Approach :-
int TotalCount(string A){
    int S = 0, n = A.size();

    for(char c: A){
    	S += (c-'0');
    }

    vector<vector<int>> dp(A.size()+1, vector<int>(S+1,0));
    for(int s=0; s<=S; s++){
    	dp[n][s] = 1;
    }

    for(int start=n-1; start>=0; start--){
        for(int prev_sum=0; prev_sum<=S; prev_sum++){
            int sum = 0, res = 0;
            for(int i=start;i<n;i++){
                sum += (A[i]-'0');
                if(sum >= prev_sum)
                    dp[start][prev_sum] += dp[i+1][sum];
            }
        }
    }
    return dp[0][0];
}



//Second Solution :- DP Solution
int grouping(string str, int index, int sum){
	if(index==str.length()){
		return 1;
	}
	if(dp[index][sum]!=-1){
		return dp[index][sum];
	}
	int curr_sum=0;
	int ans=0;
	for(int i=index;i<str.size();i++){
		curr_sum+=str[i]-'0';
		if(curr_sum>=sum){
			ans+=grouping(str,i+1,curr_sum);
		}
	}
	return dp[index][sum]=ans;
}

vector<vector<int>> dp;
int TotalCount(string str){
    int n=str.size();
    dp.resize(n,vector<int>(9*n,-1));
    return grouping(str,0,0);
}



//Third Solution :- Recursion 
vector<vector<int>> dp;
int TotalCount(string str){
    return grouping(str,0,0);  //index=0 and sum=0
}

int grouping(string str, int index, int sum){
	if(index==str.length()){
		return 1;
	}
	int curr_sum=0;
	int ans=0;
	for(int i=index;i<str.size();i++){
		curr_sum+=str[i]-'0';
		if(curr_sum>=sum){
			ans+=grouping(str,i+1,curr_sum);
		}
	}
	return ans;
}
