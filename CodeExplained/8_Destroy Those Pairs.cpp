// Destroy Those Pairs!
// You are given a string str of lower case letters. If this string has any adjacent pairs of the same characters, that pair must be removed. The new string must again be checked for adjacent pairs. Repeat these steps until no pairs exist.


#include<bits/stdc++.h>
using namespace std;

string remove_pair (string str) {
   string ans;  //for storing answer
   for(char i:str)  //for traversing each element in the string
   {
      if(ans.size()==0) ans.push_back(i);  //if string is empty then just push                                                  element simply...
      else if(i==ans.back()) ans.pop_back();  //or if the current element is                                               equal to the last element of the string then                                             it's the adjacent one, so delete it.
      else ans.push_back(i);  //else just push the element simply
   }
   return ans;  //return the string
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;

    string out_;
    out_ = remove_pair(str);
    cout << out_;
}




//Second Solution :-

string removeDuplicates(string a) {
  stack<char> st;
  string ans="";
  for(auto curr:a) {
    if(st.empty()) st.push(curr);
    else if(st.top() == curr) st.pop();
    else st.push(curr);
  }

  while(!st.empty()) {
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());

  return ans;
}