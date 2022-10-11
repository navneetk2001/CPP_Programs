https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1




//Solution Approach :-
vector<int> diagonalSum(Node* root) {
   	vector<int>v;
   	if(!root){
   		return v;
   	}
   
   	queue<Node*>q;
   	q.push(root);

   	while(!q.empty()){
       	int n=q.size();
       	int sum=0;

       	while(n--){
           	Node*temp=q.front();
           	q.pop();
           
           	while(temp){
               sum+=temp->data;
               if(temp->left){
                   q.push(temp->left);
               }
               temp=temp->right;
           	}
       	}
       	v.push_back(sum);
   	}
   	return v;
}




//Second Solution :-
void help(vector<int>&v, Node* root, int start){
    if(root==nullptr){
    	return;
    }
    int dt=root->data;
    if(v.size()+1 == start){
    	v.push_back(dt);
    }
    else if(v.size()>=start){
    	v[start-1]+=dt;
    }
    
    if(root->left!=nullptr){
        help(v,root->left,start+1);
    }
    if(root->right!=nullptr){
        help(v,root->right,start);
    }
}

vector <int> diagonalSum(Node* root){
    vector<int>v;
    help(v,root,1);
    return v;
}



