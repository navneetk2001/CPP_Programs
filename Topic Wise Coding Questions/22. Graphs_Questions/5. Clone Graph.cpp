// Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

// Test case format:
// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

// Example 1:
// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

// Example 2:
// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

// Example 3:
// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.


//Approach :-
// We are able to do this question using both DFS and BFS.
// Just one important thing we have to consider here that, Suppose we are standing on any particular node and we want to make a copy of the node then we have to keep a record that whether the copy of this node is already created or not.
// See, we try to move in neighbor and creating a copy of node, so if two nodes are neighbour of each other, say 1 and 2, then node 1 say okay, node 2 is my neighbour so when i move to this then i have to create a copy and we create a copy of node 2 and since we are on the node 1so for node 1 we also create a copy.
// Now, we move further to node 2, then node 2 say okay, i have to create my copy, but as well as since 1 is also my neighbour so i also have to create the copy of node1.
// In this way, for only both of the nodes, we create copies and this is the problem that we want to avoid.
// Also, if we create a copy, then being a good neighbor, we find whether our neighbor have a copy or not, so we will travel all around our adjcant.


//Solution Approach :- DFS Approach 
class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    Node* cloneGraph(Node* node) {
        if(node == NULL){           // if node is null, then simply return null
            return NULL;
        }
        
        //for a node, we will check whether we already creates a copy of thii or not. If it is present in map that means we already creates a copy of this.
        //But if not present in map, that means we have not a copy of this.
        //Also, if we create a copy, then being a good neighbor, we find whether our neighbor have a copy or not, so we will travel all around our adjcant.
        
        if(mp.find(node) == mp.end()){ // if not present in map
            mp[node] = new Node(node -> val, {}); // make a copy
            for(auto adj: node -> neighbors){ // travel in adjcant
                mp[node] -> neighbors.push_back(cloneGraph(adj)); //add copy
            }
        }

        return mp[node];   // and at last, return mp[node] as till now we clone our whole graph
    }
};


//Second Solution :- DFS 
class Solution {
    public:
    Node* dfs(Node* cur, unordered_map<Node*,Node*>& mp){
        vector<Node*> neighbour;

        Node* clone=new Node(cur->val);
        mp[cur]=clone;

        for(auto it:cur->neighbors){
            if(mp.find(it)!=mp.end()){   //already clone and stored in map
                neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
            }
            else{
                neighbour.push_back(dfs(it,mp));
            }
        }

        clone->neighbors=neighbour;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL){
            return NULL;
        }

        if(node->neighbors.size()==0){   //if only one node present no neighbors
            Node* clone= new Node(node->val);
            return clone; 
        }

        return dfs(node,mp);
    }
};


//DFS Approach :-
// ALGORITHM TO USE :-
// 	We need to traverse all node of original graph and as soon as we reach a node, we will make a copy node.
// 	And recur for rest of the graph.
// 	This is a typical recursion type problem implemented on Graph.
// 	For 'Recursion' we use basically 'DFS' or 'BFS'.
// 	I am using DFS

// KEY POINTS :- 
// 	1. We use HashMap to solve it and using DFS.
// 	2. Initially our hash map will be empty and we try to map the old node with the new node or the copy node.
// 	3. We start with any entry point.
// 	4. I am using '1' as my entry point.

// Now lets see how its going i am starting with 1 and whenever i visited a new node i coloned it and put in there.
// We are using DFS so algorithm is like 'it starts at the root node (select some arbitrary node as root node in the case of a graph) and explores as far as possible along each branch before backtracking.
// So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacentunmarked node and continue this loop until there is no unmarked adjacent node. 
// Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.'
// So we are using HashMap to put all the visited node or old node there with clone one to.
//  _________
// | HashMap |
//  ----------
// |Old|Clone| 
// | 1  | 1 |
// |  2 | 2 |
// |  3 | 3 |                                                     
// |  4 | 4 |                                                                                                            
// ---------

// Now i started with 1 so i cloned it and from 1 can go to 2 and 4 so i go 2 and when i visited 2 i cloned 2 and now fro  i have two choices either go to previous one that is 1 or discover 3 i.e new node
// so accordingly to dfs i go to 3 and from 3 i can go to 4 i go there and cloned it. Now if we see fro each node we have viisted to a new node but what about 4. So here half part of Dfs is completed,
// and now its time for recursive call to go back and now from here we check from current node i can go where and where.
// And follow the same rules over there.

// BUT BEFORE STARTING ANY CLONING WE HAVE TO CHECK THAT IF WE HAVE CLONED THAT NODE ALREADY THERE OR NOT. IF NOT THAN ONLY WE CLONED IT. 

// Thats the only reason we are using hash map so that we don't need to clone again and again.
// For every uncloned node we make a clone and iterate over the neighbors of original node using dfs traversal or bfs traversal.


//Solution Approach :- BFS Approach 
class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){ // if node is null, then simply return null
            return NULL;
        }
        
        Node* first = new Node(node -> val, {}); // make a copy of first node
        mp[node] = first;
        
        queue<Node*> q; //For bfs, we create queue
        q.push(node); // push into queue
        
        while(q.empty() == false) // until q. empty == false
        {
            Node* curr = q.front();  // extract front node
            q.pop();                 // pop that from queue
            
            for(auto adj: curr -> neighbors) // now travel in adjcant
            {
                if(mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj -> val, {}); // then create copy
                    q.push(adj); // push nto the queue
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }
        
        return mp[node];
    }
};
