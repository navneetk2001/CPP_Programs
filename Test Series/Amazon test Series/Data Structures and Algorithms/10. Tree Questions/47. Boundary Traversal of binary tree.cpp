https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1




//Solution Approach :-
class Solution {
private:
    void traverseLeft(Node* root, vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left, ans);
        }
        else{
            traverseLeft(root->right, ans);
        }
    }
     
    void traverseLeaf(Node* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }   
    
    void traverseRight(Node* root, vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->right){
            traverseRight(root->right, ans);
        }
        else{
            traverseRight(root->left, ans);
        }
        ans.push_back(root->data);
    }

public:
    vector <int> boundary(Node *root){
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
       
        ans.push_back(root->data);
       
        traverseLeft(root->left, ans);    //left boundary traversal
        
        traverseLeaf(root->left, ans);    //leaf traversal of left subtree
        traverseLeaf(root->right, ans);   //leaf traversal of right subtree
        
        traverseRight(root->right, ans);  //right boundary traversal
    }
};




//Second Solution :-
class Solution {
public:
    unordered_set<Node*> s;
    bool b=false;
    bool isLeaf(Node* n){
        return (n->left==NULL)&&(n->right==NULL);
    }
    void addLeftBoundary(Node* root,vector<int> &ans){
        if(!root)return;
        Node* t=root;
        if(t->left){
            t=t->left;
            b=true;
        }else
            t=t->right;
        
        while(t&&!isLeaf(t)){
            ans.push_back(t->data);
            
            s.insert(t);
        
            if(t->left){
                t=t->left;
                b=true;
            }else
                t=t->right;
        }
    }

    void addRightBoundary(Node* root,vector<int> &ans){
        if(!root)return;
        vector<int> res;
        Node* t=root;
        if(t->right)
            t=t->right;
        else
            t=t->left;
    
        while(t&&!isLeaf(t)){
            if(s.find(t)==s.end()){
            res.push_back(t->data);
            if(t->right)
                t=t->right;
            else
                t=t->left;
            }else
                break;
        }
        
        reverse(res.begin(),res.end());
        
        ans.insert(ans.end(),res.begin(),res.end());
    }

    void inorderTraversal(Node* node,vector<int> &ans){
        if(!node)return;
        
        inorderTraversal(node->left,ans);
        if(isLeaf(node))ans.push_back(node->data);
        inorderTraversal(node->right,ans);
    }
    void addLeafBoundary(Node* root,vector<int> &ans){
        inorderTraversal(root,ans);
    }
    
    vector <int> boundary(Node *root){
        
        if(!root)return {};
        vector<int> ans;
        
        if(!isLeaf(root))ans.push_back(root->data);
        s=unordered_set<Node*>();
        b=false;
        
        addLeftBoundary(root,ans);
        
        // If no left children are there then it must 
        // not be included as left boundary so clear;
        if(!b){
            ans=vector<int>();
            s=unordered_set<Node*>();
            if(!isLeaf(root)){ans.push_back(root->data);};
        }
        
        addLeafBoundary(root,ans);
        
        // If in traversing we found an element which
        // is included in leftboundary exit.
        addRightBoundary(root,ans);
        
        return ans;
    }
};