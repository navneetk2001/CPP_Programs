// Given an adjacency matrix representation of an unweighted undirected graph named graph, which has N vertices. You have to find out if there is an eulerian path present in the graph or not.
// Note: The graph consists of a single component

// Example 1:
// Input: N = 5
// graph = {{0, 1, 0, 0, 1}, 
//          {1, 0, 1, 1, 0}, 
//          {0, 1, 0, 1, 0}, 
//          {0, 1, 1, 0, 0}, 
//          {1, 0, 0, 0, 0}}
// Output: 1
// Explaination: There is an eulerian path. The path is 5->1->2->4->3->2.

// Example 2:
// Input: N = 5
// graph = {{0, 1, 0, 1, 1}, 
//          {1, 0, 1, 0, 1}, 
//          {0, 1, 0, 1, 1}, 
//          {1, 1, 1, 0, 0}, 
//          {1, 0, 1, 0, 0}}
// Output: 0
// Explaination: There is no eulerian path in the graph.




//Solution Approach :-
//There are two possibilities for an Eulerian path.
//No. of vertices with odd number of edges should be 0 or 2.

int eulerPath(int N, vector<vector<int>> graph){
    int odd_edged = 0;
    
    for(int i=0;i<N;i++){
        int count = 0;
        for(int j=0;j<N;j++){
            if(graph[i][j]==1)
                count++;
        }
        if(count%2==1){
	        odd_edged++;
        }
    }

    if(odd_edged == 0 || odd_edged == 2){
        return 1;
    }
    else{
        return 0;
    }
}



//Second Solution :-
//🙂 For a graph to be an Euler Path, it has to have only 2 odd vertices.

class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        vector<int>degree(N,0);
       
        for(int i=0;i<N;++i){
            int count=0;
            for(int j=0;j<N;++j){
                if(graph[i][j]==1){
               		count++;
            	}
           }
           degree[i]=count;
        }

        int oddVertex=0;
        for(int i=0;i<N;++i){
            if(degree[i]%2)
            	oddVertex++;
        }
       
        return oddVertex==2?1:0;
    }
};

