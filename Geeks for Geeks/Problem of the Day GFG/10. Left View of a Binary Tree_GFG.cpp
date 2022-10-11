Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:
Input:
   1
 /  \
3    2
Output: 1 3



//Solution Approach :- Recursive
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);
    }
    
    vector<int> leftSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};



//Second Recursive Solution :-
int maxLevel=-1;               // Taking maxLevel initially as -1.
void leftView_Helper(TreeNode *node, int level){
    if(node==NULL){    // Base case i->e-> if node is NULL then return
        return;
    }
    
    // If the current level is greater than maxLevel so far.
    if(level>maxLevel){
        cout<<node->val<<" ";    // Print value of the node->
        maxLevel=level;    // Update maxLevel as level
    }
    
    leftView_Helper(node->left, 1 + level);     // Call for the left subtree and  increasing the level by 1.
    leftView_Helper(node->right, 1 + level);    // Call for the right subtree and increasing the level by 1.
}

void leftView(TreeNode *root){
    leftView_Helper(root, 0);     // Calling leftView_Helper with current level as 0->
}



//Second Solution :- using Hashing
void leftView_Helper(TreeNode *node, int level, auto &map){
    if(node==NULL) {    // Base case i->e-> if node is NULL then return
        return;
    }
    
    // If we have not visited this level yet, storing it in the Map.
    if(map.find(level)==map.end()){
        map[level]=node->val;
    }
    
    leftView_Helper(node->left, 1 + level,map);        // Call for the left subtree and  increasing the level by 1.    
    leftView_Helper(node->right, 1 + level,map);       // Call for the right subtree and increasing the level by 1.
}

void leftView(TreeNode *root){
    unordered_map<int, int> map;   // Create a map, to store node at each level.
 
    // Calling leftView_Helper with current level as 0
    leftView_Helper(root, 0,map);
    
    // Printing the data stored in the map. 
    for (int i = 0; i < map.size(); i++) {
        cout << map[i] << " ";
    }
}



//Second Solution :- Iterative
void leftView(TreeNode *root){
    if(root==NULL) 
        return;
    
    queue<TreeNode*> q;     // Creating a queue of TreeNode type for level order traversal.
    q.push(root);
    
    // Iterating while q is not empty. 
    while(!q.empty())
    {
        // Finding the current size of the queue.
        int size=q.size();
        for(int i=0;i<size;i++){            
            TreeNode *node=q.front();    // Polling the front entry of queue.
            q.pop();

            // If it is the first node of the current level, print it.
            if(i==0){
              cout<<node->val<<" ";
            }
            
            if(node->left!=NULL) {
                q.push(node->left);   // If node's left child is not null enqueue it.
            }
            if(node->right!=NULL){ 
                q.push(node->right);    // If node's left child is not  null enqueue it.
            }
        }
    }
}
