#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

bool compare(string x, string y){
    return x + y < y + x;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    sort(numbers.begin(),numbers.end(),compare);

}

int main()
{
	vector<int> numbers{10,11,20,30,3};

	return 0;
}