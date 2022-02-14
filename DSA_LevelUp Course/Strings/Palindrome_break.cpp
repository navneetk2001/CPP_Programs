#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

string breakPalindrome(string palindrome) {
        
}

int main()
{
	string s;
	cin>>s;

	vector<string> v;
	string output="";

    subsequence(s,output,v);

    sort(v.begin(),v.end(),compare);

    for(auto s : v){
    	cout<<s<<" ,";
    }

	return 0;
}