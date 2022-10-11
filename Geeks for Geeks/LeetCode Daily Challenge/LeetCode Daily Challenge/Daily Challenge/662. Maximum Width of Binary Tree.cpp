// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
// It is guaranteed that the answer will in the range of a 32-bit signed integer.

// Example 1:
// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

// Example 2:
// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

// Example 3:
// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2).



//Width :- No of nodes in a level between any two nodes
//We should find the index of first and last node in a level to calculate the width of that level
// left child index :-  will be 2 * idx + 1;
// right child index :- will be 2 * idx + 2;

//Solution Approach :-
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
     
            int start = q.front().second;       // start is the index of root node for first level
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




//Second Solution :- DFS Solution
class Solution {
public:
	unsigned long long ans = 1;
	void solve(TreeNode* root,vector<unsigned long long > &v, int l, unsigned long long p){
	    if(root == NULL){
	        return;
	    }
	    
	    if(v[l] == -1){
	        v[l] = p;
	    }
	    
	    ans = max(ans,p-v[l]+1);
	    
	    solve(root->left,v,l+1,2*p);
	    solve(root->right,v,l+1,2*p+1);
	}

	int widthOfBinaryTree(TreeNode* root) {
	    if(root == NULL){
	        return 0;
	    }
	    
	    vector<unsigned long long> v(3000,-1);
	    solve(root,v,0,1);
	    
	    return ans;
	}
};