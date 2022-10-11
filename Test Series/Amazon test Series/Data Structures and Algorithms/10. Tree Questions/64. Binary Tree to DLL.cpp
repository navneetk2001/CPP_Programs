https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1



//Solution Approach :-
class Solution{
public: 
    //Function to convert binary tree to doubly linked list and return it.
    void create_DLL(Node* &head, Node* &tail, Node* root){
        if(head == NULL){    //if no node exits in doubly linked list i.e. dll is empty
            head = root;
            tail = root;
        }
        else{                  //if some node already present in dll
            tail->right = root;
            root->left = tail;
            tail =root;
        }
        return;
    }
        
    void inorder(Node* root,Node *&head,Node* &tail){
        if(root == NULL){
            return;
        }
        inorder(root->left, head, tail);
        create_DLL(head, tail, root);         // Step 3 -- Create a funtion that just create a DLL
        inorder(root->right, head, tail);
    }
    
    Node * bToDLL(Node *root)
    { 
        Node* head = NULL;                 // Step 1 - create head and tail pointer's of Doubly linked list
        Node* tail = NULL;
        inorder(root, head, tail);           // Step 2 - For traversing tree call inorder
        return head;
    }
};




//Second Solution :-
class Solution{
public: 
   	//Function to convert binary tree to doubly linked list and return it.
   	Node* prev = NULL;
   	Node * bToDLL(Node *root)
   	{
       	if(root==NULL){
       		return root;
       	}
       
       	Node* head = bToDLL(root->left);
       
       	if(prev==NULL){
           	head = root;
       	}
       	else{
           	prev->right = root;
           	root->left = prev;
       	}
       	prev=root;
       
       	bToDLL(root->right);
       
       	return head;
   	}
};




//Third Solution :-
Node *head= NULL;
Node *tail=NULL;

void dll(Node* root)
{
   	if(head==NULL)
   	{
       	tail=head=root;
   	}
   	else
   	{
       	tail->right=root;
       	root->left=tail;
       	tail=root;
   	}
   	return ;
}

void inorder(Node *root)
{
   	if(root==NULL)return ;
   	inorder(root->left);
   	dll(root);
   	inorder(root->right);
   
}

Node * bToDLL(Node *root)
{
   	inorder(root);
   	return head;
}




//Fourth Solution :-
class Solution{
public:
    vector<Node* > v;
    void inorder(Node* node){
       	if(node == NULL){
          	return;
       	}
       	inorder(node->left);
       	v.push_back(node);
       	inorder(node->right);
    }
    
    Node* bToDLL(Node *root)
    {
        inorder(root);
        Node* head = v[0];
        Node* prev = head;
        
        for(int i = 0; i<v.size()-1; i++){
           Node* next = v[i+1];    
           prev->right = next;
           next->left = prev;
           prev = prev->right;
        }
        
    return head;     
    }
};
