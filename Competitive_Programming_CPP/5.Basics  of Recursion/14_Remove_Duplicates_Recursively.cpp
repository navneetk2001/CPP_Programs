/*
@csalgo

Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

@csalgo

*/


#include<iostream>
using namespace std;

void Remove_Duplicates(char str[])
{
	if (str[0]=='\0')
	{
		return ;
	}
    if (str[0]!=str[1])
	{
        Remove_Duplicates(str+1);  
    }
    else{
    	int i=1;
    	for( ;str[i]!='\0';i++)
    	{
    		str[i-1]=str[i];
    	}
    	str[i-1]=str[i];
    	Remove_Duplicates(str);
    }
}

int main()
{
	char str[100];
	cin>>str;

	Remove_Duplicates(str);
	cout<<str;
} 