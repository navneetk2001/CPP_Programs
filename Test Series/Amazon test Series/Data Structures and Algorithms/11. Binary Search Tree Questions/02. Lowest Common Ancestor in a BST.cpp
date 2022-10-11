https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1




//Solution Approach :-
Node* LCA(Node *root, int n1, int n2)
{
   	Node* temp; 
   	if(n1 > root->data && n2 > root->data){
       	temp = LCA(root->right,n1,n2);
   	}
   	else if(n1 < root->data && n2 < root->data){
       	temp = LCA(root->left,n1,n2);
   	}
   	else{
       	temp = root;
   	}
   	return temp;
}



//Second Solution :-
Node* LCA(Node *root, int n1, int n2)
{
   	while(1)
   	{
		int value=root->data;
		if(value == n1 || value == n2){
		    return root;
		}
		if(n1 < value && n2 < value){
		    root=root->left;
		}
		else if(n1 > value && n2 > value){
		    root=root->right;
		}
		else{
		    return root;
		}
   	}
}



//Third Solution :-
Node *ans;
Node *solve(Node *root,int n1,int n2){
    if(!root){
    	return root;
    }
    
    if(root->data>=n1 && root->data<=n2){
    	return root;
    }
    
    if(root->data<n1){     //both n1 and n2 are in right side
      	return solve(root->right,n1,n2);
    }
    
  	//root-data>n2 ,both are in left side 
    return solve(root->left,n1,n2);
   
}

Node* LCA(Node *root, int n1, int n2)
{
    if(n1>n2){
    	swap(n1,n2);
    }
   	return solve(root,n1,n2);
}
