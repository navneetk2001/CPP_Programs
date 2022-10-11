// Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints. 
// Vertex coloring is the most common graph coloring problem. The problem is, given m colors, find a way of coloring the vertices of a graph such that no two adjacent vertices are colored using same color. The other graph coloring problems like Edge Coloring (No vertex is incident to two edges of same color) and Face Coloring (Geographical Map Coloring) can be transformed into vertex coloring. 
// Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. For example, the following can be colored minimum 2 colors




//Approach 1: Brute Force
// The simplest approach to solve this problem would be to generate all possible combinations (or configurations) of colours.
// After generating a configuration, check if the adjacent vertices have the same colour or not. If the conditions are met, add the combination to the result and break the loop.
// Since each node can be coloured by using any of the M colours, the total number of possible colour configurations are mV. The complexity is exponential which is very huge.

bool isSafeToColor(vector < vector < int >> & graph, vector < int > color) {
  for (int i = 0; i < V; i++)
    for (int j = i + 1; j < V; j++)
      if (graph[i][j] == 1 && color[j] == color[i])
        return false;
  return true;
}
 
void printColorArray(vector < int > color) {
  cout << ("Solution colors are: ") << endl;
  for (int i = 0; i < color.size(); i++) {
    cout << (color[i]);
  }
}

bool graphColoring(vector < vector < int >> & graph, int m, int i, vector < int > color) {
  if (i == V) {
    if (isSafeToColor(graph, color)) {
      printColorArray(color);
      return true;
    }
    return false;
  }
  
  for (int j = 1; j <= m; j++) {
    color[i] = j;
    if (graphColoring(graph, m, i + 1, color))
      return true;
 
    color[i] = 0;
  }
 
  return false;
}



//Approach 2: Backtracking
//In the previous approach, trying and checking every possible combination was tedious and had an exponential time complexity.
//Some of the permutation calculations were unnecessary but were calculated again and again. Therefore, the idea is to use a backtracking approach to solve the problem.
// //In this approach, the idea is to color a vertex and while coloring any adjacent vertex, choose a different color. Similarly, color every possible vertex following the restrictions, till any further vertex is left coloring. In any case, if all adjacent vertices for a given vertex are colored, then backtrack and change color.
// If after coloring, if we return back to the same vertex that was started with and all colors are used, then more colors are needed. Hence, return False.

// Algorithm
// 	Consider a color and check if it is valid i.e. from the given vertex check whether its adjacent vertices have been coloured with the same color.
// 	If true, pick a different colour, else continue colouring the vertices.
// 	If no other color is left un-used, then backtrack.


class InterviewBit {
	public:
    int V = 4;
 
bool isSafeToColor(int v, vector < vector < int >> & graphMatrix, vector < int > color, int c) {
    for (int i = 0; i < V; i++){
      	if (graphMatrix[v][i] == 1 && c == color[i]){
        	return false;
      	}
    }
    return true;
}
 
bool graphColorUtil(vector < vector < int >> & graphMatrix, int m, vector < int > color, int v) {
    if (v == V){
      return true;
    }
 
    for (int i = 1; i <= m; i++){
	    if(isSafeToColor(v, graphMatrix, color, i)){
        	color[v] = i;
        	if(graphColorUtil(graphMatrix, m, color, v + 1)){
          		return true;
        	}
        	color[v] = 0;
        }
    }
    return false;
}
 
void printColoringSolution(int color[]){
    cout << ("Color schema for vertices are: ") << endl;
    for (int i = 0; i < V; i++){
     	cout <<color[i]<< endl;
    }
}

bool graphColoring(vector<vector<int>>&graphMatrix, int m){
    vector<int>color(V, 0);
 
    if(!graphColorUtil(graphMatrix, m, color, 0)){
      	cout << "Color schema not possible" << endl;
      	return false;
    }
 
    printColoringSolution(color);
    return true;
}


//Time Complexity:O(M^V), in the worst case.
//Space Complexity:O(V), as extra space is used for coloring vertices.


