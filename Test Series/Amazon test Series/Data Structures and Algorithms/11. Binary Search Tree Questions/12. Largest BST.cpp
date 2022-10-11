https://practice.geeksforgeeks.org/problems/largest-bst/1



//Solution Approach :-
class NodeValue {
    public:
        int maxNode, minNode, maxSize;
        NodeValue(int minNode, int maxNode, int maxSize) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
};

class Solution{
    public:
    NodeValue largestBSTSubtreeHelper(Node* root) {
        if(!root){              // An empty tree is a BST of size 0.
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if(left.maxNode < root->data && root->data < right.minNode){            //IF It is a BST.
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root){
    	return largestBSTSubtreeHelper(root).maxSize;
    }
};




//Second Solution :-   Brute Force
int sizeofbst(Node*root){
	if(root == NULL){
		return 0;
	}
	int lh = sizeofbst(root->left);
	int rh = sizeofbst(root->right);
	return 1 + lh + rh;
}

bool isBst(Node*root, int min, int max){
   	if(root==NULL){
   		return true;
   	}
   	if(root->data <=min or root->data >= max){
       	return false;
   	}
   	
   	bool lh = isBst(root->left, min, root->data);
   	bool rh = isBst(root->right, root->data, max);
   	
   	return lh and rh;
}

int largestBst(Node *root){
	if(root==NULL){
		return 0;
	}
	if(isBst(root, INT_MIN, INT_MAX)){
	    return sizeofbst(root);
	}
	int lh=largestBst(root->left);
	int rh=largestBst(root->right);
	return max(lh,rh);
}





//Third Solution :-
class Solution{
    public:
    int mx = -1e9;
    
    void isValid(Node* root,int &prev,bool &flag,int &count){
        if(!root) return;
        if(!flag) return;
        isValid(root->left,prev,flag,count);
        if(root->data <= prev){
            flag = false;
            count = 0;
        }
        else{
            prev = root->data;
            count++;
        }
        isValid(root->right,prev,flag,count);
    }
    
    void dfs(Node* root){
        if(!root) return;
        int prev = -1e9;
        bool flag = true;
        int count = 0;
        isValid(root,prev,flag,count);
        mx = max(mx,count);
        dfs(root->left);
        dfs(root->right);
    }
    
    int largestBst(Node *root){
        dfs(root);
    	return mx;
    }
};




//Fourth Solution :- BY STRIVER
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        if(!root){        // An empty tree is a BST of size 0.
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if(left.maxNode < root->val && root->val < right.minNode){            // It is a BST.
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};