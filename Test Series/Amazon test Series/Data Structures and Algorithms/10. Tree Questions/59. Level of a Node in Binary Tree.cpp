https://practice.geeksforgeeks.org/problems/level-of-a-node-in-binary-tree/1



//Solution Approach :-
void solve(Node* node,int target,int& ans,int level)
{
   	if(node == NULL){
       return;
   	}
   	if(node->data == target){
       	ans = level;
       	return ;
   	}
   	solve(node->left,target,ans,level+1);
   	solve(node->right,target,ans,level+1);
}

int getLevel(struct Node *node, int target){
	int ans = 0;
	solve(node,target,ans,1);
	return ans;
}



//Second Solution :-
int getLevel(struct Node *node, int target){
	if(node==NULL){
		return 0;
	}

	queue<Node*>q;
	q.push(node);
	int level=0;
	
	while(!q.empty()){
	    int n=q.size();
	    level++;

	    while(n--){
	        Node*temp=q.front();
	        q.pop();
	    
	        if(temp->data==target){
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
	return 0;
}