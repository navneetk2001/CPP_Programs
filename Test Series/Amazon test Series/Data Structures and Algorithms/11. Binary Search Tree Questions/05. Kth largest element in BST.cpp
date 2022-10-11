https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/




//Solution Approach :-
void inorder(Node *root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

int kthLargest(Node *root, int K){
    vector<int>arr;
    inorder(root,arr);
    return arr[arr.size()-K];
    return -1;
}



//Second Solution :-
int kthLargest(Node *root, int K){
    priority_queue <int, vector<int>, greater<int>> pq(K,INT_MIN); 
    if(root==NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        
        while(size!=0){
            Node* curr=q.front();
            q.pop();
          
            int val=curr->data;
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
            size--;
        }
    } 
    return pq.top();
}



//Third Solution :-
int ans=-1;
int kthLargest(Node *root, int k){
    fun(root,k);
    return ans;
}

void fun(Node* root,int &k){
    if(root==NULL){
        return;
    }
    
    if(root->right){
        fun(root->right,k);
    }
   
    k--;
    if(k==0){
        ans=root->data;
        return;
    }
   
    if(root->left){
        fun(root->left,k);
    }
}



//Fourth Solution :- Using Morris Traversal In TC : O(N)
class Solution{
public:
    void Inorder(Node *root , vector<int>&ans){
        if(root==NULL) return;
        Node *curr = root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node *prev = curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev = prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right  = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
    }
   
    int kthLargest(Node *root, int K)
    {
        vector<int>ans;
        Inorder(root , ans);
        return ans[ans.size()-K];
    }
};

