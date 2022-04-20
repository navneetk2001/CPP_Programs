Given an integer array A with distinct elements, which represents the preorder traversal of a binary search tree,
onstruct the tree and return its root.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Input 1:
A = [2, 1, 4, 3, 5]
Input 2:
A = [1, 2, 3]

Output 1:
    2
   / \
  1   4
     / \
    3   5
Output 2:
      1
     /
    2
   /
  3

Explanation 1: We can see that is the tree created by the given pre order traversal.
Explanation 2: We can see that is the tree created by the given pre order traversal

//Hint :-
Can you construct a Binary Tree from its given preorder and inorder traversal?

//Solution Approach :- 
Since, the given binary tree is a BST. The inorder traversal is the ascending order of the keys in the tree.
We can simply find that out by sorting and then our time complexity would be O(N log N).

But, we can further optimize it by using the fact that the inorder traversal above was used only to check 
if the element could be placed in this subtree.
We can do this recursively. 
1) Initiate the lower and upper limits as negative and positive infinity because one could always place the root.
2) Start from the first element in the preorder array idx = 0.
3) Return helper(lower, upper):
    a) If the preorder array is used up idx = n then the tree is constructed, return null.
    b) If current value val = preorder[idx] is smaller then lower limit, or larger than upper limit, return null.
    c) If the current value is in the limits, place it here root = TreeNode(val) and proceed to construct 
       recursively left and right subtrees: root.left = helper(lower, val) and root.right = helper(val, upper).
4) Return root.


//First Solution :-
TreeNode* build(vector<int>& A, int& i, int bound) {
    if (i == A.size() || A[i] > bound) return NULL;
    TreeNode* root = new TreeNode(A[i++]);
    root->left = build(A, i, root->val);
    root->right = build(A, i, bound);
    return root;
}

TreeNode* Solution::constructBST(vector<int> &A) {
    int i = 0;
    return build(A, i, INT_MAX);
}

//Second Solution :-
// O(N) - NO TLE
TreeNode* Solution::constructBST(vector<int> &A) {
    TreeNode* root = new TreeNode(A[0]);
    stack<TreeNode*> s;
    s.push(root);

    TreeNode* temp;
    int idx = 1;
    while(idx<A.size()){
        temp = NULL;
        TreeNode* curr = new TreeNode(A[idx]);
        while(!s.empty() && s.top()->val<A[idx]){
            temp = s.top();
            s.pop();
        }
        if(temp){
            temp->right = curr;
        }
        else{
            s.top()->left = curr;
        }
        s.push(curr);
        idx++;
    }

    return root;
}


//Third Solution :- 
// O(N) - BUT TLE

// TreeNode* fun(vector<int> preorder, int st, int en, unordered_map<int,int> &m){
//     if(st>en){
//         return NULL;
//     } 
//     TreeNode* n = new TreeNode(preorder[st]);
//     if(st==en){
//         return n;
//     }
//     int pos = m[n->val];
//     n->left = fun(preorder, st+1, pos, m); 
//     n->right = fun(preorder, pos+1, en, m); 
//     return n;
// }

// TreeNode* Solution::constructBST(vector<int> &A) {
//     unordered_map<int,int> m;
//     int i = 0;
//     stack<int> s;
//     // cout<<"ok"<<endl;
//     while(i<A.size()){
//         int minElemIdx = (s.empty()==true? -1:s.top());
//         while(!s.empty() && A[s.top()]<A[i]){
//             m[A[s.top()]] = minElemIdx;
//             s.pop();
//             // cout<<"k"<<endl;
//         }
//         // cout<<"k"<<endl;
//         s.push(i);
//         m[A[s.top()]] = i;
//         i++;
//     }
//     // cout<<"ok"<<endl;
//     int minElemIdx = s.top();
//     while(!s.empty()){
//         m[A[s.top()]] = minElemIdx;
//         s.pop();
//     }
//     // cout<<"ok"<<endl;
//     // for(auto t:m){
//     //     cout<<t.first<<" "<<t.second<<endl;
//     // }
//     TreeNode* ans = fun(A, 0, A.size()-1, m);
//     return ans;
// }

