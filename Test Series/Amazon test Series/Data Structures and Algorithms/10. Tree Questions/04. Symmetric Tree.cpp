https://practice.geeksforgeeks.org/problems/symmetric-tree/1



//Solution Approach :-
bool solve(struct Node* r1,struct Node* r2) {
    if((!r1&&r2) || (r1&&!r2)){
        return false;
    }
    if(r1 && r2){
        if(r1->data!=r2->data){
            return false;
        }
        if(!solve(r1->left,r2->right) || !solve(r1->right,r2->left)){
            return false;
        }
        
    }
    return true;
}
public:
bool isSymmetric(struct Node* root){
    if(root==NULL){
        return true;
    }
    return solve(root->left,root->right);
    
}



//Second Solution :-
class Solution{
   public:
   // return true/false denoting whether the tree is Symmetric or not
   bool solve(struct Node*n1,struct Node*n2){
       if(n1==NULL and n2==NULL) return true;
       if(n1==NULL or n2==NULL) return false;
       if(n1->data!=n2->data) return false;
       bool lh=solve(n1->left,n2->right);
       bool rh=solve(n1->right,n2->left);
       return lh and rh;
   }
   
   	bool isSymmetric(struct Node* root){
	    if(root==NULL){
	    	return true;
	    }
		return solve(root->left,root->right);
   	}
};



//Third Solution :-
class Solution{
public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root){
	    queue <Node*> q1;
       	queue <Node*> q2;
       
       	if (root==NULL || (root->left==NULL && root->right==NULL)) return true;
       	if (root->left==NULL || root->right==NULL)  return false;
       
       	q1.push(root->left);
       	q2.push(root->right);
       
       	while(!q1.empty() && !q2.empty()){
           Node *temp1=q1.front();
           q1.pop();

           Node *temp2=q2.front();
           q2.pop();
           
           if (q1.empty() && !q2.empty()) return false;
           if (!q1.empty() && q2.empty()) return false;
           
           if (temp1->data != temp2->data) return false;
           
           if (temp1->left==NULL && temp2->right!=NULL)  return false;
           if (temp1->left!=NULL && temp2->right==NULL)  return false;
           
           if (temp1->left) q1.push(temp1->left);
           if (temp1->right) q1.push(temp1->right);
           
           if (temp2->right) q2.push(temp2->right);
           if (temp2->left) q2.push(temp2->left);
       	}
       
       	if (q1.empty() && q2.empty())  return true;
       	return false;
    }
};