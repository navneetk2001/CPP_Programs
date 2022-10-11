// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.

// Example 1:
// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

// Example 2:
// Input: word1 = "leetcode", word2 = "etco"
// Output: 4



//Solution Approach :- (Dynamic Programming - Memoization) [Accepted]
// We can observe that the above solution makes a lot of repeated recursive calls. This is because we can reach same (i, j) index pair in multiple ways. But the answer to equalize word1[i:] (characters from index i till end) and word2[j:] (characters from index j till end) will always remain the same.
// Thus, we can avoid the recomputations by using Dynamic Programming. We will maintain a 2D DP array where dp[i][j] will denote the number of steps required to equalize word1[i:] and word2[j:].
// All the steps remain the same as the brute force solution. The only addition is of dp array, storing the results before returning and if results are already computed, directly returning them instead of recalculations.

vector<vector<int>> dp;      // dp[i][j] will denote minimum steps required to equalize word1[i:end] and word[2:j:end]
int minDistance(string& word1, string& word2) {
	dp.resize(size(word1) + 1, vector<int>(size(word2) + 1, 1000));
	return solve(word1, word2, 0, 0);
}

int solve(string &w1, string &w2, int i, int j) {
	if(i == size(w1) && j == size(w2)){
		return 0;
	}
	if(i == size(w1) || j == size(w2)){
		return max(size(w1) - i, size(w2) - j);
	}

	if(dp[i][j] != 1000){
		return dp[i][j];  // directly return stored answer if already computed before
	}

	if(w1[i] == w2[j]){
		return solve(w1, w2, i + 1, j + 1);
	}
	return dp[i][j] = 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
}



//Second Solution :- (Dynamic Programming - Tabulation) [Accepted]
int minDistance(string& word1, string& word2) {        
	vector<vector<int> >dp(size(word1) + 1, vector<int>(size(word2) + 1));
	
	for(int i = 0; i <= size(word1); i++){
		for(int j = 0; j <= size(word2); j++){
			if(!i || !j){                      // if one word == "", all other characters of other word need to be deleted
				dp[i][j] = i + j;  
			}
			else{                     			// if characters match ? dont delete : 1 deletion + min to equalize after deletion of (word1[i], word2[j])
				dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[size(word1)][size(word2)];
}



//Third Solution :-  //Using LCS 
int minDistance(string& word1, string& word2) {   
	int m=word1.size(); 
	int n=word2.size(); 
	vector<vector<int>>dp(m+1, vector<int>(n+1,0));
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(word1[i-1] == word2[j-1]){                      // if one word == "", all other characters of other word need to be deleted
				dp[i][j] = 1 + dp[i-1][j-1];  
			}
			else{                     			// if characters match ? dont delete : 1 deletion + min to equalize after deletion of (word1[i], word2[j])
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return m-dp[m][n] + n-dp[m][n];
}


//Fourth Solution :- Brute Force Solution (TLE) 
int minDistance(string& word1, string& word2) {
	return solve(word1, word2, 0, 0);
}

// recursive solver to find minimum deletions to equalize w1 & w2
int solve(string w1, string w2, int i, int j) {
	if(i == size(w1) && j == size(w2)){
		return 0;  // reached end of both strings -> both strings have been equalized and no further steps required
	}

	if(i == size(w1)){
		return size(w2) - j;        // reached end of word1 -> need to delete remaining characters of word2 to equalize
	}

    if(j == size(w2)){
    	return size(w1) - i;        // reached end of word2 -> need to delete remaining characters of word1 to equalize
    }

	if(w1[i] == w2[j]){
		return solve(w1, w2, i + 1, j + 1);  // no deletion required since the characters already match
	}
	
	return 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));   // 1 current character deletion + min(after deleting w1[i], after deleting w2[j])
}