Given a singly linked list of size N, and an integer K. You need to swap the Kth node from the beginning and Kth node from the end of the linked list. Swap the nodes through the links. Do not change the content of the nodes.

Example 1:
Input:
N = 4,  K = 1
value[] = {1,2,3,4}
Output: 1
Explanation: Here K = 1, hence after swapping the 1st node from the beginning and end thenew list will be 4 2 3 1.
 

Example 2:
Input:
N = 5,  K = 7
value[] = {1,2,3,4,5}
Output: 1
Explanation: K > N. Swapping is invalid. Return the head node as it is.



//Solution Approach :-
Node *swapkthnode(Node* head, int n, int k)
{
    if(k>n){      //if k is greater than total no of nodes
    	return head;
    }
    if(k==(n-k+1)){   //if kth node from begin and end both are same 
    	return head;
    }
    
    Node* beg=head, *beg_prev=NULL;
    Node* end=head, *end_prev=NULL;
    
    for(int i=1;i<k;i++){
    	beg_prev=beg;
    	beg=beg->next;
    }
    
    for(int i=1;i<n-k+1;i++){
    	end_prev=end;
    	end=end->next;
    }
    
    if(beg_prev!=NULL){
    	beg_prev->next=end;
    }
    
    if(end_prev!=NULL){
    	end_prev->next=beg;
    }
    
    Node* temp=beg->next;
    beg->next=end->next;
    end->next=temp;
    
    if(k==1){
    	return head=end;
    }
    if(k==n){
    	return head=beg;
    }
    
    return head;
}



//Second Solution :-
Node *swapkthnode(Node* head, int n, int k){
  Node *prev1, *node1, *node2, *copy = new Node(-1);
  prev1 = node1 = node2  = copy;
  copy->next = head;
  if (k > n) {
  	return copy->next;
  }
  int ct = 1, fromLast = n - k + 1;  //take some test cases then you can observe that kth node from last is this
  
  while (head) {
    prev1 = head;
    head = head->next;
    ct++;
    if (ct == k) {
      node1 = prev1;
    }
    else if (ct == fromLast) {
      node2 = prev1;
    }
  }
  swap(node1->next, node2->next);
  swap(node1->next->next, node2->next->next);
  return copy->next;
}