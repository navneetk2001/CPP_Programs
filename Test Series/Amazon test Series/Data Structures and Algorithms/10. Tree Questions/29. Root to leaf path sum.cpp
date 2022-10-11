https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1



//Solution Approach :-
bool hasPathSum(Node *root, int S) {
    if(!root){
    	return root;
    }
    S -= root->data;
    if(root->left == NULL && root->right==NULL){
    	return S==0;
    }
    return (hasPathSum(root->left, S) | hasPathSum(root->right, S));
}



//Second Solution :-
void solve(Node * root, vector<int> ans, vector<vector<int>> &res) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL and root->right == NULL) {
        ans.push_back(root->data);
        res.push_back(ans);
        return;
    }
    ans.push_back(root->data);
    solve(root->left, ans, res);
    solve(root->right, ans, res);    
}

bool hasPathSum(Node *root, int S) {
    vector<vector<int>> res;
    vector<int> ans;
    
    solve(root, ans, res);
    
    for(auto i: res) {
        int sum = 0;
        for(auto j: i) {
            sum += j;
        }
        if(sum == S) {
            return true;
        }
    }
    
    return false;
}



//Third Solution :-
class Solution{
public:
    bool hasPathSum(Node *root, int S) {
        if(!root){
        	return 0;
        }
        if(!root->left && !root->right){
            if(S-root->data ==0){
            	return true;
            }
            else{ 
            	return false;
            }
        }
        return hasPathSum(root->left, S - root->data) || hasPathSum(root->right, S - root->data);
    }
};