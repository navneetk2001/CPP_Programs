// Given the root of a binary tree A, the value of a target node B, and an integer C, return an array of the values of all nodes that have a distance C from the target node.
// You can return the answer in any order.

// Input 1:
// A =     1
//        / \
//       2   3
//      / \
//     4   5
// B = 2
// C = 1
// Output 1: [1, 4, 5]
// Explanation 1: For the given tree, we have target node as 2. All the nodes with are at distance 1, meaning the adjacent nodes are [1, 4, 5].


// Input 2:
// A =     1
//        / \
//       2   3
//      / \
//     4   5
// B = 2
// C = 2
// Output 2: [3]
// Explanation 2: The given tree is same, and [3] is the only node with distance 2.


//Hint :-
//How do we traverse to the parent of a node?

//Solution Approach :- 
// Traverse every node with a depth first search dfs. 
// We'll add all nodes x to the answer such that node is the node on the path from x to target that is closest to the root.
// To help us, dfs(node) will return the distance from node to the target. Then, there are 4 cases:
// 1) If node == B, then we should add nodes that are distance C in the subtree rooted at target.
// 2) If target is in the left branch of node, say at distance L+1, 
//    then we should look for nodes that are distance C - L - 1 in the right branch.
// 3) If target is in the right branch of node, the algorithm proceeds similarly.
// 4) If target isn't in either branch of node, then we stop.
// In the above algorithm, we make use of the auxillary function subtree_add(node, dist) 
// which adds the nodes in the subtree rooted at node that are distance C - dist from the given node.


//First Solution :- For InterviewBit
map<TreeNode*, TreeNode*> parent;
TreeNode* target;
vector<int> ans;
void dfs(TreeNode* root, int B){
    if(root->val==B){
        target = root;
    }
    if(root->left!=NULL){
        parent[root->left] = root;
        dfs(root->left, B);
    }
    if(root->right!=NULL){
        parent[root->right] = root;
        dfs(root->right, B);
    }
}

void bfs(int C){
    
    map<TreeNode*, int> depth;
    queue<TreeNode*> q;
    q.push(target);
    depth[target] = 0;
    
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        
        if(parent.find(cur)!=parent.end()){
            TreeNode* t = parent[cur];
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
        
        if(cur->left!=NULL){
            TreeNode* t = cur->left;
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
        
        if(cur->right!=NULL){
            TreeNode* t = cur->right;
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
    }
}

vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    parent.clear();
    ans.clear();
    dfs(A, B);
    bfs(C);
    return ans;
}


//Second Solution :- For InterviewBit
vector<int>res;

void add(TreeNode *root,int dist){
    if(!root) return;
    if(dist<0) return;
    if(dist==0) {
        res.push_back(root->val);
        return;
    }
    add(root->left,dist-1);
    add(root->right,dist-1);        
}

int dfs(TreeNode* root, int target, int k){
    if(!root) return -1;
    if(root->val==target){
        add(root,k);
        return k-1;
    }
    int left=dfs(root->left,target,k);
    if(left!=-1){
        if(left==0) res.push_back(root->val);
        add(root->right,left-1);
        return left-1;
    }
    int right=dfs(root->right,target,k);
    if(right!=-1){
        if(right==0) res.push_back(root->val);
        add(root->left,right-1);
        return right-1;
    }
    return -1;
}

vector<int> Solution::distanceK(TreeNode* root, int target, int k) {
    res.clear();
    dfs(root,target,k);
    return res;
}



// Solution :- For InterviewBit
void find(TreeNode* A,int C,vector<int>& v)
{
    if(A==NULL || C<0)
    {
        return;
    }
    if(C==0)
    {
        v.push_back(A->val);
        return;
    }
    find(A->left,C-1,v);
    find(A->right,C-1,v);
}
int solve(TreeNode* A,int B,int C,vector<int>& v)
{
    if(A==NULL)
    {
        return -1;
    }
    if(A->val==B)
    {
        find(A,C,v);
        return 0;
    }
    int dl=solve(A->left,B,C,v);
    if(dl!=-1)
    {
        if(dl+1==C)
        {
            v.push_back(A->val);
        }
        else
        {
            find(A->right,C-dl-2,v);
        }
        return 1+dl;
    }
    int dr=solve(A->right,B,C,v);
    if(dr!=-1)
    {
        if(dr+1==C)
        {
            v.push_back(A->val);
        }
        else
        {
            find(A->left,C-dr-2,v);
        }
        return 1+dr;
    }
    return -1;
}

vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
	vector<int>v;
	v.clear();
	solve(A,B,C,v);
	return v;
}



//Third Solution :- 
class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track, target); 
        
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};


//Fourth Solution :- 
class Solution {
public:
    vector<int> ans;   
    map<TreeNode*, TreeNode*> parent;  // son=>parent  
    set<TreeNode*> visit;    //record visied node
    
    void findParent(TreeNode* node){
        if(!node ) return;
        if( node->left ){
            parent[node->left] = node;
            findParent(node->left);
        }
        if( node->right){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if( !root ) return {};
        
        findParent(root);
        dfs(target, K );
        return ans;
    }
    
    void dfs( TreeNode* node, int K){
        if( visit.find(node) != visit.end() )
            return;
        visit.insert(node);
        if( K == 0 ){
            ans.push_back(node->val);
            return;
        }
        if( node->left ){
            dfs(node->left, K-1);
        }
        if( node->right){
            dfs(node->right, K-1);
        }
        TreeNode* p = parent[node];
        if( p )
            dfs(p, K-1);
    }
};

