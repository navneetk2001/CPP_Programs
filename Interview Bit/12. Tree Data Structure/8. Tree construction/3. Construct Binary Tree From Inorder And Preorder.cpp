Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

Example :
Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]
Return :
            1
           / \
          2   3

//Hint :-
First element of preorder traversal will be root. Combine this info with inorder traversal. How can this help you?

//Solution Approach :- 
Focus on the preorder traversal to begin with.
The first element in the traversal will definitely be the root.
Based on this information, can you identify the elements in the left subtree and right subtree ? ( Hint : Focus on inorder traversal and root information )

Once you do that, your problem has now been reduced to a smaller set. Now you have the inorder and preorder traversal for the left and right subtree and you need to figure them out.
Divide and conquer.

Bonus points if you can do it without recursion.

//First Solution :-
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildTreeHelper(vector<int> &in, vector<int> &pre, int inStart, int inEnd, int preStart, int preEnd){
    if(inStart>inEnd){
        return NULL;
    }

    int rootData = pre[preStart];
    int rootIndex=-1;
    for(int i=inStart;i<=inEnd;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }

    int leftInStart = inStart;
    int leftInEnd = rootIndex-1;
    int leftPreStart = preStart+1;
    int leftPreEnd = leftInEnd-leftInStart+leftPreStart;
    
    int rightInStart = rootIndex+1;
    int rightInEnd = inEnd;
    int rightPreStart = leftPreEnd+1;
    int rightPreEnd = preEnd;

    TreeNode* root = new TreeNode(rootData);
    root->left = buildTreeHelper(in,pre,leftInStart,leftInEnd,leftPreStart,leftPreEnd);
    root->right = buildTreeHelper(in,pre,rightInStart,rightInEnd,rightPreStart,rightPreEnd);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
    int size=in.size();
    return buildTreeHelper(in,pre,0,size-1,0,size-1);
}


//Second Solution :-
TreeNode* build(vector<int> &A,int prestart,int preend,vector<int> &B,int instart,int inend, map<int,int>&mp){
	if(instart>inend||prestart>preend){
		return NULL;
	}

	TreeNode* root=new TreeNode(A[prestart]);
	int x=mp[root->val];
	int y=x-instart;

	root->left=build(A,prestart+1,prestart+y,B,instart,x-1,mp);
	root->right=build(A,prestart+y+1,preend,B,x+1,inend,mp);
	return(root);
}


TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
	map<int,int>mp;
	for(int i=0;i<B.size();i++){
		mp[B[i]]=i;
	}
	return(build(A,0,A.size()-1,B,0,B.size()-1,mp));
}


//Third Solution :- 
TreeNode *buildTreeUtil(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd){
    if (preStart > preEnd || inStart > inEnd) 
    	return nullptr;
    
    TreeNode *root = new TreeNode(preorder[preStart]);
    int k = 0;
    for (int i = inStart; i <= inEnd; i++){
        if (inorder[i] == preorder[preStart]){
            k = i;
            break;
        }
    }
    root->left = buildTreeUtil(preorder, inorder, preStart + 1, preStart + (k - inStart), inStart, k-1);
    root->right = buildTreeUtil(preorder, inorder, preStart + (k-inStart+1), preEnd, k+1, inEnd);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() <= 0) 
    	return nullptr;
    
    return buildTreeUtil(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}

