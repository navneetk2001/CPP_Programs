// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

// Example 1:
// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

// Example 2:
// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23
// Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.



//First Solution :-  Using recursion
int rangeSumBST(TreeNode* root, int low, int high) {
    if(root== NULL)
        return 0;
        
    if(root->val<low){
        return rangeSumBST(root->right,low,high);
    }
        
    if(root->val>high){
        return rangeSumBST(root->left,low,high);
    }
        
    return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
}
    

//Second Solution :-  Using Iteration
int rangeSumBST(TreeNode* root, int low, int high) {
    int rangeSum=0;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        if(node!=NULL){
            if(node->val>=low && node->val<=high) {
                rangeSum+=node->val;
                st.push(node->left);
                st.push(node->right);
            }
            if(node->val < low) {
                st.push(node->right);
            }
            if(node->val > high){
                if(node->left) {
                    st.push(node->left);
                }
            }
        }
    }
    return rangeSum;
}

