Given a binary tree A, invert the binary tree and return it. 
Inverting refers to making left child as the right child and vice versa.

Input 2:
     1
   /   \
  2     3
 / \   / \
4   5 6   7

Output 2:
     1
   /   \
  3     2
 / \   / \
7   6 5   4

//Solution Approach :- 
Think recursively.
On every node, you need to invert the left and right subtree and then swap them.

//First Solution :-
TreeNode* Solution::invertTree(TreeNode* A) {
    if(!A)
        return A;
    
    invertTree(A->left);
    invertTree(A->right);
    
    //Swap the child pointers
    TreeNode *temp;
    temp = A->left;
    A->left = A->right;
    A->right = temp;

    return A;
}


//Second Solution :-
TreeNode* Solution::invertTree(TreeNode* root) {
    if(root == NULL)
        return root;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    root->left = invertTree(r);
    root->right = invertTree(l);
    return root;
}


//Third Solution :-  Iterative
TreeNode* Solution::invertTree(TreeNode* root) {
    if(root==NULL) return NULL;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        swap(curr->left,curr->right);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return root;
}


