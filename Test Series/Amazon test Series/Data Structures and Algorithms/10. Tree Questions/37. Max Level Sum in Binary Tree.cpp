https://practice.geeksforgeeks.org/problems/max-level-sum-in-binary-tree/1/




//Solution Approach :-
int maxLevelSum(Node* root) {
    queue<Node*> q;
    q.push(root);
    
    int maxSum = INT_MIN;
    while(q.empty() == false){
        int currSum = 0;
        int count = q.size();
        
        for(int i = 0; i < count; i++){
            Node* curr = q.front();
            q.pop();
            
            currSum += curr->data;
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}



//Second Solution :-
void helper(Node * root,int level, map<int,int>&m){
    if(!root){
    	return;
    }
    
    m[level]+=root->data;
    helper(root->left,level+1,m);
    helper(root->right,level+1,m);
}

int maxLevelSum(Node* root){
    map<int,int>m;
    helper(root,0,m);
    
    int maximum=INT_MIN;
    for(auto it=m.begin(); it!=m.end(); it++){
        maximum=max(maximum,it->second);
    }
    return maximum;
}
