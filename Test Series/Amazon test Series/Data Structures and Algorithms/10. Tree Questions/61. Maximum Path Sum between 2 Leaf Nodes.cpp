https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/



//Solution Approach :-
int solve(Node* root, int &ans){
    if (root==NULL){
        return 0;
    }
        
    int l = solve(root->left,ans);
    int r = solve(root->right,ans);
    
    if (root->left!=NULL && root->right!=NULL){
        ans = max(ans, l+r+root->data);
        return max(l+root->data, r+root->data);
    }
    
    if (root->left==NULL && root->right==NULL){
        return root->data;
    }
    
    if (root->right==NULL){
        return root->data + l;
    }
        
    if (root->left==NULL){
        return root->data + r;
    }
}

int maxPathSum(Node* root)
{
    if (root==NULL){
        return 0;
    }
        
    if (root->right==NULL && root->left==NULL){
        return root->data;
    }
        
    int ans = INT_MIN;
    int x = solve(root,ans);
    
    if (root->left == NULL || root->right == NULL){
        return max(ans, x);
    }
    return ans;
}




//Second Solution :-
class Solution {
public:
    int maxSum(Node *node, int &sum)
    {
        if(node == NULL) return 0;
        int leftSum = maxSum(node->left, sum);
        int rightSum = maxSum(node->right, sum);
        if(!node->left && !node->right){
            return node->data;
        }
        if(!node->left){
            return node->data + rightSum;
        }
        if(!node->right){
            return node->data + leftSum;
        }
        sum = max(sum, leftSum + rightSum + node->data);
        return (node->data + max(leftSum, rightSum));
    }

    int maxPathSum(Node* root){
        int sum = INT_MIN;
        int ans = maxSum(root, sum);
        // Here Leaf node is a node which is connected to exactly one different node.
        // If root has only one child the it is also a leaf node
        // hence, will be counted
        if(!root->left || !root->right){
            sum = max(sum, ans);
        }
        return sum;
    }
};
