https://leetcode.com/problems/count-vowels-permutation/




//Solution Approach :- 
#include <unordered_map>
class Solution {
    unordered_map<int, vector<int>> m;
    int MOD = 1e9+7;
public:
        int helper(int n, int i, char prev, vector<vector<long long> > &dp){
            if (i > n){           //base case or edge case
                return 0;
            }
            if(i == n){           //base case
                switch(prev){
                    case 'a':
                        return 1;
                    case 'e':
                        return 2;
                    case 'i':
                        return 4;
                    case 'o':
                        return 2;
                    case 'u':
                        return 1;
                    default:
                        return 5;
                }
            }

            int idx = prev - 'a';      //prev char
            if(dp[i][idx] != -1){
                return dp[i][idx];
            }
            long long ans = 0;      //stores answer
            for(auto next : m[prev]){     //recursive call on all the next values it can take
                ans += (helper(n, i+1, next, dp) % MOD);
            }

            return dp[i][idx] = ans % MOD;
        }

        int countVowelPermutation(int n) {
            m['c'] = {'a','e','i','o','u'};
            m['a'] = {'e'};
            m['e'] = {'a','i'};
            m['i'] = {'a','e','o','u'};
            m['o'] = {'i','u'};
            m['u'] = {'a'};

            vector<vector<long long> > dp(vector<vector<long long> >(n+2,vector<long long>(27,-1)));
            return helper(n , 1 , 'c', dp);

        }
};






//❌ Solution - I (Brute-Force)
// We need to form a string of length n with vowels. We are also given some initial rules or mappings which tells us what character will come after the current character. We need to return the total number of different strings we can form.
// Let's try to solve this problem starting with the brute-force appraoch. We can start with any of the 5 vowels and thereafter we have the choice to choose next vowel depending on what's allowed after the previous vowel in the given mappings. The given mappings state what vowels are allowed after a given vowel -
// start   =>  a / e / i / o / u   # start denotes 1st character of string which can be any vowel
// a       =>  e
// e       =>  a / i
// i       =>  a / e / o / u
// o       =>  i / u
// u       =>  a
// So, we will follow this approach. At each index, we will try choosing all vowels allowed after the previous one. The start will be denoted by s (any vowel is allowed after it).

