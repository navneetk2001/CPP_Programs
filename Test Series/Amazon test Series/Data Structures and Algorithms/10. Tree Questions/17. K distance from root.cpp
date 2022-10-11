https://practice.geeksforgeeks.org/problems/k-distance-from-root/0/?problemStatus=unsolved&difficulty[]=0&page=1&query=problemStatusunsolveddifficulty[]0page1




//Solution Approach :-
void solve(struct Node *root, int k, vector<int>&ans){
    if(root == NULL) return;

    if(k == 0){        //This immplies we are at a distance k
        ans.push_back(root->data);
        return;
    }

    solve(root->left, k-1, ans);
    solve(root->right, k-1, ans);
    return;
}

vector<int> Kdistance(struct Node *root, int k){
  vector<int>ans;
  solve(root, k, ans);
  return ans;
}



//Second Solution :-
vector<int> Kdistance(struct Node *root, int k){
	vector<int>v;
	if(root==NULL){
		return v;
	}

	int c=0;
	queue<Node*>q;
	q.push(root);
	
	while(!q.empty()){
	    int h=q.size();

	    for(int i=1;i<=h;i++){
	        Node*temp=q.front();
	        q.pop();

	        if(c==k){
	            v.push_back(temp->data);
	        }
	        if(temp->left){
	            q.push(temp->left);
	        }
	        if(temp->right){
	            q.push(temp->right);
	        }
	    }
	    c++;
	}
	return v;
}
