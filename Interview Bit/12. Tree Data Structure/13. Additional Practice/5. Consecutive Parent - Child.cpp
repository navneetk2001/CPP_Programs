// You are given the root of a binary tree A.
// You have to find out the number of parent - child relationship whose values are consecutive numbers.

// Input 1:
// A =  2
//     / \
//    1   3

// Input 2:
// A =  5
//     / \
//    1   3
//       / \
//      1   4

// Output 1: 2
// Output 2: 1

// Explanation 1: (2, 1) and (2, 3) are the consecutive parent - child relationships.
// Explanation 2: (3, 4) is the only consecutive parent - child relationship.

//Solution Approach :- 
We call two numbers x and y as consecutive iff abs(x - y) = 1,
where abs(z) denotes the absolute value of an integer.

We just have to call another recursive function where we pass the root of the binary tree as the parameter.
In the function, we check if the left and right child exist, then we just compare the values and if they fulfil the condition,
we just increment the counter which we will return as the answer.


//First Solution :-
int Solution::consecutiveNodes(TreeNode* A) {
    if(!A) return 0;
    int ans = consecutiveNodes(A->left)+consecutiveNodes(A->right);

    if(A->left && abs(A->left->val-A->val)==1) ans++;
    if(A->right && abs(A->right->val-A->val)==1) ans++;
    return ans;
}

//Second Solution :-
void consecutiveNodesUtil(TreeNode* root,int& numOfConsecutiveRelations){
    if(root == nullptr){
        return;
    }
    
    if(root->left == nullptr && root->right == nullptr){
        return;
    }
    
    if(root->left!=nullptr && abs(root->val - root->left->val)==1){
        numOfConsecutiveRelations++;
    }
    
    if(root->right!=nullptr && abs(root->val - root->right->val)==1){
        numOfConsecutiveRelations++;
    }
    
    consecutiveNodesUtil(root->left,numOfConsecutiveRelations);
    consecutiveNodesUtil(root->right,numOfConsecutiveRelations);
}


// Third Solution
int Solution::consecutiveNodes(TreeNode* root) {
    if(root==NULL) return 0;
    int ans=0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                if(curr->left->val+1==curr->val || curr->left->val-1==curr->val) ans++;
                q.push(curr->left);
            }
            if(curr->right){
                if(curr->right->val+1==curr->val || curr->right->val-1==curr->val) ans++;
                q.push(curr->right);
            }
        }
    }
    return ans;
}