https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1




//Solution Approach :-
class Solution{
  public:
    /* The function should clone the passed tree and return root of the cloned tree */
    unordered_map<Node*,Node*> mp;
    Node* helper(Node* root){
        if(!root){
        	return NULL;
        }
        Node* node = new Node(root->data);
        mp[root] = node;
        
        node->left = helper(root->left);
        node->right = helper(root->right);
        
        return node;
    }

    void setRandom(Node* root){
        if(!root){
        	return;
        }
        if(root->random){
            mp[root]->random = mp[root->random];
        }
        setRandom(root->left);
        setRandom(root->right);
    }

    Node* cloneTree(Node* tree){
       Node* clone=helper(tree);
       setRandom(tree);
       return clone;
    }
};




//Second Solution :- 
Node* cloneTree(Node* tree)
{
	if(!tree){
		return NULL;
	}

	Node* newNode = new Node(tree->data);

	newNode->left = cloneTree(tree->left);
	newNode->right = cloneTree(tree->right);
	newNode->random = tree->random;

	return newNode;
}