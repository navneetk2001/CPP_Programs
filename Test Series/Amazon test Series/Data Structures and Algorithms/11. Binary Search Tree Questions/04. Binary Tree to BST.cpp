https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1




//Solution Approach :-
void inorder(Node*&root,vector<int>&temp){
    if(!root){
    	return;
    }

    inorder(root->left,temp); 
    temp.push_back(root->data); 
    inorder(root->right,temp); 
}

void helper(Node* &root, vector<int>&temp, int &idx){
    if(!root){
    	return ; 
    }

    helper(root->left,temp,idx); 
    root->data = temp[idx++];
    helper(root->right,temp,idx);
}

Node *binaryTreeToBST (Node *root){
    vector<int>temp; 
    inorder(root,temp); 

    sort(temp.begin(),temp.end());
 	int temp1=0;

    helper(root,temp,temp1); 
    return root;
}



//Second Solution :-
class Solution{
  public:
    // The given root is the root of the Binary Tree      // Return the root of the generated BST
    void preorder(Node* root, vector<int> &ans) {
        if(root == NULL){
            return;
        }
            
        ans.push_back(root->data);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    
    Node* solve(vector<int> &ans, int mini, int maxi, int &i) {
        if(i >= ans.size()) {        // base case
            return NULL;
        }
        
        if(ans[i] < mini || ans[i] > maxi) {
            return NULL;
        }
        
        Node* root = new Node(ans[i++]);
        root->left = solve(ans, mini, root->data, i);
        root->right = solve(ans, root->data, maxi, i);
        
        return root;
    }
    
    Node *binaryTreeToBST (Node *root){
        vector<int> ans;
        preorder(root, ans);
        
        sort(ans.begin(), ans.end());
        
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        
        return solve(ans, mini, maxi, i);
    }
};



//Third Solution :-
class Solution{
public:
    void inorder(Node *root,vector<int>&v){
        if(root==NULL)return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }

    Node *getBst(int s,int e,vector<int>&v){
        if(s>e)return NULL;
        int mid=(s+e)/2;
        Node *root = new Node(v[mid]);
        root->left = getBst(s,mid-1,v);
        root->right = getBst(mid+1,e,v);
        return root;
    }

    Node *binaryTreeToBST (Node *root)
    {
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        return getBst(0,v.size()-1,v);
       
    }
};