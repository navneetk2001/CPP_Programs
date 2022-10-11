// You are given an equation of the form x1+x2+...+xN=K. You need to find the total number of positive integral solutions of this equation.
 
// Example 1:
// Input: s = a+b=5
// Output: 4
// Explanation: (4,1) , (1,4) , (2,3) , (3,2)

// Example 2:
// Input: s = a+b=1
// Output: 0
// Explanation: No solution exist.



//Solution Approach :-
class Solution{
public:
    long long int solve(int n, int r)    //this is to calculate ncr 
    {
        if(n==r){
            return 1;
        }
        if(n<r){
            return 0;
        }
        
        long long int num=1,den=1;
        for(int i=n-r+1;i<=n;i++){
            num=num*i;
        }
        for(int i=1;i<=r;i++){
            den=den*i;
        }
        return num/den;
    }
    
    long posIntSol(string s){
        int n=s.size();
        int count=0,k=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='+'){   //finding total no.of '+' characters
                count++;
            }
            if(s[i]=='='){
            	k=stoll(s.substr(i+1));
            }
        }
    
        long long int ans=0;
        ans=solve(k-1,count);
        return ans;
    }
};




