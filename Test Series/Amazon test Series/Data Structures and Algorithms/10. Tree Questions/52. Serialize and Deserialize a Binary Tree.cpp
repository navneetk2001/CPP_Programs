https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1




//Solution Approach :-
class Solution{
public:
    void serialize_helper(Node *root, vector<int> &serial_tree){
        if(root==NULL) return;
        serialize_helper(root->left, serial_tree);
        serial_tree.push_back(root->data);
        serialize_helper(root->right, serial_tree);
    }

    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        vector<int> serial_tree;
        serialize_helper(root, serial_tree);
        return serial_tree;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A){
        struct Node* newroot = new Node(-1);
       	Node* temp = newroot;

       	int n = A.size();
       	for(int i=0;i<n;i++){
           	temp->right = new Node(A[i]);
           	temp = temp->right;
       	}
       	return newroot->right;
    }
};




//Second Solution :-
class Solution{
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        if(root==NULL) return {-1};
        vector<int> vec;
        queue<Node*> q;
        q.push(root);
     
     	while(!q.empty())
     	{
         	Node *temp=q.front();
         	q.pop();
         
         	if(temp==NULL) vec.push_back(-1);
         	else vec.push_back(temp->data);
         
         	if(temp!=NULL)
         	{
	            q.push(temp->left);
    	        q.push(temp->right);
         	}
     	}
     	return vec;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       Node* root = new Node(A[0]);
       queue<Node*> q;
       q.push(root);
       int index = 1;
       
       while (!q.empty()) {
           Node* curr = q.front();
           q.pop();
           
           int newN = A[index++];
           if (newN == -1) {
               curr->left = NULL;
           }
           else {
               curr->left = new Node(newN);
               q.push(curr->left);
           }
           
           newN = A[index++];
           if (newN == -1) {
               curr->right = NULL;
           }
           else {
               curr->right = new Node(newN);
               q.push(curr->right);
           }
       }
       return root;
    }




//Third Solution :-
class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> ans;
    vector<int> serialize(Node *root) 
    {
        if(root == NULL)
        {
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(root->data);
        serialize(root->left);
        serialize(root->right);
        
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    int i = 0;;
    Node * deSerialize(vector<int> &A)
    {
       if(i == A.size()) return NULL;
       int val = A[i];
       i++;
       if(val == -1) return NULL;
       
       Node *root = new Node(val);
       root->left = deSerialize(A);
       root->right = deSerialize(A);
       return root;
    }

};




//Deserialize :-
//Function to deserialize a list and construct the tree.
Node*Create_Node(int Data){
	if(Data==0)return NULL;
	Node*newnode=new Node(Data);
	return newnode;
}
Node * deSerialize(vector<int> &A)
{   
	int i=0;
	if(A[i]==0){
	   	return NULL;
	}
	Node*root=Create_Node(A[i++]);
	queue<Node*>q;
	q.push(root);
   	while(!q.empty()){
		Node*frnt=q.front();
		q.pop();
		frnt->left=Create_Node(A[i++]);
		frnt->right=Create_Node(A[i++]);
		if(frnt->left!=NULL)q.push(frnt->left);
		if(frnt->right!=NULL)q.push(frnt->right);
   	}
   	return root;
}