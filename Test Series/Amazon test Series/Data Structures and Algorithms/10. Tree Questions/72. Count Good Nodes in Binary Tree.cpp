https://leetcode.com/problems/count-good-nodes-in-binary-tree/



//Solution Approach :-
// logic :
// preorder traverse the tree
// for every recurson call apart from the parent node also pass the maximum value seen so far
// if the current node value is greater or equal to maximum seen till now then increase count and update that maximum

class Solution {
public:

    int ans=0;
    void pre(TreeNode* root,int max){
        if(!root)return;
        if(root->val >= max){ 
        	ans++; 
        	max=root->val; 
        }
        pre(root->left,max);
        pre(root->right,max);
    }

    int goodNodes(TreeNode* root) {
        pre(root,INT_MIN);
        return ans;
    }
};



//Second Solution :-
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 1;
        queue<pair<TreeNode*, int>> qu;
        qu.push({root, root->val});
        
        while(!qu.empty()) {
            TreeNode* front = qu.front().first;
            int maxval = qu.front().second;
            qu.pop();

            if(front->left != NULL) {
                if(front->left->val >= maxval) {
                    count++;
                    qu.push({front->left, front->left->val});
                }
                else{
                    qu.push({front->left, maxval});
                }
            }

            if(front->right != NULL) {
                if(front->right->val >= maxval) {
                    count++;
                    qu.push({front->right, front->right->val});
                }
                else{
                    qu.push({front->right, maxval});
                }
            }            
        }
        return count;
    }
};