https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1




//Solution Approach :-
int findCeil(Node* root, int x) {
   	if(root == NULL) return -1;
	int res=-1;
   	
   	while(root){
       	if(root->data == x){
       		return x;
       	}
       	else if(root->data < x){
       		root = root->right;
       	}
       	else{
           	res = root->data;
           	root = root->left;
       	}
   	}
   	return res;
}



//Second Solution :- Simple inorder trversel
void inorder(Node* root,int key, int &prev){
   	if(root==NULL){
   		return;
   	}
	inorder(root->left, key, prev);
	if(root->data>=key && root->data < prev){
		prev = root->data; 
	}
	inorder(root->right, key, prev);
}

 

int findCeil(Node* root, int input) {
   	if(root == NULL){
   		return -1;
   	}

   	int prev = INT_MAX;
   	inorder(root, input, prev);
   
   	return prev;
}



//Third Solution :-
int findCeil(Node* root, int input) {
    if(!root) return 0;
    if(input <= root->data){
        int t=findCeil(root->left,input);
        return (t)? t:root->data;
    }
    int t=findCeil(root->right,input);
    return (t)? t:0;
}