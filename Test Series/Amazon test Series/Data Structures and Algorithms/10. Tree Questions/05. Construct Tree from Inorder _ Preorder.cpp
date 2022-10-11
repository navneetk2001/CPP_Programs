https://practice.geeksforgeeks.org/problems/construct-tree-1/1




//Solution Approach :-
Node* buildTree_help(int in[], int pre[],int inS, int inE, int preS, int preE){
    if(inS>inE){
        return NULL; 
    }

    int rootData = pre[preS];   //root of the tree in preOrder
    
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;               //root of the tree in inOrder
            break;
        }
    }
    
    int linS=inS;
    int linE=rootIndex-1;
    int rinS=rootIndex+1;
    int rinE=inE;
    int lpreS=preS+1;
    int lpreE=linE-linS+lpreS;
    int rpreS=lpreE+1;
    int rpreE=preE;
    
    Node* root = new Node(rootData);
    root->left = buildTree_help(in,pre,linS,linE,lpreS,lpreE);
    root->right = buildTree_help(in,pre,rinS,rinE,rpreS,rpreE);
    return root;
}

class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* root=buildTree_help(in,pre,0,n-1,0,n-1);
        return root;
    }
};




//Second Solution :-
class Solution{
    void createMapping(unordered_map<int, int> &m, int in[], int n){
        for(int i =0;i<n;i++){
            m[in[i]] = i;
        }
    }

    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, unordered_map<int, int> &m, int n){
        if(index>= n || (inOrderStart > inOrderEnd) ){         //base case
            return NULL;
        }
        int element = pre[index++];
        Node* root = new Node(element);
        int position = m[element];
        root->left = solve(in, pre, index, inOrderStart,position-1, m,n );
        root->right = solve(in, pre,index, position+1, inOrderEnd, m, n);
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n){
        int preOrderIndex = 0;
        unordered_map<int, int> m;
        createMapping(m, in, n);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, m, n);
        return ans;
    }
};



//Third Solution :-
int findposition(int in[],int element,int n){
    for(int i=0;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}

Node*solve(int in[],int pre[],int &index,int start,int end,int n){
    if(index>=n || start>end){
        return NULL;
    }
    int element=pre[index++];
    
    Node* root = new Node(element);
    int position=findposition(in,element,n);

    root->left = solve(in,pre,index,start,position-1,n);
    root->right = solve(in,pre,index,position+1,end,n);
    return root;
}

Node* buildTree(int in[],int pre[], int n){
    int preorderindex=0;
    Node* ans = solve(in,pre,preorderindex,0,n-1,n);
    return ans;
}




//Fourth Solution :- LeetCode Accepted
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
};


// Basic idea is :->
// preorder[0] is the root node of the tree
// preorder[x] is a root node of a sub tree
// In in-order traversal
// When inorder[index] is an item in the in-order traversal
// inorder[0]-inorder[index-1] are on the left branch
// inorder[index+1]-inorder[size()-1] are on the right branch
// if there is nothing on the left, that means the left child of the node is NULL
// if there is nothing on the right, that means the right child of the node is NULL

// Algorithm :->
// Start from rootIdx 0
// Find preorder[rootIdx] from inorder, let's call the index pivot
// Create a new node with inorder[pivot]
// Create its left child recursively
// Create its right child recursively
// Return the created node.




//Fifth Solution:- Usinh HashMap
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        unordered_map<int,int> hmap;
        for (int i=0; i< inorder.size(); i++) {
            hmap[inorder[i]] = i;
            //value -> index mapping for inorder array
        }
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1, hmap);
    }
    
    //***Note*** that rootIdx is passed as reference 
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int left, int right, unordered_map<int,int> &hmap) {
        if(left > right) return nullptr;
        
        int pivot = hmap[preorder[rootIdx]];
        TreeNode* node = new TreeNode(inorder[pivot]); //inorder[pivot] == prorder[rootIdx]
        rootIdx++;
        
        node->left = build(preorder, inorder, rootIdx, left, pivot-1, hmap);
        //rootIdx value gets changed after successive calls to build the left subtree
        //Since it is passed as reference, updated value of rootIdx is passed to build
        //the right subtree
        node->right = build(preorder, inorder, rootIdx, pivot+1, right, hmap);
             
        return node;
    }
};