// Given the root of a binary tree, return the sum of every tree node's tilt.
// The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.

// Example 1:
// Input: root = [1,2,3]
// Output: 1
// Explanation: 
// Tilt of node 2 : |0-0| = 0 (no children)
// Tilt of node 3 : |0-0| = 0 (no children)
// Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
// Sum of every tilt : 0 + 0 + 1 = 1

// Example 2:
// Input: root = [4,2,9,3,5,null,7]
// Output: 15
// Explanation: 
// Tilt of node 3 : |0-0| = 0 (no children)
// Tilt of node 5 : |0-0| = 0 (no children)
// Tilt of node 7 : |0-0| = 0 (no children)
// Tilt of node 2 : |3-5| = 2 (left subtree is just left child, so sum is 3; right subtree is just right child, so sum is 5)
// Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right subtree is just right child, so sum is 7)
// Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree values are 3, 5, and 2, which sums to 10; right subtree values are 9 and 7, which sums to 16)
// Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15

// Example 3:
// Input: root = [21,7,14,1,1,2,2,3,3]
// Output: 9



//Solution Approach :-
int res=0;
int DFS(TreeNode* root){
    if(root==NULL) {
    	return 0;
    }

    int l=DFS(root->left);
    int r=DFS(root->right);
    
    res+=abs(l-r);
    return l+r+root->val;
}

int findTilt(TreeNode* root){
    DFS(root);
    return res;
}
    
  

//Second Solution :-
// Approach:-
// The only thing we need to maintain is subtree sum for every node right? Why?
// Since our answer is the summation of absolute values of the difference between left and right child subtree sum for every node.
// Wait, How do we calculate the subtree sum and sum of tilt's value in one pass(one recursive step)?
// Maintain pair<int, int> for every node where first element of the pair will be the sum of tilt's value for left child subtree and the second element of the pair will be left child subtree sum.
// Now, our answer will be the first element of the pair of the root node obviously.
// Also, The key step is what do we return to the parents of every node?
// return {l.first+r.first+abs(l.second-r.second),l.second+r.second+root->val}
// You can easily observe that first value is the sum of tilt's value of all nodes in the current subtree and the second element is subtree sum of the current node.

class Solution {
public:
    // Time Complexity:- O(n)
    // Space Complexity:- O(1) [neglecting the space due to recursion stack]
    pair<int,int> BinaryTreeTilt(TreeNode* root){
        if(!root){
            return {0,0};
        }

        pair<int,int> l = BinaryTreeTilt(root->left); // {sum of tilt values for left child,left child subtree sum}
        pair<int,int> r = BinaryTreeTilt(root->right); // {sum of tilt values for right child,right child subtree sum}
        return {l.first+r.first+abs(l.second-r.second),l.second+r.second+root->val};
    }
    
    int findTilt(TreeNode* root) {
        return BinaryTreeTilt(root).first; // answer is first element of pair
    }
};



//Third Solution :-
int findTilt_Iterative(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int sumOfTilt = 0;
    map<TreeNode*, int> m; // <node, sum>

    // postorder traversal
    stack<pair<TreeNode*, bool>> stk;
    stk.emplace(root, false);
    while (!stk.empty()) {
        TreeNode* node = stk.top().first;
        if (stk.top().second) {
            stk.pop();

            int lftSum = (node->left ? m[node->left] : 0);
            int rhtSum = (node->right ? m[node->right] : 0);
            m[node] = lftSum + node->val + rhtSum;
            sumOfTilt += abs(lftSum - rhtSum);
        }
        else {
            stk.top().second = true;
            if (node->right) {
                stk.emplace(node->right, false);
            }
            if (node->left) {
                stk.emplace(node->left, false);
            }
        }
    }

    return sumOfTilt;
}

int findTilt(TreeNode* root) {
    return findTilt_Iterative(root);
}

