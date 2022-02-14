#include<bits/stdc++.h>
#define int long long 
using namespace std;

//polynomial hashing string :- Rolling hash
int poly_hash_string(string s){
	int p=31, m=1e9+7;
	int p_powr=1;
	int hash=0;
	for(int i=0;i<s.size();i++){
		hash+=(p_powr *(s[i]-'a'+1));
		p_powr*=p;
		p_powr%=m;
		hash%=m;
	}
	return hash;
}


int32_t main(){
	string s;
	cin>>s;
	
	int s_hash=poly_hash_string(s);
	cout<<s_hash<<endl;
    return 0;
}