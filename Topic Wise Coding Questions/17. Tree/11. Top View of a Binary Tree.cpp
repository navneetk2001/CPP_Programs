       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

//Iterative Solution :-

// Structure of binary tree
struct Node {
    Node* left;
    Node* right;
    int hd;
    int data;
};
 
// function to create a new node
Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
 
// function should print the topView of
// the binary tree
void topview(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
 
    // push node and horizontal distance to queue
    q.push(root);
 
    cout << "The top view of the tree is : \n";
 
    while (q.size()) {
        hd = root->hd;
 
        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
}



//Recursive Solution :-
// Node structure
struct Node {
    // Data of the node
    int data;
 
    // Horizontal Distance of the node
    int hd;
 
    // Reference to left node
    struct Node* left;
 
    // Reference to right node
    struct Node* right;
};
 
// Initialising node
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->hd = INT_MAX;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
void printTopViewUtil(Node* root, int height,
    int hd, map<int, pair<int, int> >& m)
{
    // Base Case
    if (root == NULL)
        return;
 
    // If the node for particular horizontal distance
    // is not present in the map, add it.
    // For top view, we consider the first element
    // at horizontal distance in level order traversal
    if (m.find(hd) == m.end()) {
        m[hd] = make_pair(root->data, height);
    }
    else{
        pair<int, int> p = (m.find(hd))->second;
                 
        if (p.second > height) {
            m.erase(hd);
            m[hd] = make_pair(root->data, height);
        }
    }
 
    // Recur for left and right subtree
    printTopViewUtil(root->left, height + 1, hd - 1, m);
    printTopViewUtil(root->right, height + 1, hd + 1, m);
}
 
void printTopView(Node* root)
{
    // Map to store horizontal distance,
    // height and node's data
    map<int, pair<int, int> > m;
    printTopViewUtil(root, 0, 0, m);
 
    // Print the node's value stored by printTopViewUtil()
    for (map<int, pair<int, int> >::iterator it = m.begin();
                                        it != m.end(); it++) {
        pair<int, int> p = it->second;
        cout << p.first << " ";
    }
}
 