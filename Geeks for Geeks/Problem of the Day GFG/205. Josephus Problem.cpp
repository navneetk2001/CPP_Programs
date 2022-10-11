https://practice.geeksforgeeks.org/problems/josephus-problem/1



//Solution Approach :-  Recursion
class Solution{
public:
    int f(int n, int k){
        if(n==1){
            return 0;
        }
        int ans = f(n-1, k);
        ans = (ans + k) % n;
        return ans;
    }

    int josephus(int n, int k)
    {
        int ans = f(n, k);
        return 1 + ans;    //1-based indexing
    }
};



//Second Solution :- 
class Solution{
public:
    int josephus(int n, int k)
    {
        int prev =1;
        for(int i = 1;i<=n;i++){
            prev = (prev + k -1) % i + 1;
        }
        return prev;
    }
};



//Third Solution :- Brute Force
int josephus(int n, int k){
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    while(q.size()>1){
        for(int i=0;i<k-1;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}



//Fourth Solution :- DP
int josephus(int n, int k)
{
    vector <int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] + k - 1) % i + 1;
    }
    return dp[n];
}