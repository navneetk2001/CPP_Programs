https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1





//Solution Approach :-
Node* insert(Node* root, int key) {
    Node* parent = NULL;
    Node* cur = root;
     
    while(cur!=NULL){
        parent = cur;
        if(cur->data==key){
        	return root;
        }
        else if(key<cur->data){
        	cur=cur->left;
        }
        else{
        	cur=cur->right;
        }
    }
     
  
    if(key<parent->data){
    	parent->left=new Node(key);
    }
    else{
    	parent->right=new Node(key);
    }
    
    return root;
}



//Second Solution :-
Node* insert(Node* root, int Key) {
    if(root==NULL){
    	return new Node(Key);
    }
    
    Node* curr = root;
    
    while(true)
    {
        if(curr->data == Key){
        	break;
        }
        
        if(curr->data>Key){
            if(curr->left==NULL){
                curr->left = new Node(Key);
                break;
            }
            else{
                curr=curr->left;
            }
        }
        
        else{
            if(curr->right==NULL){
                curr->right = new Node(Key);
                break;
            }
            else{
                curr=curr->right;
            }
        }
    }
    
    return root;
}




//Third Solution :- Recursive Solution :-
Node* insert(Node* root, int key) {
    if(root == NULL){
        return (new Node(key));
    }
    else if(root->data > key){
       root->left =  insert(root->left, key);
        
    }
    else if(root->data < key){
        root->right =  insert(root->right, key);
    }
    
    return root;
}



//Fourth Solution :-
//using a parent variable, the code seems to run a bit faster, sorry for the messy imple :P (ha bhai LL ka pujari hu mai)

void ins(TreeNode* root, TreeNode* prev, int val){
    if(!root){
        TreeNode *nnode = new TreeNode(val);
        if(prev->val < val)prev->right = nnode;
        else prev->left = nnode;
        return;
    }
    prev = root;
    if(root->val < val)ins(root->right,prev,val);
    if(root->val > val)ins(root->left, prev, val);
    
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* dmy = new TreeNode(0);
    TreeNode* prev = dmy;
    dmy->left = root;
    
    // when root is given empty return that node
    if(!root){
        TreeNode *nnode = new TreeNode(val);
        dmy->left = nnode;
    }
    else{
        ins(root,prev,val);
    }
    
    // return ins(root,prev,val);
    return dmy->left;
}




//Solution :- By STRIVER
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode *cur = root;
        while(true) {
            if(cur->val <= val) {
                if(cur->right != NULL) cur = cur->right;
                else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if(cur->left != NULL) cur = cur->left;
                else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};