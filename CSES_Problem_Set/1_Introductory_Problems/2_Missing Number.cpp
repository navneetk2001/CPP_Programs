#include <iostream>
using namespace std;

int main()
{
    long long int n,sum=0,num,missing_no=0;
    cin >> n;

    for (int i=0;i<n-1;i++)
    {
        cin>>num;
        sum+=num;
    }
    missing_no=(n*(n+1)/2)-sum;

    cout<<missing_no;
    return 0;
}
