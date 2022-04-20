// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.

// Example 2:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

// Example 3:
// Input: root = [1,2], p = 1, q = 2
// Output: 1


//Solution Approach :- 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        
        TreeNode* a=NULL, *b=NULL;
        if(root->left!=NULL){
            a=lowestCommonAncestor(root->left, p, q);
        }
        
        if(root->right!=NULL){
            b=lowestCommonAncestor(root->right, p, q);
        }
        
        if(a==NULL && b==NULL){
            return NULL;
        }
        
        if(a!=NULL && b==NULL){
            return a;
        }
        
        if(a==NULL && b!=NULL){
            return b;
        }
        
        if(a!=NULL && b!=NULL){
            return root;
        }
        return root;
    }
};


//Second Solution :-
// // method one with recursion..
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // first check root is null 
       if(root == NULL){
           return root;
       }
         // second if one(given two nodes) is equal to root
        if(root == p || root == q){
            return root;
        }
         // find left and right node..
         TreeNode *lef =  lowestCommonAncestor(root->left,p,q);
         TreeNode *rig =  lowestCommonAncestor(root->right,p,q);
        // if left is null then return rig
           if(lef == NULL){
               return rig;
           }
         // if right is null then return left
           if(rig == NULL){
               return lef;
           }
         //else return root
         return root;
    }
};


//Third Solution :- Iterative
// method second with array.
class Solution {
    bool getpath(vector<TreeNode*>& s1, TreeNode* root, TreeNode* x) {
        if(!root)   return false;
        s1.push_back(root);
        if(root->val == x->val)  return true;
        if(getpath(s1, root->left, x) || getpath(s1, root->right, x)) return true;
        s1.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> s1, s2;
        
        getpath(s1, root, p);
        getpath(s2, root, q);
        
        TreeNode* lastval;
        for(int i=s1.size()-1;i>=0;i--) {
            for(int j=s2.size()-1;j>=0;j--) {
                if(s1[i]->val ==s2[j]->val) {
                    lastval=s1[i];
					break;
                }
            }
            if(lastval!=NULL)
                break;
        }
        return lastval;
    }
};


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