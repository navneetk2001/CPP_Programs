Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :
Given A : [1, 2, 3]
A height balanced BST  : 
      2
    /   \
   1     3


//Hint :-
What will happen when you choose middle element of array as root?
Can you simulate the same thing for the left and right part of the array after that?

//Solution Approach :- 
For a BST, all values lower than the root go in the left part of root, and all values higher go in the right part of the root.
For the tree to be balanced, we will need to make sure we distribute the elements almost equally in left and right part.
So we choose the mid part of the array as root and divide the elements around it .
Things to take care of :
1) Are you passing a copy of the array around or are you only passing around a reference ?
2) Are you dividing the array before passing onto the next function call or are you just specifying the start and end index ?


//First Solution :-
TreeNode* buildutil(const vector<int> &A, int start, int end){
    if (start>end) return NULL;

    int mid = start + (end-start)/2;
    TreeNode* root = new TreeNode(A[mid]);

    if(start == end){
        return root;
    } 
    else{
        root->left = buildutil(A, start, mid-1);
        root->right = buildutil(A, mid+1, end);
    }

    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return buildutil(A, 0, A.size()-1);
}


//Second Solution :-
class Solution {
public:
    TreeNode* helper(vector<int> &num, int low, int high) {
        if (low > high) { // Done
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(num[mid]);
        node->left = helper(num, low, mid - 1);
        node->right = helper(num, mid + 1, high);
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) return NULL;
        return helper(num, 0, ((int)num.size()) - 1);
    }
};

//Third Solution :- 


