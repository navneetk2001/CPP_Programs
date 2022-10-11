https://practice.geeksforgeeks.org/problems/check-for-bst/1


//Solution Approach :-
bool isBST(Node* root, int min=INT_MIN, int max=INT_MAX) {
    return root && root->data < max && root->data > min && isBST(root->left, min, root->data) && isBST(root->right, root->data, max) || !root;
}



//Second SOlution :-
int maximum(Node* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}

int minimum(Node* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data, max(minimum(root->left),minimum(root->right)));
}

class Solution{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        if(root==NULL){
            return true;
        }
        int leftMax=maximum(root->left);
        int rightMin=minimum(root->right);
        
        bool output=(root->data>leftMax) && (root->data<rightMin) &&isBST(root->left) && isBST(root->right);
        return output;
    }
};



//Third Solution :-
int flag = 1;
bool check(Node*root, int lowerLimit, int upperLimit){
    if (root->data<lowerLimit || root->data>upperLimit) flag = 0;
    if (root->right) bool a = check(root->right, root->data+1, upperLimit);
    if (root->left) bool b = check(root->left, lowerLimit, root->data-1);
}

bool isBST(Node* root){
    check(root, INT_MIN, INT_MAX);
    return flag;
}