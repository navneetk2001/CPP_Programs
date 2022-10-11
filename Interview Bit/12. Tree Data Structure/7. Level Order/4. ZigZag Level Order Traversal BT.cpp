Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : Given binary tree
    3
   / \
  9  20
    /  \
   15   7

return
[   [3],
    [20, 9],
    [15, 7]  
]

//Hint :-
// There are 2 approaches possible here.
// 1) Can you modify the level order approach to take care of this problem ? Reversing the entries in alternate row ?
// 2) If you don’t prefer reversing after the initial pass, can you instead use 2 stacks instead of queue to solve this problem ?

//Solution Approach :- 
// We will be using 2 stacks to solve this problem. One for the current layer and other one for the next layer. Also keep a flag which indicates the direction of traversal on any level.
// You need to pop out the elements from current layer stack and depending upon the value of flag push the childs of current element in next layer stack. You should maintain the output sequence in the process as well. Remember to swap the stacks before next iteration.
// When should you terminate this algorithm?


//First Solution :- Recursive
void preorder(int level, TreeNode* node, unordered_map<int,vector<int>> &hash){
    if(node==NULL){ 
    	return;
    }

    hash[level].push_back(node->val);
    preorder(level+1,node->left,hash);
    preorder(level+1,node->right,hash);
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    unordered_map<int,vector<int>> hash;
    vector<vector<int>> ans;
    
    int level = 0;
    preorder(level, A, hash);

    for(int i=0; i<hash.size(); i++){
        if(i%2!=0){
            reverse(hash[i].begin(),hash[i].end());
        }
        ans.push_back(hash[i]);
    }
    return ans;
}


//Second Solution :- Iterative
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



//Third Solution :- 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> solution;
    if(root == NULL){
        return solution;
    }

    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    
    bool zigzag=false;
    vector<int> level;
    TreeNode* temp;
    
    while(!q.empty()){
        temp = q.front();
        q.pop();
        
        if(temp == nullptr){
            if(!q.empty()){
                q.push(nullptr);
            }
            
            if(zigzag){
                reverse(level.begin(), level.end());
            }

            zigzag = !zigzag;
            solution.push_back(level);
            level.clear();
        }
        else{
            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right); 
            }
            level.push_back(temp->val);
        }
    }
    return solution;
}



//Fourth Solution :- 
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

