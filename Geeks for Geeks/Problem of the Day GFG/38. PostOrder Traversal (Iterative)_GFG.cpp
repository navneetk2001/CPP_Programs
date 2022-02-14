// Given a binary tree. Find the postorder traversal of the tree without using recursion.

// Example 1
// Input:
//            1
//          /   \
//         2     3
//       /  \
//      4    5

// Output: 4 5 2 3 1
// Explanation:
// Postorder traversal (Left->Right->Root) of the tree is 4 5 2 3 1.

// Example 2
// Input:
//              8
//           /      \
//         1          5
//          \       /   \
//           7     10    6
//            \   /
//             10 6

// Output: 10 7 1 6 10 6 5 8 
// Explanation:
// Inorder traversal (Left->Right->Root) of the tree is 10 7 1 6 10 6 5 8 .



//We will use stack to do it in Iterative manner
class Solution{
    public:
    vector<int> postOrder(Node* node) {
        stack<Node*>st;
        vector<int>ans;
        st.push(node);

        while(!st.empty()){   //Iterate till stack is empty
          Node* temp=st.top();
          st.pop();

          ans.push_back(temp->data);

          if(temp->left!=NULL){
            st.push(temp->left);
          }
          
          if(temp->right!=NULL){
            st.push(temp->right);
          }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



//Without reversing :-
class Solution{
    public:
    vector<int> postOrder(Node* node) {
        stack<Node*>st;
        vector<int>ans;
        st.push(node);

        while(!st.empty()){   //Iterate till stack is empty
          Node* temp=st.top();
          st.pop();

          ans.push_back(ans.begin(), temp->data);

          if(temp->left!=NULL){
            st.push(temp->left);
          }
          
          if(temp->right!=NULL){
            st.push(temp->right);
          }
        }
        return ans;
    }
};



//Third Solution :-
vector<int> postOrder(Node* node) {
    vector<int> res;
    stack<Node*> st;
    st.push(node);
    while(!st.empty()) {
        Node* top = st.top();
        if(top -> left) {
            st.push(top -> left);
            top -> left = NULL;
        } else if(top -> right) {
            st.push(top -> right);
            top -> right = NULL;
        } else {
            res.push_back(top -> data);
            st.pop();
        }
    }
    return res;
}