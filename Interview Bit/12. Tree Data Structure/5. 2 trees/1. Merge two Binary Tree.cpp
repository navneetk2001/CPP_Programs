Given two Binary Trees A and B, you need to merge them in a single binary tree.
The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.
Otherwise, the non-null node will be used as the node of new tree.

Input 1:
 A =   2
      / \
     1   4
    /
   5

B =   3
      / \
      6  1
      \   \
       2   7

Output 1:
     5
    / \
   7   5
  / \   \ 
 5   2   7       


//Hint :-
Traverse the tree in Preorder fashion and keep forming the new tree.
You can also for an iterative version of pre-order traversal using stacks.

//Solution Approach :- 
Recursive Algorithm:
	Traverse the tree in Preorder fashion
	Check if both the tree nodes are NULL
	If not, then update the value
	Recur for left subtrees
	Recur for right subtrees
	Return root of updated Tree
Complexity Analysis:
Time complexity : O(n) :- A total of n nodes need to be traversed. Here, n represents the minimum number of nodes from the two given trees.
Auxiliary Space : O(n) :- The depth of the recursion tree can go upto n in case of a skewed tree. In average case, depth will be O(logn).

Iterative Algorithm:
Create a stack
Push the root nodes of both the trees onto the stack.
While the stack is not empty, perform following steps :
Pop a node pair from the top of the stack
For every node pair removed, add the values corresponding to the two nodes and update the value of the corresponding node in the first tree
If the left child of the first tree exists, push the left child(pair) of both the trees onto the stack.
If the left child of the first tree doesn’t exist, append the left child of the second tree to the current node of the first tree
Do same for right child pair as well.
If both the current nodes are NULL, continue with popping the next nodes from the stack.
Return root of updated Tree

Complexity Analysis:
Time complexity : O(n) :- A total of n nodes need to be traversed. Here, n represents the minimum number of nodes from the two given trees.
Auxiliary Space : O(n) :-The depth of the stack can go upto n in case of a skewed tree.


//First Solution :-
TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2) {
    if(!root1){
        return root2;
    }
    if(!root2){
        return root1;
    }
    root1->val+=root2->val;
    root1->left=solve(root1->left,root2->left);
    root1->right=solve(root1->right,root2->right);
    return root1;
}

//Second Solution :- Iterative :- BFS Solution 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        if(root1==NULL && root2 ==NULL) return NULL;
        
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root1,root2});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            /* if the right subtree is not null or the root of the right sub-tree (either left or right isnt null)
               then we will process further */ 
            
            if(temp.second!=NULL){
                temp.first->val += temp.second->val;
            
            
            /* if the left node of the first subtree is null we can just point the left node of second tree to the
               left node of the first subtree */ 
            
            if(temp.first->left == NULL){
                temp.first->left = temp.second->left;
            }
            else{
                q.push({temp.first->left,temp.second->left});
            }
            
             /* if the right node of the first subtree is null we can just point the right node of second tree to the
               right node of the first subtree */ 
            
            if(temp.first->right == NULL){
                temp.first->right = temp.second->right;
            }
            else{
                q.push({temp.first->right,temp.second->right});
            }
            }
        }
        return root1;
    }
};


//Third Solution :- 
class Solution {
public:
    TreeNode* merge(TreeNode* t1, TreeNode* t2){
      
        // if both null return 0
        if(t1==NULL && t2==NULL)  return 0; 
      
        // if one is null return another
        if(t1==NULL && t2!=NULL)  return t2; 
        if(t1!=NULL && t2==NULL)  return t1;
      
        // else make a node sumnode == t1 + t2
        TreeNode* sumnode = new TreeNode (t1-> val + t2-> val);
        // recursively call the left-subtree and right-subtree of the sumnode
        sumnode->left = merge (t1->left, t2->left);
        sumnode->right = merge (t1->right, t2->right);
        
        // return the sum node
        return sumnode;
      
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1,t2);
    }
};


//Fourth Solution :- 
/*
Start travese from root->left->right
It should be the depth first searching
use stack to store pairs: left, rigth pair
pop the stack and merge to the Tree node 1
switch the branch
*/
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	if (root1 == nullptr && root2 == nullptr)
	return nullptr;

	if (root1 == nullptr || root2 == nullptr)
		return root1 ? root1 : root2;

	 stack<pair<TreeNode*, TreeNode*>> nodes;
	 nodes.push(make_pair(root1, root2));
	 while (!nodes.empty())
	 {
		auto current = nodes.top();
		nodes.pop();
		if (current.first == nullptr || current.second == nullptr)
			continue;

		//Root nodes
		 current.first->val += current.second->val;

		//Left nodes
		 if (!current.first->left)
			current.first->left = current.second->left;
	   	 else
			nodes.push(make_pair(current.first->left, current.second->left));
		 
	     //Right nodes
		 if (!current.first->right)
			current.first->right = current.second->right;
		  else
			nodes.push(make_pair(current.first->right, current.second->right));
	}
	return root1;
}