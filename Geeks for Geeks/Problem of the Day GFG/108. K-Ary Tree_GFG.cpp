// Find the number of leaf nodes in a full k-ary tree of height m.
// Note: You have to return the answer module 109+7.

// Example 1:
// Input: k = 2, m = 2
// Output: 4
// Explanation: A full Binary tree of height 2 has 4 leaf nodes. 

// Example 2:
// Input: k = 2, m = 1
// Output: 2
// Explanation: A full Binary tree of height 1 has 2 leaf nodes.



//Solution Approach :-
class Solution {
public:
    static long pow(long k,long m){
        long mod = 1000000007L;
        long ans = 1L;
        while(m>0){
            if(m%2!=0){
                ans = (ans%mod)*(k%mod);
            }
            m=m>>1;
            k = (k%mod)*(k%mod);
        }
        return ans%mod;
    }
    
    static long karyTree(int k, int m) {
        return pow(k,m);
    }
};


//Second Solution :- 
long long int m=1e9+7;

long long karyTree(int k, int h) {
    if(h==1) return k;
    long long int res = karyTree(k,h/2);
   
    if(h%2==0){
        return (res%m*res%m)%m;
    }
    else{
        long long int x = (res%m*res%m)%m;
        return (x%m*k%m)%m;
    }
}

//Third Solution :-
class Solution {
    static Long karyTree(int k, int m) {
        long ans=1L;
        while(m>0){
            ans=ans*k;
            ans=ans%1000000007L;
            m--;
        }
        return ans;
    }
};