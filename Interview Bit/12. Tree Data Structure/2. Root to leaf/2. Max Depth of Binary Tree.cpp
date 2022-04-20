Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
max depth = 2.


//Hint :-
Can you traverse the tree while keeping the distance from root to current node? How can you check if you have reached the leaf or not?

//Solution Approach :- 
You know that a path ends when you reach a leaf ( how do you define a leaf ? ).
All that you need to do is that a particular node, you pick the maximum of the depth of the left and right subtree ?
What do you do when one of the left or right subtree is NULL ?


//First Solution :-
int Solution::maxDepth(TreeNode* A) {
      if(A==NULL) 
        return 0;
        
    return 1 + max(maxDepth(A -> left), maxDepth(A -> right));
}


//Second Solution :-
int Solution::maxDepth(TreeNode* A) {
      if(A != nullptr){
      if(A->left == nullptr && A->right == nullptr) return 1; //leaf
      int l = maxDepth(A->left);
      int r = maxDepth(A->right);
      return 1+max(l,r);
    } 
    else 
      return 0; //after leaf
}

//Third Solution :- BFS iterative solution
int Solution::maxDepth(TreeNode* A) {
    if(!A)
        return 0;
        
    queue<TreeNode*> bfs;
    bfs.push(A);
    int ans = 0;
    
    while(!bfs.empty()){
        ++ans;
        int n = bfs.size();
        for(int i = 0; i < n; ++i){
            TreeNode* temp = bfs.front();
            bfs.pop();
            if(temp -> left)
                bfs.push(temp -> left);
            if(temp -> right)
                bfs.push(temp -> right);
        }
    }
    return ans;
}

