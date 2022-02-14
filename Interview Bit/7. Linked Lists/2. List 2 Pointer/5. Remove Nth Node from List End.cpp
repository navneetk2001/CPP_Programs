// Given a linked list, remove the nth node from the end of list and return its head.
// For example,
//    Given linked list: 1->2->3->4->5, and n = 2.
//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// If n is greater than the size of the list, remove the first node of the list.
// Try doing it using constant additional space.

//Solution Approach
Obviously, since we do not have back pointers, reaching the end node and then making our way back is not an option.

There are 2 approaches :
1) Find out the length of the list in one go. Then you know the number of node to be removed. Traverse to the node and remove it.
2) Make the first pointer go n nodes. Then move the second and first pointer simultaneously. This way, the first pointer is always ahead of the second pointer by n nodes. So when first pointer reaches the end, you are on the node to be removed.


// First Method :-
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A == NULL || B == 0) return A;
    int len=0;
    ListNode* temp=A;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    //If B is greater than or = to length, delete first Node
    if(B >= len){
        A = A->next;
        return A;
    }

    ListNode* prev = NULL;
    temp=A;
    for(int i=0;i<len-B;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    temp->next=NULL;

    return A;
}


//Second Method :-
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) 
{
    ListNode*fast=A;
    ListNode*slow=A;
    for(int i=0;i<B;i++)
    {
        fast=fast->next;
        if(fast==NULL)
        {
            return A->next;
        }
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return A;
}


//Third Method :-
ListNode* Solution::removeNthFromEnd(ListNode* head, int n) 
{
    
    ListNode*temp=head,*curr=head,*prev;
    if(!head)return NULL;
    while(n--&&curr)
    {
        
        curr=curr->next;
    }
   
    if(!curr)
    {ListNode*t=head->next;
       // head=head->next;
        delete(head);
        return t;
    }
    
    while(curr)
    {
        prev=temp;
        temp=temp->next;
        curr=curr->next;
        
    }
    
    prev->next=temp->next;
    delete(temp);
    return head;}

        




