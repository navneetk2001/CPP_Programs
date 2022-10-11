https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1




//Solution Approach :-
vector<int> diagonal(Node *root)
{
   vector<int>ans;
    if(!root){ 
        return ans;
    }

    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        
        while(temp){
            if(temp->left){
                q.push(temp->left);  //Push left of curr node in queue 
            }
            ans.push_back(temp->data); //Push data of each node in vector
            temp=temp->right;         //Move to right of current node for diagonal traversal
        }
    }
    return ans;
}



//Second Solution :-
void solve(Node* root, map<int, vector<int>>&mp, int index)
{
   	if(!root){
       	return;
   	}
   	mp[index].push_back(root->data);
   	solve(root->left, mp, index+1);
   	solve(root->right, mp, index);
}

vector<int> diagonal(Node *root)
{
	map<int, vector<int>>mp;
	solve(root, mp, 1);
	vector<int>v;
	for(auto i:mp){
      	for(auto j:i.second){
	        v.push_back(j);
      	}
	}
	return v;
}



//Third Solution :-
vector<int> diagonal(Node *root){
    queue<Node*> q;
    
    // add the root to the queue
    q.push(root);
    vector<int> res;
    
    // loop while q is not empty
    while(q.empty() == false){
        // take out the front element from the queue
        Node* curr = q.front();
        q.pop();
        
        // loop while curr is not NULL
        while(curr != NULL){
            // add curr's data to res vector
            res.push_back(curr->data);
            
            // if curr has a left child push it to the queue
            if(curr->left){
                q.push(curr->left);
            }
            
            // set curr = curr's right child
            curr = curr->right;
        }
    }
    return res;
}
