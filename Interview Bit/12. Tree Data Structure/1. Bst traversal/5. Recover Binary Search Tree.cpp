// Two elements of a binary search tree (BST) are swapped by mistake.
// Tell us the 2 values swapping which the tree will be restored.
// Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

// Example :
// Input : 
//          1
//         / \
//        2   3
// Output : [1, 2]
// Explanation : Swapping 1 and 2 will change the BST to be 
//          2
//         / \
//        1   3
// which is a valid BST        


//Hint :-




//Solution Approach :- 



//First Solution :-
class Solution {
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
private: 
    void inorder(TreeNode* root) {
        if(root == NULL) return; 
        
        inorder(root->left);
        
        if (prev != NULL && (root->val < prev->val))
        {
           
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        prev = root;
        inorder(root->right); 
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val); 
    }
};



//Second Solution :-  
// First we will find the inorder traversal and store it in vector inorder
// then we know that the inorder of BST gives sorted sequence so now we scan and find the positions which are not sorted
void inorder(TreeNode* A,vector<int> &v){
    if(A==NULL) {
        return;
    }
    inorder(A->left,v);
    v.push_back(A->val);
    inorder(A->right,v);
}

vector<int> Solution::recoverTree(TreeNode* A) {
    vector< int> v,c,d;
    inorder(A,v);
    int n=v.size();

    for(int i=0;i<n;i++){
        c.push_back(v[i]);
    }

    sort(c.begin(),c.end());
    for(int i=0;i<n;i++){
        if(c[i]!=v[i]){
            d.push_back(c[i]);
            d.push_back(v[i]);
            break;
        }
    }

    return d;
}



//Third Solution :- Recursive solution:
// As you know, in-order traversal in binary tree is always in ascending order.
// We use this property to mark inconsistency, then swap the values.

class Solution {
private:
    TreeNode *prev = nullptr, *first, *second;
    
    void travel(TreeNode* root) {
        if (!root) return;
        travel(root->left);
        
        if(prev){
            if(root->val < prev->val) {
                if (!first){
                    first = prev;
                }
                second = root;
            }
        }

        prev = root;
        travel(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        travel(root);
        swap(first->val, second->val);
    }
};



//Fourth Solution :- Interviewbit
vector<int>swapped;
void inorder(TreeNode* root, int& prev)
{
	if(!root)
	return;

	inorder(root->left,prev);
	if(prev!=INT_MIN && prev>root->val)
	{
		swapped.push_back(prev);
		swapped.push_back(root->val);
	}

	prev=root->val;
	inorder(root->right,prev);
}

vector<int> Solution::recoverTree(TreeNode* A) {

	swapped.clear();
	int prev=INT_MIN;
	inorder(A, prev);
	sort(swapped.begin(),swapped.end());
	vector<int> ans = {swapped[0], swapped[swapped.size()-1]};
	return ans;
}

