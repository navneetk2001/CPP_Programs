// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

// Example 1:
// Input:
//         1
//       /   \
//      4     4
//    /   \
//   6     8
// Output: 1
// Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the
// leaf Nodes are the BSTs with size equal to 1.

// Example 2:
// Input: 6 6 3 N 2 9 3 N 8 8 2
//             6
//           /    \ 
//          6      3
//         \      /   \
//          2    9     3
//           \  /  \
//           8 8    2 
// Output: 2
// Explanation: The following sub-tree is a
// BST of size 2: 
//        2
//     /    \ 
//    N      8




//Solution Approach :-
class NodeValue {
public:
       int maxNode, minNode, maxSize;
       NodeValue(int minNode, int maxNode, int maxSize) {
              this->maxNode = maxNode;
              this->minNode = minNode;
              this->maxSize = maxSize;
       }
};

class Solution {
private:
       NodeValue largestBSTSubtreeHelper(TreeNode* root) {
              // An empty tree is a BST of size 0.
              if (!root) {
                     return NodeValue(INT_MAX, INT_MIN, 0);
              }
        
              // Get values from left and right subtree of current tree.
              auto left = largestBSTSubtreeHelper(root->left);
              auto right = largestBSTSubtreeHelper(root->right);
        
              // Current node is greater than max in left AND smaller than min in right, it is a BST.
              if (left.maxNode < root->val && root->val < right.minNode) {  //IF It is a BST.
                     return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
              }
        
              // Otherwise, return [-inf, inf] so that parent can't be valid BST
              return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
       }
public:
       int largestBSTSubtree(TreeNode* root) {
              return largestBSTSubtreeHelper(root).maxSize;
       }
};




//Second Solution :-
struct bst{
    bool isBST;
    int size;
    int mx;
    int mn;
};

class Solution{
public:
       bst Large(Node* root)
       {
              if(!root){
                   bst b={true,0,INT_MIN,INT_MAX};
                   return b;
              }
              bst l=Large(root->left);
              bst r=Large(root->right);
              bst b;
              if(l.isBST && r.isBST && l.mx<root->data && r.mn>root->data){
                     bst b={true,l.size+r.size+1,max(root->data,r.mx),min(root->data,l.mn)};
              }
              else{
                     bst b={false,max(l.size,r.size),-1,-1};
              }
              return b;
       }

       int largestBst(Node *root)
       {
              bst b=Large(root);
              return b.size;
       }
};


