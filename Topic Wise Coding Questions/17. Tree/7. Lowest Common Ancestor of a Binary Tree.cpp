

//assuption both a and b are present in the tree, all keys are unique
node *lca(node *root, int a, int b){
	if(root==NULL){
		return NULL;
	}
	if(root->data==a or root->data==b){
		return root;
	}

	//search in left and right subtrees
	node *leftans = lca(root->left,a,b);
	node *rightans = lca(root->right,a,b);

	if(leftans!=NULL && rightans!=NULL){
		return root;
	}
	if(leftans!=NULL){
		return leftans;
	}
	return rightans;
}