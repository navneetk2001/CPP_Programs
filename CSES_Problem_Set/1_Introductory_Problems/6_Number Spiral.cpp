#include <iostream>
#define ll long long 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
    	ll y,x;
    	cin>>y>>x;

    	if(x>y){
    		if((x&1)==1){
    			cout<<x*x-y+1<<endl;
    		}
    		else{
    			--x;
    			cout<<x*x+y<<endl;
    		}
    	}
    	else{
    		if((y&1)==0){
    			cout<<y*y-x+1<<endl;
    		}
    		else{
    			--y;
    			cout<<y*y+x<<endl;
    		}
    	}
    }
    return 0;
}