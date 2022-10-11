https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1



//Solution Approach :-
void f(Node* node,vector<int>v,vector<vector<int>>&ans)
{
    if(node == NULL){
        return;
    }
    if(node->left == NULL && node->right == NULL){
        v.push_back(node->data);
        ans.push_back(v);
        return;
    }
    v.push_back(node->data);
    f(node->left, v, ans);
    f(node->right, v, ans);
}

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    vector<int> v;
    f(root, v, ans);
    return ans;
}



//Second Solution :-
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    vector<int> v;
    stack<pair<Node*, vector<int>>> s;
    
    s.push({root, v});
    while(!s.empty()) {
        Node* currNode = s.top().first;
        vector<int> currPath = s.top().second;
        s.pop();
        
        currPath.push_back(currNode->data);
        
        if(currNode->left == NULL && currNode->right == NULL){
            ans.push_back(currPath);
        }
        
        if(currNode->left){
            s.push({currNode->left, currPath});
        }
        if(currNode->right){
            s.push({currNode->right, currPath});
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}



//Third Solution :-
vector<vector<int>>ans;
void dfs(Node* node,vector<int>curr)
{
    if(node==NULL)
       return;
    curr.push_back(node->data);
    if(node->left==NULL && node->right==NULL)
    {
        ans.push_back(curr);
    }
    dfs(node->left,curr);
    dfs(node->right,curr);
    curr.pop_back();
}

vector<vector<int>> Paths(Node* root)
{
    vector<int>curr;
    dfs(root,curr);
    return ans;
}



