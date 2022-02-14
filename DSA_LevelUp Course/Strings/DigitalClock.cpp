#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    if(minutes < 0 or minutes > 1440){
        return "";
    }

    string ans="";
    
    
}

int main()
{
	int minutes;
    cin>>minutes;

    string ans=convert_to_digital_time(minutes);

	return 0;
}