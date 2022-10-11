https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#



//Solution Approach :- //O(K) Time Complexity && O(1) space complexity Solution 
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void solve( Node *root, int K, int &ans, int &count){
    	if(!root){
    	   	return;
    	}
    
    	solve(root->left, K, ans, count);
    
    	if(count<K){
    	   	ans = root->data;
    	   	count++;
    	}
    	solve(root->right, K, ans, count);
       
    }
    int KthSmallestElement(Node *root, int K){
    	int ans = -1;
    	int count = 0;
    	solve(root, K, ans, count);
    
    	if(count != K){
    		return -1;
    	}
    	return ans;
    }
};




//Second Solution :- 
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void solve(Node *root, int &k ,int &ans ){
        if(!root){
            return;
        }
        
        solve(root->left,k,ans);
        k--;
        if(k == 0){
            ans = root->data;
            return;
        }
        solve(root->right , k,ans);
        
    }
    
    int KthSmallestElement(Node *root, int k) {
        int ans =-1;
        solve(root , k , ans);
        return ans;
    }
};


//Third Solution :-
class Solution {
  public:
    int inorder(Node* node, int& i, int K){
        if(not node){
            return -1;
        }
        
        int left = inorder(node->left, i, K);
        if(left != -1){
            return left;
        }
        
        if(i == K){
            return node->data;
        }
        i++;
        
        int right = inorder(node->right, i, K);
        if(right != -1){
            return right;
        }
        
        return -1;
    }
  
    int KthSmallestElement(Node *root, int K) {
        int i=1;
        return inorder(root, i, K);
    }
};



//Fourth Solution :-
void inorder(Node* root, vector<int> &res)
{
	if(root==NULL ) return;
	inorder(root->left,res);
	res.push_back(root->data);
	inorder(root->right,res);
}

int KthSmallestElement(Node *root, int K) {
	vector<int>res;
	inorder(root,res);
	if(K > res.size()) return -1;
	return res[K-1];
}



//Fifth Solution :-  MORRIS TRAVERSAL 
class Solution {
  public:
    int KthSmallestElement(Node *root, int k) {
        Node* current = root;
        int element = -1;
        while (current) {
            if (!current -> left) {
                // visit the node
                if (!(--k)) {
                    element = current -> data;
                }
                current = current -> right;
            } else {
                // find the inorder predecessor
                Node* predecessor = current -> left;
                while (predecessor -> right && predecessor -> right != current) {
                    predecessor = predecessor -> right;
                }
                if (!predecessor -> right) {
                    predecessor -> right = current;
                    current = current -> left;
                } else {
                    predecessor -> right = NULL;
                    // visit the node
                    if (!(--k)) {
                        element = current -> data;
                    }
                    current = current -> right;
                }
            }
        }
        return element;
    }
};



//Sixth Solution :-
class Solution {
    private:
    int res;
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<int> s = new LinkedList<>();
	    while (true) {
	      	while (root != NULL) {
	        	s.push(root);
	        	root = root->left;
	      	}
	      	root = stack.pop();
	      	if (--k == 0) return root->val;
	      	root = root->right;
	    }
	}  
};



