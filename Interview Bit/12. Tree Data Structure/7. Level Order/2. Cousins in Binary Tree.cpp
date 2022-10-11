// Given a Binary Tree A consisting of N nodes. You need to find all the cousins of node B.
// NOTE:
// Siblings should not be considered as cousins.
// Try to do it in single traversal.
// You can assume that Node B is there in the tree A.
// Order doesn't matter in the output.
//cousins are nodes that are on the same level but they belong to a different parents

// Example 1:
// Input : 
//              1
//            /   \
//           2     3
//         /   \  /  \
//        4    5  6   7

// Given node : 5
// Output : 6 7
// Explanation : Nodes 6 and 7 are on the same level as 5 and have different parents.

// Given node : 7
// Output : 4 5

// Example 2 :
// Input :
//          9
//         /
//        5
// Given node : 5
// Output : -1
// Explanation : There no other nodes than 5 in the same level.


//Hint :-
//The idea is to go for level order traversal of the tree, as the cousins and siblings of a node can be found in its level order traversal. Run the traversal till the level containing the node is not found, and if found, print the given level

//Solution Approach :- 
// The idea is to go for level order traversal of the tree, as the cousins and siblings of a node can be found in its level order traversal. Run the traversal till the level containing the node is not found, and if found, print the given level.
// How to print the cousin nodes instead of siblings and how to get the nodes of that level in the queue?
// During the level order, when for the parent node, if parent->left == Node_to_find, or parent->right == Node_to_find, then the children of this parent must not be pushed into the queue (as one is the node and other will be its sibling). Push the remaining nodes at the same level in the queue and then exit the loop. The current queue will have the nodes at the next level (the level of the node being searched, except the node and its sibling). Now, print the queue.
// This is a single level order traversal, hence time complexity = O(N), and Auxiliary space = O(N)



//Solutions Approach :- (Using level order traversal) :- BFS
class Solution{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find){
        queue<Node *>q;
        q.push(root);

        int flag=1;   //to find the current level of node whose cousion is to be found
        while(!q.empty()){  
        	int sz=q.size();  //size of current level

        	while(sz--){
        		Node* curr=q.front();
        		q.pop();

        		if(curr->left==node_to_find or curr->right==node_to_find){
        			flag=0;
        		}
        		else{
        			if(curr->left){
        				q.push(curr->left);
        			}
        			if(curr->right){
        				q.push(curr->right);
        			}
        		}
        	}
        	if(flag==0){
        		break;
        	}
        }

        vector<int>v;
        if(q.size()>0){
        	while(!q.empty()){
        		Node *curr=q.front();
        		v.push_back(curr->data);
        		q.pop();
        	}
        	return v;
        }
        else{
        	v.push_back(-1);
        	return v;
        }
    }
};


//Second Solution :- Recursive
int getLevel(Node *root, Node *node, int level){
	if (root == NULL){   // base cases
		return 0;
	}
	if (root == node){
		return level;
	}

	int downlevel = getLevel(root->left,node, level + 1);      // If node is present in left subtree
	if (downlevel != 0){
		return downlevel;
	}
	return getLevel(root->right, node, level + 1);     // If node is not present in left subtree
}

void printGivenLevel(Node* root, Node *node, int level){
	if (root == NULL || level < 2){  // Base cases
		return;
	}

	if(level == 2){
		if (root->left == node || root->right == node){       // If current node is parent of a node with given level
			return;
        }
		if (root->left){
			cout << root->left->data << " ";
        }
		if (root->right){
			cout << root->right->data;
        }
	}	
	else if (level > 2){                       // Recur for left and right subtrees
		printGivenLevel(root->left, node, level - 1);
		printGivenLevel(root->right, node, level - 1);
	}
}

void printCousins(Node *root, Node *node){
	int level = getLevel(root, node, 1);    // Get level of given node
	printGivenLevel(root, node, level);    // Print nodes of given level.
}



//First Solution :-






//Third Solution :- 


