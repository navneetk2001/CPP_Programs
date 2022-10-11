https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1/




//Solution Approach :-
// Steps: 
// 1. find height
// 2. get balanced factor(bf)
// 3. implement right and left rotate
// 4. Use normal BST insertion with extra conditions 
// 5. use bf value and given data/key value for
// 6. left left
// 7. right right
// 8. left right
// 9. right left
// 10. return root


//This is AVL tree rotation
class Solution{
  public:
    //Not using the height given to us instead calculating every time cause this is easy
    int height(Node *root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;   
    }
    
    int getbf(Node *root){   //calculates balance-factor
        if(root==NULL){
            return -1;
        }
        else{
            return (height(root->left)-height(root->right));    
        }
    }
    
    Node *rightRotate(Node *y){
        Node *x = y->left;
        Node *temp = x->right;
        
        //rotate
        x->right = y;
        y->left = temp;
        
        return x;
    }
    
    Node *leftRotate(Node *x){
        Node *y = x->right;
        Node *temp=y->left;
        
        //rotation
        y->left = x;
        x->right = temp;
        
        return y;
    }
    
    Node* insertToAVL(Node* root, int x)
    {
        if(root==NULL){
            return new Node(x);
        }
        
        if(root->data<x){
            root->right = insertToAVL(root->right,x);
        }
        else if(root->data>x){
            root->left = insertToAVL(root->left,x);
        }
        else{
            return root;
        }
            
        int bf= getbf(root);
        // left left
        if(bf>1 and x <root->left->data){
            return rightRotate(root);
        }
        
        //ritght right
        if(bf<-1 and x>root->right->data){
            return leftRotate(root);
        }
        
        //left right rotate
        if(bf>1 and x>root->left->data){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        
        //right left
        if(bf<-1 and x < root->right->data){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
    }
};




//Second Solution :-
class Solution{
    int height(Node *node){
        if(!node){
            return 0;
        }
        return max(height(node->left),height(node->right))+1;
    }
    int BF(Node *node){
        if(!node){
            return -1;
        }
        else{
            return height(node->left)-height(node->right);
        }
    }

    Node *lr(Node *node){
        Node *parent=node->left;
        Node *temp=parent->right;
        parent->right=node;
        node->left=temp;
        return parent;
    }

    Node *rr(Node *node){
        Node *parent=node->right;
        Node *temp=parent->left;
        parent->left=node;
        node->right=temp;
        return parent;
    }

  public:
    Node* insertToAVL(Node* node, int data)
    {
        if(!node){
            return new Node(data);
        }
            
        if(node->data<data){
            node->right= insertToAVL(node->right,data);
        }
        else if(node->data>data){
            node->left=insertToAVL(node->left,data);
        }
        else{
            return node;
        }
        
        int bf = BF(node);   //calculate balance factor
        if(bf>1 and data<node->left->data){   //right-right 
            return lr(node);
        }
        if(bf<-1 and data>node->right->data){  //left-left
            return rr(node);
        }
        if(bf>1 and data>node->left->data){  //right-left 
            node->left=rr(node->left);
            return lr(node);
        }
        if(bf<-1 and data<node->right->data){  //left-right
            node->right=lr(node->right);
            return rr(node);
        }
        return node;
    }
};    




//Third Solution :-
int height(Node *N){
    if(N == NULL){
        return 0;
    }
    return N->height;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
 
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
 
    return y;
}

int getBalance(Node *N)
{
    if(N == NULL){
        return 0;
    }
    return height(N->left) - height(N->right);
}

Node* insertToAVL(Node* node, int key)
{
    if(node == NULL){
        return(new Node(key));
    }
 
    if (key < node->data){
        node->left = insertToAVL(node->left, key);
    }
    else if (key > node->data){
        node->right = insertToAVL(node->right, key);
    }
    else {
        return node;
    }
 
   
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
 
    if (balance > 1 && key < node->left->data){
        return rightRotate(node);
    }
 
    if (balance < -1 && key > node->right->data){
        return leftRotate(node);
    }
 
    if (balance > 1 && key > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && key < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}