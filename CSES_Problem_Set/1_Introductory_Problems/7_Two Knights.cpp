#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    cout << 0 << endl;
    for (long long i = 2 ; i <= n ; i++) {
      cout << (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)) << endl;
    }

    return 0;
}

/*
#include<bits/stdc++.h> 
using namespace std; 
int main()
{ int n,k1,k2,ktot,red; 
  cin>>n; 
  k1=n*n;              // number of ways to place first knights
  k2=k1-1;             // number of ways to place second knights 
  ktot=k1*k2/2;        // total number of ways to place 2 knights
  red=4*(n-1)*(n-2);   // total number of attacked places to be reduced
  cout<<ktot-red;      // total number of places not attacked
  return 0; 
}
*/