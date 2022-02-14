//Problem Code: CHEAPFUEL
#include<iostream>
using namespace std;

int main(){
    long long t,X,Y,A,B,K;
    cin>>t;

    while(t--){
        cin>>X>>Y>>A>>B>>K;
        
        for(int i=0;i<K;i++){
              X+=A;
              Y+=B;
        }
        if(X>Y){
            cout<<"DIESEL"<<endl;
        }
        else if(X<Y){
            cout<<"PETROL"<<endl;
        }
        else{
            cout<<"SAME PRICE"<<endl;
        }
    }
    return 0;
}



//Problem Code: EQUALCOIN
#include<iostream>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        long long X,Y;
        cin>>X>>Y;
        if(X==0 and Y % 2 !=0){
            cout<<"NO"<<endl;
        }
        else if(X%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}






//Problem Code: MAKEPAL
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        long long N;
        cin>>N;

        long long arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }

        int odd_count=0,even_count=0;
        for(int i=0;i<N;i++){
            if(arr[i]%2==0){
                even_count+=1;
            }
            else{
                odd_count+=1;
            }
        }

        if(odd_count%2==1){
            odd_count--;
        }
        cout<<odd_count/2<<endl;
    }
    return 0;
}




//Problem Code: HILLSEQ --> Solution_1
#include<iostream>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        bool flag = true;
        map<long long int, long long int> lexo;
        cin >> n;
        for(int i = 0; i<n; i++)
        {
            int temp;
            cin >> temp;
            lexo[temp]++;
        }
        
        for(auto x: lexo)
        {
            auto j = lexo.rbegin();
            if(j->second ==2)
            {
                cout << "-1\n";
                flag = false;
                break;
            }
            else if(x.second > 2)
            {
                cout << "-1\n";
                flag = false;
                break;
            }
        }
        
        if(flag == true)
        {
           for(auto x: lexo)
           {
                if(x.second==2){
                	cout << x.first << " ";
                }
           }
        for(auto k = lexo.rbegin(); k!=lexo.rend(); k++)
        {
            cout << k->first << " ";
        }  
        cout << endl;
        }
      
    }
}




//Problem Code: HILLSEQ --> Solution_2
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    lli t;
    cin >> t;
    while(t--)
    {
        lli n,x;
        cin >> n;

        bool flag=false;
        map<lli,lli> height;
        vector<lli>ans;
        for(lli i=0;i<n;i++){
            cin>>x;
            height[x]++;
        }

        for(auto x:height){
            if(x.second>2){
                flag=true;
                break;
            }
            ans.push_back(x.first);
        }

        sort(ans.begin(),ans.end());
        if(flag == true || height[ans[ans.size()-1]]==2){
            cout<<"-1";
        }
        else{
            for(lli i=0;i<ans.size();i++){
                if(height[ans[i]]==2){
                    cout<<ans[i]<<" ";
                }
            }
            for(lli i=ans.size()-1;i>=0;i--){
                    cout<<ans[i]<<" ";
            }
        }
      cout<<endl;
    }
}






//Problem Code: MAXBRIDGE












//Problem Code: XOREQN










//Problem Code: WLDRPL













//Problem Code: FLIPCOMP










//Problem Code: FUNARR













//Problem Code: CONHULK








