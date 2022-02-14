#include<bits/stdc++.h>
using namespace std;

vector<int>dsuf;  //disjoint set union-find operation

//Find Operation
int find(int v){
	if(dsuf[v]==-1)
		return v;
	return find(dsuf[v]);
}

void union_op(int fromP, int toP){
	fromP=find(fromP);
	toP=find(toP);
	dsuf[fromP]=toP;
}

bool isCyclic(vector<pair<int,int>>& edge_list){
	for(auto p:edge_list){
		int fromP=find(p.first);  //find absolute parent of subset
		int toP=find(p.second);

		if(fromP==toP)
			return true;

		//Union operation
		union_op(fromP,toP);  //union of 2 sets
	}
	return false;
}

int main(){
	int E;  //No of edges
	int V;  //No of vertices (0 to V-1)
	cin>>E>>V;

	dsuf.resize(V,-1);   //Mark all vertices as desperate with only 1 element
	vector<pair<int,int>>edge_list; //Adjacency list
	for (int i = 0; i < E; ++i)
	{
		int from,to;
		cin>>from>>to;
		edge_list.push_back({from,to});
	}

	if(isCyclic(edge_list))
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;

	return 0;
}