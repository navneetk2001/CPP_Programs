https://practice.geeksforgeeks.org/problems/two-mirror-trees/1




//Solution Approach :-
int areMirror(Node* a, Node* b) {
   	if(a==NULL and b==NULL){
   		return 1;
   	}
   	if(a==NULL or b==NULL){
   		return 0;
   	}
   	if(a->data!=b->data){
   		return 0;
   	}
   	int lh = areMirror(a->left,b->right);
   	int rh = areMirror(a->right,b->left);
   	return lh and rh;
}



//Second Solution :-
int areMirror(Node* a, Node* b){
    stack<Node*>st1, st2;
    st1.push(a) ;
    st2.push(b) ;
      
    while(!st1.empty()){
        int n = st1.size() ;
          
        if(st1.size() != st2.size()){
        	return false ;
        }
        for( int i = 0 ; i<n ; i++)
        {
            a = st1.top() ;
            b = st2.top() ;
            st1.pop() ;
            st2.pop() ;
             
            if(a->data != b->data)  return false ;
            if(a->right) st1.push(a->right) ;
            if(a->left) st1.push(a->left) ;
            if(b->left) st2.push(b->left) ;
            if(b->right) st2.push(b->right) ;
        }
    }
    return true ;
}


//Third Solution :-
class Solution {
    bool areMirror(Node a, Node b) {
        if(a == NULL || b == NULL){
            return a == b;
        }
        return a.data == b.data && areMirror(a.left, b.right) && areMirror(a.right, b.left);
    }
}