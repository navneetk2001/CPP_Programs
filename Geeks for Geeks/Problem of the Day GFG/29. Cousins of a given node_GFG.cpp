Given a binary tree and a node, print all cousins of given node in order of their appearance. Note that siblings should not be printed.

Example 1:
Input : 
             1
           /   \
          2     3
        /   \  /  \
       4    5  6   7

Given node : 5
Output : 6 7
Explanation :
Nodes 6 and 7 are on the same level 
as 5 and have different parents.

Given node : 7
Output : 4 5


Example 2 :
Input :
         9
        /
       5
Given node : 5
Output : -1
Explanation :
There no other nodes than 5 in the same level.


//cousins are nodes that are on the same level but they belong to a different parents

//Solutions Approach :- (Using level order traversal) :- BFS
class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
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





// C++ program to print cousins of a node :- Recursive 

/* It returns level of the node if it is
present in tree, otherwise returns 0.*/
int getLevel(Node *root, Node *node, int level)
{
	
	// base cases
	if (root == NULL)
		return 0;
	if (root == node)
		return level;

	// If node is present in left subtree
	int downlevel = getLevel(root->left,
							node, level + 1);
	if (downlevel != 0)
		return downlevel;

	// If node is not present in left subtree
	return getLevel(root->right, node, level + 1);
}

/* Print nodes at a given level such that
sibling of node is not printed if it exists */
void printGivenLevel(Node* root, Node *node, int level)
{
	// Base cases
	if (root == NULL || level < 2)
		return;

	// If current node is parent of a node
	// with given level
	if (level == 2)
	{
		if (root->left == node || root->right == node)
			return;
		if (root->left)
			cout << root->left->data << " ";
		if (root->right)
			cout << root->right->data;
	}

	// Recur for left and right subtrees
	else if (level > 2)
	{
		printGivenLevel(root->left, node, level - 1);
		printGivenLevel(root->right, node, level - 1);
	}
}

// This function prints cousins of a given node
void printCousins(Node *root, Node *node)
{
	// Get level of given node
	int level = getLevel(root, node, 1);

	// Print nodes of given level.
	printGivenLevel(root, node, level);
}

