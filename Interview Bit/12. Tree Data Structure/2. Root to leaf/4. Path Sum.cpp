// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// Example :
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

//Solution Approach :- 
Recursion might make this problem much easier to solve.
You just need to keep a track of the sum from the root to the current node.
Then it becomes a question of just checking if the current node is a leaf node, and if so, do the sum match.

//First Solution :-
int PathSum(TreeNode* A,int B, int sum){ 
    sum+=A->val;
    if(A->left==NULL && A->right==NULL && sum==B) 
        return 1;

    if(A->left==NULL && A->right==NULL) 
        return 0;

    int l=0,r=0;
    if(A->left){
        l=PathSum(A->left,B,sum);
    }

    if(A->right){
        r=PathSum(A->right,B,sum);
    }

    return l||r;

}

int Solution::hasPathSum(TreeNode* A, int B) {
     return PathSum(A,B,0);
}

//Second Solution :-
class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if (root == NULL) return false;
            if (root->left == NULL && root->right == NULL) {
                return sum == root->val;
            }
            int remainingSum = sum - root->val;
            return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
        }
};


//Third Solution :- 
int Solution::hasPathSum(TreeNode* A, int B) {
    if (A == NULL)
        return 0;
    B -= A->val;

    if (A->left == NULL && A->right == NULL && B == 0)
        return 1;
    int left = hasPathSum(A->left, B);
    int right = hasPathSum(A->right, B);
    free(A->left);
    free(A->right);
    return left || right;
}


//Fourth Solution :- Iterative
int Solution::hasPathSum(TreeNode* A, int B) {
	int sum=0;
	queue<pair<TreeNode*,int>>s;

	s.push({A,A->val});
	while(!s.empty()){
		TreeNode* curr=s.front().first;

		sum=s.front().second;
		s.pop();

		if(sum==B && !curr->left && !curr->right){
			return 1;
		}

		if(curr->left){
			s.push({curr->left,sum+curr->left->val});
		}

		if(curr->right){
			s.push({curr->right,sum+curr->right->val});
		}

	}
	return 0;
}