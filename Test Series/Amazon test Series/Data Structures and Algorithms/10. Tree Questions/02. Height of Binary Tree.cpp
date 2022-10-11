https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1




//Solution Approach :-
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node == NULL) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};


//Second Solution :-
class Solution{
   public:
   //Function to find the height of a binary tree.
   int height(struct Node* root){
       	queue<Node *> q;
       	q.push(root);
       	q.push(NULL);
       	int i = 0;
       	while(!q.empty())
       	{
           	Node *temp = q.front();
           	q.pop();

           	if(temp == NULL){
               	i++;
               	if(!q.empty()){
                   q.push(NULL);
               	}
           	}
           	else{
               	if(temp->left){
                   q.push(temp->left);
               	}
               	if(temp->right){
                   q.push(temp->right);
               	}
           	}
       	}
	    return i;
   }
};
