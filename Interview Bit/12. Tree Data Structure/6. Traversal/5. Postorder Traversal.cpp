Given a binary tree, return the Postorder traversal of its nodes values.
NOTE: Using recursion is not allowed.

Example Input
Input 1:
   1
    \
     2
    /
   3

Input 2:
   1
  / \
 6   2
    /
   3

Output 1: [3, 2, 1]
Output 2: [6, 3, 2, 1]


//Hint :-
Think stack.
Recursive call would look something like this :

postorderprint(root->left);
postorderprint(root->right);
print(root->val);

Instead of calling the functions, can you put the nodes on a stack and process them ?
Would the solution be easier if you were to print the reverse of the asked ?

//Solution Approach :- 
For each node, we need to process the left first, then right, and then node itself.
We start by putting a node inside the stack.

Now this node at the top of the stack can have a left child, so we don’t process the node yet
–> we first remove the connection with left, and then add the left child to stack.

When we’re at a node that has only the right child (either forcefully, like we did when we removed the left child, or naturally), we know we can’t process the node until we process right child.
–> We first remove the connection with right, and then add the right child to stack. (LEAVING CURRENT NODE WITH NO CHILDREN)
When we’re at a node with no children (i.e. left and right processed, or naturally leaf node), we process the node, i.e. we add it to the array


//First Solution :-
vector<int> Solution::postorderTraversal(TreeNode* A) {
	vector<int> ans;
	if(A==NULL) 
		return ans;

	stack<TreeNode*> st;
	st.push(A);

	while(!st.empty()){
	    TreeNode* topNode = st.top();
	    if(topNode->left){
	        st.push(topNode->left);
	        topNode->left = NULL;
	        continue;
	    }
	    if(topNode->right){
	        st.push(topNode->right);
	        topNode->right = NULL;
	        continue;
	    }
	    ans.push_back(topNode->val);
	    st.pop();
	}

	return ans;
}


//Second Solution :-
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int>ans;

    stack<TreeNode*>st;
    st.push(A);

    while(!st.empty()){   //Iterate till stack is empty
        TreeNode* temp=st.top();
        st.pop();

        ans.push_back(temp->val);

        if(temp->left!=NULL){
        st.push(temp->left);
        }
        
        if(temp->right!=NULL){
        st.push(temp->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//Third Solution :- 
vector<int> Solution::postorderTraversal(TreeNode* A) {
	stack<pair<TreeNode*,int>> s;
	vector<int> v;

	if(A==NULL) 
		return v;

	TreeNode* curr=A->left;
	s.push(make_pair(A,0));
	while(!s.empty()){
	    while(curr){
	        s.push(make_pair(curr,0));
	        curr=curr->left;
	    }
	    pair<TreeNode*,bool> temp = s.top();
	    if(temp.second){
	        s.pop();
	        v.push_back(temp.first->val);
	    }else{
	        s.top().second = true;
	        curr=temp.first->right;
	    }
	}
	return v;
}


//Fourth Solution :- Using recursion 
vector<int>sol;
void helper(TreeNode* A){
	if(A==NULL){
		return;
	}

	helper(A->left);
	helper(A->right);
	sol.push_back(A->val);
}

vector Solution::postorderTraversal(TreeNode* A) {
	sol.clear();
	helper(A);
	return sol;
}
