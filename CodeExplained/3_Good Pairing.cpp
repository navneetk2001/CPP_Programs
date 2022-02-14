// Good Pairing
// You are given an array arr in which a good pair is defined as a pair of numbers in the array which satisfy the following conditions:
// arr[i] = arr[j] (The two numbers must be equal)
// i<j
// Find the number of good pairs in the array.



#include<bits/stdc++.h>
using namespace std;

int good_pairs (int n, vector<int> arr) {
   unordered_map<int,int>mp;
   for(int i=0;i<n;++i)
   {
      if(mp.find(arr[i])==mp.end())
         mp[arr[i]] = 1;
      else
         mp[arr[i]] += 1;
   }
   
   int count=0;
   for(auto itr=mp.begin();itr!=mp.end();itr++){
		auto x=itr->second;
      count = count + (x*(x-1)/2);
	}
   return count;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr = 0; i_arr < n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    int out_;
    out_ = good_pairs(n, arr);
    cout << out_;
}