class Solution {
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings{ {'s', {'a', 'e', 'i', 'o', 'u'} }, // start
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
public:
    int countVowelPermutation(int n) {
        return solve(n, 's');                         // start with s
    }

    int solve(int rem, char prev) {
        if(rem == 0) return 1;                        // no need to pick further. We have formed 1 string of length = n.
        int ans = 0;
        for(auto c : mappings.at(prev))               // try each vowel allowed after prev character
            ans = (ans + solve(rem - 1, c)) % MOD;  
        return ans;
    }
};


// Alternate Concise Implementation
// Time Complexity : O(5N), at each index we have maximum of 5 choices with us. There are total of n indices. Thus 5*5*5...N times = O(5N).
// Space Complexity : O(N), required for recursive stack. Max recursive depth at any point will be N



// ✔️ Solution - II (Dynamic Programming - Top-Down Recursive)
// We can observe does a lot of repeated calculations. The total number of possible strings when we know the previous character prev and remaining length rem will always be constant. So there's no need to repeat the same calculation. We can store the calculated result for a given state and reuse it in the future. Thus, we can optimize the solution using dynamic programming.
// We will maintain a dp array of length n+1 for each vowel. Here, dp[prev_vowel][rem] will denote the number of strings that can be formed when previous character was prev_vowel and number of characters still required is equal to rem. Each time, we will try all vowels possible at current index and explore the further path. We will store the calculated result in dp[prev][rem] and reuse it whenever required in future recursive calls.

class Solution {
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings{ {'s', {'a', 'e', 'i', 'o', 'u'} }, // start
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
    unordered_map<char, vector<int>> dp;
public:
    int countVowelPermutation(int n) {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);
        return solve(n, 's');                         // start with s
    }
    int solve(int rem, char prev) {
        if(rem == 0) return 1;                        // no need to pick further. We have formed 1 string of length = n.
        if(dp[prev][rem]) return dp[prev][rem];       // if result already calculated for current state, directly return it
        for(auto c : mappings.at(prev))               // try each vowel allowed after prev character
            dp[prev][rem] = (dp[prev][rem] + solve(rem - 1, c)) % MOD;  
        return dp[prev][rem];
    }
};

// ✔️ Alternate Concise Implementation (Faster Runtime)
// Time Complexity : O(N), we will be calculating the total possible strings for a given vowels when rem characters are requried, only once. Thus, each vowel will make a max of N recursive calls. Hence the total time complexity becomes O(5*N) = O(N)
// Space Complexity : O(N), O(N) space is required by recursive stack. Further, a total of O(5*N) space is used by dp. Thus the total space complexity becomes O(N) + O(5*N) = O(N)




//✔️ Solution - III (Dynamic Programming - Bottom-Up Iterative)
//We can also solve this using iterative DP. Here we will start with the state for n = 1 where we can form 1 string using each vowel at start. We will use the previous states to calculate the result for next. Here dp[k][i] will denote the number of possible strings of length i that end at vowel numbered - k. Here, I have just converted from vowel character mappings to integer mappings like -
// 0 (a)       =>  1
// 1 (e)       =>  0 / 2
// 2 (i)       =>  0 / 1 / 3 / 4
// 3 (o)       =>  2 / 4
// 4 (u)       =>  0
// Each time, we use the stored number of strings possible for length i-1 to calculate for length i. We will use only those state for dp[k] from which it is allowed to use kth vowel at next position.

class Solution {
public:
    int countVowelPermutation(int n){
        const int MOD = 1e9 + 7;
        long dp[5][n+1], ans = 0;
        dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[0][i] =  dp[1][i-1];
            dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % MOD;
            dp[2][i] = (dp[0][i-1] + dp[1][i-1] + dp[3][i-1] + dp[4][i-1]) % MOD;
            dp[3][i] = (dp[2][i-1] + dp[4][i-1]) % MOD;
            dp[4][i] =  dp[0][i-1];
        }

        for(int i=0; i < 5; i++){
            ans = (ans + dp[i][n]) % MOD;
        }
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)



//✔️ Solution - IV (Space-Optimized DP)
//We can observe that at any point of time we are only using the previous state of each dp[i]. So, we can don't need to store all the states and further optimize the solution by storing only the state for previous length for each vowel.

class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        long a = 1, e = 1, i = 1, o = 1, u = 1, a_new, e_new, i_new, o_new, u_new;
        for(int j = 2; j <= n; j++) {
            a_new =  e;
            e_new = (a + i) % MOD;
            i_new = (a + e + o + u) % MOD;
            o_new = (i + u) % MOD;
            u_new =  a;
            a = a_new, e = e_new, i = i_new, o = o_new, u = u_new;
        }
        return (a + e + i + o + u) % MOD;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)




// ✔️ Solution - V (Pre-compute DP)
// Just precompute the answers for all N at the start and use the globally stored result for all test cases instead of repeating the calculation for each test case. Also since in this case the algorithm performs the same operations for any test cases, by definition, it is a constant time and space solution since it doesn't depend on input :).

int vowelPerms[20001];
auto _ = []{
    const int MOD = 1e9 + 7;
	long a = 1, e = 1, i = 1, o = 1, u = 1, a_new, e_new, i_new, o_new, u_new;
	vowelPerms[1] = 5;
	for (int j = 2; j <= 20000; j++) {
		a_new =  e;
		e_new = (a + i) % MOD;
		i_new = (a + e + o + u) % MOD;
		o_new = (i + u) % MOD;
		u_new =  a;
		a = a_new, e = e_new, i = i_new, o = o_new, u = u_new;
		vowelPerms[j] = (a + e + i + o + u) % MOD;
	}
	return true;
}();  // IIFE

class Solution {
public:
    int countVowelPermutation(int n) {
        return vowelPerms[n];
    }
};


// Time Complexity : O(1), time required by countVowelPermutation() doesn't depend on input n. The pre-computation time complexity in this case is O(MAX_N) = O(20000) = O(1). This solution would be more efficient than Solution-IV when there are multiple queries / test-cases that we need to solve for.
// Space Complexity : O(1)