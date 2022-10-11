https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1




//Solution Approach :-
class Solution{
    private:
    void solve(Node* root,unordered_map<int,int> &parent)
    {
        if(root==NULL){
            return;
        }
        
        if(root->left){
            parent[root->left->data]=root->data;
            solve(root->left,parent);
        }
        if(root->right){
            parent[root->right->data]=root->data;
            solve(root->right,parent);
        }
    }
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
        unordered_map<int,int> parent;
        parent[root->data]=-1;
        solve(root, parent);
         
        vector<int> ans;
        while(parent[target]!=-1){
            ans.push_back(parent[target]);
            target=parent[target];
        }
        return ans;
    }
};



//Second Solution :-
class Solution{
public:
    int solve(Node*root,int K,vector<int>&v){
       	if(root==NULL)return 0;
       	if(root->data==K){
           	return 1;
       	}
       	int lh=solve(root->left,K,v);
       	int rh=solve(root->right,K,v);
       	if(lh==1 or rh==1){
           	v.push_back(root->data);
           	return 1;
       	}
       	return 0;
    }
    
    vector<int> Ancestors(struct Node *root, int target){
        vector<int> v;
        if(root==NULL){
        	return v;
        }
        solve(root,target,v);
        return v;
    }
};




//Third Solution :-
class Solution{
  public:
    // Function should return all the ancestor of the target node
    void help(vector<int> &ans,Node* root,int target,bool &found){
        if(root == NULL) return;
        if(root->data == target){
            found=true;
            return;
        }
        help(ans,root->left,target,found);
        if(found){ 
        	ans.push_back(root->data);
        	return;
        }

        help(ans,root->right,target,found);
        if(found){ 
        	ans.push_back(root->data);
        	return;
        }
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int> ans;
        bool found = false;
        help(ans,root,target,found);
        return ans;
    }
};




//Fourth Solution :- SIMPLY USING LEVEL ORDER TRAVERSAL AND MAP
vector<int> Ancestors(struct Node *root, int target){
    vector<int> v;
    if(!root){
        return v;
    }
    
    Node * t = NULL;
     
    map<Node*, Node*> m;
    m[root] = NULL;
     
    queue<Node*> q;
    q.push(root);
     
    while(!q.empty()){
        Node * c = q.front();             
        q.pop();
         
        if(c->left){
            m[c->left] = c;
            q.push(c->left);
        }             
        if(c->right){
            m[c->right] = c;
            q.push(c->right);
        }             
        if(c->data == target){
            t = c;
            break;
        }
    }
     
    while(m[t] != NULL){
        Node * c = m[t];
        v.push_back(c->data);
        t = c;
    }
     
    return v;
}