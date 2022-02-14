#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

vector<int> pairSum(vector<int> arr, int sum)
{
	vector<int> result;
	unordered_set<int> s;

	for(int i=0;i<arr.size();i++)
	{
		int x=sum-arr[i];
		if(s.find(x)!=s.end())
		{
			result.push_back(x);
			result.push_back(arr[i]);
			return result;
		}
		s.insert(arr[i]);
	}
	return {};
}

int main()
{
	vector<int> arr{10,5,2,3,-6,9,11};
	int sum=4;

	auto p=pairSum(arr,sum);
	if(p.size()==0)
		cout<<"No Such Pair"<<endl;
	else
		cout<<p[0]<<" "<<p[1]<<endl;

	return 0;
}