https://practice.geeksforgeeks.org/problems/mirror-tree/1



//Solution Approach :-
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL){
        	return; 
        }
        
        swap(node->left, node->right) ; 
        
        mirror(node->left) ; 
        mirror(node->right) ; 
    }

};



//Second Solution :- iterative way
void mirror(Node* node) {
    if(!node){
    	return;
    }
    
    queue<Node*> q;
    q.push(node);                               // push the root node
    
    while(!q.empty()){                          // till q is empty, all nodes are covered
        auto curr = q.front();                  // take each node from queue
        q.pop();
        
        swap(curr->left, curr->right);          // swap its left and right
        
        if(curr->left) q.push(curr->left);      // call its left and right if not null
        if(curr->right) q.push(curr->right);
    }
}
