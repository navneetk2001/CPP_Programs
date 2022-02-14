#include<iostream>
using namespace std;

const int N=1e5+5;
int n,b;
int a[N];

int main(){
	int t;
	cin>>t;
    
    int tc=0;
	while(t--){
		tc++;
		cin>>n>>b;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}

		sort(a+1,a+n+1); //nlogn
		int ans=0;
		for (int i = 1; i <= n; ++i)
		{
			if(b>= a[i]){
				ans++;
				b-=a[i];
			}
		}
		cout<<"case #"<<tc<<": "<<ans<<endl;
	}
	return 0;
}