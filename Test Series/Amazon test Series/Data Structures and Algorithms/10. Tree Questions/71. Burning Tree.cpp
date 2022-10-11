https://practice.geeksforgeeks.org/problems/burning-tree/1




//Solution Approach :-
int ans=0;
int helper(int h,Node* root,int target){
    if(!root){
        return 0;
    }

    if(root->data==target){
        helper(1,root->left,target);
        helper(1,root->right,target);
        return 1;
    }

    if(h){
        ans=max(ans,h);
        helper(h+1,root->left,target);
        helper(h+1,root->right,target);
        return 0;
    }
    int l=helper(0,root->left,target);
    int r=helper(0,root->right,target);
    
    ans=max(ans,max(l,r));
    if(l){
        helper(l+1,root->right,target);
        return l+1;
    }
    if(r){
        helper(r+1,root->left,target);
        return r+1;
    }
}

int minTime(Node* root, int target) 
{
    ans=0;
    helper(0,root,target);
    return ans;
}



//Second Solution :- C++ Solution:- BFS Traversal
class Solution {
    private:
    Node* bfsToparent(Node* root, map<Node*, Node*> &mpp, int target){
        /* This BFS Do:
           1>   Parent Mapping
           2>   Giving Target Node
        */
        queue<Node*> q{{root}};
        Node* res;
        while(!q.empty()){
            Node* curr = q.front(); 
            q.pop();

            if(curr->data == target){
                res = curr;
            }
            if(curr->left){
                q.push(curr->left);
                mpp[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                mpp[curr->right] = curr;
            }
        }
        return res;
    }

  public:
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> mpp;    //for storing parent and finding target node
        Node* targetNode = bfsToparent(root, mpp, target);
        
        map<Node*, bool> visited;
        visited[targetNode] = 1;

        queue<Node*> q{{targetNode}};
        int timer = 0;

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i = 0;i < size; i++){
                Node* curr = q.front();
                q.pop();

                if(curr->left && !visited[curr->left]){   //push current->left if not visited and mark it visited
                    flag = true;        
                    q.push(curr->left);
                    visited[curr->left] = 1;
                }
                if(curr->right && !visited[curr->right]){    //push current->right if not visited and mark it visited 
                    flag = true;
                    q.push(curr->right);
                    visited[curr->right] = 1;
                }
                if(mpp[curr] && !visited[mpp[curr]]){       // //push current->parent if not visited and mark it visited
                    flag = true;
                    q.push(mpp[curr]);
                    visited[mpp[curr]] = 1;
                }
            }
            if(flag){    //every time u push something then increase time
                timer++;
            }
        }
        
        return timer;
    }
};



//Third Solution :-
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        vector<Node*> ans,v;
        root_to_node_path(root,target,ans,v);
        reverse(ans.begin(),ans.end());
        int maxi=0;
        for(int i=0;i<ans.size();i++){
            maxi=max(maxi,i+burn(ans[i],i==0?NULL:ans[i-1]));
        }
        return maxi-1;
    }
    void root_to_node_path(Node* root,int target,vector<Node*> &ans,vector<Node*> &v ){
        if(!root) return ;
        if(target==root->data){ 
            v.push_back(root);
            ans=v;
            return;
        }
        v.push_back(root);
        root_to_node_path(root->left,target,ans,v);
        root_to_node_path(root->right,target,ans,v);
        v.pop_back();
        
    }
    int  burn(Node* root,Node* blocker){
        if(!root || root==blocker ) return 0;
        int l=1+burn(root->left,blocker);
        int r=1+burn(root->right,blocker);
        return max(l,r);
    }
};




//Fourth Solution :-
class Solution {
  public:
    unordered_map<Node*,Node*> mp;
    Node* tar;
    int minTime(Node* root, int target) {
        dfs(root,target);
        queue<pair<Node*,int>>q;
        unordered_map<Node*,int> vis;
        q.push({tar,0});
        int t=INT_MIN;
        while(q.size()!=0){
             Node* f = q.front().first;
             int   l = q.front().second;q.pop();
             if(vis.find(f)!=vis.end()){
                 continue;
             }
             vis[f]=1;
             if(f==NULL){
                 continue;
             }
             
             q.push({f->left,l+1});
             q.push({f->right,l+1});
             q.push({mp[f],l+1});
             t=max(t,l);
        }
        return t;
    }
    void dfs(Node*root,int target){
        if(root==NULL)
            return;
        if(root->data==target)
            tar=root;
        dfs(root->left,target);
        dfs(root->right,target);
        
        if(root->left!=NULL){
            mp[root->left]=root;
        }
        if(root->right!=NULL){
            mp[root->right]=root;
        }
        
    }
};



//Solution :- BY STRIVER
#include<bits/stdc++.h> 

int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>*> q; 
    q.push(target); 
    map<BinaryTreeNode<int>*,int> vis; 
    vis[target] = 1;
    int maxi = 0; 
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) {
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            if(node->right && !vis[node->right]) {
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            
            if(mpp[node] && !vis[mpp[node]]) {
                fl = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(fl) maxi++; 
    }
    return maxi; 
}
BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, 
                                     map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, int start) {
    queue<BinaryTreeNode<int>*> q; 
    q.push(root); 
    BinaryTreeNode<int>* res; 
    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); 
        if(node->data == start) res = node; 
        q.pop(); 
        if(node->left) {
            mpp[node->left] = node; 
            q.push(node->left); 
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right); 
        }
    }
    return res; 
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp; 
    BinaryTreeNode<int>* target = bfsToMapParents(root, mpp, start); 
    int maxi = findMaxDistance(mpp, target); 
    return maxi; 
}
 