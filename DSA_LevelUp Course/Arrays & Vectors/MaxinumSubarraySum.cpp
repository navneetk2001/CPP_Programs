#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarraySum(vector<int> arr){
    int n = arr.size();
    
    int maxSumSoFar=INT_MIN;
    int sum=0;

    for(int i=0;i<n;i++)
    {
    	
    	sum+=arr[i];
    	if(sum>maxSumSoFar)
    		maxSumSoFar=sum;

    	if(sum<0)
    		sum=0;
    }
    return maxSumSoFar;
}

int main()
{
	vector<int> arr{-2, -3, 4, -1, -2, 1, 5, -3};
	cout<<maxSubarraySum(arr)<<endl;

	return 0;
}