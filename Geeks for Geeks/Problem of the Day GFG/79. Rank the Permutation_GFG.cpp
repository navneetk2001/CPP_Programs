Given a string, find the rank of the string amongst its permutations sorted lexicographically. 

Example 1:
Input:
S = "abc"
Output: 1
Explanation: The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
Example 2:

Input:
S = "acb"
Output: 2



//Solution :-
//Approach :- Like ranking the word in dictionary similar problem

//1.just check for each character how many characters to right are smaller 
//2.position(from right) factorial and multiply the count from above step with factorial and //these both +1 u will get ans 

long long findRank(string str) {
   int n=str.size();
   long long int fac[n+1]={0};
   fac[0]=1;
   for(int i=1;i<=n;i++){
       fac[i]=i*fac[i-1];
   }

   long long int ans=0;
   for(int i=0;i<n-1;i++){
       int count=0;          //to store no of elements less than current character
       for(int j=i+1;j<n;j++){
           if(str[i]>str[j])    //check if curr char is less than how many characters
           count++;
       }
      ans+=count*fac[n-i-1];   //stores ans as (no of char less than curr char * no of permutation possible for remaining places)
   }
   
   return ans+1;      // we have done +1 in ans for last word itself
}




//Second Solution :-
long long fac(int n){
    return (n <= 1) ? 1 : n * fac(n - 1);
}

long long countSmallRight(string s, int l, int h){
    long long cnt= 0;
    for(long long i=l+1; i<=h; i++){
    	cnt += s[i]<s[l] ? 1 : 0;
    }

    return cnt;
}

long long findRank(string str) {
    long long len = str.length();
    long long fact = fac(len);
    long long rank= 1;
    for(long long i=0; i<len; i++){
        fact /= len-i;
        long long cr = countSmallRight(str, i, len-1);
        rank += cr*fact;
    }
    return rank;
}
