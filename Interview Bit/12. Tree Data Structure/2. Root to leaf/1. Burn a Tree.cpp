// Given a binary tree denoted by root node A and a leaf node B from this tree.
// It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.
// You need to find the minimum time required to burn the complete binary tree.

//Input 1:
//  Tree :      1 
//             / \ 
//            2   3 
//           /   / \
//          4   5   6
//  B = 4
// Output 1:
//  4
// Explanation 1:
//  After 1 sec: Node 4 and 2 will be burnt. 
//  After 2 sec: Node 4, 2, 1 will be burnt.
//  After 3 sec: Node 4, 2, 1, 3 will be burnt.
//  After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.

//Hint :-
// The idea is to store additional information for every node:
// -> Depth of left subtree.
// -> Depth of right subtree.
// -> The time required for the fire to reach the current node starting from the first leaf node burned.
// -> A boolean variable to check if the initial burnt node is in the tree rooted under current node.

//Solution Approach :- 
// Now, for the minimum time required to burn any subtree will be:
//     The time required for fire to reach the root node from initial burnt leaf + depth of the opposite side
// Therefore, to find time required to burn the complete tree, we need to calculate the above value for every node, and take maximum of that value.
//     ans = max(ans, (time required for fire to reach current node + depth of other subtree))


//Solution :- Using height and depth
    //Giving Wrong Answer
static int ans =-1;

int burn(TreeNode* root, int target, int &depth){
	if(!root) {
		return 0;
    }
	if(root->val==target){
		depth=1;
		return 1;
	}

	int ld=-1;
	int rd=-1;

	int lh=burn(root->left,target,ld);
	int rh=burn(root->right,target,rd);

	if(ld!=-1){
		ans=max(ans,ld+1+rh);
		depth=ld+1;
	}
	else if(rd!=-1){
		ans=max(ans,rd+1+lh);
		depth=rd+1;
	}

	return max(lh,rh)+1;
}

int Solution::solve(TreeNode* A, int B) {
	int depth=-1;
	burn(A,B,depth);
	return ans;
}




//First Solution :-
// The trick is to use the diameter of the tree concept, but here we just need a little tweak, 
// we want that our diameter to always picks up the given leaf node with value B.
// So when the recursive call, comes to the leaf, I return a very high value, and it will ensure that my leaf node always gets picked up.

int fun(TreeNode* root, int &res, int B){
	if(!root) 
		return 0;
	if(root->left==NULL && root->right==NULL && root->val==B) 
		return (10000000);
	int l=fun(root->left, res, B);
	int r=fun(root->right, res, B);
	int temp=1+ max(l, r);
	int ans=max(temp, l+r+1);
	res= max(ans, res);
	return temp;
}

int Solution::solve(TreeNode* A, int B) {
	int res=0;
	fun(A, res, B);
	return res-10000000;
}



//Second Solution :-
int Solution::solve(TreeNode* A, int B) {
	unordered_map <BinaryTreeNode* ,bool> visited;
    unordered_map <BinaryTreeNode* ,BinaryTreeNode<int>* > m;
        
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        BinaryTreeNode<int>* node=q.front();
        q.pop();
        
        if(node->left)
        {
            m[node->left]=node;
            q.push(node->left);
        }
        
        if(node->right)
        {
            m[node->right]=node;
            q.push(node->right);
        }    
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(start);
     
    visited[start]=true;
    int t=0;
    
    while(!q.empty)
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {   
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            
            if(node->left && !visited[node->left])
            {
                visited[node->left]=true;
                q.push(node->left);
            }
            if(node->right && !visited[node->right])
            {
                visited[node->right]=true;
                q.push(node->right);
            }
            
            if(m[node] && !visited[m[node]])
            {
                visited[m[node]]=true;
                q.push(m[node]);
            }
            t++;
        }
    }
	return t;
}


//Third Solution :- 
void inorder(TreeNode* A, unordered_map<int, vector<int>> &mp){
    if(!A) 
    	return;

    inorder(A->left, mp);
    if(A->left){
        mp[A->val].push_back(A->left->val);
        mp[A->left->val].push_back(A->val);
    }

    if(A->right){
        mp[A->val].push_back(A->right->val);
        mp[A->right->val].push_back(A->val);
    }
    inorder(A->right, mp);
}

int Solution::solve(TreeNode* A, int B) {
    unordered_map<int, vector<int> > mp;
    inorder(A, mp);

    unordered_map<int, int> isVisited;
    queue<int> q;
    q.push(B);
    isVisited[B]=1;

    int sec=-1;
    while(!q.empty()){
        vector<int> v;
        while(!q.empty()){
            isVisited[q.front()]=1;
            for(auto n: mp[q.front()]){
                if(!isVisited[n]){
                    v.push_back(n);
                }
            }
            q.pop();
        }

        if(v.size()>0){
            for(auto num: v) 
            	q.push(num);
        }
        sec++;
    }
    return sec;
}


