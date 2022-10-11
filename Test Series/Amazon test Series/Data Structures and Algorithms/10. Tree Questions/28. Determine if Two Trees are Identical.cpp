https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1




//Solution Approach :-
bool isIdentical(Node *r1, Node *r2){
    if(r1 == NULL || r2 == NULL){
    	return (r1 == r2);
    }
    return (r1 -> data == r2 -> data) && isIdentical(r1 -> left, r2 -> left) && isIdentical(r1 -> right, r2 -> right);
}



//Second Solution :-
class Solution{
public:
    bool isIdentical(Node *r1, Node *r2){
        if(r1==NULL && r2==NULL){
        	return true;
        }
        if(r1==NULL && r2!=NULL){
        	return false;
        }
        if(r1!=NULL && r2==NULL){
        	return false;
        }
        
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        bool val = (r1->data == r2->data);
        
        if(left && right && val){
            return true;
        }
        else{
	        return false;
        }
    }
};
