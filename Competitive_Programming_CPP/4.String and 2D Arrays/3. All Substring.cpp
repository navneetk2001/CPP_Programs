/*
Coding Problem
Problem Name: All substrings
Problem Level: MEDIUM
Problem Description: #### Given a String S of length n, print all its substrings. 
#### Substring of a String S is a part of S (of any length from 1 to n), which contains all consecutive characters from S. 


##### Input Format : 
    String S

##### Output Format :
     All Substrings of S, one in each line.

##### Constraints :
    0 <= |S| <= 10^2
    where |S| represents the length of string, S.

##### Note : The order in which you print substrings doesn't matter.
 #### Sample Input 1 :
    xyz
#### Sample Output 1 :
    x
    xy
    xyz
    y
    yz
    z

#### Sample Input 2 :
    ab
#### Sample Output 2 :
    a
    b
    ab



*/



#include <iostream>  
#include <string.h>  
using namespace std;  


//User-defined substring function that will take string(str), position(p) and no of character(len) as input  
//Produces result c as output  
void substring(char s[], char sub[], int p, int len){  
   int c = 0;  
   while (c < len) {  
      sub[c] = s[p+c];  
      c++;  
   }  
   sub[c] = '\0';  
}  
   
int main()  
{  
    char c[20];
    char str[10];
    cin>>str;

    int i, j, len = strlen(str);  
      
    cout<<"All subsets for the given string are: ";  
   

    for(i = 0; i < len; i++){                   //This loop maintains the starting character 
        for(j = 1; j <= len-i; j++){           //This loop adds the next character every iteration for the subset to form and add it to the array
            substring(str,c,i,j);  
            cout<<"\n"<<c; 
        }  
    }  
    return 0;  
}  




#include<bits/stdc++.h>
using namespace std;

void subString(string s, int n)
{
 
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
            cout << s.substr(i, len) << endl;
}
 
 
int main()
{
    string s = "abcd";
    subString(s,s.length());
    return 0;
}

