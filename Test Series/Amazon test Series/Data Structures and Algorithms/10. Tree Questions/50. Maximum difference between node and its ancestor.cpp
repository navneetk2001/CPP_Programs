https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1





//Solution Approach :-
int helper(Node*&root,int &ans){
    if(!root){
    	return INT_MAX; 
    }

    if(!root->left and !root->right){
    	return root->data; 
    }

    auto left = helper(root->left,ans);
    auto right = helper(root->right,ans); 

    auto mini = min(left,right); 
    ans = max(ans, root->data - mini);

    return min(mini, root->data); 
}

int maxDiff(Node* root){
   int ans=INT_MIN; 
   helper(root,ans); 
   return ans;
}



//Second Solution :-
void dfs(Node *v,int mx,int &ans){
    if(!v)return;
    ans=max(ans,mx-v->data);
    dfs(v->left,max(mx,v->data),ans);
    dfs(v->right,max(mx,v->data),ans);
}
int maxDiff(Node* root){
    int ans=INT_MIN;
    dfs(root,-1e8,ans);
    return ans;
}



//Third Solution :-
// helper function to find the max difference
// our aim is to propagate min value of the children nodes from bottom to top
int diff_helper(Node *root, int &max_diff) {
    if(!root){
        return INT_MAX;
    }
    // condition for leaf node
    if(!root->left && !root->right){
        return root->data;
    }
    // recursive calls: postorder LRN
    int left = diff_helper(root->left, max_diff);
    int right = diff_helper(root->right, max_diff);
    // find the min value among the children nodes
    int min_val = min(left, right);
    // update max diff
    max_diff = max(max_diff, root->data - min_val);
    // propage the min value upwards
    return min(min_val, root->data);
}

//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root) {
    // Your code here 
    int max_diff = INT_MIN;
    diff_helper(root, max_diff);
    
    return max_diff;
}



//Fourth Solution :-
int ret = -INT_MIN;
int helper(Node *root){
    if(!root){
        return INT_MAX;
    }
    int left = helper(root->left);
    int right = helper(root->right);
    ret  = max({ret, root->data - left, root->data  - right});
    return min({root->data,left,right});
}

int maxDiff(Node* root)
{
    ret = -INT_MIN;
    helper(root);
    return ret;
}