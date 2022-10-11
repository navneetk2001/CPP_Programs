https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1




//Solution Approach :-
vector<int> rightView(Node *root){
	vector<int> res;
    if(root==NULL){
    	return res;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int n=q.size();

        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            
            if(i==n-1){
            	res.push_back(temp->data);
            }
            
            if(temp->left){
            	q.push(temp->left);
            }
            if(temp->right){
            	q.push(temp->right);
            }
        }
    }
    return res;
}
 


//Second Solution :-
void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}

vector<int> rightView(Node *root){
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}



//Third Solution :-
vector<int> rightView(Node *root){
    vector<int>v;
    if(root==NULL){
      	return v;
    }
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
      	int count=q.size();
      	v.push_back(q.front()->data);
      	
      	while(count--){
            Node *curr=q.front();
            q.pop();
            
            if(curr->right!=NULL){
              	q.push(curr->right);
            }
            if(curr->left!=NULL){
              	q.push(curr->left);
            }
        }
    }
    return v;
}
