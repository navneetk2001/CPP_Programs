https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1




//Solution Approach :-
int minVal(Node* root){    //it will give smallest value on right side
    while(root->left){
        root=root->left;
    }
    return root->data;
}

Node *deleteNode(Node *root, int X) {
    if(root==NULL){
        return NULL;
    }
    
    if(root->data > X){      //if data to be deleted is smaller than root
        root->left=deleteNode(root->left,X);
    }
    else if(root->data < X){  //if data to be deleted is greater than root
        root->right=deleteNode(root->right,X);
    }
    else{                     //if it is equal to the value to be deleted itself
        if(root->left==NULL){     //if its left does not exist then return right
            return root->right;
        }
        else if(root->right==NULL){     //if its right does not exist then return its left
            return root->left;
        }
        // if both its child exists
        int min_value_on_right = minVal(root->right);    //then find the smallest value on right side
        root->data = min_value_on_right; 
        root->right = deleteNode(root->right,root->data);   //And now delete the value of curr->root
    }
  
    return root;
}



//Second SOlution :-
Node *deleteNode(Node *root, int X) {
	Node*temp=NULL;
	Node*curr=root;
	while(curr!=NULL)
	{
		if(curr->data==X){
		   temp=curr;
		   break;
		}
		else if(curr->data>X){
			curr=curr->left;
		}
		else{
			curr=curr->right;
		}
	}

   	if(temp==NULL){
   		return root;
   	}

	Node*pre=NULL;
	curr=root;
   	while(curr!=NULL)
   	{
       	if(curr->data<=X)
       	{
          	if(curr->right)
          	{
              	pre=curr;
              	curr=curr->right;
          	}
          	else
          		break;
       	}
       	else
       	{
           	if(curr->left)
           	{
               	pre=curr;
               	curr=curr->left;
           	}
           	else{
           		break;
           	}
       	}
   	}
   	if(pre==NULL){
   		return NULL;
   	}
   	swap(curr->data,temp->data);
   	if(pre->right==curr){
   		pre->right=NULL;
   	}
   	else{
   		pre->left=NULL;
   	}
   	return root;
}




//Third Solution :-
Node* findRight(Node* root)
{
    if(root->right ==NULL)
    {
         return root;        
    }
    return findRight(root->right);
}

Node* helper(Node* root)
{
    if(root->left == NULL)
    {
        return root->right;
    }
   if(root->left == NULL)
    {
        return root->right;
    }
    Node* rightChild = root->right;
    Node* lastChild  = findRight(root->left);
    lastChild->right = rightChild;
    return root->left;
}


Node *deleteNode(Node *root, int x) {
    if(root == NULL){
        return NULL;
    }
    if(root->data == x)
        {
            return helper(root);
        }
    Node* curr = root;
    while(root!=NULL)
    {
        if(root->data >x)
        {
            if(root->left!= NULL && root->left->data == x)
            {
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right != NULL && root->right->data == x)
            {
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }
        }
    }
    return curr;
}





//Fourth Solution :-
Node *deleteNode(Node *root, int x) {
    if (!root) {
        return root;
    }
    if (root -> data == x) {
        if (!root -> left && !root -> right) {
            delete root;
            return NULL;
        }
        if (!root -> left && root -> right) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        if (root -> left && !root -> right) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        // If both children are present
        // a. find max in left subtree or min in right subtree
        // b. replace root -> val with that val
        // c. now we have two nodes with same val so continue delete operation in the respective subtree for temp -> val
        if (root -> left && root -> right) {
            Node* temp = root -> left;
            while (temp -> right) {
                temp = temp -> right;
            }
            root -> data = temp -> data;
            root -> left = deleteNode(root -> left, temp -> data);
        }
    } else if (root -> data > x) {
        root -> left = deleteNode(root -> left, x);
    } else {
        root -> right = deleteNode(root -> right, x);
    }
    return root;
}




//Fifth Solution :-
Node* traverse(Node* root,int X){
    if(root==NULL) return NULL;
    if(root->data==X) return root;
    if(X<root->data) return traverse(root->left,X);
    else return traverse(root->right,X);
}
bool isLeaf(Node* root){
    if(root->right==NULL && root->left==NULL) return true;
    return false;
}
bool hasTwoChild(Node* root){
    if(root->right!=NULL && root->left!=NULL) return true;
    return false;
}
bool hasOneChild(Node* root){
    if(root->right==NULL && root->left!=NULL) return true;
    if(root->right!=NULL && root->left==NULL) return true;
    return false;
}
Node* findParent(Node* root,int X){
    if(isLeaf(root)) return NULL;  //has no parent
    
    if(root->left!=NULL && root->left->data==X) return root;  //left child is X
    if(root->right!=NULL && root->right->data==X) return root;   //right child is X
    
    if(X<root->data) return findParent(root->left,X);
    else return findParent(root->right,X);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL) return;
if(root->data > key) {
    suc= root;
    findPreSuc(root->left,pre,suc,key);
} else if(root->data <key) {
    pre= root;
    findPreSuc(root->right,pre,suc,key);
} else {
    findPreSuc(root->left,pre,suc,key);
    findPreSuc(root->right,pre,suc,key);
}
}
Node *deleteNode(Node *root, int X) {
    Node* posX=traverse(root,X);
    if(posX){                                           // if node to be deleted exists
        
        if(isLeaf(posX)){        // if deletion of LEAF NODE 
            Node* temp=findParent(root,X);
            if(temp){
                if(temp->left==posX) temp->left=NULL;
                else temp->right=NULL;
            }
            else{               // when root is all alone only itself
                return NULL;
            }
            return root;
        }
        if(hasTwoChild(posX)){          //deletion of node which has two children
            Node* temp;Node *waste;
            findPreSuc(root,temp,waste,posX->data);          //predecessor
            int store=temp->data;
            deleteNode(root,temp->data);     //recursively delet predecessor  
            posX->data=store;
            return root;
        }
        if(hasOneChild(posX)){
            Node* parent=findParent(root,posX->data);
            if(parent->left==posX){              //posX is left child of parent
                if(posX->left==NULL) parent->left=posX->right;     //last 
                else parent->left=posX->left;
            } 
            else {                               //posX is right child of parent
                if(posX->left==NULL) parent->right=posX->right;
                else parent->right=posX->left;
            }
            return root;
        }
        
    }
    return root;
}