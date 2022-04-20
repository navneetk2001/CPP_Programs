Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Input 1:
    1
   / \
  2   2
 / \ / \
3  4 4  3

Input 2:
    1
   / \
  2   2
   \   \
   3    3

Output 1: 1
Output 2: 0

2 trees T1 and T2 are symmetric if
1) value of T1’s root is same as T2’s root
2) T1’s left and T2’s right are symmetric.
3) T2’s left and T1’s right are symmetric.

Can you use the above fact to model an easy recursion based solution ?


//First Solution :-
int comparer(TreeNode* A, TreeNode* B){
    if(!A && !B) return 1;
    if(!A || !B) return 0;
    if(A->val != B->val) return 0;
    
    return (comparer(A->left, B->right) && comparer(A->right, B->left));
} 

int Solution::isSymmetric(TreeNode* A) {
    return comparer(A,A);
}


//Second Solution :-
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};


//Third Solution :- 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true; //Tree is empty
        
        return isSymmetricTest(root->left,root->right);
    }
    
    bool isSymmetricTest(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) //left & right node is NULL 
            return true; 
        
        else if(p == NULL || q == NULL) //one of them is Not NULL
            return false; 
        
        else if(p->val!=q->val) 
            return false;
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left); //comparing left subtree's left child with right subtree's right child --AND-- comparing left subtree's right child with right subtree's left child
    }
};

