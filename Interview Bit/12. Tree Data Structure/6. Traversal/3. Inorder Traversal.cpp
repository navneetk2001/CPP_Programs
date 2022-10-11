Given a binary tree, return the inorder traversal of its nodes values.
NOTE: Using recursion is not allowed.

//Hint :-


//Solution Approach :- 
The algorithm approach can be stated as:
We first take an explicit stack data structure and set an infinite loop.
In every iteration we check whether our current node is pointing to NULL or not.
If it is not pointing to null, we simply push the current value to the stack and move the current node to its left child.
If it is pointing to NULL, we first check whether the stack is empty or not. If the stack is empty, it means that we have traversed the tree and we break out of the loop.
If the stack is not empty, we pop the top value of the stack, print it and move the current node to its right child.


//First Solution :- //Iterative Method
vector<int> Solution::inorderTraversal(TreeNode* curr) {
    vector<int>inOrder;
	stack<TreeNode*> s;

	while (true) {
		if(curr != NULL) {
			s.push(curr);
			curr = curr -> left;
		} 
		else{
			if (s.empty()) break;
			curr = s.top();

			inOrder.push_back(curr->val);
			s.pop();
			curr = curr -> right;
		}
	}
	return inOrder;
}


//Second Solution :- //using recursion
void inOrder(TreeNode *A, vector<int> &res){
	if(!A) 
		return;  

	inOrder(A->left, res);
	res.push_back(A->val);
	inOrder(A->right, res);
}
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    inOrder(A, res);
    return res;
}


//Third Solution :- 


