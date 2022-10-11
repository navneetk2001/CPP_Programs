https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1



class Solution{
  public:
    /*You are required to complete this method*/
    int minDepth(Node *root) {
        if(root == NULL){
        	return INT_MAX;
        }
        if(root -> right == NULL && root -> left == NULL){
            return 1;
        }
        
        int lh = minDepth(root -> left);
        int rh = minDepth(root -> right);
        
        return 1 + min(lh, rh);
    }
};



//Second Solution :-
class Solution{
public:
   	int minDepth(Node *root) {
       	if(!root){
           	return 0;
       	}
       	
       	queue<Node *> q;
       	q.push(root);
       	
       	int level=0;
       	while(!q.empty()){
           	int S=q.size();
           	level++;
           	while(S--){
               	Node *temp=q.front();
               	q.pop();
               	if(temp->left==NULL && temp->right ==NULL){
                   	return level;
               	}
               	if(temp->left){
                   q.push(temp->left);
               	}
               	if(temp->right){
                   	q.push(temp->right);
               	}
           	}
       	}
       	return level;
   	}
};




//Third Solution :-
int minDepth(Node *root) {
   	vector<int>v;
   	if(root==NULL){
       	return 0;
   	}
   	int level=0;
   	queue<Node*>q;
   	q.push(root);
   	
   	while(!q.empty()){
       	int n=q.size();
       	level++;

       	for(int i=1;i<=n;i++){
           	Node*temp=q.front();
           	q.pop();
           	
           	if(temp->left){
               	q.push(temp->left);
           	}
           	if(temp->right){
               	q.push(temp->right);
           	}
           	if(temp->left==NULL and temp->right==NULL){
               v.push_back(level);
           	}
       	}
   	}
   	sort(v.begin(),v.end());
   	return v[0];
}

