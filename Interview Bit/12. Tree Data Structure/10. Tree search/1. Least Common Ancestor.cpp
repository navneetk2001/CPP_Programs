// Find the lowest common ancestor in an unordered binary tree given two values in the tree.
// Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.
// Example :
//         _______3______
//        /              \
//     ___5__          ___1__
//    /      \        /      \
//    6      _2_     0        8
//          /   \
//          7    4
// For the above tree, the LCA of nodes 5 and 1 is 3.
// LCA = Lowest common ancestor

// Please note that LCA for nodes 5 and 4 is 5.
// You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
// No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
// There are no duplicate values.
// You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

//Hint :-
Bruteforce approach :
Pick every node. For every node, search for val1, val2 in the subtree. If val1 and val2 are both found in the subtree, then the current node is definitely one of the ancestors. Also track the depth of the current node. Pick the qualifying node of highest depth.

Hint for a better solution :
1. If you had the path from the nodes to the root, what property would the path have ? Can the paths be used to determine LCA ?
2. If you took bottom up approach using recursion, can you think of a simple solution ?

//Solution Approach :- 
Linear solution using path calculation :
1 Find path from root to n1 and store it in a vector or array.
2) Find path from root to n2 and store it in another vector or array.
3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch

Linear solution using recursion :
We traverse from the bottom, and once we reach a node which matches one of the two nodes, we pass it up to its parent. The parent would then test its left and right subtree if each contain one of the two nodes. If yes, then the parent must be the LCA and we pass its parent up to the root. If not, we pass the lower node which contains either one of the two nodes (if the left or right subtree contains either p or q), or NULL (if both the left and right subtree does not contain either p or q) up.


//Solution :- 
bool is_there(TreeNode *root,vector<int>&v,int x)
{
    if(!root)
    {
        return false;
    }
    if(root->val==x)
    {
        v.push_back(root->val);
        return true;
    }
    if(is_there(root->left,v,x) || is_there(root->right,v,x))
    {
        v.push_back(root->val);
        return true;
    }
    else
    {
        return false;
    }
}
int Solution::lca(TreeNode* A, int B, int C) 
{
    vector<int>first,second;
    bool f=is_there(A,first,B);
    bool s=is_there(A,second,C);
    if(!f || !s)
    {
        return -1;
    }
    int i=first.size()-1,j=second.size()-1;
    while(i>0 && j>0 && first[i-1]==second[j-1])
    {
        i--;
        j--;
    }
    return first[i];
}



//Second Solution :-
class Solution {
    public:
        TreeNode *LCA(TreeNode *root, int val1, int val2) {
            if (!root) return NULL;
            if (root->val == val1 || root->val == val2) return root;
            TreeNode *L = LCA(root->left, val1, val2);
            TreeNode *R = LCA(root->right, val1, val2);
            if (L && R) return root; // If val1, val2 are on both sides 
            return L ? L : R; // either one of val1, val2 is on one side OR val1, val2 is not in L&R subtrees
        }

        bool find(TreeNode *root, int val1) {
            if (!root) return false;
            if (root->val == val1) return true;
            return (find(root->left, val1) || find(root->right, val1));
        }

        int lca(TreeNode *root, int val1, int val2) {
            if (!find(root, val1) || !find(root, val2)) return -1;
            TreeNode *ans = LCA(root, val1, val2);
            if (!ans) return -1;
            return ans->val;
        }
};


//Third Solution :- Iterative
// path function checks whether the value exists in the tree or not. Also it gives the root to that value path if the value exists in the tree
bool path(TreeNode *root,int n,vector<int>&ans)
{
    if(!root)
    {
        return false;
    }
    ans.push_back(root->val);
    if(root->val==n)
    {
        return true;
    }
    else if(path(root->left,n,ans) || path(root->right,n,ans))
    {
        return true;
    }
    ans.pop_back();
    return false;
}

int Solution::lca(TreeNode* A, int B, int C) 
{
    vector<int>v1,v2;
    if(!path(A,B,v1) || !path(A,C,v2))
    {
        return -1;
    }
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]!=v2[j])
        {
            break;
        }
        i++;
        j++;
    }
    return v1[i-1];
}



//Fourth Solution :-  Using map
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> s;
    unordered_map<TreeNode*,TreeNode*> mp;
    mp[root]=NULL;
    s.push(root);
    while(mp.find(p)==mp.end() || mp.find(q)==mp.end()){
        TreeNode *t=s.top();
        s.pop();
        if(t->left){
            mp[t->left]=t;
            s.push(t->left);
        }
        if(t->right){
            mp[t->right]=t;
            s.push(t->right);
        }
    }
    set<TreeNode*> sett;
    while(p!=NULL){
        sett.insert(p);
        p=mp[p];
    }
    while(sett.find(q)==sett.end()){
        q=mp[q];
    }
    return q;
}