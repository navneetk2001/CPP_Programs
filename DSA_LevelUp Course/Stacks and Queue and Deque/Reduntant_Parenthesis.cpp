#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool checkRedundant(string str){
	 stack<char>s;

	 for(char ch : str){
	 	if(ch!=')'){
	 		s.push(ch);
	 	}
	 	else{
	 		bool operator_found  = false;
	 		while(!s.empty() and s.top()!='('){
	 			char top=s.top();
	 			if(top == '+' or top == '-' or top == '*' or top == '/'){
	 				operator_found=true;
	 			}
	 			s.pop();
	 		}
	 		s.pop(); //pop the opening bracket after the loop is over

	 		if(operator_found == false){
	 			return true;
	 		}
	 	}
	}
    return false;
}


int main()
{
	string str = "((a+b)+c)";

    if(checkRedundant(str)){
    	cout<<"Contains Redundant Parenthesis"<<endl;
    }
    else{
    	cout<<"Doesn't contain Redundant Parenthesis"<<endl;
    }

	return 0;
}