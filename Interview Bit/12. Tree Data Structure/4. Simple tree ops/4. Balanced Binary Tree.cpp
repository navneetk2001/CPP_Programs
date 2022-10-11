// Given a binary tree, determine if it is height-balanced.
// Height-balanced binary tree  : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

// Input : 
//           1
//          / \
//         2   3

// Return : True or 1 

// Input 2 : 
//          3
//         /
//        2
//       /
//      1
// Return : False or 0 
//          Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
//          Difference = 2 > 1.


//Solution Approach :- 
// A tree is balanced if :
// 1) Left subtree is balanced
// 2) Right subtree is balanced
// 3) And the difference is height of left and right subtree is atmost 1.

// Can you think of a way to simulate that with recursion ?
// Note that depth of a tree can also be calculated recursively as max(depth(rightSubtree), depth(leftSubtree)) + 1.


//First Solution :- Naive approach
//Intuition + Approach: 
//For a Balanced Binary Tree, Check left subtree height and right subtree height for every node present in the tree. Hence, traverse the tree recursively and calculate the height of left and right subtree from every node, and whenever the condition of Balanced tree violates, simply return false.
class Solution {
private:
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left,right) + 1;
        
        return ans;
    }

public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs (height(root->left) - height(root->right)) <= 1;
        
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};


//Second Solution :-
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight (root) != -1;
    }

    int dfsHeight(TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight(root -> left);
        if(leftHeight == -1){ 
            return -1;
        }
        
        int rightHeight = dfsHeight(root -> right);
        if(rightHeight == -1){
            return -1;
        }
        
        if(abs(leftHeight - rightHeight) > 1){  
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
};


//Third Solution :- 
// The subtree is balanced if right subtree is balanced, left subtree is balanced 
// and the depth difference is less than 1.
pair<int, bool> isBalancedWithDepth(TreeNode *root) {
    if (root == NULL){ 
    	return make_pair(0, true);
    }

    pair<int, bool> left = isBalancedWithDepth(root->left);
    pair<int, bool> right = isBalancedWithDepth(root->right);
    
    int depth = max(right.first, left.first) + 1;
    bool isbalanced = right.second && left.second && (abs(right.first - left.first) < 2);

    return make_pair(depth, isbalanced);
}

int Solution::isBalanced(TreeNode* root) {
    if (root == NULL){ 
    	return true;
    }
    return isBalancedWithDepth(root).second;
}

