// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
// If the last word does not exist, return 0.
// Note: A word is defined as a character sequence consists of non-space characters only.
// Example:
// Given s = "Hello World",
// return 5 as length("World") = 5.
// Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.


//Solution Approach
// As said before, this problem does not allow using library functions.
// What if you maintained the length of the current word?
// You reset the length of the word when the next word begins (When does a new word begin?)
// Return the last length you have.


// First Method :-
int Solution::lengthOfLastWord(const string A) {
    if(A.size()==0){
        return 0;
    }
    
    int i= A.length()-1,count=0;
    while(A[i]==' ') {
        i--;           //to get first white space
    }
    for(;i>=0 && A[i]!=' ';i--) {
        count++;
    }

    return count;
}


//Second Method :-
int Solution::lengthOfLastWord(const string A) {
    int cnt=0;
    int i=A.size()-1;

    while(A[i]==' ' && i>=0){
        i--;
    }

    while(i>=0 && A[i]!=' '){
        cnt++;
        i--;
    }
    return cnt;
}



//Third Method :-
int Solution::lengthOfLastWord(const string s) {
    string word;
    stringstream ss(s);
    int ans=0;
    while(ss>>word){
        ans=word.length();
    }
    return ans;
    
}


