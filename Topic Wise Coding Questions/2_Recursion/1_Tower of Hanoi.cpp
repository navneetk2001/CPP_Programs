//************ IMPORTANT LITTLE DOUBT ****************


#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void solve(char s,char d, char h, int n)
 {
     if(n==1){
         cout<<"moving disc 1 from " <<s <<" to "<< d<<endl;
         return;
     }
      solve(s,h,d,n-1);
     cout<<"moving disc "<< n << " from "<< s <<" to " << h <<endl;
    solve(h,d,s,n-1);
    
    

 }
int main() {
int n;
cin>>n;
char s,d,h;
s='A';
h='B';
d='C';

solve(s,h,d,n);
    return 0;
}











// void solve(int fromRod, int helperRod, int toRod, int n, vector<vector<int>> &ans)
//  {
//      if(n==1){
//          ans.push_back({fromRod, toRod});
//          return;
//      }
//      solve(1,3,2,n-1,ans);
//      ans.push_back({fromRod, toRod});
//      solve(2,1,3,n-1,ans);
//  }

// vector<vector<int>> towerOfHanoi(int n)
// {
//     //    Write your code here.
//     vector<vector<int>> ans;
//     solve(1,2,3,n,ans);
//     return ans;
// }


