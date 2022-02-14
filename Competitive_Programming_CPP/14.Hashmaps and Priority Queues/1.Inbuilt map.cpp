#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif

	unordered_map<string,int> ourmap;


// To Insert elements in the map....
	pair<string,int> p("abc",1);           //First Method for insertion...
	ourmap.insert(p);

	ourmap["def"]=2;                       //Second Method for insertion...


// To find or Access elements in the map....
	cout<<ourmap["abc"]<<endl;
	cout<<ourmap.at("def")<<endl;

	cout<<ourmap["ghi"]<<endl;       //If not found, then Square bracket will insert the element at default value "Zero"
	cout<<ourmap.at("ghi")<<endl;    //If not found, then at function will gives error.


// To check if element present in the map....
	if(ourmap.count("ghi")>0)
	{
		cout<<"ghi"<<" is present."<<endl;
	}


// To check the size  in the map....
	cout<<"Size: "<<ourmap.size()<<endl;


// To erase the element present in the map....
	ourmap.erase("ghi");

	cout<<"Size: "<<ourmap.size()<<endl;
	if(ourmap.count("ghi")>0)
	{
		cout<<"ghi"<<" is present."<<endl;
	}

}