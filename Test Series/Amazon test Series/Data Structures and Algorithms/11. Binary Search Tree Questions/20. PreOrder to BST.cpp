https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1




//Solution Approach :-
Node *buildTree( int pre[] , int &idx  , int size ,int Min = -1e8 ,  int Max = 1e8 ){
    if(idx >= size )return NULL;
    if(pre[idx] < Min || pre[idx] > Max){
    	return NULL;
    }
    
    Node *root = newNode(pre[idx]);
    idx++;
    
    root->left = buildTree(pre , idx , size , Min , root->data - 1);
    root->right = buildTree(pre , idx , size , root->data + 1 , Max );
    
    return root;
}


Node* post_order(int pre[], int size){
    int idx = 0;
    Node *root = buildTree(pre, idx, size);
    return root;
} 




//Second Solution :-
Node* post_order(int pre[], int size)
{
    if(size == 0){
        return nullptr;
    }
    
    Node* root = newNode(pre[0]);
    
    int Left[size], Right[size];
    int p = 1, i = 0, j = 0;
    
    while(p < size){
        if(pre[p] < pre[0]){
        	Left[i++] = pre[p++];
        }
        else{
        	Right[j++] = pre[p++];
        }
    }
    
    root->left = post_order(Left, i);
    root->right = post_order(Right, j);
    return root;
}




//Third Solution :-
TreeNode *buildBST(TreeNode* &root, int ele) {
    if(!root){
        return root = new TreeNode(ele);
    }
    
    if(root->val > ele){
        root->left = buildBST(root->left, ele);
    }
    else{
        root->right = buildBST(root->right, ele);
    }
    return root;
}

TreeNode* bstFromPreorder(vector<int>& pre) {
    TreeNode *root = NULL;
    
    for(auto x : pre){
        buildBST(root, x);
    }
    return root;
}




//Fourth Solution :-
void createMapping(int in[],int size,map<int,int>& mp){
   for(int i=0;i<size;i++)  mp[in[i]]=i;
   return;
}

Node* makeBST(int pre[],int in[],int size,int& preidx,int instart,int inend,map<int,int>& mp){
   if(preidx>=size || instart>inend) return NULL;
   int element=pre[preidx++],position=mp[element];
   Node* root=newNode(element);
   root->left=makeBST(pre,in,size,preidx,instart,position-1,mp);
   root->right=makeBST(pre,in,size,preidx,position+1,inend,mp);
   return root;
}

Node* post_order(int pre[], int size)
{   
   int in[size],preidx=0,instart=0,inend=size-1;;
   copy_n(pre,size,in);
   sort(in,in+size);
   map<int,int> mp;
   createMapping(in,size,mp);
   return makeBST(pre,in,size,preidx,instart,inend,mp);
}