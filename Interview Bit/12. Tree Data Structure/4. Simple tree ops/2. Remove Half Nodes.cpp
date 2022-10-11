// Given a binary tree A with N nodes.
// You have to remove all the half nodes and return the final binary tree.
// NOTE:
// Half nodes are nodes which have only one child.
// Leaves should not be touched as they have both children as NULL.

// Input 1:

//            1
//          /   \
//         2     3
//        / 
//       4
// Output 1:
//            1
//          /   \
//         4     3
// Explanation 1: The only half node present in the tree is 2 so we will remove this node.
        
// Input 2:
//             1
//           /   \
//          2     3
//         / \     \
//        4   5     6
// Output 2:
//             1
//           /   \
//          2     6
//         / \
//        4   5
// Explanation 2: The only half node present in the tree is 3 so we will remove this node.


//Hint :-
// -> 4 case to take care of
// 	1) No child : return root
// 	2) Both child : connect left child and right child then retrun root
// 	3) No left child: return right child.
// 	4) NO right child : return left child.

//Solution Approach :- 
// The idea is to use post-order traversal to solve this problem efficiently.
// We first process the left children, then right children, and finally the node itself.
// So we form the new tree bottom up, starting from the leaves towards the root.
// By the time we process the current node, both its left and right subtrees were already processed.

// Time Complexity of the above solution is O(N) as it does a simple traversal of binary tree.
// Space Complexity- O(1)


//First Solution :-
TreeNode* Solution::solve(TreeNode* A) {
    if(!A){
        return NULL;
    }
    if(A->left and A->right){
        A->left = solve(A->left);
        A->right = solve(A->right);
    }
    else if(A->left){
        A = solve(A->left);
    }
    else if(A->right){
        A = solve(A->right);
    }
    return A;
}


//Second Solution :-
TreeNode* Solution::solve(TreeNode* a) {
	if(a==NULL){
		return NULL;
	}

	a->left=solve(a->left);
	a->right=solve(a->right);

	if(a->left==NULL&&a->right==NULL){
		return a;
	}

	if(a->left==NULL){
	    return a->right;
	}

	if(a->right==NULL){
	    return a->left;
	}

	return a;    
}


//Third Solution :- 
TreeNode* Solution::solve(TreeNode* A) {
    if(A->left == NULL && A->right == NULL){
    	return A;
    }
    if(A->left == NULL){
        return solve(A->right);
    }
    if(A->right == NULL){
        return solve(A->left);
    }
    
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
    
}

