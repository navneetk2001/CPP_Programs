Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:
Input:
   1
 /  \
3    2
Output: 1 3


void leftViewUtil(struct Node *root,int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
 
    // Recur for left subtree first, then right subtree
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

void rec(Node* root, vector<int>&ans, int &mx, int curr){
	if(root==NULL){
		return;
	}
	if(curr>mx){
		mx=curr;
		ans.push_back(root->data);
	}
	rec(root->left,ans,mx,curr+1);
	rec(root->right,ans,mx,curr+1);
}


vector<int> leftView(Node* root){
	vector<int>ans;
	int mx=0;
	rec(root,ans,mx,1);
	return ans;
}