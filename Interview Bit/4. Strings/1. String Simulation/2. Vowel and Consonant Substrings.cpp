// Given a string A consisting of lowercase characters.
// You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.
// Return the count of substring modulo 109 + 7.

// Input 1: A = "aba"
// Output 1: 2
// Explanation 1: Substrings of S are : [a, ab, aba, b, ba, a] Out of these only 'ab' and 'ba' satisfy the condition for special Substring. So the answer is 2.

// Input 2: A = "a"
// Output 2: 0
// Explanation 2: No possible substring that start with vowel and end with consonant or vice-versa.


//Hint 1
// Think of maintaining count of vowels and consonants in every suffix of string and using this try to find the count.
// Try to do this in linear time.

//Solution Approach
// Method-1
// An efficient solution is to count vowels and consonants in every suffix of string.
// After counting these, we traverse string from beginning.
// For every consonant, we add number of vowels after it to result. Similarly, for every vowel, we add number of consonants after it.
// Time Complexity:O(|A|)
// Space Complexity:O(|A|)

// Method-2
// Just loop from 1 to	A	and maintain two variables named “vow” and “con” denoting the number of vow and con seen so far.
// If the current character is vowel then do:
// vow += 1
// numberofSubstring += con //denoting the number of substring start with consonants and ending with this vowel.
// Do similarly for consonants
// Time Complexity:O(|A|)
// Space Complexity:O(1)


// First Method :-
#define mod 1000000007
int Solution::solve(string A) {
    int n=A.length();
    if(n==0 or n==1){
        return 0;
    }
    int count=0;
    vector<int> vowel(n,0);
    vector<int> cons(n,0);
    for(int i=n-2;i>=0;i--){
        if(A[i+1]=='a' or A[i+1]=='e' or A[i+1]=='i' or A[i+1]=='o' or A[i+1]=='u'){
            vowel[i]+=1;
        }
        else{
            cons[i]+=1;
        }
    }

    for(int i=n-2;i>=0;i--){
        vowel[i]+=vowel[i+1];
        cons[i]+=cons[i+1];
    }
  
    for(int i=0;i<n-1;i++){
        if(A[i]=='a' or A[i]=='e' or A[i]=='i' or A[i]=='o' or A[i]=='u'){
            count+=cons[i];
        }
        else{
            count+=vowel[i];
        }
    }
    return count%mod;
}



//Second Method :-
// Consonants = number of consonants in the string
// Vowels = number of vowels in the string
// return answer = Consonants * Vowels
// And yeah…don’t ever forget to use long long data type instead of int when mod is given!

int mod = 1e9+7;
int Solution::solve(string A) {
    long long int consonants = 0, vowels = 0;
    for(long long int i = 0; i<A.length(); i++){
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u'){
            vowels = (vowels+1)%mod;
        }
        else{
            consonants = (consonants+1)%mod;
        }
    }
    long long int ans = (consonants*vowels)%mod;
    return (int)ans;
}

//Third Method :-
int Solution::solve(string A) {
    long long v=0;
    long long c=0;
    long long ans=0;
    long long mode=1000000007;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u')
        {
            v++;
            ans= (ans+c)%mode;
        }
        else
        {
            c++;
            ans=(ans+v)%mode;
        }
    }
    return (int)ans;
}


