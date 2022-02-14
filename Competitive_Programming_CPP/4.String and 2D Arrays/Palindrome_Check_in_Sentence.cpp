/*

#include<bits/stdc++.h>
#include <string.h> 
using namespace std;


void isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;
 
    while (low < high)
    {
        if (str[low] != str[high]) {
            cout<<"->  Not Palindrome "<<endl;;
        }
 
        low++;
        high--;
    }
 
    cout<<"->  Palindrome "<<endl;
}


void check_Palindrome(string str)
{
	string word;
 
    stringstream iss(str);

    while (iss >> word)
    {
        cout << word << " ";
        isPalindrome(word);
    }
}



int main()
{
	char str[100];
	cout << "Enter a string : ";
    cin.getline(str, 99);

    check_Palindrome(str); 

}

*/



/*
#include<iostream>
using namespace std;
int main()
{
    string str;
    int l;
    
    cout<<"enter a sentence"<<endl;
    getline(cin, str);
    string n=str+" ";
    l=n.length();
    string p="",q="";
    for (int i=0;i<l;i++)
    {
        char ch=n.at(i);
        if (ch!=' ')
        {
            p=p+ch;
            q=ch+q;
        }
        else
        {
            if(p==q)
            cout<<p<<" is palindrome"<<endl;
            p="";
            q="";
        }
    }
}

*/



#include<iostream>
using namespace std;
int main()
{
    string str;
    int l;
    
    cout<<"enter a sentence"<<endl;
    getline(cin, str);
    string n=str+" ";
    l=n.length();
    string p="",q="";
    for (int i=0;i<l;i++)
    {
        char ch=n.at(i);
        if (ch!=' ')
        {
            p=p+ch;
            q=ch+q;
        }
        else
        {
            if(p==q)
            {
            cout<<p<<" is palindrome"<<endl;
            }
            else{
                cout<<p<<" is not palindrome"<<endl;
            }
            p="";
            q="";
        }
    }
}













//Java code for palindrome check

 import java.util.*;
    class stackOverflow {
        public static void main(String[] args){     
            Scanner input=new Scanner(System.in);  
            String s1=input.nextLine();   
            String arr[]=s1.split("\\s",s1.length());   

            for(int i=0;i<arr.length;i++){

              String s2="";
              for(int j=arr[i].length()-1;j>=0;j--){
              s2=s2.concat(Character.toString(arr[i].charAt(j)));
              //System.out.println(arr[i].charAt(j));
              }
              //System.out.print(" ");
              if(arr[i].equals(s2)){
                  //palindrome[i]=s2; // you are inserting the s2 value into the first element of the array, 
                  //so the rest of the positions remains empty/null that's not a problem to solve palindrome

                System.out.println("Is a palindrome");
              }
              else 
                 System.out.println("Not a palindrome");
            }

        }
    }










/*C++ program to count number of palindrome words in a sentence*/
#include <bits/stdc++.h>
using namespace std;
  
// Function to check if a word is 
// palindrome 
bool checkPalin(string word) 
{ 
    int n = word.length(); 
    transform(word.begin(), word.end(), word.begin(), ::tolower);
  
    for (int i = 0; i < n; i++,n--) 
    if (word.at(i) != word.at(n - 1)) 
        return false;     
    return true; 
} 
  
// Function to count palindrome words 
int countPalin(string str) 
{         
    // to check last word for palindrome 
    str = str + " "; 
      
    // to store each word 
    string word = ""; 
    int count = 0; 
    for (int i = 0; i < str.length(); i++) 
    { 
        char ch = str.at(i); 
          
        // extracting each word 
        if (ch != ' ') 
            word = word + ch; 
        else { 
            if (checkPalin(word)) 
                count++; 
            word = ""; 
        } 
    } 
      
    return count; 
} 
      
// Driver code 
int main() 
{ 
      
    cout<<countPalin("Madam Arora teaches malayalam")<<endl; 
                  
    cout<<countPalin("Nitin speaks malayalam")<<endl; 
} 