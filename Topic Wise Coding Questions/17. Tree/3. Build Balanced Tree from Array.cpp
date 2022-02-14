
//Build Tree from Array :- Which will be height balanced

node* bulidTreeFromArray(int *a, int s, int e){
	//Base case
	if(s>e){
		return NULL;
	}

	//Recursive Case
	int mid=(s+e)/2;
	node* root=new node(a[mid]);
	node->left=bulidTreeFromArray(a,s,mid-1);
	node->right=bulidTreeFromArray(a,mid+1,e);
	return root;
}