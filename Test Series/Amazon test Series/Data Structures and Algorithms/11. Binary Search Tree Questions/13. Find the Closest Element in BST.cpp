https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1



//Solution Approach :-
class Solution{
public:
    //Function to find the least absolute difference between any node value of the BST and the given integer.
    int minDiff(Node *root, int k){
        if(!root){
        	return INT_MAX;
        }
        if(root->data < k){   //if the given value of k is greater than root value
            return min(k - root->data, minDiff(root->right, k));
        }
        return min(root->data - k, minDiff(root->left, k));
    }
};




//Second Solution :-
class Solution{
public:
   	int minDiff(Node *root, int K){
       	Node* temp = root;
       	int minDiff = INT_MAX;
       	
       	while(temp != NULL)
       	{
           	minDiff = min(minDiff , abs(K - temp->data));
           	if(minDiff == 0) return 0;
           
           	if(temp->data <= K){
               	temp = temp->right;
           	}
           	else{
               	temp = temp->left;
           	}
       	}
       	return minDiff;
   	}
};



//Third Solution :-
int mind=INT_MAX;
int minDiff(Node *root, int k){
   	if(root==NULL) return -1;
   
   	if(root->data > k){
       	mind=min(mind,abs(k-root->data));
       	minDiff(root->left,k);
   	}
   	else{
       	mind=min(mind,abs(k-root->data));
       	minDiff(root->right,k);
   	}
   
   	return mind;
}




//Fourth Solution :-
int minDiff(Node *root, int K)
{
	if(root==NULL){
		return 0;
	}
	queue<Node*>q;
	q.push(root);
	int mini=INT_MAX;
   	
   	while(!q.empty()){
       	int n=q.size();
       	for(int i=1;i<=n;i++){
           	Node*temp=q.front();
           	q.pop();
           	mini=min(mini,abs(K-temp->data));
           	if(temp->left){
               	q.push(temp->left);
           	}
           	if(temp->right){
               	q.push(temp->right);
           	}
       	}
   	}
   	return mini;
}


