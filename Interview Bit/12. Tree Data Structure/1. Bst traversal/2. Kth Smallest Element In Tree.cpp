// Given a binary search tree, write a function to find the kth smallest element in the tree.
// Example :
// Input : 
//   2
//  / \
// 1   3
// and k = 2
// Return : 2
// As 2 is the second smallest element in the tree.
// NOTE : You may assume 1 <= k <= Total number of nodes in BST

//Hint :-
Think about the property of binary search tree and how it can help you.
Do you really need to visit right subtree of any node before visiting entire left subtree of it?

//Solution Approach :- 
Note the property of the binary search tree.
All elements smaller than root will be in the left subtree, and all elements greater than root will be in the right subtree.
This means we need not even explore the right subtree till we have explored everything in the left subtree. Or in other words, we go to the right subtree only when the size of left subtree + 1 ( root ) < k.

With that in mind, we can come up with an easy recursive solution which is similar to inorder traversal :

Step 1: Find the kth smallest element in left subtree decrementing k for every node visited. If answer is found, return answer.
Step 2: Decrement k by 1. If k == 0 ( this node is the kth node visited ), return node’s value
Step 3: Find the kth smallest element in right subtree


//First Solution :- Inorder-Traversal-Of-Bst-Will-Give-Us-A-Sorted-Array
int k = 0;
void inorder(TreeNode* root,int B,int &ans){
    if(root==NULL){
        return ;
    }
    inorder(root->left,B,ans);
    k++;
    if(k==B){
    	ans = root->val;
    }
    inorder(root->right,B,ans);
     
    return ;
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    k = 0;
    int ans = -1;
    inorder(A,B,ans);
    return ans;
}


//Second Solution :-  //Heap Based Approach
priority_queue<int> p;
void recur(TreeNode* root, int k){
    if(!root) return;

    if(p.size()>k){ 
        p.pop();
    }
    p.push(root->val);
    recur(root->left,k);
    recur(root->right,k);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    while(p.size()!=0){ 
       p.pop();
    }
    
    recur(A,B);
    if(p.size()>B){ 
        p.pop();
    }

    return p.top();
}

//Recursive and Heap Based Simple Solution :- 
void solve(TreeNode* A, int B, priority_queue<int> &max_h){
    if(A==NULL)
    return;
    max_h.push(A->val);
    if(max_h.size()>B)
        max_h.pop();
    solve(A->left,B,max_h);
    solve(A->right,B,max_h);
} 
int Solution::kthsmallest(TreeNode* A, int B) {
    priority_queue<int> max_h;
    solve(A,B,max_h);
    return max_h.top();
}

//Third Solution :- 
int kthsmallestRes(TreeNode *root, int k, int &current) {
    if(root->left != NULL) {
        int res = kthsmallestRes(root->left, k, current);        
        if(current == k)
            return res;
    }
    ++current;
    if(current == k)
        return root->val;

    if(root->right != NULL) {
        int res = kthsmallestRes(root->right, k, current);        
        if(current == k)
            return res;
    }    
} 

int Solution::kthsmallest(TreeNode* root, int k) {
    int level = 0;
    return kthsmallestRes(root, k, level);
    
}

//Fourth Solution :-
void traverse(vector &v,TreeNode* p)
{
	if(p==NULL)
	return;

	traverse(v,p->left);
	v.push_back(p->val);
	traverse(v,p->right);

}
int Solution::kthsmallest(TreeNode* A, int B) {
	vector<int>v;
	traverse(v,A);
	return v[B-1];
}

//Fifth Solution :-
void inorder(TreeNode* A, int b, deque<TreeNode* > &dq)
 {
 if(A==NULL) return;
 
 inorder(A->left,b,dq);
 if(dq.size()<b) dq.push_back(A);
 
 if(dq.size()==b) return;
 else inorder(A->right,b,dq);
 
 }
 
 
int Solution::kthsmallest(TreeNode* A, int B) {
    deque<TreeNode* > dq;
    inorder(A,B,dq);
    return dq.back()->val;
}