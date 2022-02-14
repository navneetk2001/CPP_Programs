#include<bits/stdc++.h>
using namespace std;

bool isValid(int arr[],int n,int k,int mid){
	int student=1;
	int sum=0;

	for(int i=0;i<n;i++){
		sum+=arr[i];

	    if(sum>mid){
		    student++;
		    sum=arr[i];
	    }

	    if(student>k){
		    return false;
	    }
    }
    return true;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,k;
		cin>>n>>k;

		int arr[n];
		int max_element =0;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
			max_element=max(max_element,arr[i]);
		}

		int start=max_element;
        int end=sum-max_element;

        int res=-1;
        while(start<=end){
	        int mid=start+(end-start)/2;

	        if(isValid(arr,n,k,mid)==true){
		        res=mid;
		        end=mid-1;
	        }
	        else{
		        start=mid+1;
	        }
        }
        cout<<res<<endl;
	}
	return 0;
}



//Input:-
1
4 2
10 20 30 40

//Output :-
60