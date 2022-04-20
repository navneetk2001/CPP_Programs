       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

//Iterative Solution :-
vector<int> topView(Node *root)
{
   vector<int> ans;  // creat vector in which we will store top view element
   if(root==NULL)
       return ans;   // simply return empty vector if root is null
   map<int,int> mp;   // creat map in which we store line as a key and corresponding node will its value 
   
   queue<pair<Node*,int>>q;  // we will use queue data structure in which first Node and its corresponding line on which it lies 
   q.push({root,0});   // Initially we will store the root and assign line zero to 
   
   while(!q.empty())   // initiate queue and run it untill become empty
   {
       auto it=q.front();    // store the front of the queue in auto variable
       
       q.pop();      // delete it 
       Node* node=it.first;  // creat new variable node and store the first value of it 
       int line=it.second;    // and second will be its line 
       if(mp.find(line)==mp.end())   // now find that particular line is present in the map or not if not then insert it otherwise escape 
           mp[line]=node->data;
       if(node->left!=NULL)   // now move to its left side and inserting accordingly
           q.push({node->left,line-1});
       if(node->right!=NULL)   // similary for the right nodes and insert accordingly
           q.push({node->right,line+1});
    
   }
   
   for(auto it:mp)
   {
       ans.push_back(it.second);   // now push that particular 
   }
   
   
   return ans;
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
 