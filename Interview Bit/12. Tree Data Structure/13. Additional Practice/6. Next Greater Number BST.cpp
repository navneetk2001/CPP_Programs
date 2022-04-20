// Given a BST node, return the node which has value just greater than the given node.

// Example:
// Given the tree

//                100
//               /   \
//             98    102
//            /  \
//          96    99
//           \
//            97
// Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
// If there are no successor in the tree ( the value is the largest in the tree, return NULL).
// Using recursion is not allowed.
// Assume that the value is always present in the tree.


//Solution Approach :- 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* ans=NULL;
    TreeNode* curr=A;
    
    while(curr!=NULL){
        if(B>curr->val){
            curr=curr->right;
        }
        else if(B==curr->val){
            curr=curr->right;
        }
        else{
            if(ans==NULL || ans->val>curr->val){
                ans=curr;
            }
            curr=curr->left;
        }
    }
    return ans;
}


//Second Solution :- 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode *t=A,*ans=NULL;
    while(t!=NULL){
        //cout<<t->val<<endl;
        if(t->val<=B){
            t=t->right;
        }else{
            ans=t;
            t=t->left;
        }
    }
    return ans;
}


// Solution ::- Using Recursion
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    
    if(A==NULL) return NULL;
   
    if(A->val<=B){ 
    	return getSuccessor(A->right,B);
    }

    if(A->val>B){
        if(getSuccessor(A->left,B))
        {
            TreeNode* temp = getSuccessor(A->left,B);
	        if(temp->val > A->val){ 
	        	return A;
	        }
	        else{ 
	        	return temp;
	        }
        }
        return A;
    }
}



// Another Solution 
TreeNode* FindMin(TreeNode *root){
    if(root == NULL) return NULL;
    while(root->left != NULL) 
    	root = root->left;
    return root;
}

TreeNode* Find(TreeNode *root, int B){
    while(root != NULL){
        if(root->val == B) 
        	return root;
        
        if(B > root->val) 
        	root = root->right;
        else 
        	root = root->left;
    }
    return NULL;
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // if node has right subtree, go deep leftmost of right subT (min of right subT)
    // when no right subtree -> go to nearest ancestor for which gn node is in left subT
    
    TreeNode *curr = Find(A, B); // first find the node in question
    if(curr == NULL) return NULL;
    // if currnode has right subtree
    if(curr->right != NULL) return FindMin(curr->right);
    // if no right subtree
    else {
        TreeNode *successor = NULL;
        TreeNode *ancestor = A;
        while(ancestor != curr){
            if(curr->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }
        return successor;
        
    }
    
    
    
}