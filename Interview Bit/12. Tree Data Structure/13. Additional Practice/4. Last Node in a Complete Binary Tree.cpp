// You are given the root of a complete binary tree A.
// You have to return the value of the rightmost node in the last level of the binary tree.
// Try to find a solution with a better time complexity than O(N).

// Input 1:
// A = 
//     1
//    /
//   2
// Output 1: 2
// Explanation 1:
// There is only a single node in the last level of the binary tree. Therefore, the answer is 2.

// Input 2:
// A = 
//     1
//    / \
//   2   3
// Output 2: 3
// Explanation 2:
// There a two nodes in the last level of the tree. The rightmost nodes is 3.


//Hint :-
//What is the difference between the two subtrees, one which has the righmost node, and the one which is after it?

//Solution Approach :- 
// So, the idea here is to compare the height of the two subtrees.
// If the height of the left subtree is higher, we go left, else we go right.
// We can find the height of a subtree in O(log N), and this will be repeated for O(log N) steps.
// Therefore, we can find the answer in O(log N * log N).


//First Solution :-
int Solution::lastNode(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int ans;
    while(!q.empty()){
        TreeNode* temp = q.front();
        ans = temp->val;
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    return ans;
}


//Second Solution :-
// So Basically for every current node Get the height of the left subtree and right subtree
// if leftHeight==RightHeight --> that means our answer lies in right subtree because it is a CBT and we fill the node from left to right.
// elif leftHeight>RightHeight --> that means our node lies in the left subtree because we are filling the tree in left to right manner and last node would be in the last level

int height(TreeNode* root){
    if(!root){
       	return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int lastNode(TreeNode* A) {
    if(!A->left and !A->right){ 
    	return A->val;
    }

    int lHeight = height(A->left);
    int rHeight = height(A->right);

    if(lHeight > rHeight){
        return lastNode(A->left);
    }
    return lastNode(A->right);
}



//Third Solution :- 
int Solution::lastNode(TreeNode* root) {
    int height=0;
    int ans;
    
    TreeNode* tmp=root;
    while(tmp!=NULL){
        height++;
        tmp=tmp->left;
    }
    
    int low=0;
    int high=(1<<(height-1))-1;
    while(low<=high){
        int mid=(low+high)/2;
        
        tmp=root;
        for(int h=0;h<height-1;h++){
            if((mid>>(height-h-2))&1){
                tmp=tmp->right;
            }
            else {
                tmp=tmp->left;               
            }
        }
        
        if(tmp!=NULL){
            ans=tmp->val;
            low=mid+1;
        }
        else{ 
            high=mid-1;
        }
    }
    return ans;
}



//Fourth Solution :-
void find(int &ans, TreeNode* A, int &max_l, int l)
{
    if(A==NULL)
        return;
    if(l>max_l){
        ans = A->val;
        max_l=l;
    }
    if(l==max_l)
        ans = A->val;
    find(ans,A->left,max_l,l+1);
    find(ans,A->right,max_l,l+1);
}

int Solution::lastNode(TreeNode* A) {
    int ans;
    int max_l = -1;
    find(ans,A,max_l,0);

    return ans;
}