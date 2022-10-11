// https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/

// There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites, for example to pick task 0 you have to first pick task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks and a list of prerequisite pairs, is it possible for you to finish all tasks?

// Examples:
// Input: 2, [[1, 0]] 
// Output: true 
// Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0. So it is possible.

// Input: 2, [[1, 0], [0, 1]] 
// Output: false 
// Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0, and to pick task 0 you should also have finished task 1. So it is impossible.

// Input: 3, [[1, 0], [2, 1], [3, 2]] 
// Output: true 
// Explanation: There are a total of 3 tasks to pick. To pick tasks 1 you should have finished task 0, and to pick task 2 you should have finished task 1 and to pick task 3 you should have finished task 2. So it is possible.




//Solution Approach :-  If a cycle is found , then We can't Complete all the tasks

//We can consider this problem as a graph (related to topological sorting) problem. All tasks are nodes of the graph and if task u is a prerequisite of task v, we will add a directed edge from node u to node v. Now, this problem is equivalent to detecting a cycle in the graph represented by prerequisites. If there is a cycle in the graph, then it is not possible to finish all tasks (because in that case there is no any topological order of tasks). Both BFS and DFS can be used to solve it.
//Since pair is inconvenient for the implementation of graph algorithms, we first transform it to a graph. If task u is a prerequisite of task v, we will add a directed edge from node u to node v.


//Solution :- Using DFS 
// For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor… and so on. If it meets a node which was visited in the current process of DFS visit, a cycle is detected and we will return false. Otherwise it will start from another unvisited node and repeat this process till all the nodes have been visited. Note that you should make two records: one is to record all the visited nodes and the other is to record the visited nodes in the current DFS visit.
// We use a vector visited to record all the visited nodes and another vector onpath to record the visited nodes of the current DFS visit. Once the current visit is finished, we reset the onpath value of the starting node to false.

#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list of pairs.
vector<unordered_set<int> > make_graph(int numTasks,vector<pair<int, int> >& prerequisites){
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites){
		graph[pre.second].insert(pre.first);
	}
	return graph;
}

// A DFS based function to check if there is a cycle in the directed graph.
bool dfs_cycle(vector<unordered_set<int> >& graph, int node, vector<bool>& onpath, vector<bool>& visited){
	if (visited[node]){
		return false;
	}

	onpath[node] = visited[node] = true;
	for (int neigh : graph[node]){
		if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited)){
			return true;
		}
	}
	return onpath[node] = false;
}

// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int>> graph = make_graph(numTasks, prerequisites);
	vector<bool> onpath(numTasks, false), visited(numTasks, false);
	
	for (int i = 0; i < numTasks; i++){
		if (!visited[i] && dfs_cycle(graph, i, onpath, visited)){
			return false;
		}
	}
	return true;
}

int main(){
	int numTasks = 4;
	vector<pair<int, int> > prerequisites;

	// for prerequisites: [[1, 0], [2, 1], [3, 2]]
	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));

	if(canFinish(numTasks, prerequisites)) {
		cout << "Possible to finish all tasks";
	}
	else{
		cout << "Impossible to finish all tasks";
	}

	return 0;
}






//Solution :- Using BFS 

// A BFS based solution to check if we can finish all tasks or not. This solution is mainly based on Kahn's algorithm.
#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list of pairs.
vector<unordered_set<int> > make_graph(int numTasks,vector<pair<int, int> >& prerequisites){
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites){
		graph[pre.second].insert(pre.first);
	}
	return graph;
}

// Finds in-degree of every vertex
vector<int> compute_indegree(vector<unordered_set<int> >& graph){
	vector<int> degrees(graph.size(), 0);
	for (auto neighbors : graph){
		for (int neigh : neighbors){
			degrees[neigh]++;
		}
	}
	return degrees;
}

// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites){
	vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites);
	vector<int> degrees = compute_indegree(graph);

	for (int i = 0; i < numTasks; i++) {
		int j = 0;
		for (; j < numTasks; j++){
			if (!degrees[j]){
				break;
			}
		}

		if (j == numTasks){
			return false;
		}

		degrees[j] = -1;
		for (int neigh : graph[j]){
			degrees[neigh]--;
		}
	}
	return true;
}

int main(){
	int numTasks = 4;
	vector<pair<int, int> > prerequisites;

	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));
	if (canFinish(numTasks, prerequisites)) {
		cout << "Possible to finish all tasks";
	}
	else {
		cout << "Impossible to finish all tasks";
	}

	return 0;
}




//Solution :- Using Union-find 
//Another approach which is Union-find method can also be used to solve this problem. Each pair we get can be considered in a parent-child relation.
//As soon as we find a pair of tasks which are supposed to be in a parent-child relation, we check if they already have a common parent and hence it means there is a dependency cycle in the tasks which will never end and hence solving such set of tasks is not possible.
