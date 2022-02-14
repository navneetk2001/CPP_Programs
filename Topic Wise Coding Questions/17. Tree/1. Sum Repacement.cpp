int replaceSum(node* root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}

	//Recursive Part
	int leftSum=replaceSum(root->left);
	int rightSum=replaceSum(root->right);

	int temp=root->data;
	root->data=leftSum+rightSum;
	return temp+root->data;
}