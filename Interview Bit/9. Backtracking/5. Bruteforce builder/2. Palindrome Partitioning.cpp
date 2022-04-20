// Given a string s, partition s such that every string of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
// For example, given s = "aab",
// Return
//   [
//     ["a","a","b"]
//     ["aa","b"],
//   ]
// Ordering the results in the answer :

// Entry i will come before Entry j if :
// len(Entryi[0]) < len(Entryj[0]) OR
// (len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR*
// (len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
// In the given example,
//    ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")


//Hint :-
Since, we are listing out all the partitions ( and not counting them), we need to do brute force here.
Think of recursion.

//Solution Approach :- 
When on index i, you incrementally check all substring starting from i for being palindromic. If found, you recursively solve the problem for the remaining string and add it to your solution. Start this recursion from starting position of the string.
PS: You can optimize your solution by not computing the answer for same index multiple times using Dynamic Programming.


//First Solution :-
bool isPalindrome(string s){
    int l = 0;
    int r = s.size() - 1;
    while(l < r){
        if(s[l++] != s[r--]){
            return false;
        }
    }
    return true;
}
    
void helper(string s, vector<vector<string>> &result, vector<string> temp){
    if(s.size() == 0){         //base case
        result.push_back(temp);
    }
    for(int i = 0; i < s.size(); i++){
        string leftPar = s.substr(0, i + 1);
        if(isPalindrome(leftPar)){
            temp.push_back(leftPar);
            helper(s.substr(i + 1), result, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> result;
    vector<string> temp;
    helper(A, result, temp);
    return result;
}



//Second Solution :- Backtracking with Dynamic Programming
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) 
        	result.push_back(currentList);

        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};



//Third Solution :- 
class Solution {
public:            
bool palindrome(string s,int st,int end){
	while(st<=end)
	{
	    if(s[st]==s[end])
	    {
	        st++;
	        end--;
	    }
	    else
	        return false;
	}
	return true;
}         

vector<vector<string>> partition(string s) {
    unordered_map<int,vector<vector<string>>> um;
    vector<string> temp2;
    um[-1].push_back(temp2);

    for(int i=0;i<s.length();i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(palindrome(s,j,i))
            {
                vector<vector<string>> first = um[j-1];
                string str = s.substr(j,i-j+1);
                for(int k=0;k<first.size();k++)
                {
                    vector<string> v = first[k];
                    v.push_back(str);
                    um[i].push_back(v);
                }
            }
        }
    }
    return um[s.length()-1];
}
};


