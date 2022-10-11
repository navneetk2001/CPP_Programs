https://www.interviewbit.com/problems/level-order/



//Solution Approach :-
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* root) {
    vector<vector<int>> v;
    if(root==NULL){
        return v;
    }
    
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        vector<int> level;
        int h = q.size();

        for(int i=1;i<=h;i++){
            TreeNode* temp=q.front();
            q.pop();

            level.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        v.push_back(level);
    }
    return v;
}




//Second Solution :- 
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ret;
    if (!A) {
        return ret;
    }
    queue<TreeNode*> currLevel, nextLevel;
    currLevel.push(A);
    vector<int> curr;
    while (!currLevel.empty()) {
        TreeNode *currNode = currLevel.front();
        currLevel.pop();
        if (currNode) {
            curr.push_back(currNode->val);
            nextLevel.push(currNode->left);
            nextLevel.push(currNode->right);
        }
        if (currLevel.empty()) {
            if (curr.size() > 0) {
                ret.push_back(curr);
            }
            curr.clear();
            swap(currLevel,nextLevel);
        }
    }
    return ret;
}



//Third Solution :- DFS
void build(TreeNode* root,vector<vector<int>> &ret,int depth){
    if(!root){
     	return;
     }
    if(ret.size()==depth){
    	ret.push_back(vector<int>(0));
    }
    ret[depth].push_back(root->val);
    
    build(root->left,ret,depth+1);
    build(root->right,ret,depth+1);
     
    return;
 }
 
vector<vector<int> > Solution::levelOrder(TreeNode* B) {
    vector<vector<int>> ret;
    build(B,ret,0);
    return ret;
}