https://practice.geeksforgeeks.org/problems/quicksort-on-doubly-linked-list/1



//Solution Approach :- USING HOARE PARTITION 
Node* partition(Node *l, Node *h)
{
    Node *pivot=l;
    Node *left=l;
    Node *right=h;
    
    while(true){
        while(left != NULL  &&  pivot->data > left->data){
            left=left->next;
        }
        
        while(right != NULL  && pivot->data <= right->data && left != right){
           right=right->prev;
        }

        if(left==right){
            return left;
        }
        swap(left->data, right->data);
    }
}




//Second Solution :-
Node* partition(Node *l, Node *h){
    Node* pivot = l;
    Node *i = l, *j = h;
    bool flag = false;
    
    while(!flag) {
        while(i != NULL && i->data <= pivot->data){
            if(i == j) flag = true;
            i = i->next;
        }
        
        while(j != NULL && j->data > pivot->data){
            if(i == j) flag = true;
            j = j->prev;
        }
        
        if(!flag)
            swap(i->data,j->data);
    }
    
    if(flag){
        swap(pivot->data, j->data);
    }
    
    return j;
}




//Third Solution :-
Node* partition(Node *l, Node *h){
    Node *x=l,*y=l;
    
    while(x!=h){
        if(x->data<h->data){
            swap(x->data,y->data);
            y=y->next;
        }
        x=x->next;
    }
    swap(h->data,y->data);
    return y;
}
