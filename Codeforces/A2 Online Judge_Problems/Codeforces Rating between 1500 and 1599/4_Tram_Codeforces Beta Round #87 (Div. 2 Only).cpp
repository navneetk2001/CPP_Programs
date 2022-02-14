#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[n][2];
    for (int i = 0; i < n; i++) {
       for(int j=0;j<2;j++){
        cin>>arr[i][j];
       }
    }
    int num=0;int maxim=0;
    for (int i = 0; i < n; i++) {
        num+=arr[i][1]-arr[i][0];
        maxim=max(num,maxim);
    }
    
    cout<<maxim<<endl;
}