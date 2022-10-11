//not possible to find shortest path if there is a negative edge cycle in Directed graph
//For undirected graph, convert it into a directed graph and then apply bellmsn ford algo



//Solution Approach :-
// Recall that in Dijkstra’s algorithm, we update the distance array every time we find a better solution which was a lesser distance. With the presence of negative edge weights, our algorithm would continue to update the distance array with lesser and lesser values and we might end up in time limit exceeded or segmentation fault error. Try to dry run the following example and you would understand the issue yourself.
// Intuition: We would try to update our distance array in a somewhat same manner as we did in Dijkstra’s algorithm. However, we need to handle the negative edge weights as well. Thus, we need to update the array in a controlled fashion may be, a specific number of times. Remember, we don’t want to end up in an endless loop.

// Approach:
// We would use a technique what is known as “Relaxing Edges” wherein we would update our distance array if we find a better solution. We would do this N-1 times. 
// Now why N-1? Understand that for a given graph with N nodes, the maximum number of edges we could have between any two nodes is N-1 in a single path. Moreover, our adjacency list might be in such a manner that only one node is updated in a single pass. Thus, to try out all nodes, we would require atleast N-1 iterations.The following is the demonstration of the same:

#include <bits/stdc++.h>
using namespace std;

struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N=6,m=7;
    vector<node> edges; 
	edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,-2));
	edges.push_back(node(1,5,-3));
	edges.push_back(node(2,4,3));
	edges.push_back(node(3,2,6));
	edges.push_back(node(3,4,-2));
	edges.push_back(node(5,3,1));

    int src=0;

    int inf = 10000000; 
    vector<int> dist(N, inf); 
    dist[src] = 0; 

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}
