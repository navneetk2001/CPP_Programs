https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1





//Solution Approach :-
Node* solve(int pre[], char preLN[], int n, int &i){
    if(i>n){
        return NULL;
    }

    if(preLN[i]=='L'){
        return new Node(pre[i++]);
    }

    Node* root = new Node(pre[i++]);
    root->left = solve(pre,preLN,n,i);
    root->right = solve(pre,preLN,n,i);
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[]){
    int i=0;
    return solve(pre, preLN, n, i);
}



//Second Solution  :-
struct Node *constructTree(int n, int pre[], char preLN[]){
    if(n == 0){
    	return NULL ;
    }
    
    if(preLN[0] == 'L'){
    	return new Node(pre[0]) ;
    }

    Node* arr[n];
    for(int i = 0 ;i < n ;i++) {
        arr[i] = new Node(pre[i]) ;
    }

    stack<Node*> s ; 
    s.push(arr[0]) ;
    
    for(int i =1 ;i < n ; i++) {
        if(s.top()->left == NULL) {
            s.top()->left = arr[i];
        }
        else{
            s.top()->right = arr[i];
            s.pop();
        }
        if(preLN[i] == 'N') {
            s.push(arr[i]) ;
        }
    }
    return arr[0] ;
}



//Third Solution :-
struct Node *constructTree(int n, int pre[], char preLN[])
{
    stack<Node*>st;
    Node* root = new Node(pre[0]);
    if(preLN[0] == 'N'){
        st.push(root);
    }
    int i = 1;
    while(!st.empty()){
        Node* child = new Node(pre[i]);
        Node* par = st.top();
        if(par -> left == NULL){
            par -> left = child;
        }
        else{
            par -> right = child;
            st.pop();
        }
        if(preLN[i] == 'N'){
            st.push(child);
        }
        i++;
    }
    return root;
}



//Fourth Solution :-
struct Node *constructTree(int n, int pre[], char preLN[]){
    stack<Node*>st;
    Node* root=new Node(pre[0]);
    st.push(root);
    for(int i=1;i<n;i++){
        int val=pre[i];
        char ch=preLN[i];
        while(!st.empty() and (st.top()->left and st.top()->right)){
            st.pop();
        }
        Node* p= st.top();
        Node* child=new Node(val);
        if(p->left){
            p->right=child;
            st.pop();
        }else{
            p->left=child;
        }
        if(ch=='N') st.push(child);
    }
    return root;
}
