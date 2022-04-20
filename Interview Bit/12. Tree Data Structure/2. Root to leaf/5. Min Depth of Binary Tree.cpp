// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// NOTE : The path has to end on a leaf node.
// Example :
//          1
//         /
//        2
// min depth = 2.

//Hint :-
Can you traverse the tree while keeping the depth from root to current node?
How can you check if you have reached the leaf or not?

//Solution Approach :- 
You know that a path ends when you reach a leaf ( how do you define a leaf ? ).
All that you need to do is that a particular node, you pick the minimum of the depth of the left and right subtree ?
What do you do when one of the left or right subtree is NULL ?


//First Solution :-
int depth(TreeNode* A){
    if(A->left==NULL && A->right==NULL) 
        return 1;

    int l=INT_MAX, r=INT_MAX;

    if(A->left!=NULL){
        l=depth(A->left)+1;
    }

    if(A->right!=NULL){
        r=depth(A->right)+1;
    }

    return min(l,r);
 }

int Solution::minDepth(TreeNode* A) {
    return depth(A);
}

//Second Solution :-
typedef TreeNode node;
void minh(node *A,int curmn,int &mn){
    if(!A)return ;
    if(!A->left && !A->right){
        mn=min(mn,curmn+1);
        return;
    }
    curmn++;
    minh(A->left,curmn,mn);
    minh(A->right,curmn,mn);
   // mn=min(mn,curmn);
    return ;
}
int Solution::minDepth(TreeNode* A) {
    int mn=INT_MAX;
    minh(A,0,mn);
    return mn;
}



//Third Solution :- 
class Solution {
    public:
        int minDepth(TreeNode *root) {
            // Corner case. Should never be hit unless the code is called on root = NULL
            if (root == NULL) return 0;
            // Base case : Leaf node. This accounts for height = 1.
            if (root->left == NULL && root->right == NULL) return 1;

            if (!root->left) return minDepth(root->right) + 1;
            if (!root->right) return minDepth(root->left) + 1;

            return min(minDepth(root->left), minDepth(root->right)) + 1; 
        }
}

//Fourth Solution :- Iterative
int Solution::minDepth(TreeNode* root) {
	if(!root)
	    return 0;
	    
	queue <TreeNode*> q;
	q.push(root);

	int lvl = 0;
	while(!q.empty())
	{
	    lvl++;
	    int k = q.size();
	    while(k--)
	    {
	        TreeNode* top = q.front();
	        q.pop();
	        
	        if(!top->left && !top->right)
	            return lvl;
	        if(top->left)
	            q.push(top->left);
	        if(top->right)
	            q.push(top->right);
	    }
	}
	return lvl;
}