#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int closest_Number(vector<int>& b, int x){
	sort(b.begin(),b.end());
	auto lower=lower_bound(b.begin(),b.end(),x);

    if(lower == b.begin()){
    	return 0;
    }

    int first_low = *(lower-1);
    int second_low = *(lower);

    if(abs(x-first_low) < abs(x-second_low)){
    	return lower - b.begin() - 1;
    }
    return lower - b.begin();
}

pair<int,int> minDifference(vector<int> a,vector<int> b){
	int n1=a.size();
	int n2=b.size();

    int min_diff=INT_MAX;
    int diff=INT_MAX;
    int temp1, temp2;
	for(int i=0;i<n1;i++)
	{
		int x=a[i];
		int l_idx=closest_Number(b,x);
		int diff=abs(x-b[l_idx]);
		if(diff<min_diff){
			min_diff=diff;
			temp1=x;
			temp2=b[l_idx];
		}
	}	
	return {temp1,temp2};
}

int main()
{
	vector<int> arr1{23,5,10,17,30};
	vector<int> arr2{26,134,135,14,16,19};
	
	auto p=minDifference(arr1,arr2);
	cout<<p.first<<","<<p.second<<endl;

	return 0;
}

