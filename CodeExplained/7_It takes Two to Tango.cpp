// It takes Two to Tango!
// You are given an array arr, along with an integer named target. Calculate the number of pairs in arr that can be added together to form target.


#include<bits/stdc++.h>
using namespace std;

int two_sum (int n, vector<int> arr, int target) {
   unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(target - arr[i]) != m.end()) {
            count += m[target - arr[i]];
        }
        m[arr[i]]++;
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
    int target;
    cin >> target;

    int out_;
    out_ = two_sum(n, arr, target);
    cout << out_;
}