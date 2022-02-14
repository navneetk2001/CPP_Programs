//Using Prefix Sum :-
//value[i] = character * p^i

#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1e9+7;
const int p=31;


int powr(int a, int b){
	int res=1;
	while(b){
		if(b & 1ll){
			res*=a;
			res%=mod;
		}
		b/=2;
		a*=a;
		a%=mod;
	}
	return res;
}

int inv(int a){
	//a^-1 %m
	return powr(a, mod-2);
}

//polynomial hashing string :- Rolling hash
int poly_hash_string(string s){
	int p_powr=1;
	int hash=0;
	for(int i=0;i<s.size();i++){
		hash+=(p_powr *(s[i]-'a'+1));
		p_powr*=p;
		p_powr%=mod;
		hash%=mod;
	}
	return hash;
}

//steps of Rabin Karp :-
//1. Subset(character*p^0)
//2. Left Shift the string (Divide by P)
//3. Add a new character in the back of string


int32_t main(){
	string text,pattern;
	cin>>text>>pattern;  //text will be big and pattern will be small
    
    int pat_hash=poly_hash_string(pattern);
    int n=text.size(), m=pattern.size();
    int pref[n];

	for (int i = 0; i < n; ++i)
	{
		pref[i]=(text[i]-'a'+1)*powr(p,i);
		pref[i]%=mod;
	}
	for (int i = 1; i < n; ++i)
	{
		pref[i]+=pref[i-1];
		pref[i]%=mod;
	}

	for (int i = 0; i+m <= n; ++i)
	{
		//substring from s[l......r]
		//r=i+m-1
		//l=i
		int new_hash=pref[i+m-1];
		if(i-1>=0) new_hash-=pref[i-1];

		new_hash+=mod;
		new_hash%=mod;

		if(new_hash==(pat_hash*powr(p,i)) %mod){
    		cout<<i<<endl;
    	}
	}
    return 0;
}