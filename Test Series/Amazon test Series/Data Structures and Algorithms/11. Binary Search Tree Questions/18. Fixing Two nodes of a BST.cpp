https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1




//Solution Approach :-
/* here we will do simple inorder traversal and we will store the info of 
prev node. Since it's bst then prev->data 
should not be greater then it's, if it's then it's a violation , 
similarly we will store 2 violation, and at last we'll swap it.
*/
Node* prev =NULL;
Node* first = NULL;
Node* second = NULL;

void inorder(Node* root){
    if(root==NULL){
        return;         
    }
    inorder(root->left);
    if(prev != NULL && root->data < prev->data){
        if(first == NULL){
            first = prev;
        }
        second = root;
    }
    prev = root;
    inorder(root->right);
}
 
void correctBST( struct Node* root ){
   	if(root==NULL){
       	return;
   	}
   	inorder(root);
   	//start swapping first and second
   	int temp = first->data;
   	first->data = second->data;
   	second->data =temp;
}



//Second Solution :-
class Solution {
public:
   	void inorder(Node* root, vector<Node*> &v){
       	if(root==NULL){
       		return;
       	}
       	inorder(root->left,v);
       	v.push_back(root);
       	inorder(root->right,v);
       	return;
   	}

   	void correctBST( struct Node* root ){
       	vector<Node*> v;
       	inorder(root,v);
       	int i,j;
       	
       	for (int i = v.size()-1; i > 0; i--){
           	if (v[i]->data < v[i-1]->data){                // Check if arr[i] is not in order
               	int j = i-1;
               	while (j>=0 && v[i]->data < v[j]->data){
                   	j--;
               	}
    
               	swap(v[i]->data, v[j+1]->data);
               	break;
           	}
       	}
       	return;
   	}
};
 



//Third Solution :- T.C: O(n), S.C: O(1), using Morris Traversal.
class Solution {
  public:
    void correctBST( struct Node* root )
    {
        Node* curr = root, *prev = NULL, *a = NULL, *b = NULL;
        while(curr){
            if(!curr -> left){
                if(prev and prev -> data > curr -> data){
                    if(!a)a = prev;
                
                    b = curr;
                }
                
                prev = curr;
                curr = curr -> right;
            }
            else{
                Node* rm = curr -> left;
                while(rm -> right and rm -> right != curr)rm = rm -> right;
                
                if(rm -> right == NULL){
                    rm -> right = curr;
                    curr = curr -> left;
                }
                else{
                    
                    if(prev -> data > curr -> data){
                        if(!a)a = prev;
                        b = curr;
                    }
                    
                    rm -> right = NULL;
                    prev = curr;
                    curr = curr -> right;
                }
            }
        }
        swap(a -> data, b -> data);
    }
};
