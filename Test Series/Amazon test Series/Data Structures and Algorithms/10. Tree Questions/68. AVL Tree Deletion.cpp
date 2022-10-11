https://practice.geeksforgeeks.org/problems/avl-tree-deletion/1/




//Solution Approach :-
int height(Node* root)
{
    if(!root)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}

int getBalance(Node* root)
{
    if(!root)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return (lh-rh);
}

Node* rightRotate(Node* root)
{
    Node* temp1=root->left;
    Node* temp2=temp1->right;
    temp1->right=root;
    root->left=temp2;
    return temp1;
}

Node* leftRotate(Node* root)
{
    Node* temp1=root->right;
    Node* temp2=temp1->left;
    temp1->left=root;
    root->right=temp2;
    return temp1;
}

Node* inorderSucc(Node* root)
{
    while(root && root->left){
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data)
{
    if(!root)return NULL;
    if(root->data < data){
        root->right=deleteNode(root->right,data);
    }
    else if(root->data >data){
        root->left=deleteNode(root->left,data);
    }
    else{
        if(root->left==NULL){
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        else{
            Node* temp=inorderSucc(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    if(root==NULL){
        return root;
    }
    
    int balance = getBalance(root);
    
    
    if(balance>1 && getBalance(root->left)>=0){
        return rightRotate(root);
    }
    else if(balance>1 && getBalance(root->left)<0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    else if(balance<-1 && getBalance(root->right)<=0){
        return leftRotate(root);
    }
    else if(balance<-1 && getBalance(root->right)>0){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}




//Second Solution :- 
int NodeHeight(Node* p)
{
    int hl=0, hr=0;
    hl = p&&p->left?p->left->height:0;
    hr = p&&p->right?p->right->height:0;
    return (hl>hr?hl+1:hr+1);
}

int BalanceFactor(Node* p)
{
    // hl-hr
    int hl=0, hr=0;
    hl = p&&p->left?p->left->height:0;
    hr = p&&p->right?p->right->height:0;
    
    return (hl-hr);
}

Node* LLRotate(Node* p)
{
    Node* pl = p->left;
    Node* plr = pl->right;
    
    pl->right = p;
    p->left = plr;
    
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    
    return pl;
}

Node* LRRotate(Node* p)
{
    Node* pl = p->left;
    Node* plr = pl->right;
    
    pl->right = plr->left;
    p->left = plr->right;
    
    plr->left = pl;
    plr->right = p;
    
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    
    return plr;
}

Node* RRRotate(Node* p)
{
    Node* pr = p->right;
    Node* prl = pr->left;
    
    pr->left = p;
    p->right = prl;
    
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    
    return pr;
}

Node* RLRotate(Node* p)
{
    Node* pr = p->right;
    Node* prl = pr->left;
    
    p->right = prl->left;
    pr->left = prl->right;
    
    prl->left = p;
    prl->right = pr;
    
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    
    return prl;
}

Node* InSuccessor(Node* p)
{
    while(p && p->left)
    {
        p=p->left;
    }
    return p;
}

Node* InPredecessor(Node* p)
{
    while(p && p->right)
    p=p->right;
    return p;
}


Node* deleteNode(Node* root, int data)
{
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(data==root->data)
        {
            free(root);
            return NULL;
        }
    }
    
    if(data<root->data)
    root->left = deleteNode(root->left,data);
    else if(data>root->data)
    root->right = deleteNode(root->right,data);
    else
    {
        if(root->right!=NULL)
        {
            // successor
            Node* q = InSuccessor(root->right);
            root->data = q->data;
            root->right = deleteNode(root->right, q->data);
        }
        else
        {
            // Predecessor
            Node* q = InPredecessor(root->left);
            root->data = q->data;
            root->left = deleteNode(root->left,q->data);
        }
    }
    root->height = NodeHeight(root);
    if(BalanceFactor(root)==2 && BalanceFactor(root->left)==1){
        return LLRotate(root);
    }
    else if(BalanceFactor(root)==2&&BalanceFactor(root->left)==-1){
        return LRRotate(root);
    }
    else if(BalanceFactor(root)==2&&BalanceFactor(root->left)==0){
        return LLRotate(root);
    }
    else if(BalanceFactor(root)==-2&&BalanceFactor(root->right)==1){
        return RLRotate(root);
    }
    else if(BalanceFactor(root)==-2&&BalanceFactor(root->right)==-1){
        return RRRotate(root);
    }
    else if(BalanceFactor(root)==-2&&BalanceFactor(root->right)==0){
        return RRRotate(root);
    }
    
    return root;
}










//Third Solution :-
//Not an actual method to delete an element from an AVL tree. There will be rotations involved.
//But this is certainly a way to deal with the task at hand.
void inorder(vector<int>&v, Node*root, const int data){
    if(root){
        inorder(v,root->left,data);
        if(root->data != data){
            v.push_back(root->data);
        }
        inorder(v,root->right,data);
    }
}

Node* buildTree(vector<int>&v,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* root = new Node(v[mid]);
    root->left = buildTree(v,s,mid-1);
    root->right = buildTree(v,mid+1,e);
    return root;
}

Node* deleteNode(Node* root, int data){
    vector<int> v;
    inorder(v,root,data);
    return buildTree(v,0,v.size()-1);
}