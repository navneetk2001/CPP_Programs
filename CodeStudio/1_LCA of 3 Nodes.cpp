/*
Problem Statement :-

You have been given a Binary Tree of 'N' nodes where the nodes have integer values 
and three integers 'N1', 'N2', and 'N3'. 
Find the LCA(Lowest Common Ancestor) of the three nodes represented by the given three
('N1', 'N2', 'N3') integer values in the Binary Tree.
*/


// First Approach :- By Preorder Traversal

/*
In this method, we will traverse the tree in a depth-first manner to find the LCA. 
The moment we encounter either of three nodes ‘N1’, ‘N2’, or ‘N3’. we will return the node. 
The LCA would then be the node for which both the subtree recursions return a non-NULL node. 
LCA can also be the node which itself is one of ‘N1’, ‘N2’,  or ‘N3’ and for which one of the subtree 
recursions returns that particular node.

    Time Complexity: O(N)
    Space Complexity: O(N)
    
    Where N is the total nodes in binary tree.

*/

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    if (root == NULL) {
        return NULL;
    }

    // Check if root is any of the three nodes.
    if (root->data == node1 || root->data == node2 || root->data == node3) {
        return root;
    }

    BinaryTreeNode<int>* left = lcaOfThreeNodes(root->left, node1, node2, node3);
    BinaryTreeNode<int>* right = lcaOfThreeNodes(root->right, node1, node2, node3);

    // If both subtree return not-Null value it means current node could be LCA.
    if (left != NULL && right != NULL) {
        return root;
    }
    // If left subbtree return not-null value then for now return node is LCA.
    else if (left != NULL) {

        return left;
    }
    // If right subbtree return not-null value then for now return node is LCA.
    else {
        return right;
    }
}







//Second Approach :-   By Storing Paths
//A simple solution would be to store the path from the root to ‘N1’, 
//the path from the root to ‘N2’, and the path from the root to ‘N3’ in the three auxiliary Lists/Array.
/*

    Time Complexity: O(N)
    Space Complexity: O(N)
    
    Where N is the total nodes in binary tree.

*/

#include <vector>

bool lcaOfThreeNodesHelper(int node, vector<BinaryTreeNode<int>*> &nodePath, BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return false;
    }

    nodePath.push_back(root);

    if (root->data == node) {
        return true;
    }

    bool leftSubTree = lcaOfThreeNodesHelper(node, nodePath, root->left);
    bool rightSubTree = lcaOfThreeNodesHelper(node, nodePath, root->right);

    if (leftSubTree || rightSubTree) {
        return true;
    }

    // Remove current node which is not in path from root to node.
    nodePath.pop_back();
    return false;
}

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    // Store the path from root to node1.
    vector<BinaryTreeNode<int>*> node1Path;

    // Store the path from root to node2.
    vector<BinaryTreeNode<int>*> node2Path;

    // Store the path from root to node3.
    vector<BinaryTreeNode<int>*> node3Path;

    // Find the path from root to node1.
    lcaOfThreeNodesHelper(node1, node1Path, root);

    // Find the path from root to node2.
    lcaOfThreeNodesHelper(node2, node2Path, root);

    // Find the path from root to node3.
    lcaOfThreeNodesHelper(node3, node3Path, root);

    // Traverse all lists simultaneously till the values in the list match.
    // The last matched value will be the LCA. If the end of one array is reached then the last seen value is LCA.
    int i;
    for (i = 0; i < node1Path.size() && i < node2Path.size() && i < node3Path.size(); i++) {

        if (node1Path[i]->data != node2Path[i]->data || node1Path[i]->data != node3Path[i]->data 
            || node2Path[i]->data != node3Path[i]->data) {
            break;
        }

    }

    return node1Path[i - 1];
}
