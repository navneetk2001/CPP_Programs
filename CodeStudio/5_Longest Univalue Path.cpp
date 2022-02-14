// Problem Statement :- Longest Univalue Path

/*
You are given a binary tree, the task is to find out the length of the longest path which contains nodes with the exact same value. 
It is not necessary for the path to pass through the root of the binary tree.
Between two nodes, the length of the path can be defined as the number of edges contained between them.
*/

//First Approach :-
#include<bits/stdc++.h>
int findHeight(BinaryTreeNode<int> *root, int data){
        if(root==NULL)
            return 0;
        if(root->data!=data)
            return 0;
        return 1+max(findHeight(root->left,data),findHeight(root->right,data));
    }

int longestUnivaluePath(BinaryTreeNode<int> *root) {
    // Write yout code here
    // return maximum Longest Path Value
    if(root==NULL){
            return 0;
    }
    int lmax = findHeight(root->left,root->data);
    int rmax = findHeight(root->right,root->data);
    return max(lmax+rmax,max(longestUnivaluePath(root->left),longestUnivaluePath(root->right)));
}



//Second Approach :-
#include<bits/stdc++.h>
int dfs(BinaryTreeNode<int> * node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->data == node->data ? l + 1 : 0;
        int resr = node->right && node->right->data == node->data ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }

int longestUnivaluePath(BinaryTreeNode<int> *root) {
    // Write yout code here
    // return maximum Longest Path Value
    int lup = 0;
        if (root) dfs(root, lup);
        return lup;
}




// C++ program to find the length of longest path with same values in a binary tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node {
int val;
struct Node *left, *right;
};

/* Function to print the longest path of same values */
int length(Node *node, int *ans) {
if (!node)
	return 0;

// Recursive calls to check for subtrees
int left = length(node->left, ans);
int right = length(node->right, ans);

// Variables to store maximum lengths in two directions
int Leftmax = 0, Rightmax = 0;

// If curr node and it's left child has same value
if (node->left && node->left->val == node->val)
	Leftmax += left + 1;

// If curr node and it's right child has same value
if (node->right && node->right->val == node->val)
	Rightmax += right + 1;

*ans = max(*ans, Leftmax + Rightmax);
return max(Leftmax, Rightmax);
}

/* Driver function to find length of longest same value path*/
int longestSameValuePath(Node *root) {
int ans = 0;
length(root, &ans);
return ans;
}

/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
Node *newNode(int data) {
Node *temp = new Node;
temp->val = data;
temp->left = temp->right = NULL;
return temp;
}

// Driver code
int main() {
/* Let us construct a Binary Tree
     4
	/ \
	4 4
	/ \ \
	4 9 5 
*/

Node *root = NULL;
root = newNode(4);
root->left = newNode(4);
root->right = newNode(4);
root->left->left = newNode(4);
root->left->right = newNode(9);
root->right->right = newNode(5);
cout << longestSameValuePath(root);
return 0;
}
