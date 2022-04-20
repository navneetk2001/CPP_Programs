Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :
Input : 
   1       1
  / \     / \
 2   3   2   3
Output : 1 or True

//Solution Approach :- 
When are the 2 trees the same ?
When the root values are the same, and left subtree of both trees are same, and right subtree of both trees are the same.
Can you think of very easy recursive solution based on the above fact ?


//First Solution :-
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A && !B) return 1;
    if((!A && B) || (A && !B)) return 0;

    if(A->val!=B->val) return 0;
    
    int left=isSameTree(A->left,B->left);
    int right=isSameTree(A->right,B->right);
    if(left && right){ 
    	return 1;
    }
    else{ 
    	return 0;
    }
}

//Second Solution :- Iterative
bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> queue;
    if(p==NULL || q==NULL) return p==q;
    queue.push(p); queue.push(q);
    while(!queue.empty())  {
        TreeNode* left = queue.front(); queue.pop();
        TreeNode *right = queue.front(); queue.pop();

        if(left==NULL && right==NULL) continue;
        if(left==NULL || right==NULL) return false;
        if(left->val != right->val) return false;

        queue.push(left->left);
        queue.push(right->left);
        queue.push(left->right);
        queue.push(right->right);
    }
    return true;  
}


//Third Solution :- 
class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == NULL && q == NULL) return true;
            if (p == NULL || q == NULL) return false;
            return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); 
        }
};

