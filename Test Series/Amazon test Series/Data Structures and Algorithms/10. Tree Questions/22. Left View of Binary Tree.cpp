https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1




//Solution Approach :-
void solve(Node* root,vector<int> &ans,int level){
     if(root==NULL){     //base case
        return;
     }
        
    //we entered into a new level
    if(level==ans.size()){
        ans.push_back(root->data);
    }
        
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
    
vector<int> leftView(Node *root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}



//Second Solution :-
vector<int> leftView(Node *root){
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
            
            if(i==0){   //push first element of each level
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



//Third Solution :-
vector<int> leftView(Node *root)
{
   	vector<int>ans;
   	if(!root) return ans;
   	queue<Node*>q;
   	q.push(root);
   
   	while(!q.empty()){
       	int sz = q.size();
       	ans.push_back(q.front()->data);
    	
    	while(sz--){
      		Node* temp= q.front();
      		q.pop();
      
      		if(temp->left) q.push(temp->left);
      		if(temp->right) q.push(temp->right);
    	}
   	}
    return ans;
}



//Fourth Solution :-
void rec(Node* root, vector<int>&ans, int &mx, int curr){
	if(root==NULL){
		return;
	}
	if(curr>mx){
		mx=curr;
		ans.push_back(root->data);
	}
	rec(root->left,ans,mx,curr+1);
	rec(root->right,ans,mx,curr+1);
}

vector<int> leftView(Node* root){
	vector<int> ans;
	int mx = 0;
	rec(root, ans, mx, 1);
	return ans;
}
