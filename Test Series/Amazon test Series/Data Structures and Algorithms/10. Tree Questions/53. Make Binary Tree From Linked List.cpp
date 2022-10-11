https://practice.geeksforgeeks.org/problems/make-binary-tree/1/




//Solution Approach :-
TreeNode *buildTree(vector<int> &in, int i) {
    if(i >= in.size()) {
        return NULL;
    }
    
    TreeNode *root = new TreeNode(in[i]);
    root->left = buildTree(in, 2*i+1);
    root->right = buildTree(in, 2*i+2);
    
    return root;
}

void convert(Node *head, TreeNode *&root) {
    if(head == NULL) {
        return;
    }
    
    vector<int> ans;
    int i = 0;
    
    Node *t = head;
    while(t){
        ans.push_back(t->data);
        t= t->next;
    } 
    
    root = buildTree(ans, i);
}




//Second Solution :-
void convert(Node *head, TreeNode *&root) {
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    q.push(root);
    
    Node* ptr = head->next;
    while(!q.empty() && ptr){
        TreeNode* temp = q.front();
        q.pop();
        
        if(ptr){
            temp->left = new TreeNode(ptr->data);
            q.push(temp->left);
            ptr = ptr->next;
        }
        
        if(ptr){
            temp->right = new TreeNode(ptr->data);
            q.push(temp->right);
            ptr = ptr->next;
        }
        
    }
}





//Third Solution :-
void help(Node *head, TreeNode *&root, const int &attachToRight) {
   	if(head == NULL) return;
   	TreeNode* temp = new TreeNode(head->data);
   	root = temp;
   	if(!attachToRight){
       help(head->next, root->left, !attachToRight);
   	}
   	else{
       help(head->next, root->right, !attachToRight);
   	}
}

void convert(Node *head, TreeNode *&root) {
   help(head, root, 0);
}



//Fourth Solution :- Found a loop hole lol!
void convert(Node *head, TreeNode *&root) {
    if(!head)return;
    root = new TreeNode(head->data);
    convert(head->next,root->left);
}