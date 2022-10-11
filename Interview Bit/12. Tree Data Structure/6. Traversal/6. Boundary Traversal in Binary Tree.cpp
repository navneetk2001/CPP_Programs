// Write a program for the Anti-Clockwise Boundary traversal of a binary tree.
// The boundary nodes of a binary tree include nodes from the left boundary, right boundary and the leaf nodes without duplicate nodes. However, the values from the nodes may contain duplicates. 

// Sample Input 1:
// 2
// 1 2 3 4 -1 5 -1 -1 -1 -1 -1
// 1 2 -1 3 -1 4 -1 -1 -1

// Sample Output 1:
// 1 2 4 5 3 
// 1 2 3 4

// Explanation Of Sample Input 1:
// For the first test case, we have 1 as the root node. 2, 4 as left boundary nodes. 3, 5 as the right boundary nodes. We don't have any leaf nodes.
// For the second test case, we have 1 as the root node. 2, 3 as the left boundary nodes and 4 as a leaf node. We don't have any right boundaries.


//Approach :-
// Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

// Part 1: Left Boundary of the tree (excluding the leaf nodes).
// Part 2: All the leaf nodes travelled in the left to right direction.
// Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.
// We take a simple data structure like a vector/Arraylist to store the Boundary Traversal. The root node is coming from both the boundaries (left and right). Therefore, to avoid any confusion, we push it on our list at the very start.

// Part 1:  Left Boundary
// 	To traverse the left boundary, we can set a simple iteration. Initially, we make the cur pointer point to the root’s left. In every iteration, if the cur node is not a leaf node, we print it. Then we always try to move left of the cur pointer. If there is no left child, then we move to the right of cur and in the next iteration, again try to move to the left first. We stop our execution when cur is pointing to NULL. 
// Part 2: Leaf nodes
// 	To print the leaf nodes, we can do a simple preorder traversal, and check if the current node is a leaf node or not. If it is a leaf node just print it.
// Part 3: Right Boundary
// 	We need to print the right boundary in the Reverse direction. It is very similar to the left boundary traversal. We initialize our cur pointer to the right child of the root node and set an iterative loop. To achieve the reverse direction, we take an auxiliary list. In every iteration, we check if the current node is not a leaf node then we push it to the auxiliary list. Then we first try to move right of cur, if there is no right child only then we move left. We stop our execution once cur points to NULL.
// 	Now the auxiliary list contains the nodes of the right boundary. We iterate from the end to start off this list and in every iteration, push the value to our main boundary traversal list. This way we get the nodes in the reverse direction.


//Code :-
#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}


bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}

void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }

  if (root -> left) {
  	addLeaves(root -> left, res);
  }

  if (root -> right){
   addLeaves(root -> right, res);
  }

}

vector<int> printBoundary(node * root) {
  vector<int> res;
  if (!root) return res;

  if (!isLeaf(root)){ 
  	res.push_back(root -> data);
  }

  addLeftBoundary(root, res);
  addLeaves(root, res);   // add leaf nodes
  addRightBoundary(root, res);

  return res;
}


