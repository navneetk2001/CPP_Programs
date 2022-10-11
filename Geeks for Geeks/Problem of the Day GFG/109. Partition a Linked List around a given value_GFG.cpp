// Given a linked list and a value x, partition it such that all nodes less than x come first, then all nodes with value equal to x and finally nodes with value greater than or equal to x. The original relative order of the nodes in each of the three partitions should be preserved. The partition must work in-place.
 
// Example 1:
// Input: 1->4->3->2->5->2->3,
// x = 3
// Output: 1->2->2->3->3->4->5
// Explanation: Nodes with value less than 3 come first, then equal to 3 and then greater than 3.

// Example 2:
// Input: 1->4->2->10 
// x = 3
// Output: 1->2->4->10
// Explanation: Nodes with value less than 3 come first, then equal to 3 and then greater than 3.



//Solution Approach :-
struct Node* partition(struct Node* head, int x) {
    Node * greater = NULL, *greater_head = NULL ; 
    Node * smaller = NULL, *smaller_head = NULL ;
    Node * equal   = NULL, *equal_head   = NULL ; 

    while(head){
        if(head -> data > x)
            (greater) ? greater = greater -> next = head  : greater = greater_head = head ;
        else if(head -> data == x)
            (equal)   ? equal   = equal   -> next = head  : equal   = equal_head   = head ;
        else
            (smaller) ? smaller = smaller -> next = head  : smaller = smaller_head = head ;
        head = head -> next ; 
    }

    if(greater){
        greater -> next = NULL ;
    }
    if(equal){
        equal   -> next = greater_head ;
        greater_head    = equal_head   ;
    }
    if(smaller){
        smaller -> next = greater_head ;
        greater_head    = smaller_head ;
    }
    return greater_head ;
}



//Second Solution :-
struct Node* partition(struct Node* head, int x) {
    vector<int>small;
    vector<int>eqal;
    vector<int>big;
    
    struct Node*cur=head;
    while(cur!=NULL){
        if(cur->data<x) 
        	small.push_back(cur->data);
        else if(cur->data==x) 
        	eqal.push_back(cur->data);
        else 
        	big.push_back(cur->data);
        
        cur=cur->next;
    }
    
    struct Node* newhead=new Node(0);
    head=newhead;
    for(auto x: small){
        head->next=new Node(x);
        head=head->next;
    }
    
    for(auto x: eqal){
        head->next=new Node(x);
        head=head->next;
    }
    
    for(auto x:  big){
        head->next=new Node(x);
        head=head->next;
    }
    head->next=NULL;
    return newhead->next;
}


//Third Solution :-
//just compare the data and make a new list.

struct Node* partition(struct Node* head, int x) {
   struct Node *zero = new Node(0);
   struct Node *ans = zero;
   
   struct Node *temp = head;
   
   while(temp){
       if(temp->data<x){
           struct Node *mynode = new Node(temp->data);
           zero->next = mynode;
           zero = zero->next;
       }
       temp = temp->next;
   }
   
   temp = head;
   
   while(temp){
       if(temp->data==x){
           struct Node *mynode = new Node(temp->data);
           zero->next = mynode;
           zero = zero->next;
       }
       temp = temp->next;
   }
   
   temp = head;
   
   while(temp){
       if(temp->data>x){
           struct Node *mynode = new Node(temp->data);
           zero->next = mynode;
           zero = zero->next;
       }
       temp = temp->next;
   }
   
   return ans->next;
   
}

