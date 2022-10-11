// Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.
// Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.

// Input 1:
//         1
//       /   \
//      2    3
//     / \  / \
//    4   5 6  7
//   /
//  8 

// Output 1: [1, 3, 7, 8]

// Input 2:
//     1
//    /  \
//   2    3
//    \
//     4
//      \
//       5

// Output 2: [1, 3, 4, 5]


//Solution Approach :- 
// For each level whenever you encounters the last node on that level append it to the answer.
// try to Modify the level order traversal of tree for this problem.


//First Solution :- Recursive
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res){
        if(root==NULL){ 
        	return ;
        }

        if(res.size()==level){ 
        	res.push_back(root->val);
        }

        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};


//Second Solution :- Recursive
void rightViewUtil(TreeNode *root, int level, int *max_level, vector<int>&ans){
    if (root == NULL){         // Base Case
        return;
    }
 
    if (*max_level < level){         // If this is the last Node of its level
        ans.push_back(root->val);
        *max_level = level;
    }
 
    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level + 1, max_level,ans);
    rightViewUtil(root->left, level + 1, max_level,ans);
}

vector<int> Solution::solve(TreeNode* root) {
    vector<int>ans;
    if (root == NULL){
        return ans;
    }
    int max_level = 0;
    rightViewUtil(root, 1, &max_level,ans);
    return ans;
}




//Third Method :-  Iterative
vector<int> Solution::solve(TreeNode* root) {
    vector<int>ans;
    if (root == NULL){
        return ans;
    }
 
    queue<TreeNode*> q;
    q.push(root);
 
    while (!q.empty()) {
        int n = q.size();        // get number of nodes for each level
 
        while (n--){             // traverse all the nodes of the current level
            TreeNode* x = q.front();
            q.pop();
 
            if (n == 0) { 
                ans.push_back(x->val);        // print the last node of each level
            }
            
            if (x->left){
                q.push(x->left);      // if left child is not null push it into the queue
            }
            if (x->right){
                q.push(x->right);    // if right child is not null push it into the queue
            }
        }
    }
    return ans;
}
