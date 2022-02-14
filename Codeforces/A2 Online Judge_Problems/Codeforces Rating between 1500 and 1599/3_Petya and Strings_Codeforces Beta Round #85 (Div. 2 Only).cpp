#include <iostream>
#include <algorithm>
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
    int x=0;int y=0;
    for (int i = 0; i < n-1; i++) {
        x+=arr[i][0];
    }
    
    for (int i = 0; i < n; i++) {
        y+=arr[i][1];
    }

    cout<<y-x<<endl;
}