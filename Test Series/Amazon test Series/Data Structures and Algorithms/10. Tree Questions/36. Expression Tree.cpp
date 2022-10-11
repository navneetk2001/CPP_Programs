https://practice.geeksforgeeks.org/problems/expression-tree/1



//Solution Approach :-
int evalTree(node* root) {
   	if(root==NULL){
   		return 0;
   	}
   	if(root->left == NULL and root->right == NULL){
   		return stoi(root->data);
   	}
   	
   	int lh=evalTree(root->left);
   	int rh=evalTree(root->right);
   	
   	if(root->data=="+"){
   		return lh + rh;
   	}
   	if(root->data=="-"){
   		return lh - rh;
   	}
   	if(root->data=="*"){
   		return lh * rh;
   	}
   	if(root->data=="/"){
   		return lh / rh;
   	}
}



//Second Solution :-
int evalTree(node* root) {
    if(root==NULL){
        return 0;
    }
    int l = evalTree(root->left);
    int r = evalTree(root->right);
    
    if(root->data=="*")     return l*r;
    else if(root->data=="+")return l+r;
    else if(root->data=="/")return l/r;
    else if(root->data=="-")return l-r;
    else return stoi(root->data);
}


