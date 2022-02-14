//Trie Data Structure is a tree.
//n-ary tree  (can consists of char a....z)


#include<bits/stdc++.h>
using namespace std;


struct trie{
	struct trie *nxt[26];
	bool ended;

	trie(){
		for(int i=0;i<26;i++){
			nxt[i]=NULL;
		}
		ended=false;
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
	//cur pointer will be on the last node
	cur->ended=true;
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
	return cur->ended;
}



//Now, How can we use trie to match pattern
//1). Insert all suffix of text into tries
//2). 


int main(){
	root=new trie();

	insert("navneet");
	insert("abhijeet");
	insert("vishal");
	insert("rahul");
	insert("kirti");
	insert("raju");

	if(in_trie("vishal")){
		cout<<"Yes Found"<<endl;
	}
	else{
		cout<<"Not Found"<<endl;
	}
}