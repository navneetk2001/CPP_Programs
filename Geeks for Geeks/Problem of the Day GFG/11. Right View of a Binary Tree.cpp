Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side. 

Right view of following tree is 1 3 7 8

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
                  \
                   8


void rightViewUtil(struct Node *root, int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the last Node of its level
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }
 
    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
 
// A wrapper over rightViewUtil()
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}



//Second Method :-
void printRightView(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        // get number of nodes for each level
        int n = q.size();
 
        // traverse all the nodes of the current level
        while (n--) {
 
            Node* x = q.front();
            q.pop();
 
            // print the last node of each level
            if (n == 0) {
                cout << x->data << " ";
            }
            // if left child is not null push it into the
            // queue
            if (x->left)
                q.push(x->left);
            // if right child is not null push it into the
            // queue
            if (x->right)
                q.push(x->right);
        }
    }
}