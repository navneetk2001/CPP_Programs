https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1




//Solution Approach :- 
// First hint:IT'S a BST,so go for its properties,
// 1)now if u r at a node,then if its NULL so return null
// 2)if its value is less greater or equal to k,then all the values of its right subtree will also be greater,so call for left subtree and return it
// 3)now if current node's value is less,than recursively call for right subtree and assign the returned node to current root's right

Node* deleteNode(Node* root, int k)
{
    if(root==NULL) return NULL;
    if(root->data >= k){
        root = deleteNode(root->left,k);
    }
    else{
        root->right = deleteNode(root->right,k);
    }
    return root;     
}




//Second Solution :-
/* IDEA: 
    1) Agr root NULL ho gya toh bhyi simply return NULL;
    2) Agr root ki val exactly equal hai k toh iska mtlb iske left main jitni
    bhi values hongi woh k se km hongi, toh return root -> left.
    3) Agr root ka data k se bda hai toh yeh toh pkka hai ki right main bhi sb values
    k se bdi hongi toh hme right main toh jana nhi, hm phir root ke left main jayenge
    aur khojenge ki aisi konsi jagah se root ki value less than k milti hai, toh isiliye
    return deleteNode(root -> left, k);
    4) Agr root ka data k se km hai toh yeh toh sure hai ki iske left main jitni bhi 
    values hongi woh sb k se km hongi toh unhe toh delete nhi krna hai. Since root ka
    data k se km hai toh iske right main yeh possibility ho skti hai ki koi value 
    k se bdi ho, toh hme usse delete krna hoga, so go into the right, i.e
    deleteNode(root -> right, k);
*/

class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k)
    {
        if(root == NULL){            // agr root NULL toh return NULL (point 1)
            return NULL;
        }
        if(root -> data == k){       // (point 2)
            return (root -> left);
        }

        if(root -> data > k){        //(point 3)
            return deleteNode(root -> left, k);
        }
        if(root -> data < k){         // ( point 4)
            root -> right = deleteNode(root -> right, k);
        }
        
        return root;
    }
};




//Third Solution :-
class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k){
        if(root==NULL){
            return NULL;
        }
        
        root->left=deleteNode(root->left,k);
        
        if(root->data >=k){
            return root->left;
        }
        root->right=deleteNode(root->right,k);
        
        return root;
    }
};