// Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
// Example 1:
// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [0]
// Output: [0]




//Solution Approach :-
class Solution {
public:
  	TreeNode * prev = NULL;

    void flatten(TreeNode * root) {
      	if (root == NULL){
      		return;
      	}

      	flatten(root -> right);
      	flatten(root -> left);

      	root -> right = prev;
      	root -> left = NULL;
      	prev = root;
    }
};




//Second Solution :-
class Solution {
public:
   	void flatten(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		stack<TreeNode *> st;
		st.push(root);

		while (!st.empty()) {
			TreeNode * cur = st.top();
			st.pop();

			if (cur -> right != NULL) {
			  	st.push(cur -> right);
			}
			if (cur -> left != NULL) {
			  	st.push(cur -> left);
			}
			if (!st.empty()) {
			  	cur -> right = st.top();
			}
			cur -> left = NULL;
		}
	}
};




//Third Solution :- Iterative Solution
class Solution {
public:
    void flatten(TreeNode *root) {
		TreeNode *now = root;
		
		while (now){
			if(now->left){
                //Find current node's prenode that links to current node's right subtree
				TreeNode *pre = now->left;
				while(pre->right){
					pre = pre->right;
				} 
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};