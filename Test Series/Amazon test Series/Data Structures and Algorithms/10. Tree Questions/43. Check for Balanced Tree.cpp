https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1




//Solution Approach :-
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root){
    if(root==NULL){
        return true;
    }

    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1){
        return false;
    }
    bool l_bal=isBalanced(root->left);
    bool r_bal=isBalanced(root->right);
    
    if(l_bal&&r_bal){
        return true;
    }
    else{
        return false;
    }
}


//Second Solution :-
class Solution{
public:
    pair<bool,int> solve(Node *root){
        if(root == NULL){
            pair<bool,int> p = {true,0};
            return p;
        }
        
        pair<bool,int> left = solve(root->left);
        pair<bool,int> right = solve(root->right);
        
        bool l = left.first;
        bool r = right.first;
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        if(l && r && diff){
            ans.first = true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return solve(root).first;
    }
};



//Third Solution :-
int flag = 1;
int balence(Node*root) {
    if (root==NULL) return 0;
    int a = 1+balence(root->left);
    int b = 1+balence(root->right);
    if (abs(a-b)>1) flag = false;
    return max(a,b);
}

bool isBalanced(Node *root) {
    if (root==NULL) return 1;
    balence(root);
    return flag;  
}