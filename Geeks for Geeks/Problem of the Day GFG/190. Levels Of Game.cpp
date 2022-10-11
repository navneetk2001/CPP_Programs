// You are playing a game. At each level of the game, you have to choose one of the roads to go to the next level. Initially, you have h amount of health and m amount of money.
// If you take the first road then your health increases by 3 and money increase by 2. If you take the second road then your health decreases by 5 and money decrease by 10. If you take the third road then health decreases by 20 and money increase by 5.
// You have to tell what is the maximum level you can reach up to under the constraints that in no two consecutive levels you can select the same road twice and once your health or money becomes <= 0 game ends(that level is not counted).

// Example 1:
// Input:
// H=2
// M=10
// Output: 1
// Explanation: For the first level, we can only choose the first road. Now we cannot move ahead anymore.

// Example 2:
// Input:
// H=20
// M=8
// Output: 5
// Explanation: Go like this:- R1(23,10)->R3(3,15)->R1(6,17)->R2(1,7)->R1(4,9)-> game ends as we cannot choose any more roads.




//Recursion Solution :-
class Solution{
public:	
    int solve(int h, int m){
        if(h<=0 || m<=0){
        	return 0;
        }
        
        int first_sec = solve(h-2, m-8) + 2;     //first and second combine
        int first_third = solve(h-17, m+7) + 2;  //first and third combine

        return max(first_sec, first_third);
    }
    
    int maxLevel(int h, int m){
        int ans = solve(h, m);
        return ans - 1;
    }
};
//Now, we can change it in memoization



//Solution Appproach :-
class Solution{
public:	
    int solve(int h, int m, bool flag,vector<vector<int>>&dp){
        if(h<=0 || m<=0){
        	return 0;
        }
        
        if(dp[h][m] != -1){
        	return dp[h][m];
        }
       
        return dp[h][m] = 1 + (flag ? solve(h+3,m+2,false,dp) : max(solve(h-5,m-10,true,dp), solve(h-20,m+5,true,dp)));
    }
    
    int maxLevel(int h, int m){
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        int ans = solve(h, m, true, dp);
        return ans - 1;
    }
};




//Second Solution :-
class Solution{
public:
    int maxLevel(int h,int m)
    {
        int i=0,j=0;
        while(h>0 && m>0){
            if(i%2==0 && j!=1){
                h = h+3; 
                m = m+2;
                j=1;
            }
            else{
                if(h>5 && m>10 && j!=2){
                    h = h-5;
                    m = m-10;
                    j=2;
                }
                else if(h>20 && j!=3){
                    h = h-20;
                    m = m+5;
                    j=3;
                }
                else{
                    break;
                }
            }
            i++;
        }
        return i;
    }
};



//Third Solution :-
int solve(int h, int m, int path, vector<vector<int>> &dp){
    if(m<=0 || h<=0){
    	return -1;
    }
    // cout<<path<<endl;
    
    if(dp[h][m]!=-1){
    	return dp[h][m];
    }
    
    int a=0, b=0, c=0;
    if(path!=1){
        a = 1 + solve(h+3, m+2, 1, dp);
    }
    if(path!=2){
        b = 1 + solve(h-5, m-10, 2, dp);
    }
    if(path != 3){
        c = 1 + solve(h-20, m+5, 3, dp);
    }

    return dp[h][m] = max(a, max(b, c));
}

int maxLevel(int h,int m){
    int n = 2000;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(h, m, 0, dp);
}




//Fourth Solution :-
class Solution{
public:
   const int N=2008;
   int helper(int h, int m, int path,  vector<vector<int>> &dp){
       	if(h<=0 || m<=0){
           	return 0;
       	}
       
       	if(dp[h][m] != -1)return dp[h][m];
       
       	if(path == 0){
           	int w1=helper(h+3, m+2, 1, dp);
           	int w2=helper(h-5, m-10, 2, dp);
           	int w3=helper(h-20, m+5, 3, dp);
           
           	return dp[h][m] = 1+max({w1, w2, w3});
       	}
       	if(path == 1){
           	int w1=helper(h-5, m-10, 2, dp);
           	int w2=helper(h-20, m+5, 3, dp);
           
           	return dp[h][m] = 1+max(w1, w2);
       	}
       	if(path == 2){
           	int w1=helper(h+3, m+2, 1, dp);
           	int w2=helper(h-20, m+5, 3, dp);
           	
           	return dp[h][m] = 1+max(w1, w2);
       	}
       	if(path == 3){
           	int w1=helper(h+3, m+2, 1, dp);
           	int w2=helper(h-5, m-10, 2, dp);
           	
           	return dp[h][m] = 1+max(w1, w2);
       	}
   	}
   
	int maxLevel(int h,int m){
	   	vector<vector<int>> dp(N, vector<int>(N, -1));
	   	int ans=helper(h, m, 0, dp);
	   
	   	return ans-1;
	}
};



//Fifth Solution :-
class Solution{
public:
    vector<vector<int>> v{
        {3,2},
        {-5,-10},
        {-20,5}
        
    };
    
    int maxLevel(int h,int m)
    {
        vector<vector<int>> dp(2001,vector<int> (2001,-1));
        return func(h,m,-1,dp);
    }

    int func(int h,int m,int f,vector<vector<int>> &dp){
        if(h<=0 || m<=0) return -1;
        
        if(dp[h][m]!=-1) return dp[h][m];
        int mx = INT_MIN;
         
        for(int i=0;i<3;i++){
            if(i!=f)
            mx = max(mx,1+func(h+v[i][0],m+v[i][1],i,dp));
        }
        return dp[h][m] = mx;
    }
};



//Sixth Solution :-
class Solution{
public:
    int maxLevel(int h,int m)
    {
        int result=0;
        while(h>0 && m>0)
        {
            h = h + 3;
            m = m + 2;
            result++;
            if(m > 10){
                h = h - 5;
                m = m - 10;
            }
            else{
                h = h - 20;
                m = m + 5;
            }
            if(h>0 && m>0){
                result++;
            }
        }
        return result;
    }
};