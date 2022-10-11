https://practice.geeksforgeeks.org/problems/level-order-traversal-line-by-line/1



//Solution Approach :-
vector<vector<int>> levelOrder(Node* node){
 	vector<vector<int>> v;
 	if(node==NULL){
 		return v;
 	}
 	queue<Node*>q;
 	q.push(node);

 	while(!q.empty()){
     	vector<int> level;
     	int h = q.size();
     	
     	for(int i=1;i<=h;i++){
         	Node*temp=q.front();
         	q.pop();

         	level.push_back(temp->data);
         	if(temp->left){
	            q.push(temp->left);
         	}
         	if(temp->right){
             	q.push(temp->right);
         	}
     	}
     	v.push_back(level);
 	}
 	return v;
}



	