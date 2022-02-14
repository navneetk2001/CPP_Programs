#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	vector<int>arr(n,0);
   
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int i,j;
	i=0;j=0;

	list<int>ans;
	while(j<n){
		if(arr[j]<0){
			ans.push_back(arr[j]);
		}
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			if(ans.size()==0){
				cout<<"0"<<" ";
			}
			else{
				cout<<ans.front()<<" ";
			}
            if(arr[i]<0){
				ans.pop_front();
			}
            i++;
            j++;
		}
	}
    return 0;
}