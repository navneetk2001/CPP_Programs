#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin>>N;

    set<int> s;
    long long ele=0;
    for (int i=0;i<N;i++)
    {
        cin>>ele;
        s.insert(ele);
    }
    cout<<s.size();
    return 0;
}