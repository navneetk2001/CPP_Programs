// You are given an array A consisting of strings made up of the letters 'a' and 'b' only.
// Each string goes through a number of operations, where:
// 1.  At time 1, you circularly rotate each string by 1 letter.
// 2.  At time 2, you circularly rotate the new rotated strings by 2 letters.
// 3.  At time 3, you circularly rotate the new rotated strings by 3 letters.
// 4.  At time i, you circularly rotate the new rotated strings by i % length(string) letters.

// Eg: String is "abaa"
//  At time 1, string is "baaa", as 1 letter is circularly rotated to the back
//  At time 2, string is "aaba", as 2 letters of the string "baaa" is circularly rotated to the back
//  At time 3, string is "aaab", as 3 letters of the string "aaba" is circularly rotated to the back
//  At time 4, string is again "aaab", as 4 letters of the string "aaab" is circularly rotated to the back
//  At time 5, string is "aaba", as 1 letters of the string "aaab" is circularly rotated to the back
// After some units of time, a string becomes equal to its original self.
// Once a string becomes equal to itself, it's letters start to rotate from the first letter again (process resets). So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will be its original self at 2t time.
// You have to find the minimum time, where maximum number of strings are equal to their original self.
// As this time can be very large, give the answer modulo 109+7.

// Note: Your solution will run on multiple test cases so do clear global variables after using them.

// Input 1:  A: [a, ababa, aba]
// Output 1:  4
// Explanation 1:  String 'a' is it's original self at time 1, 2, 3 and 4.
// String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
// String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)
// Hence, 3 strings are their original self at time 4.

// Input 2:  A : [a, aa]
// Output 2:  1
// Explanation 2:  Both strings are their original self at time 1.

//Hint 1
// The number of bits being rotated for each string goes in the series 1,1+2,1+2+3,1+2+3+4 etc. So for the ith operation, (i*(i+1))/2 bits are rotated.
// Find the smallest i for which you get the same string.

//Hint 4
// Strings with same lengths may have different answers depending on the string.
// String 1010 takes 3 operations, while string 1001 takes 7 operations.

//Solution Approach
// With respect to a single string, the total number of bits rotated after N operations is 1+2+3+….+N which is (N*(N+1))/2.
// We get back the original string only when the total number of rotated bits is a multiple of the length of the string S(LEN).
// This can be done in O(N) time for each string (Summation of length of all strings is <= 1e6), by finding all (N(N+1))/2 where N starts from 1 and goes upto (2LEN-1).
// But there is a catch, this wont always give you the minimum number of operations.
// Its possible that during rotation, you can get the original string before the number of bits rotated is a multiple of LEN.
// Example: S=> 100100
// Here, in 2 operations, we get the original string back.
// This takes place because the string is made up of recurring substrings.
// Assume string A to be 100
// S => AA
// Hence, over here our length S of string is the length of recurring substring A, so N*(N+1)/2 should be a multiple of length of A.
// Length of recurring substring can easily be found out using KMP algorithm in O(N) time complexity for each string.
// Find the minimum number of operations for each string, and take the LCM of all these values to get the answer.
// Handling of overflow for LCM should be handled by breaking the number down into factors, and then taking LCM (Not needed for languages that don’t have integer limit).
// Hence total time complexity is O(N).


// First Method :-
#define mod 1000000007
int Solution::solve(vector<string> &A) {
    int l = 1,len=A.size(),h;

    vector<int>v(len);       //  for saving time interval t for each string
    for(int k=0;k<len;k++){ 
        int n = A[k].length(); 
        if(n<=1){ 
            v[k] = 1;
        }
        else{
            long long i=1,j=1,changes=0;
            string s = A[k];
            while(1){
                changes = (i*(i+1))/2; 
            if(changes%n==0){
                v[k]=i;
                break;
            }
                i++;
            }
        } 
    }

    long long ans=1;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len && v[i]!=1 ;j++){            
            v[j] = v[j]/__gcd(v[j],v[i]);
        }
        ans = 1ll*(ans%mod*(v[i])%mod)%mod;
    }
    return ans%mod;
}




//Second Method :-
const int mod=1e9+7;
void fact(int n , map<int,int> &m){
    int i=2,j=n;
    while(i*i<=n){
        if(n%i==0){
          int pw=0;
          while(n%i==0){
            pw++,n/=i;
          }
          m[i]=max(m[i],pw);
        }
        i++;
    }
    if(n>1){
        m[n]=max(m[n],1);
    }
}
int kmp(string &s){
    int n=s.size();
    vector<int> lps(n);
    for(int i=1;i<n;++i){
        int j=lps[i-1];
        while(j>0 and s[i]!=s[j]){
            j=lps[j-1];
        }
        if(s[i]==s[j]) j++;
        lps[i]=j;
    }
    int t=n-lps.back();
    if(n%t);
    else
        n=t;
    long long j=0;
    for(long long i=1;;++i){
         j+=i;
        if(j%n==0) return i;
    }
}
int Solution::solve(vector<string> &A) {
    map<int,int> mp;
    for(auto &it:A){
        fact(kmp(it),mp);
    }
    long long res=1;
    for(auto &it:mp){
        while(it.second--){
            res=(res*it.first)%mod;
        }
    }
    return res;
    
}


//Third Method :-
int Solution::solve(vector<string> &A) {
    int n=A.size();
    long long int arr[n];  //to store the time
    for(int i=0;i<A.size();i++)  //Finding time for each string when it becomes same as original 
    {
        long long int val=1;
        long long int sum=1;
        int len=A[i].length();
        while(sum%len!=0)    // string starts to repeat at the time 't' when (1+2+....+t)%length==0 you can easily observe this through multiple examples
        {
            val++;
            sum+=val;
        }
        arr[i]=val;
    }
    long long int ans=1;
    long long int M=1000000007;
    for(int i=0;i<n;i++)   // Calculating LCM
    {
        for(int j=i+1;j<n;j++)
        {
            arr[j]=arr[j]/__gcd(arr[i],arr[j]);
        }
        ans=((ans%M)*(arr[i]%M))%M;
    }
    return (ans)%M;
}









string leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());

    return s;
}

int Solution::solve(vector<string> &A) {
    int n=A.size();
    int count=0;
    int ans=0;

    for(int i=0;i<n;i++){
        string temp=A[i];
        int j=1;
        int k=2;
        while(count>=0){
            int m=A[i].size();
            string t=leftrotate(temp,j%m);
            count++;
            if(t==A[i]){
                ans=max(ans,count);
                break;
            }
            j=k*(k+1)/2;
            k++;
        }
        count=0;
    }
    return ans%1000000007;
}