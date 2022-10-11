// Alice and Bob take turns playing a game, with Alice starting first.
// Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
// Also, if a player cannot make a move, he/she loses the game.
// Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

// Example 1:
// Input: n = 1
// Output: true
// Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.

// Example 2:
// Input: n = 2
// Output: false
// Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).

// Example 3:
// Input: n = 4
// Output: true
// Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).



//Solution Approach :- Top Down Approach 
class Solution {
public:
    int dp[100005];
    int rec(int n)
    {
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        for(int i=1;i*i<=n;i++){
            if(rec(n-i*i)==0){
                return dp[n]=1;
            }
        }
        return dp[n]=0;
    }

    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=rec(n);
        return ans;
    }
};



//Solution Approach :- Bottom Up Approach 
class Solution {
public:
    bool winnerSquareGame(int n)
    {
        vector<int>v;
        v.push_back(1);
        int res[n+5];
        res[1]=1;
        res[2]=0;
        res[3]=1;
        for(int i=4;i<=n;i++)
        {
             int sq=sqrt(i);
            if((sq*sq)==i)
            {
                res[i]=1;
                v.push_back(i);
            }
            else
            {
                int ok=0;
                for(int k=0;k<(int)v.size();k++)
                {
                    if(res[i-v[k]]==0)
                    {
                        res[i]=1;
                        ok=1;
                        break;
                    }
                }
                if(ok==0)
                    res[i]=0;
            }
        }
        return res[n];
    }
};



