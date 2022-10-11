https://practice.geeksforgeeks.org/problems/height-of-spiral-tree/1



//Solution Approach :-
// Concept:- 1)here we have to identify speacial property of a DLL,ie...
//             a)The right child of the left child of the current node is the node itself.
//             b)The left child of the right child of the current node is the node itself.
//           2)So,to identify the leaves,we will check the one of the following conditions

int findTreeHeight(Node* root){
	if(root==NULL){
		return 0;
	}
	if(root->right && root == root->right->left){
		return 1;
	}
	if(root->left && root == root->left->right){
		return 1;
	}
	return 1 + max(findTreeHeight(root->left),findTreeHeight(root->right));
}

