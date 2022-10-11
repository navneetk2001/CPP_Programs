// Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.
// The values smaller than root go to the left side
// The values greater and equal to the root go to the right side

// Example 1:
// Input:
//       10
//      /  \
//     5    50
//    /    /  \
//   1    40  100
// l = 5, h = 45
// Output: 3
// Explanation: 5 10 40 are the node in the range

// Example 2:
// Input:
//      5
//     /  \
//    4    6
//   /      \
//  3        7
// l = 2, h = 8
// Output: 5
// Explanation: All the nodes are in the given range.




//Solution Approach :-
int getCount(Node *root, int l, int h)
{
     if(!root){
          return 0;
     }
     if(root->data >= l && root->data <= h){
          return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
     }
     else if(root->data < l){
          return getCount(root->right, l, h);
     }
     else{
          return getCount(root->left, l, h);
     }
}




//Second Solution :-
int getCount(Node *root, int l, int h){
     if(root==NULL){
          return 0;
     }
     if(root->data>=l && root->data<=h){
          return 1 + getCount(root->right,l,h) + getCount(root->left,l,h);
     }
     else{
          return getCount(root->right,l,h) + getCount(root->left,l,h);
     }
}




//Third Solution :- Hint :- Use level Order Traversal
int countBSTnodes(Node* root, int l, int h) {
     queue<Node*> q;
     q.push(root);
     int ans = 0;

     while(!q.empty()) {
          Node* temp = q.front();
          q.pop();
          
          if(temp->data >= l && temp->data <= h) {
               ans++;
          }
          if(temp->left != NULL) {
               q.push(temp->left);
          }
          if(temp->right != NULL) {
               q.push(temp->right);
          }
     }
     return ans;
}