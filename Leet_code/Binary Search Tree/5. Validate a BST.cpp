// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 
// Example 1:
// Input: root = [2,1,3]
// Output: true

// Example 2:
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.



//Solution :-
class Solution  {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
	}

	bool isValidBSTHelper(TreeNode* root, long min, long max) {
		if (root == NULL) 
			return true;

		if (root->val <= min || root->val >= max) 
			return false;

		return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
	}
};



//Solution :- Inorder Iterative
// Fun Fact: One property of a binary search tree is that an in-order traversal walks over the nodes in order of their keys (thus the name in-order). Data maintained in a binary search tree is sorted by the key.

// Algorithm
// Use in-oder traversal, I have used stacks you can use whatever way you are comfortable with.
// Store in-order sequnece in vector.
// Check vector is sorted and vector should not contain any duplicates.

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if(!root)
        return true; //edge case
        
        vector <int> v;
        stack <TreeNode*> s;
        
        while(true)
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                if(s.empty())
                    break;
                
                root=s.top();
                s.pop();
                v.push_back(root->val);
                root=root->right;
            }
        }
        
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=v[i+1])
                return false;
        }
        
        return true;
    }
};