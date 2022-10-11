// Given a binary tree, flatten it to a linked list in-place.

// Example : Given
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
// Note that the left child of all nodes should be NULL.


//First Solution :- Iterative Solution : Using Intuition behind Morris Traversal.

// The algorithm can be described as:
// At a node(say cur) if there exists a left child, we will find the rightmost node in the left subtree(say prev).
// We will set prev’s right child to cur’s right child,
// We will then set cur’s right child to it’s left child.
// We will then move cur to the next node by assigning cur it to its right child
// We will stop the execution when cur points to NULL.

TreeNode* Solution::flatten(TreeNode* a){
    TreeNode *root = a;
    while(a) {
        if(a->left) {
            TreeNode *temp=a->left;
            while(temp->right){ 
            	temp=temp->right;
            }

            temp->right=a->right;
            a->right=a->left;
            a->left=NULL;
        }
        a=a->right;
    }

    return root;
}



//Second Solution :- Recursive Solution
TreeNode* Solution::flatten(TreeNode* A) {
	if(!A) 
		return NULL;

	TreeNode* temp = A->right;
	A->right = flatten(A->left);
	A->left = NULL;

	TreeNode *var = A;
	while(var->right) 
		var = var->right;

	var->right = flatten(temp);
	return A;
}


//Second Solution :- Second Recursive Approach

// Approach: 
// The algorithm steps can be stated as: 
// If we observe, we are moving in a reverse postorder way : i.e  right, left, root. 
// We take a reference variable (say prev) to store the previous node( initialized to NULL).
// Whenever we visit a node, we set the right child to the prev and left child to NULL. 
// Next we assign this current node to prev.
// We perform the above two operations on all the nodes in the traversal.

class Solution {
  node * prev = NULL;
  public:
    void flatten(node * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }
};


//Third Solution :- Iterative Solution_Stack

// The algorithm approach can be stated as: 
// Take a stack and push the root node to it.
// Set a while loop till the stack is non-empty.
// In every iteration, take the node at the top of the stack( say cur) and pop the stack.
// If cur has a right child, push it to the stack.
// If cur has a left child, push it to the stack.
// Set the right child of cur to node at stack’s top.
// Set the left child of cur as NULL.


void flatten(node * root) {
	if(root == NULL) 
		return;

	stack<node*>st;
	st.push(root);
	
	while (!st.empty()) {
		node * cur = st.top();
		st.pop();

		if (cur -> right != NULL) {
		    st.push(cur -> right);
		}

		if (cur -> left != NULL) {
		    st.push(cur -> left);
		}

		if (!st.empty()) {
		    cur -> right = st.top();
		}

		cur -> left = NULL;
	}
}


//Fourth Solution :-
#define null NULL

void rec(TreeNode* a){
    if(!a)
        return;
    cout<<a->val<<" ";
    rec(a->left);
    free(a->left);
    rec(a->right);
    free(a->right); 
}

TreeNode* Solution::flatten(TreeNode* A) {
    if(!A)
        return null;
    if(!A->left && !A->right)
        return A;
    rec(A);
    return null;
}