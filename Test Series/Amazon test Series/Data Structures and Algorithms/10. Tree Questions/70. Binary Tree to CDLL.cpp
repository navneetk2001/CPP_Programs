https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1




//Solution Approach :-
class Solution{
public:
   //Function to convert binary tree into circular doubly linked list.
   	void solve(Node*root,Node*&ans,Node*&curr){
       	if(root==NULL)return;
       	solve(root->left,ans,curr);
       	if(ans==NULL){
           	ans=root;
           	curr=root;
       	}
       	else{
           	curr->right=root;
           	curr->right->left=curr;
           	curr=curr->right;
       	}
       	solve(root->right,ans,curr);
   	}

   	Node *bTreeToCList(Node *root)
   	{
	   	if(root==NULL){
	   		return NULL;
	   	}
	   	Node*ans=NULL;
	   	Node*curr=NULL;

	   	solve(root,ans,curr);

	   	curr->right = ans;
	   	ans->left = curr;
	   	return ans;
   	}
};




//Second Solution :- 
void helper(Node* root, Node* &head, Node* &tail){
    if(root==NULL){
    	return;
    }
    helper(root->left, head , tail);
    
    tail->right=root;
    root->left=tail;
    tail=root;
    
    helper(root->right, head, tail);
}

Node * bTreeToCList(Node *root)
{
	Node * head=new Node(), *tail=head;
	
	helper(root, head, tail);
	
	head->right->left=tail; //making it circular now
	tail->right=head->right; //making it circular now
	
	return head->right; 
}




//Third Solution :- Reverse Inorder traversal
Node *tail = NULL, *temp = NULL;
   
void inorder(Node *root){
   	if(!root) return;
   
   	inorder(root->right);
   
   	root->right = tail;
   	if(tail)tail->left = root;
   	tail = root;
   	if(!temp) temp = tail;
   	inorder(root->left);
}

Node *bTreeToCList(Node *root)
{
   tail = NULL,temp = NULL;
   inorder(root);
   temp->right = tail;
   tail->left = temp;
   
   return tail;
}



//Fourth Solution :-
void add(Node *&head, Node *&tail, int dat){
    if(!head || !tail){
        Node *newnode = new Node();
        newnode->data = dat;
        head = tail = newnode;
        tail->right = head;
        head->left = tail;
        return;
    }
    else{
        Node *newnode = new Node();
        newnode->data = dat;
        newnode->left = tail;
        tail->right=newnode;
        head->left = newnode;
        newnode->right = head;
        tail = newnode;
    }
}

void inorder(Node *root, Node *&head, Node *&tail){
    if(root){
        inorder(root->left, head, tail);
        add(head, tail, root->data);
        inorder(root->right, head, tail);
    }
}

Node *bTreeToCList(Node *root)
{
    if(!root){
        return nullptr;
    }
    Node *head = nullptr;
    Node *tail = nullptr;

    inorder(root, head, tail);
    return head;
}