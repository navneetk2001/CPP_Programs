#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;

int main()
{
	string input;
	getline(cin,input);

	//create a string stream object

	stringstream ss(input);

	// supports ">>" and "<<" operators
	string token;
	vector<string> tokens;

	while(getline(ss,token,' '))
	{
		tokens.push_back(token);
	}

	for(auto token : tokens)
	{
		cout<<token<<endl;
	}

	return 0;
}