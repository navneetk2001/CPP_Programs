#include<bits/stdc++.h>
using namespace std;

int lps(string s){
	int max=0;
	int n=s.length();
	for(int i=0;i<n;i++){
		//odd length
		int l=i;
		int r=i;
		while(l>=0 && r<n && s[l]==s[r]){
			int curr_l=r-l+1;
			if(curr_l>max){
				max=curr_l;
			}
			l--;
			r++;
		}
		
		//even length
		l=i;
		r=i+1;
		while(l>=0 && r<n && s[l]==s[r]){
			int curr_l=r-l+1;
			if(curr_l>max){
				max=curr_l;
			}
			l--;
			r++;
		}	
	}
	return max;
}

int main(){
	string s;
	cin>>s;
	
	cout<<lps(s)<<endl;
    return 0;
}




//If we have to return that palindromic substring string in A
string Solution::longestPalindrome(string A) {
    int max=0;
    string ans;
	int n=A.length();
	for(int i=0;i<n;i++){
		//odd length
		int l=i;
		int r=i;
		while(l>=0 && r<n && A[l]==A[r]){
			int curr_l=r-l+1;
			if(curr_l>max){
				max=curr_l;
                ans=A.substr(l,r-l+1);
			}
			l--;
			r++;
		}
		
		//even length
		l=i;
		r=i+1;
		while(l>=0 && r<n && A[l]==A[r]){
			int curr_l=r-l+1;
			if(curr_l>max){
				max=curr_l;
                ans=A.substr(l,r-l+1);
			}
			l--;
			r++;
		}	
	}
    return ans;
}
