// You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:
// 	Create a root node whose value is the maximum value in nums.
// 	Recursively build the left subtree on the subarray prefix to the left of the maximum value.
// 	Recursively build the right subtree on the subarray suffix to the right of the maximum value.
// Return the maximum binary tree built from nums.

 

// Example 1:
// Input: nums = [3,2,1,6,0,5]
// Output: [6,3,5,null,2,0,null,null,1]
// Explanation: The recursive calls are as follow:
// - The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
//     - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
//         - Empty array, so no child.
//         - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
//             - Empty array, so no child.
//             - Only one element, so child is a node with value 1.
//     - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
//         - Only one element, so child is a node with value 0.
//         - Empty array, so no child.

// Example 2:
// Input: nums = [3,2,1]
// Output: [3,null,2,null,1]



//Solution Approach :-
class Solution {
public:
    int getmax(vector<int>&arr , int l , int r){
        int idx = 0 ; 
        int mx = INT_MIN ; 
        for(int i = l ; i<=r ; i++){
            if(arr[i] > mx){
                mx = arr[i] ; 
                idx = i ; 
            }
        }
        return idx ; 
    }
    
    TreeNode* solve(vector<int>&arr , int l , int r) {
        if ( l > r) return NULL ; 
      
        int i = getmax(arr , l , r) ; 
        TreeNode* newnode = new TreeNode(arr[i]) ; 
        newnode->left = solve(arr , l , i-1) ; 
        newnode->right = solve(arr , i+1 , r) ; 
        return newnode ; 
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& arr) {
        if ( arr.size() == 0 ) return NULL ;
        return solve(arr , 0 , arr.size() - 1) ; 
    }
};


//Solution :-
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        // Base Condition
        if (nums.size() == 0) {
            return nullptr;
        }
        
        // Induction
        int maxVal = *max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(maxVal);
        
        int maxValIdx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxVal) {
                maxValIdx = i;
                break;
            }
        }
                
        vector<int> prefix(nums.begin(), nums.begin() + maxValIdx);
        vector<int> suffix(nums.begin() + maxValIdx + 1, nums.end());
                
        // Hypothesis
        root->left = constructMaximumBinaryTree(prefix);
        root->right = constructMaximumBinaryTree(suffix);
        
        return root;
    }
};




//Second Solution :-

// The key idea is:
// 	We scan numbers from left to right, build the tree one node by one step;
// 	We use a stack to keep some (not all) tree nodes and ensure a decreasing order;
// 	For each number, we keep pop the stack until empty or a bigger number; The bigger number (if exist, it will be still in stack) is current number's root, and the last popped number (if exist) is current number's left child (temporarily, this relationship may change in the future); Then we push current number into the stack.

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int i = 0; i < nums.size(); ++i){
            TreeNode* cur = new TreeNode(nums[i]);
            while (!stk.empty() && stk.back()->val < nums[i])
            {
                cur->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};



//Third Solution :-
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
  map<int, TreeNode*> q;
  for (int num : nums) {
    auto it = q.insert({ num, new TreeNode(num) }).first;
    if (it != q.begin()) {
      it->second->left = next(it, -1)->second;
      q.erase(q.begin(), it);
    }
    if (next(it, 1) != q.end()) next(it, 1)->second->right = it->second;
  }
  return q.rbegin()->second;
}
