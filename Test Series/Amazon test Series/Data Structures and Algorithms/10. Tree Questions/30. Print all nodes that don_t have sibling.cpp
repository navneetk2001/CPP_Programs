https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1




//Solution Approach :-
void noSib(vector<int> &v,Node* root){
    if(root==NULL){
        return;
    }
    if((root->left==NULL && root->right!=NULL)){
        v.push_back(root->right->data);
    }
    if((root->left!=NULL && root->right==NULL)){
        v.push_back(root->left->data);
    }
    noSib(v,root->left);
    noSib(v,root->right);
}


vector<int> noSibling(Node* node){
    vector<int> v;
    noSib(v,node);

    if(v.empty()){
        return {-1};
    }
    sort(v.begin(),v.end());
    return v;
}



//Second Solution :-
vector<int> noSibling(Node* node){
    queue<Node*> q;
    vector<int> ans;
    if(node == NULL){
        return ans;
    }

    //Performing BFS to find such nodes which don't have a sibling
    q.push(node);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        
        if(curr->left != NULL){
            if(curr->right == NULL){
                ans.push_back(curr->left->data);
            }
            q.push(curr->left);
        }
        if(curr->right != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->right->data);
            }
            q.push(curr->right);
        }
    }
    if(ans.empty()){
        return {-1};
    }
    sort(ans.begin(), ans.end());    //Since our ans array must be sorted, hence sorting the final ans
    return ans;
}


