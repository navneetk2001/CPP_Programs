// Sort those Squares!
// You are given a sorted array arr. Your task is to sort the squares of each element of the array.


#include<bits/stdc++.h>
using namespace std;

vector<int> sort_square (int n, vector<int> A) {
    int i=0;
    int j=n-1;

    vector<int> v;  //creating a new vector

    while(i<=j){
        if(abs(A[i])>abs(A[j])){
            v.push_back(A[i]*A[i]);
            i++;
        }
        else{
            v.push_back(A[j]*A[j]);
            j--;
        }
    }

    reverse(v.begin(), v.end());
    return v; 
   
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

    vector<int> out_;
    out_ = sort_square(n, arr);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}