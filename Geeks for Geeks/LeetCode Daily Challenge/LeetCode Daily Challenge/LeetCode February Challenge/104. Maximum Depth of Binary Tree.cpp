// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2




//Solution :- Recursive 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
};


//Solution :- Iterative 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)    // Return depth as '0' if the root is NULL.
			return 0;
        queue<TreeNode *> q;    // Queue for BFS
        int ans = 0, s;
        TreeNode * temp;
        q.push(root);
        while(!q.empty()) {
            ans++;    // Increment depth at every level.
            s = q.size();    // 's' is the size of the current level. We will process these many nodes.
            for(int i = 0; i < s; i++) {
                temp = q.front();
                q.pop();
				// Only add non-NULL nodes into the queue.
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};