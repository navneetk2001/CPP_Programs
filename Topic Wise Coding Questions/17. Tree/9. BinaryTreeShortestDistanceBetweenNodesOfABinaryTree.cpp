


//Shortest Distace between 2 nodes a and b of a Binary Tree

//Approach :-
//calculate level of a (L1)
//calculate level of b (L2)
//calculate level of LCA of a & b (L3)

//Required dist :- L1+L2-2(L3) 


//Another Approach :-
//calculate level of a from LCA of a & b (p1)
//calculate level of b from LCA of a & b (p2)

//Required dist :- p1+p2

//finding the level of a given node from the root node/any given node
int search(Node* root, int key, int level){
	if(root==NULL){
		return -1;
	}

	if(root->data==key){
		return level;
	}

	int left=search(root->left,key,level+1);
	if(left!=-1){
		return left;
	}
	return search(root->right,key,level+1);
}



//function to find the distace b/w 2 nodes
int findDistance(node *root, int a, int b){
	node *lca_node=lca(root,a,b);

	int l1=search(lca_node,a,0);
	int l2=search(lca_node,b,0);

	return l1+l2;
}