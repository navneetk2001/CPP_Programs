https://practice.geeksforgeeks.org/problems/children-sum-parent/1




//Solution Approach :-
int isSumProperty(Node *root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->left!=NULL && root->right==NULL){
        if(root->data!=root->left->data){
            return false;
        }
        else{
            return isSumProperty(root->left);
        }
    }
    if(root->right!=NULL && root->left==NULL){
        if(root->data!=root->right->data){
            return false;
        }
        else{
            return isSumProperty(root->right);
        }
    }
    
    int ans1=isSumProperty(root->left);
    int ans2=isSumProperty(root->right);
    return ans1 && ans2 && (root->data==(root->left->data + root->right->data));
}



//Second Solution :-
int isSumProperty(Node *root){
    if(root == NULL){
    	return 1;
    }
    if(root->left == NULL and root->right == NULL){
    	return 1;
    }
    
    int sum = 0;
    if(root->left != NULL){
    	sum += root->left->data;
    }
    
    if(root->right != NULL){
    	sum += root->right->data;
    }
    
    if(sum == root->data && isSumProperty(root->left) == 1 && isSumProperty(root->right)==1){
        return 1;
    }
    else {
        return 0;
    }
}



//Third Solution :-
int isSumProperty(Node *root){
	if(root==NULL)return 0;

	queue<Node*>q;
	q.push(root);

	while(!q.empty()){
	    int h=q.size();
	    for(int i=1;i<=h;i++){
	        Node*temp=q.front();
	        q.pop();

	        if(temp->left){
	            q.push(temp->left);
	        }
	        if(temp->right){
	            q.push(temp->right);
	        }
	        
	        int a=temp->left==NULL?0:temp->left->data;
	        int b=temp->right==NULL?0:temp->right->data;
	        if(a==0 and b==0){
	            continue;
	        }
	        if(temp->data!=a+b){
	            return 0;
	        }
	    }
	}
	return 1;
}