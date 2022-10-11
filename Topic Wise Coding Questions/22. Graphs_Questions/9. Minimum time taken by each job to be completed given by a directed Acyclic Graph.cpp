// https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

// Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

// Examples:
// Input: N = 10, E = 13, Below is the given graph:
// Output: 1 1 2 2 2 3 4 5 2 6  
// Explanation:
// Start the jobs 1 and 2 at the beginning and complete them at 1 unit of time. 
// Since, jobs 3, 4, 5, and 9 have the only dependency on one job (i.e 1st job for jobs 3, 4, and 5 and 2nd job for job 9). So, we can start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
// Similarly, 
// Job 6 can only be done after 3rd and 4th jobs are done. So, start it at 2nd unit of time and complete it at 3rd unit of time.
// Job 7 can only be done after job 6 is done. So, you can start it at 3rd unit of time and complete it at 4th unit of time.
// Job 8 can only be done after 4th, 5th, and 7th jobs are done. So, start it at 4th unit of time and complete it at 5th unit of time.
// Job 10 can only be done after the 8th job is done. So, start it at 5th unit of time and complete it at 6th unit of time.




//Solution Approach :-
// Approach: The job can be started only if all the jobs that are prerequisites of the job that are done. Therefore, the idea is to use Topological Sort for the given network. Below are the steps:
// 	1.Finish the jobs that are not dependent on any other job.
// 	2.Create an array inDegree[] to store the count of the dependent node for each node in the given network.
// 	3.Initialize a queue and push all the vertex whose inDegree[] is 0.
// 	4.Initialize the timer to 1 and store the current queue size(say size) and do the following:
// 		.Pop the node from the queue until the size is 0 and update the finishing time of this node to the timer.
// 		.While popping the node(say node U) from the queue decrement the inDegree of every node connected to it.
// 		.If inDegree of any node is 0 in the above step then insert that node in the queue.
// 		.Increment the timer after all the above steps.
// 	5.Print the finishing time of all the nodes after we traverse every node in the above step.



// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

vector<int> graph[maxN];    // Adjacency List to store the graph
int indegree[maxN];         // Array to store the in-degree of node
int job[maxN];              // Array to store the time in which the job i can be done

// Function to add directed edge between two vertices
void addEdge(int u, int v){
	graph[u].push_back(v);    	// Insert edge from u to v
	indegree[v]++;    // Increasing the indegree of vertex v
}

// Function to find the minimum time needed by each node to get the task
void printOrder(int n, int m) {
	queue<int> q;

	for(int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);         // Pushing all the vertex in the queue whose in-degree is 0
			job[i] = 1;        // Update the time of the jobs who don't require any job to be completed before this job
		}
	}

	while (!q.empty()) {
		int cur = q.front();   // Get front element of queue
		q.pop();    // Pop the front element

		for (int adj : graph[cur]) {
			indegree[adj]--;   // Decrease in-degree ofthe current node
			if (indegree[adj] == 0) {
				job[adj] = job[cur] + 1;
				q.push(adj);    // Push its adjacent elements
			}
		}
	}

	for (int i = 1; i <= n; i++){
		cout << job[i] << " ";
	}
	cout << "\n";
}

int main(){
	int n, m;    	// Given Nodes N and edges M
	n = 10; 
	m = 13;

	// Given Directed Edges of graph
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 8);
	addEdge(2, 9);
	addEdge(3, 6);
	addEdge(4, 6);
	addEdge(4, 8);
	addEdge(5, 8);
	addEdge(6, 7);
	addEdge(7, 8);
	addEdge(8, 10);

	// Function Call
	printOrder(n, m);
	return 0;
}







