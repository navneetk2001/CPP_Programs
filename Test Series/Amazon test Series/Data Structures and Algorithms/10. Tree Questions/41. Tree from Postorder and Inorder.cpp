https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1




//Solution Approach :-
Node *Tree(int in[], int x, int y, int po[], int a, int b){
    if(x > y || a > b){
    	return nullptr;
    }
    
    Node *node = new Node(po[b]);
    int SI = x;  
    while(node->data != in[SI]){
    	SI++;
    }
    node->left  = Tree(in, x, SI-1, po, a, a+SI-x-1);
    node->right = Tree(in, SI+1, y, po, a+SI-x, b-1);
    return node;
}

Node *buildTree(int in[], int post[], int n) {
    return Tree(in,0,n-1, post,0,n-1);
}



//Second Solution :-
int postIndex;
int search(int arr[], int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(arr[i]==val){
        	return i;
        }
    }
}

Node *constructTree(int in[], int post[], int inStrt, int inEnd){
    if(inStrt>inEnd){
    	return NULL;
    }
    Node *newNode = new Node(post[postIndex--]);
    if(inStrt==inEnd){
    	return newNode;
    }
    
    int inIndex = search(in,inStrt, inEnd, newNode->data);
    newNode->right = constructTree(in,post,inIndex+1,inEnd);
    newNode->left = constructTree(in,post,inStrt,inIndex-1);
    
    return newNode;
}

Node *buildTree(int in[], int post[], int n) {
    postIndex=n-1;
    return constructTree(in,post,0,n-1);
}



//Third Solution :-
map<int, int> mp;

Node* BT(int inorder[], int inStart, int inEnd, int postorder[], int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd){
    	return NULL;
    }
    Node *root = new Node(postorder[postEnd]);
    int idx = mp[root->data];
    int leftNodes = idx - inStart;
    
    root->left = BT(inorder, inStart, idx-1, postorder, postStart, postStart+leftNodes-1);
    root->right = BT(inorder, idx+1, inEnd, postorder, postStart+leftNodes, postEnd-1);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    for(int i = 0; i < n; i++){
        mp[in[i]] = i;
    }
    return BT(in, 0, n-1, post, 0, n-1);
}


