// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #define lli long long int
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     lli n;
//     cin >> n;

//     lli arr[n];
//     for (lli i = 0; i < n; i++){
//         cin >> arr[i];
//     }
    
//     lli total = 0;
//     for (lli i = 1; i < n; i++)
//     {
//         if(arr[i]<arr[i-1]){
//             total+=(arr[i-1]-arr[i]);
//             arr[i]+=(arr[i-1]-arr[i]);
//         }
//     }
//     cout << total;
//     return 0;
// }


#include <iostream>
#define lli long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli n,pre,steps=0,in;
    cin >> n >> pre;

    while(--n){
        cin>>in;
        if(pre>in){
            steps+=pre-in;
        }
        else{
            pre=in;
        }
    }
    cout<<steps<<endl;
    return 0;
}


