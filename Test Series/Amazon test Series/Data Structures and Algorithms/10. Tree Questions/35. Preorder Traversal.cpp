https://practice.geeksforgeeks.org/problems/preorder-traversal/1



//Solution Approach :- /************* Iterative Approach ****************/
vector <int> preorder(Node* root){
  	vector<int> vc;
  	stack<Node *> s;
  
  	s.push(root);
  	while(!s.empty()){
      	Node * curr = s.top();
      	vc.push_back(curr->data);
      	s.pop();
      
      	if(curr->right){
          	s.push(curr->right);
      	}
      	if(curr->left){
          	s.push(curr->left);
      	}
  	}
  	return vc;
}



//Second Solution :-
void preor(Node* root, vector<int> &ans){
    if(root==NULL) return;
    
    ans.push_back(root->data);
    preor(root->left,ans);
    preor(root->right,ans);
}

vector <int> preorder(Node* root){
  	vector<int> ans;
  	preor(root,ans);
  	return ans;
}