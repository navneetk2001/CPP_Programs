https://practice.geeksforgeeks.org/problems/inorder-traversal/1


//Solution Approach :-
class Solution {
  public:
    void f(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        f(root->left, ans);
        ans.push_back(root->data);
        f(root->right,ans);
    }

    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        f(root,ans);
        return ans;
    }
};



//Second Solution :- Iterative Approach 
vector<int> inOrder(Node* root) {
    vector<int> ans;
    stack<Node*> s;
    
    Node* curr=root;
    
    if(curr==NULL) return ans;
    
    while(curr || !s.empty()){
        while(curr){
            s.push(curr);
            curr=curr->left;
        }
        
        curr=s.top();
        s.pop();
        ans.push_back(curr->data);
        curr=curr->right;
    }
   	return ans;
}