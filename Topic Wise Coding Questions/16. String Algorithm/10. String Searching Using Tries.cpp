//Trie Data Structure is a tree.
//n-ary tree  (can consists of char a....z)


#include<bits/stdc++.h>
using namespace std;


struct trie{
	struct trie *nxt[26];

	trie(){
		for(int i=0;i<26;i++){
			nxt[i]=NULL;
		}
	}
};

trie *root;   //initialized root globally

void insert(string s){
	trie *cur=root;
	for (int i = 0; i < s.size(); ++i)
	{
		if(cur->nxt[s[i]-'a']==NULL){
			cur->nxt[s[i]-'a']=new trie();
		}
		cur=cur->nxt[s[i]-'a'];
	}
}

bool in_trie(string s){
	trie *cur=root;

	for (int i = 0; i < s.size(); ++i)
	{
		if(cur->nxt[s[i]-'a']==NULL){
			return false;
		}
		cur=cur->nxt[s[i]-'a'];
	}
	return true;
}



//Now, How can we use trie to match pattern
//1). Insert all suffix of text into tries


int main(){
	root=new trie();

	string text="abaacadbacad";
	string pat="aaca";
    
    int n=text.size(), m=pat.size();

    //construt trie ->Insert all suffix of text into tries
    for (int i = 0; i < n; ++i)
    {
    	insert(text.substr(i));
    }

	if(in_trie(pat)){
		cout<<"Yes Found"<<endl;
	}
	else{
		cout<<"Not Found"<<endl;
	}
}