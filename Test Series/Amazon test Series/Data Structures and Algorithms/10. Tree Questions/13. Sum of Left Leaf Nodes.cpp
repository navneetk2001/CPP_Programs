https://practice.geeksforgeeks.org/problems/sum-of-left-leaf-nodes/1/



//Solution Approach :-
bool isLeaf(Node *node){ 
   	if(node == NULL){ 
       	return false;
    } 
   	if(node->left == NULL && node->right == NULL){
       return true; 
   	}
    return false; 
} 

int leftLeavesSum(Node *root){
   	if(root == NULL){
       	return 0;
   	}
   	int sum = 0;
   	if(isLeaf(root->left)){
   		sum += root->left->data;
   	}
   	sum += leftLeavesSum(root->left);
   	sum += leftLeavesSum(root->right);
   
   	return sum;
}



//Second Solution :-
int leftLeavesSum(Node *root)
{
   queue<Node*> q;
   q.push(root);
   int sum=0;
   while(!q.empty()){
       int n=q.size();
       for(int i=0;i<n;i++){
           Node* cur=q.front();
           q.pop();
           if(cur->left!=NULL && cur->left->left==NULL && cur->left->right==NULL){
               sum+=cur->left->data;
           }
           if(cur->left) q.push(cur->left);
           if(cur->right) q.push(cur->right);
       }
   }
   return sum;
}



//Third Solution :-
int leftLeavesSum(Node *root)
{
   	if(root == NULL){
       	return 0;
   	}
   	int sum = 0;
   	if(root->left && root->left->left == NULL && root->left->right == NULL){
       	sum += root->left->data;
   	}
   	sum += leftLeavesSum(root->left);
   	sum += leftLeavesSum(root->right);
   
   	return sum;
}



//Fourth Solution :-
int leftLeavesSum(Node *root){
   	if(root==NULL){
   		return 0;
   	}
   	if(root->left==NULL and root->right==NULL){
   		return 0;
   	}

   	queue<pair<Node*,int>>q;
   	q.push(make_pair(root,0));
   	int suml=0;
   	
   	while(!q.empty()){
       	int n=q.size();

       	for(int i=1;i<=n;i++){
           	Node* temp = q.front().first;
           	int l = q.front().second;
           	q.pop();

           	if(temp->left==NULL and temp->right==NULL){
               	if(l){
                   	suml+=temp->data;
               	}
           	}
           	if(temp->left){
               	q.push(make_pair(temp->left,1));
           	}
           	if(temp->right){
               	q.push(make_pair(temp->right,0));
           	}
       	}
   	}
   	return suml;
}