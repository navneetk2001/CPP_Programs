https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1/




//Solution Approach :-
vector<int> printNearNodes(Node *root, int low, int high) {
   	vector<int>v;
   	if(root==NULL){
   		return v;
   	}
   	queue<Node*>q;
   	q.push(root);
   	
   	while(!q.empty()){
       	int n=q.size();

       	for(int i=1;i<=n;i++){
           	Node*temp=q.front();
           	q.pop();
           	
           	if(temp->data >= low and temp->data <= high){
               	v.push_back(temp->data);
           	}
           	if(temp->left)q.push(temp->left);
           	if(temp->right)q.push(temp->right);
       	}
   	}
   	sort(v.begin(),v.end());
   	return v;
}



//Second Solution :-
void inrange(Node* root, int l, int h, vector<int> &v)
{
    if(root == NULL){
        return;
    }

    inrange(root->left, l, h, v);
    if(root->data >= l && root->data <= h){
        v.push_back(root->data);
    }
    inrange(root->right, l, h, v);
    return;
}

vector<int> printNearNodes(Node *root, int low, int high){
    vector<int> v;
    inrange(root, low, high, v);
    return v;
}




//Third Solution :-
class Solution {
public:
	void printNearNodesUtil(Node *root, int low, int high, vector<int> &v){
	    if(root->data <= high && root->data >= low){
	        v.push_back(root->data);
	    }
	    if(root->left){
	        printNearNodesUtil(root->left, low, high, v);
	    }
	    if(root->right){
	        printNearNodesUtil(root->right, low, high, v);
	    }
	}

    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> v;
        printNearNodesUtil(root, low, high, v);
        sort(v.begin(), v.end());
        return v;
    }
};



//Fourth Solution :-
void inorder(Node* root,vector<int> &v){
    if(root==NULL){
        return ;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

vector<int> printNearNodes(Node *root, int low, int high) {
    vector<int> v;
    vector<int> v1;
    inorder(root,v);   //inorder gives sorted arrays in bst
    for(int i=0;i<v.size();i++){
        if(v[i]>=low && v[i]<=high){
            v1.push_back(v[i]);
        }
    }
    return v1;
    
}
