//Brute Force Solution :-
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 


	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
	
    int parent[N];
    int key[N]; 
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX, mstSet[i] = false; 
    }

    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    { 
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++) 
		{
            if (mstSet[v] == false && key[v] < mini) {
                mini = key[v], u = v; 
            }
		}
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
    } 
    
    
    for (int i = 1; i < N; i++) {
        cout << parent[i] << " - " << i <<" \n"; 
    }
	return 0;
}

//Time Complexity: O(N^2). Going through N Node for N-1 times
//Space Complexity: O(N). 3 arrays of size N



//Efficient Solution :-
// Run the loop till all the nodes have been visited
// because in the brute code we checked for mstSet[node] == false while computing the minimum
// but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
// hence its better to keep running till all the nodes have been taken. 
// try the following case: 
// Credits: Srejan Bera
// 6 7 
// 0 1 5 
// 0 2 10 
// 0 3 100 
// 1 3 50 
// 1 4 200
// 3 4 250
// 4 5 50 


#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
    int key[N]; 
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX, mstSet[i] = false; 
    }
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
				key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) {
        cout << parent[i] << " - " << i <<" \n"; 
    }
	return 0;
}



// Time Complexity: O(NlogN). N iterations and logN for priority queue
// Space Complexity: O(N). Three arrays and priority queue