https://practice.geeksforgeeks.org/problems/full-binary-tree/1/



//Solution Approach :-
bool isFullTree (struct Node* root){
  	if(!root){
  		return false;
  	}
  	if(!root->left && !root->right){
  		return true;
  	}
  
  	if(isFullTree(root->left) && isFullTree(root->right)){
  		return true;
  	}
  	else{
  		return false;
  	}
}



//Second Solution :-
bool isFullTree (struct Node* root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* top = q.front();
        int ctr = 0;
        q.pop();

        if(top->left){
            ctr++;
            q.push(top->left);
        }
        if(top->right){
            ctr++;
            q.push(top->right);
        }
        if(ctr == 1){
            return false;
        }
    }
    return true;
}



//Third Solution :-
bool isFullTree (struct Node* root){
    if(!root){
        return true;
    }
    if(!root->left && !root->right){
        return true;
    }
    if(root->left && root->right){
        return isFullTree(root->left) && isFullTree(root->right);
    }
    else{
        return false;
    }
}

