#include<bits/stdc++.h>
using namespace std;


struct node
{
	int parent;
	int rank;
};
vector<int>dsuf;  //disjoint set union-find operation

//Find Operation
int find(int v){
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent); //Path Compression
}

void union_op(int fromP, int toP){  //union by rank
	if(dsuf[fromP].rank>dsuf[top].rank){ //fromP has higher rank
		dsuf[top].parent=fromP;
	}
	else if(dsuf[fromP].rank<dsuf[top].rank){ //toP has higher rank
		dsuf[fromP].parent=toP;
	}
	else{
		//Both have same rank and so anyone can be made as parent
		dsuf[fromP].parent=top;
		dsuf[toP].rank+=1;    //increse rank of parent
	}
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

	dsuf.resize(V,-1);   //Mark all vertices as seperate subsets with only 1 element
	for (int i = 0; i < E; ++i)   //Mark all sets as independent set
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}

	vector<pair<int,int>>edge_list; 
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