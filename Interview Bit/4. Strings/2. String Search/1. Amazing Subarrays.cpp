// You are given a string S, and you have to find all the amazing substrings of S.
// Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).
// Input
//     ABEC
// Output
//     6
// Explanation
// 	Amazing substrings of given string are :
// 	1. A
// 	2. AB
// 	3. ABE
// 	4. ABEC
// 	5. E
// 	6. EC
// 	here number of substrings are 6 and 6 % 10003 = 6.


//Hint 1
Brute Force Approach is to find all the substrings and count the substrings those start with a vowel.
This approach will result in the timeout as the time complexity of the same is O(n^2).
Is there any need of finding all the substrings?
Try to find a pattern.


//Solution Approach
The main idea to solve this problem is to traverse the string and when you encounter a vowel, add ( length(string) - position_of_curr_char ) to the answer.




// First Method :-
#define mod 10003
bool isVowel(char x){
    if (x == 'a' || x == 'e' || x == 'i' ||
        x == 'o' || x == 'u' || x == 'A' ||
        x == 'E' || x == 'I' || x == 'O' || x == 'U')
        return true;
    else
        return false;
}

int Solution::solve(string A) {
    int count=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(isVowel(A[i])){
            count+=n-i;
        }
    }
    return count%mod;
}




//Second Method :-
int Solution::solve(string A) {
    int n= A.size();
    transform(A.begin(),A.end(),A.begin(),::tolower);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u')
        {
            count=(count+(n-i))%10003;
        }
    }
    return count;
}



