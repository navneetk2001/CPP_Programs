/*
Coding Problem
Problem Name: String Palindrome
Problem Level: EASY
Problem Description: #### Given a String s, check it its palindrome. Return true if string is palindrome, else return false.
#### Palindrome strings are those, where string s and its reverse is exactly same.


##### Input Format : 
     String S
##### Output Format : 
    "true" if S is palindrome, else "false"
##### Constraints :
    0 <= |S| <= 10^7
    where |S| represents the length of string, S.
 ##### Sample Input 1 :
    abcdcba
##### Sample Output 1 :
    true 

##### Sample Input 1 :
    abcd
##### Sample Output 1 :
    false



*/




// Iterative function to check if the given string is a palindrome or not

#include <iostream>
using namespace std;
 

bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;
 
    while (low < high)
    {
        if (str[low] != str[high]) {
            return false;
        }
 
        low++;
        high--;
    }
 
    return true;
}
 
int main()
{
    char str[50];
    cin>>str;
 
    if (isPalindrome(str)) {
        cout << "Palindrome";
    }
    else {
        cout << "Not Palindrome";
    }
 
    return 0;
}




/*
// Another Iterative function to check if the given string is a palindrome or not.


#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    char string1[20];
    
    int i, length;
    int flag = 0;
    
    cout << "Enter a string: "; 
    cin >> string1;
    
    length = strlen(string1);
    
    for(i=0;i < length ;i++){
        if(string1[i] != string1[length-i-1]){
            flag = 1;
            break;
   }
}
    
    if (flag) {
        cout << string1 << " is not a palindrome" << endl; 
    }    
    else {
        cout << string1 << " is a palindrome" << endl; 
    }
 
    return 0;
}


*/


/*
// Recursive function to check if `str[low…high]` is a palindrome or not

#include <iostream>
#include<cstring>
using namespace std;
 
bool isPalindrome(string str, int low, int high)
{
    // base case
    if (low >= high) {
        return true;
    }
 
    // return false if mismatch happens
    if (str[low] != str[high]) {
        return false;
    }
 
    // move to the next pair
    return isPalindrome(str, low + 1, high - 1);
}
 
int main()
{
	char str[50];

    cout << "Enter a string: "; 
    cin >> str;
    
    int len = strlen(str);
 
    if (isPalindrome(str, 0, len - 1)) {
        cout << "Palindrome";
    }
    else {
        cout << "Not Palindrome";
    }
 
    return 0;
}


*/