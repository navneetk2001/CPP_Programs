https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1




//Solution Approach :-
int getMaxWidth(Node* root) {
    queue<Node*> q;
    q.push(root);

    int ans = INT_MIN;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        ans = max(ans, size);
    }
    return ans;
}




//Second Solution :-
int getMaxWidth(Node* root) {
    if(root == NULL) return 0;
    int ans = INT_MIN;
    queue<Node* > q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        ans = max(size,ans);
        
        while(size--)
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}



//Third Solution :-
vector<int> v;
void traverse(Node *root, int level){
    if(!root) return;
    if(v.size() < level + 1) v.push_back(1);
    else v[level]++;
    traverse(root->left, level + 1);
    traverse(root->right, level + 1);
}

int getMaxWidth(Node* root) {
    traverse(root, 0);
    return (root)?(*max_element(v.begin(), v.end())):0;
}




//Slightly Different Question on leetcode :- Different Solution (LeetCode Accepted)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});      // also can use make_pair
        
        while(!q.empty()){
            int cnt = q.size();
     
            int start = q.front().second;  // start is the index of root node for first level
            int end = q.back().second;
            
            res = max(res,end-start + 1);
            
            for(int i = 0; i <cnt; ++i){
                pair<TreeNode*, int> p = q.front();           // we will use it while inserting it children
                
                TreeNode* node = p.first;
                int idx = p.second - start;                
                q.pop();
                
                // if  left child exist
                if(p.first->left != NULL){          // left child index will be 2 * idx + 1;
                    q.push({node->left, (long long)2 * idx + 1});
                }
                
                // if right child exist
                if(p.first->right != NULL){           // right child will be 2 * idx + 2;
                    q.push({node->right, (long long) 2 * idx + 2});
                }
            }
        }
        return res;
    }
};