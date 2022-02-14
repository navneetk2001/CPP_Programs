#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    int tc = 1;
    while(t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        unordered_map<ll,ll> m;
        m[0] = 1;
        ll minSum = 0;
        ll sum = 0;
        ll ans = 0;
        for(ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            minSum = min(minSum,sum);
            for(ll j=0;(sum-j*j)>=minSum;++j)
            {
                if(m.count(sum-j*j)==1)
                    ans+=m[sum-j*j];
            }
            m[sum]+=1;
        }
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
        tc+=1;
    }
}