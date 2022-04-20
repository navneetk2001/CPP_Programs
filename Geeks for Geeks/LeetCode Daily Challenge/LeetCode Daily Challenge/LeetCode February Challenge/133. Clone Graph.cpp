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


//We can use both DFS or BFS to clone the graph

//Solution Approach :- Using DFS
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
        for(auto it:cur->neighbors)
        {
            if(mp.find(it)!=mp.end()){   
                neighbour.push_back(mp[it]);   
            }
            else
                neighbour.push_back(dfs(it,mp));
        }
        clone->neighbors=neighbour;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;   //to store previous node and new node
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};

ALGORITHM TO USE :- 
// We need to traverse all node of original graph and as soon as we reach a node, we will make a copy node.
// And recur for rest of the graph.
// This is a typical recursion type problem implemented on Graph.
// For 'Recursion' we use basically 'DFS' or 'BFS'.
// I am using DFS

KEY POINTS :- 
// 1. We use HashMap to solve it and using DFS.
// 2. Initially our hash map will be empty and we try to map the old node with the new node or the copy node.
// 3. We start with any entry point.
// 4. I am using '1' as my entry point.

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


//Second Solution :- Using DFS
class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    Node* cloneGraph(Node* node) {
        if(node == NULL){ // if node is null, then simply return null
            return NULL;
        }
        
        // for a node, we will check whether we already creates a copy of thiis or not. If it is present in map that means we already creates a copy of this.
        //But if not present in map, that means we have not a copy of this.
        // Also, if we create a copy, then being a good neighbor, we find whether our neighbor have a copy or not, so we will travel all around our adjcant.
        
        if(mp.find(node) == mp.end()){ // if not present in map
            mp[node] = new Node(node -> val, {}); // make a copy
            
            for(auto adj: node -> neighbors){ // travel in adjcant
                mp[node] -> neighbors.push_back(cloneGraph(adj)); //add copy
            }
        }
        
        return mp[node]; // and at last, return mp[node] as till now we clone our whole graph  
    }
};




//Third Solution :- Using BFS
class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        
        Node* first = new Node(node -> val, {}); // make a copy of first node
        mp[node] = first;
        
        queue<Node*> q; //For bfs, we create queue
        q.push(node); // push into queue
        
        while(q.empty() == false) // until q. empty == false
        {
            Node* curr = q.front(); // extract front node
            q.pop(); // pop that from queue
            
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