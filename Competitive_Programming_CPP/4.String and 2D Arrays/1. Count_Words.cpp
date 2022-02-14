/*
Coding Problem
Problem Name: Count Words
Problem Level: EASY
Problem Description: #### Given a string S, count number of words in the string.
##### Note : Assume there is single space between two words and there are no extra spaces before and after words.
<br>

##### Input Format :
     String S
##### Output Format :
    Count of words
##### Constraints :
    0 <= |S| <= 10^7
    where |S| represents the length of string, S.


 ##### Sample Input 1:
    this is a sample string

##### Sample Output 1:
    5

##### Sample Input 2:
    coding is awesome

##### Sample Output 2:
    3



*/


#include<iostream>
#include<string>
using namespace std;

int main ()
{
    char str[50];
    
    int count = 0, i; 
    
    cout << "Enter a string : ";
    cin.getline(str, 49);

    for (i = 0; str[i] != '\0';i++)
    
    {
        if (str[i] == ' ')
            count++;    
    }

    cout << "Number of words in the string are: " << count + 1;
    return 0;
}