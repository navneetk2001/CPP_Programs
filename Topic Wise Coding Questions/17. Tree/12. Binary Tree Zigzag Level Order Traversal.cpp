Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:
Input:
        3
      /   \
     2     1
Output:
3 1 2

Example 2:
Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 


//Solution :-
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while ( !nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = node->val;
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            // after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};



//Another Solution :-
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int>ans;
        if (!root)
            return ans;
    
        // declare two stacks
        stack<struct Node*> currentlevel;
        stack<struct Node*> nextlevel;
    
        // push the root
        currentlevel.push(root);
    
        // check if stack is empty   
        bool lefttoright = true;
        while (!currentlevel.empty()) {
    
            // pop out of stack
            struct Node* temp = currentlevel.top();
            currentlevel.pop();
    
            // if not null
            if (temp) {
    
                // print the data in it
                ans.push_back(temp->data);
    
                // store data according to current
                // order.
                if (lefttoright) {
                    if (temp->left)
                        nextlevel.push(temp->left);
                    if (temp->right)
                        nextlevel.push(temp->right);
                }
                else {
                    if (temp->right)
                        nextlevel.push(temp->right);
                    if (temp->left)
                        nextlevel.push(temp->left);
                }
            }
    
            if (currentlevel.empty()) {
                lefttoright = !lefttoright;
                swap(currentlevel, nextlevel);
            }
        }
    }
};