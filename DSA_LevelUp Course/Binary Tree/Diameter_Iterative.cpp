#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

int max = INT_MIN; 
   
// Self explanatory, just updates max if value is greater than max.
private: 
    void updateMax(int value) {
        if (this.max < value) {
            this.max = value;
        }
    }



int diameterOfBinaryTree(Node root) {
    // Base case.
    if (root == NULL || (root.left == NULL && root.right == NULL)) {
        return 0;
    }
        
    unordered_map <Node, int> map;      // Instead of node.val we’re storing node, as there can be multiple nodes with same values.                       
    stack<Node> st;

    map.insert(root, 0);                       // Root’s children aren’t processed, so set value to 0.
    st.push(root);    
        
    while(!st.isEmpty()) {
        Node node = st.pop();
            
        if (map.find(node) != null && map.find(node) == 0) {
            map.insert(node, 1);               // This is to indicate we will now process children for this node 
            st.push(node);
                
            if (node.left != null) {
                st.push(node->left);
                map.insert(node->left, 0);
            }

            if (node.right != null) {
                st.push(node->right);
                map.insert(node->right, 0);
            }

        } 
        else 
        {
            // We enter here when we know both children of the popped node have been processed already.
            int lMax = node->left == null ? 0 : map.insert(node->left);           // Get longest path from left subtree.        
            int rMax = node->right == null ? 0 : map.insert(node->right);

            updateMax(1 + lMax + rMax);                            // This updates the max variable in case present value is greater. This indicates the path length which includes the popped node.      
            map.insert(node, max(lMax, rMax) + 1);               // Update popped node value in map so that it’s parent can use it.
        }
    }
    return this.max - 1;          // Subtract 1 since we need edge count, but we stored node count.
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    cout << "The diameter of the tree is " << getDiameter(root);
 
    return 0;
}
