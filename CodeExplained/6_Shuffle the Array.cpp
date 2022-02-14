// Shuffle the Array!
// You are given an array nums consisting if 2n elements in the form [x1,x2,x3...xn,y1,y2,y3...yn].
// Return an array in the form [x1,y1,x2,y2,x3,y3...,xn,yn].


#include<bits/stdc++.h>
using namespace std;

vector<int> shuffle (int n, vector<int> arr) {
   int i=0, j=n;
   vector<int>ans;
   while(i<n && j<2*n){
      ans.push_back(arr[i]);
      ans.push_back(arr[j]);
      i++;
      j++;
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(2*n);
    for(int i_arr = 0; i_arr < 2*n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    vector<int> out_;
    out_ = shuffle(n, arr);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}





