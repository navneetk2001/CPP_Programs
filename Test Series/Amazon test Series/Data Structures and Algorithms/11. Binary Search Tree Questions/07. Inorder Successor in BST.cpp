https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1




//Solution Approach :-
class Solution{
public:
   // returns the inorder successor of the Node x in BST (rooted at 'root')
	int min = INT_MAX;
	Node* resultNode = NULL;
	Node* inOrderSuccessor(Node *root, Node *x)
	{
	    if(root == NULL || x == NULL){
	    	return NULL;
	    }
	    inOrderSuccessor(root->left,x);
	    
	    if(root->data < min && root->data > x->data){
	        resultNode = root;
	        min = root->data;
	    }
	    inOrderSuccessor(root->right,x);
	    return resultNode;
	}
};



//Second SOlution :- Best Solution 
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* successor = NULL;
        while(root != NULL){
            if(x ->data >= root->data){
                root = root->right;
            } 
            else{
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};



//Third Solution :-
class Solution{
  public:
    Node* ans = new Node(1e9);
    void solve(Node* root,Node* x){
        if(!root){
        	return;
        }
        
        if(root->data > x->data and ans->data > root->data){
        	ans = root;
        }
        
        solve(root->right,x);
        solve(root->left,x);    
    }

    Node* inOrderSuccessor(Node *root, Node *x){
        solve(root, x);
        return (ans->data == 1e9) ? new Node(-1) : ans;
    }
};



//Fourth Solution :-
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x){
        return ceiling(root, x);
    }
    
    Node* ceiling(Node *walk, const Node *x) {
        if (walk == NULL) return NULL;
        if (x->data >= walk->data) return ceiling(walk->right, x);
        else {
            Node *left = ceiling(walk->left, x);
            return left == NULL ? walk : left;
        }
    }
};