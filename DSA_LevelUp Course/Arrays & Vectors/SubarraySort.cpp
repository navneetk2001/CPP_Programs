#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool outOfOrder(vector<int> arr, int i)
{
	int x=arr[i];
	if(i==0)
	{
		return x > arr[1];
	}
	if(i==arr.size()-1)
	{
		return x < arr[i-1];
	}
	return x > arr[i+1] or x < arr[i-1]; 
}

pair<int,int> SubarraySort(vector<int> arr)
{
	int smallest=INT_MAX;
	int largest=INT_MIN;
	
	for(int i=0;i<arr.size();i++)
	{
		int x=arr[i];
		if(outOfOrder(arr,i)){
			smallest=min(smallest,x);
			largest=max(largest,x);
		}
	}

	// next step find the right Index where smallest and largest lie (subarray) for our solution
	if(smallest==INT_MAX)
	{
		return {-1,-1};
	}

	int left=0;
	while(smallest>arr[left])
	{
		left++;
	}

	int right=arr.size()-1;
	while(largest<=arr[right])
	{
		right--;
	}
	return {left,right};
}

int main()
{
	vector<int> arr{1,2,3,4,5,8,6,7,9,10,11};

	auto p=SubarraySort(arr);
	cout<<p.first<<" and "<<p.second<<endl;

	return 0;
}


// vector<int> SubarraySort(vector<int> a)
// {
// 	// brute-force Approach
// 	vector<int> b(a);
// 	sort(a.begin(),a.end());

// 	//do comparison
// 	int i=0;
// 	int n=a.size();

// 	while(i<n and a[i]==b[i])
// 	{
// 		i++;
// 	}
// 	int j=a.size()-1;
// 	while(j>=0 and a[j]==b[j])
// 	{
// 		j--;
// 	}
// 	//already sorted
// 	if(i==a.size()){
// 		return {-1,-1};
// 	}
// 	return {i,j};
// }