// Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.
// Note: 
// 1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
// 2.  For large test cases, the output value will be too large, return the answer MODULO 10^9+7

// Example 1:
// Input:
// S = "abbc"
// Output: 3
// Explanation: Subsequences are abc, abc and abbc.

// Example 2:
// Input:
// S = "abcabc"
// Output: 7
// Explanation: Subsequences are abc, abc,
// abbc, aabc abcc, abc and abc.




//Solution Approach :-
// here 2*a means one time we append current ‘a’ in prev subsequence and one time we do not do it . It is similar for ab and abc . 
// And  here we are adding 1 (in case of a) and a(in case of ab) and ab(in case of abc) because the individual a can start a subsequence or (in ab) without using previous ‘b’ current 'b' can contribute to whole new subsequece similarly for abc.
// But as per constraint we can add ‘b’ after a or b only and we can add ‘c’ after ab or abc only.

class Solution{
public:
    int fun(string &s){
        int n=s.size();
        long long mod=1e9+7, a=0,ab=0,abc=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a=(2*a + 1)%mod;
            }
            else if(s[i]=='b'){
                ab=(2*ab + a)%mod;
            }
            else{
                abc= (2*abc + ab)%mod;
            }
        }
        return abc;
    }
};



