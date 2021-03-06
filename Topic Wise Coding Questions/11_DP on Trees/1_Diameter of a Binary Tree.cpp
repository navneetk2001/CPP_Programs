int solve(Node* root, int &res){
	if(root==nullptr){
		return 0;
	}

	int l=solve(root->left,res);
	int r=solve(root->right,res);

	int temp=max(l,r)+1;
	int ans=max(temp,1+l+r);
    res=max(res,ans);
    
    return temp;
}


int main(){
	int res=INT_MIN;
	solve(root,res);
	return res;
}





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res;
public:
    int Solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int l = Solve(root->left);
        int r = Solve(root->right);

        int temp = 1 + max(l, r);
        int ans = max(temp, l + r + 1);
        res = max(res, ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        res = INT_MIN + 1;
        Solve(root);
        return res - 1;
    }
};