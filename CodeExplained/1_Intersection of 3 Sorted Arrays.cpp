// Intersection of 3 Sorted Arrays
// You are given three sorted arrays arr1, arr2 and arr3. Your task is to return a sorted array of elements that are common to all three arrays.

#include<bits/stdc++.h>
using namespace std;

vector<int> array_intersection (int n1, int n2, int n3, vector<int> arr1, vector<int> arr2, vector<int> arr3) {
   vector<int>res;
   int i=0, j=0, k=0;
   while(i!=n1 && j!=n2 && k!=n3){
      int x=arr1[i];
      int y=arr2[j];
      int z=arr3[k];
      if(x==y && y==z){
         res.push_back(x);
         i++;
         j++;
         k++;
      }
      else if(x<=y && x<=z){
         i++;
      }
      else if(y<=x && y<=z){
         j++;
      }
      else{
         k++;
      }
   }
   return res; 
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n1;
    cin >> n1;
    int n2;
    cin >> n2;
    int n3;
    cin >> n3;
    vector<int> arr1(n1);
    for(int i_arr1 = 0; i_arr1 < n1; i_arr1++)
    {
    	cin >> arr1[i_arr1];
    }
    vector<int> arr2(n2);
    for(int i_arr2 = 0; i_arr2 < n2; i_arr2++)
    {
    	cin >> arr2[i_arr2];
    }
    vector<int> arr3(n3);
    for(int i_arr3 = 0; i_arr3 < n3; i_arr3++)
    {
    	cin >> arr3[i_arr3];
    }

    vector<int> out_;
    out_ = array_intersection(n1, n2, n3, arr1, arr2, arr3);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}