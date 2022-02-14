// Stuff Them Candies In!
// You are given an array candies, where candies[i] defines how many candies the i-th kid has. You are also given an integer, extra_candies, which can be distributed among the kids.

// For each kid, check if there is a way to distribute extra_candies such that that kid has the maximum number of candies. Multiple kids can have maximum candies.


#include<bits/stdc++.h>
using namespace std;

vector<int> extra_candy (int n, vector<int> candies, int extra_candies) {
   vector<int> ans;
   int mx=-1;
   for(int i=0;i<n;i++){
      mx=max(mx,candies[i]);
   }

   for(int i=0;i<n;i++){
      if(candies[i]+extra_candies >= mx){
         ans.push_back(1);
      }
      else{
         ans.push_back(0);
      }
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> candies(n);
    for(int i_candies = 0; i_candies < n; i_candies++)
    {
    	cin >> candies[i_candies];
    }
    int extra_candies;
    cin >> extra_candies;

    vector<int> out_;
    out_ = extra_candy(n, candies, extra_candies);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}