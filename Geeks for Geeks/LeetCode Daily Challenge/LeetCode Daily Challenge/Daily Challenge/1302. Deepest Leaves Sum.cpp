Given the root of a binary tree, return the sum of values of its deepest leaves.
 
Example 1:
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19



//Solution Approach :-
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, i;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            for (i = q.size() - 1, res = 0; i >= 0; --i) {
                TreeNode* node = q.front(); q.pop();
                res += node->val;
                if (node->right) q.push(node->right);
                if (node->left)  q.push(node->left);
            }
        }
        return res;
    }
};


 
//Second Solution :- DFS traversal
//Approach :-
// We can do a simple Depth-First Traversal on the Tree. We can obviously do one dfs traversal and find the depth of the deepest level and in the second dfs pass, we will add only those nodes that are on the deepest level. But we don't actually need two passes. This can be done in just one DFS pass.
// We maintain sum which will store sum of values of deepest level nodes till now and deepest which will store the depth or level of the deepest nodes. There will be following cases available to us where current Node is -

// Not a Leaf Node - Traverse the left and right node of the current node.
// A Leaf Node - This case will have 3 sub-cases possible -
// 		depth > deepest - If current node is the deepest node observed till now, reset the sum to current node value and set deepest = depth.
// 		depth == deepest - The current node is part of the deepest nodes observed till now. Add current root value to sum.
// 		depth < deepest - This node is not the deepest node. Just ignore this node.
// A NULL Node - We can't traverse any further. So just return.
// Lastly, we will return the sum accumulated till now. The finaly value stored in sum will contain only the sum of value of the nodes (leaves) at deepest level.


int deepest = 0, sum = 0;
int deepestLeavesSum(TreeNode* root, int depth = 0) {
	if(!root) return 0;  // current node is NULL - just return.
	if(!root -> left && !root -> right) // if current is a leaf node
		if(depth == deepest) sum += root -> val;  // if depth is exactly equal to deepest, add to sum
		else if(depth > deepest) sum = root -> val, deepest = depth; // found a more deeper leaf node, reset sum and update deepest
	deepestLeavesSum(root -> left, depth + 1);   // recurse for the left, 
	deepestLeavesSum(root -> right, depth + 1);  // and the right node of the current node
	return sum; // finally return the sum accumulated till now which will be sum of value of deepest leaves
}



//Third Solution :- (BFS Traversal)

// We can also do a Breadth-First Traversal or Level-Order Traversal.
// In this we visit each depth level one by one. Just reset sum to 0 at start of each depth level and add the values of all nodes on that level. At the end, sum will store the sum of all values of the last level or the sum of values or deepest leaves.

int deepestLeavesSum(TreeNode* root) {
	int sum = 0, n;
	queue<TreeNode*> q; // required for level-order traversal
	q.push(root);
	while(!q.empty()){
		sum = 0, n = size(q); // reset sum when deeper level is reached and accumulate for that level
		for(int i = 0; i < n; i++){
			auto top = q.front(); q.pop();
			sum += top -> val;     
			if(top -> left) q.push(top -> left);
			if(top -> right) q.push(top -> right);
		}                
	}
	return sum; // final value held by 'sum' will be sum of values of nodes at the deepest level
}


//Fourth Solution :- Recursion
class Solution {
public:
    int get_depth(TreeNode* root){
        if(!root) 
        	return 0;
        return 1 + max(get_depth(root->left), get_depth(root->right));
    }

    int get_sum(TreeNode* root, int depth){
        if (!root) 
        	return 0;
        if (depth == 1) 
        	return root->val;
        return get_sum(root->left, depth-1) + get_sum(root->right, depth-1);
    }

    int deepestLeavesSum(TreeNode* root) {
        int depth = get_depth(root);
        int sum = get_sum(root, depth);
        return sum;
    }
};



//Important :- 
Q. DFS vs BFS. Which would be more efficient ? When would you prefer one over the other ?
Ans:- If you were to get such a problem in interview, it's very likely that the interviewer would proceed to ask a follow-up question such as this one. The DFS vs BFS is a vast topic of discussion. But one thing that's for sure (and helpful to know) is none is always better than the other. You would need to have an idea of probable structure of Tree/Graph that would be given as input (and ofcourse what you need to find depending on the question ) to make a better decision about which approach to prefer.
	  DFS is easy to implement and generally has advantage of being space-efficient, especially in a balanced / almost balanced Tree and the space required would be O(h) (where h is the height of the tree) while we would require O(2^h) space complexity for BFS traversal which could consume huge amount of memory when tree is balanced & for h is larger.
      On the other hand, BFS would perform well if you don't need to search the entire depth of the tree or if the tree is skewed and there are only few branches going very deep. In worst case, the height of a tree h could be equal to n and if there are huge number of nodes, DFS would consume huge amounts of memory & may lead to stackoverflow.
      In this question, the DFS performed marginally better giving better space efficiency than BFS. Again, this depends on the structure of trees used in the test cases.