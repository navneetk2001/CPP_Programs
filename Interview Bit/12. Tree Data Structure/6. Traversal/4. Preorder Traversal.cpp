Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree
   1
    \
     2
    /
   3
return [1,2,3].
Using recursion is not allowed.

//Hint :-
You can do this problem easily but as stated in problem recursion is not allowed here.
Stack can help you to avoid recursion. How?

//Solution Approach :- 
Think stack.
Recursive call would look something like this :
print(root->val);
preorderprint(root->left);
preorderprint(root->right);
Instead of calling the functions, can you put the nodes on a stack and process them ?


//First Solution :- Recursive solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }

private:
    void preorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        nodes.push_back(root -> val);
        preorder(root -> left, nodes);
        preorder(root -> right, nodes);
    }
};


//Second Solution :- Iterative solution using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            if (root) {
                nodes.push_back(root -> val);
                if (root -> right) {
                    todo.push(root -> right);
                }
                root = root -> left;
            } else {
                root = todo.top();
                todo.pop();
            }
        }
        return nodes;
    }
};


//Third Solution :- iterate, use stack to imitate recursive
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;
    if(!root) return v;
    TreeNode* temp = root;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        temp = s.top();
        s.pop();
        v.push_back(temp->val);
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
}


//Fourth Solution :- Morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    nodes.push_back(root -> val);
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};


