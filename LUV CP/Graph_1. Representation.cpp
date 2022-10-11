#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int graph1[N+1][N+1];

vector<int> graph2[N];

vector<pair<int,int>> graph3[N];  //for storing weight also with edges

int main(){
	int n,m;   //n :- vertices , m:- edges
	cin>>n>>m;
    
    //Adjacency matrix representation :- O(N^2) :- Space Complexity
    for(int i=0;i<m;i++){   //iterate for number of edges
    	int v1, v2;
    	cin >> v1 >> v2;
    	graph1[v1][v2] = 1;
    	graph1[v2][v1] = 1;
    }


    //Adjacency list representation :- O(N+M) :- Space Complexity
    for(int i=0;i<m;i++){   //iterate for number of edges
    	int v1, v2;
    	cin >> v1 >> v2;
    	graph2[v1].push_back(v2);
    	graph2[v2].push_back(v1);
    }

    //for storing adjacency list with weight
    for(int i=0;i<m;i++){   //iterate for number of edges
    	int v1, v2, wt;
    	cin >> v1 >> v2 >> wt;
    	graph2[v1].push_back({v2,wt});
    	graph2[v2].push_back({v1,wt});
    }


	
}
