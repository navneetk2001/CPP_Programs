Given inorder and postorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

Example :
Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]
Return : 
            1
           / \
          2   3

//Hint :-
Last element of postorder traversal will be root. Combine this info with inorder traversal. How can this help you?

//Solution Approach :- 
Focus on the postorder traversal to begin with.
The last element in the traversal will definitely be the root.
Based on this information, can you identify the elements in the left subtree and right subtree ? ( Hint : Focus on inorder traversal and root information )
Once you do that, your problem has now been reduced to a smaller set. Now you have the inorder and postorder traversal for the left and right subtree and you need to figure them out.
Divide and conquer.
Bonus points if you can do it without recursion.


//First Solution :-
TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x > y || a > b)return nullptr;
        
        TreeNode *node = new TreeNode(po[b]);
        int SI = x;  
        while(node->val != in[SI])SI++;
        node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
        node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return node;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return Tree(A,0,A.size()-1,B,0,B.size()-1);
}


//Second Solution :- 
TreeNode* build(unordered_map<int, int> &ino, vector<int> &post, int s, int e, int &ind) {
    if ( s > e ) {
        return NULL;
    }
    int x = post[ind];
    --ind;
    TreeNode *root = new TreeNode(x);
    if ( s == e ) {
        return root;
    }
    int i = ino[x];
    root->right = build(ino, post, i+1, e, ind);
    root->left = build(ino, post, s, i-1, ind);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &ino, vector<int> &post) {
    unordered_map<int, int> mp;
    for ( int i = 0; i < post.size(); ++i ) {
        mp[ ino[i] ] = i;
    } 
    int ind = post.size()-1;
    return build(mp, post, 0, post.size()-1, ind);
}


//Third Solution :- 
TreeNode *create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe)
 {
     if(ps > pe)
     {
         return NULL;
     }
     TreeNode *node = new TreeNode(postorder[pe]);
     int pos;
     for(int iter = is; iter <= ie; iter++)
     {
         if(inorder[iter] == node->val)
         {
             pos = iter;
             break;
         }
     }
     node->left = create(inorder, postorder, is, pos-1, ps, ps+pos-is-1);
     node->right = create(inorder,postorder, pos+1, ie, pe-ie+pos, pe-1);
     return node;
 }
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    return create(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}


//Fourth Solution :- 
TreeNode* buildTreeImpl( vector<int>& postOrder, int& postOrderIndex, vector<int> &inOrder, int inOrderLeftIndex, int inOrderRightIndex )
{
	if( postOrderIndex >= postOrder.size() || inOrderLeftIndex > inOrderRightIndex )
		return nullptr;

	int nodeValue = postOrder[ postOrderIndex++ ];
	TreeNode* node = new TreeNode( nodeValue );

	vector<int> inOrderLeft, inOrderRight;
	int inoderValueIndex = INT32_MAX;
	for( int i = inOrderLeftIndex; i <= inOrderRightIndex; i++ )
		if( inOrder[ i ] == nodeValue )
			inoderValueIndex = i;

	node->right = buildTreeImpl( postOrder, postOrderIndex, inOrder, inoderValueIndex + 1, inOrderRightIndex );
	node->left = buildTreeImpl( postOrder, postOrderIndex, inOrder, inOrderLeftIndex, inoderValueIndex - 1 );
	return node;
}

TreeNode* Solution::buildTree( vector<int> &inorder, vector<int> &postorder )
{
	int postOrderIndex = 0;
	reverse( postorder.begin(), postorder.end() );
	return buildTreeImpl( postorder, postOrderIndex, inorder, 0, inorder.size() - 1 );
}