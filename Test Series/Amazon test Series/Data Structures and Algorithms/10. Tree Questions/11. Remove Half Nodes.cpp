https://practice.geeksforgeeks.org/problems/remove-half-nodes/1



//Solution Approach :-
// -> 4 case to take care of
// 1) No child : return root
// 2) Both child : connect left child and right child then retrun root
// 3) No left child: return right child.
// 4) NO right child : return left child.

Node *RemoveHalfNodes(Node *root){
   	if(!root) return NULL;
   
   	root->left = RemoveHalfNodes(root->left);
   	root->right = RemoveHalfNodes(root->right);
   
   	if(!root->left && root->right){
   		return root->right;
   	}
   	if(!root->right && root->left){
   		return root->left;
   	}
   	return root;
}



//Second Solution :-
Node *RemoveHalfNodes(Node *root){
	stack<node*> s;
	Node*temp=root;

	if(root->left && root->right){
		s.push(root);
		while(!s.empty())
		{
			if(root){
				if(!root->right && root->left){
					*(root) = *(root->left);
					continue;
				}
				if(root->right && !root->left){
					*root = *(root->right);
					continue;
				}
				s.push(root);
				root=root->left;
			}
			else
			{
				root=s.top();
				s.pop();
				root=root->right;
			}
		}
	}
	else{
		return NULL;
	}
	return temp;
}


