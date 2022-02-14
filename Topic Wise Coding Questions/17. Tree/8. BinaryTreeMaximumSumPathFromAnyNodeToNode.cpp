

//Binary Tree Maximum Sum Path From Any Node To Node

int solve(Node* root, int &res){
	if(root==nullptr){
		return 0;
	}

	int l=solve(root->left,res);
	int r=solve(root->right,res);

	int temp=max(max(l,r)+root->val, root->val);
	int ans=max(temp,l+r+root->val);
    res=max(res,ans);
    
    return temp;
}