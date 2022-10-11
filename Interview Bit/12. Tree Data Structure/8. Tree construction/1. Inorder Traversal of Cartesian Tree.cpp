// Given an inorder traversal of a cartesian tree, construct the tree.
// Cartesian tree :  is a heap ordered binary tree, where the root is greater than all the elements in the subtree.
// Note: You may assume that duplicates do not exist in the tree.

// Example :
// Input : [1 2 3]
// Return :   
//           3
//          /
//         2
//        /
//       1


//Solution Approach :- 
// Inorder traversal : (Left tree) root (Right tree)
// Note that the root is the max element in the whole array. Based on the info, can you figure out the position of the root in inorder traversal ? If so, can you separate out the elements which go in the left subtree and right subtree ?
// Once you have the inorder traversal for left subtree, you can recursively solve for left subtree. Same for right subtree.


//First Solution :-
TreeNode* helper(vector<int>&A, int i, int j){
	if(i>j){
		return NULL;   //base case
	}

	int max_ele=INT_MIN, index;
	for(int k=i;k<=j;k++){
		if(A[k]>max_ele){
			max_ele=A[k];
			index=k;
		}
	}
	TreeNode *root = new TreeNode(max_ele);
	root->left = helper(A,i,index-1);
	root->right = helper(A,index+1,j);
	return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    return helper(A,0,A.size()-1);
}



//Second Solution :-
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



//Fourth Solution :-

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

