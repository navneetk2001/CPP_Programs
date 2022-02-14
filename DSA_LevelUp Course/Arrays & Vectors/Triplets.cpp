#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int sum)
{
	int n=arr.size();
	vector<vector<int>> result;

	//Logic
	sort(arr.begin(),arr.end());

    //Pick every a[i], pair sum for remaining part
	for(int i=0; i<n-3; i++)
	{
		int j=i+1;
		int k=n-1;

        // Two Pointers Approach
		while(j<k)
		{
			int current_sum=arr[i];
			current_sum+=arr[j];
			current_sum+=arr[k];

			if(current_sum==sum)
			{
				result.push_back({arr[i],arr[j],arr[k]});
				j++;
				k--;
			}
			else if(current_sum < sum)
			{
				j++;
			}
			else
			{
				k--;
			}
		}
	}
	return result;
}

int main()
{
	vector<int> arr{1,2,3,4,5,6,7,8,9,15};
	int S=18;

	auto result=triplets(arr,S);

    //Print the result
	for(auto v: result)
	{
		for(auto no:v)
		{
			cout<<no<<",";
		}
		cout<<endl;
	}
}