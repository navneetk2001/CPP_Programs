https://practice.geeksforgeeks.org/problems/leaves-to-dll/1




//Solution Approach :-
Node* tail;
Node* head;

Node* preorder(Node* root){
	if(root==NULL){
		return root;
	}

	if(root->left==NULL && root->right==NULL){  //root is the leaf node
		if(tail==NULL){        //if no element present in Doubly Linked List
			head=root;
			tail=root;
		}
		else{                   //If DLL exist then connect other elements
			tail->right=root;
			root->left=tail;
			tail=root;
		}
		return NULL;     //update the tree by making leaves node as NULL
	}

	root->left=preorder(root->left);
	root->right=preorder(root->right);
	return root;
}

// return the head of the DLL and remove those node from the tree as well.
Node* convertToDLL(Node* root){
	tail=NULL;
	head=NULL;
	preorder(root);
	return head;
}





//Second Solution :-
Node* convert(Node* root,vector<Node*> &leafs){
    if(root == NULL){
        return NULL;
    }
    
    if(root->left == NULL && root->right == NULL){   //if leaf node
        leafs.push_back(root);     //store it in vector
        return NULL;               //and return null so that it is removed from original tree
    }
    
    root->left = convert(root->left,leafs);     //traverse for left
    root->right = convert(root->right,leafs);   //traverse rigth
    
    return root;
}

Node * convertToDLL(Node *root){
    vector<Node*> leafs;          //store leaf node 
    root = convert(root,leafs);   //function to store leaf node
    
    Node* prev = NULL;
    
    for(int i=0;i<leafs.size()-1;i++){
        Node* temp = leafs[i];
        temp->left = prev;
        prev = temp;
        temp->right = leafs[i+1];
    }
    
    Node* temp = leafs[leafs.size()-1];
    temp->left = prev;
    temp->right = NULL;
    
    return leafs[0];
}



//Third Solution :-
Node*solve(Node*root,Node*&curr,Node*&ans){
   	if(root==NULL)return NULL;
   	if(root->left==NULL and root->right==NULL){
       if(ans==NULL){
           ans=new Node(root->data);
           curr=ans;
       }
       else{
           curr->right=new Node(root->data);
           curr->right->left=curr;
           curr=curr->right;
       }
       return NULL;
   	}
   	
   	root->left=solve(root->left,curr,ans);
   	root->right=solve(root->right,curr,ans);
   	return root;
}

Node * convertToDLL(Node *root){
	if(root==NULL)return NULL;
	Node*ans=NULL;
	Node*curr=NULL;
	solve(root,curr,ans);
	return ans;
}



//Fourth Solution :-
Node * convertToDLL(Node *root){
    if(!(root->left) and !(root->right)){
        return root;
    }
    
    Node *Head = nullptr;
    
    if(root->left){
        Head = convertToDLL(root->left);
        
        if(Head == root->left){
        	root->left = nullptr;
        }
    }
        
    if(root->right){
        Node *temp = convertToDLL(root->right);
        
        if(temp == root->right){
        	root->right = nullptr;
        }
        
        if(!Head){
        	Head = temp;
        }
        else{
            Node *last = Head;
    
            while(last->right){
                last = last->right;
            }
                
            last->right = temp;
            temp->left = last;
        }
    }
    return Head;
}