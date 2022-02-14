int solve(Node* root, int &res){
	if(root==nullptr){
		return 0;
	}

	int l=solve(root->left,res);
	int r=solve(root->right,res);

	int temp=max(l,r)+root->val;
	if(root->left==nullptr && root->right==nullptr){
		temp=max(temp,root->val);
	}
	int ans=max(temp,l+r+root->val);
    res=max(res,ans);
    
    return temp;
}


int main(){
	int res=INT_MIN;
	solve(root,res);
	return res;
}










class Solution {
private:
int res;

int Solve(Node* root) {
    if (root == NULL)
        return 0;

    int l = Solve(root->left);
    int r = Solve(root->right);

    int temp;
    if (root->left && root->right) {
        res = max(res, l + r + root->data);
        temp = root->data + max(l, r);
    }
    else if (root->left)
        temp = root->data + l;
    else if (root->right)
        temp = root->data + r;
    else
        temp = root->data;
}

    return temp;
}

int maxPathSum(Node* root)
{
    // code here
    res = INT_MIN;
    Solve(root);
    return res;
}