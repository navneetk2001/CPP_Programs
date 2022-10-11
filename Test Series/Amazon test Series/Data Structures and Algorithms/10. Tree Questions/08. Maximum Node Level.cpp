https://practice.geeksforgeeks.org/problems/maximum-node-level/1




//Solution Approach :-
int maxNodeLevel(Node *root){
	if(root==NULL){
        return -1;
    }

    int level=0;
    int size=-1;
    int maxlevel=0;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int count = q.size();
        if(count>size){
            size = count;
            maxlevel = level;
        }
        for(int i=0;i<count;i++){
            Node* cur=q.front();
            q.pop();

            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        level++;
    }
    return maxlevel;
}



//Second Solution :-
void mnlUtil(Node *root, map<int, int> &hM, int level) {
    if(root == NULL){
    	return;
    }
    
    hM[level]++;     // add amount of nodes at level
    mnlUtil(root->left, hM, level+1);
    mnlUtil(root->right, hM, level+1); 
}

// Return the level (0-indexed) with maximum number of nodes.
int maxNodeLevel(Node *root){
    map<int, int> hM;           // hash map for levels and nodes at level
    mnlUtil(root, hM, 0);       // recursively check all nodes at level
    
    // find max at level
    int maxNodes = INT_MIN;
    int maxLevel = 0;
    for(int i = 0; i <= 100; i++) {
        if(hM[i] > maxNodes) {
            maxNodes = hM[i];
            maxLevel = i;
        }
    }
    return maxLevel;
}

