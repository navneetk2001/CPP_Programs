// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.
// For example, given following linked lists :
//   5 -> 8 -> 20 
//   4 -> 11 -> 15
// The merged list should be :
// 4 -> 5 -> 8 -> 11 -> 15 -> 20


//Solution Approach
First thing to note is that all you would want to do is modify the next pointers. You don’t need to create new nodes.
At every step, you choose the minumum of the current head X on the 2 lists, and modify your answer’s next pointer to X. You move the current pointer on the said list and the current answer.

Corner case,
Make sure that at the end of the loop, when one of the list goes empty, you do include remaining elemnts from the second list into your answer.
Test case : 1->2->3 4->5->6

// First Method :-
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* ans = new ListNode(-1);
    ListNode* head=ans;
    ListNode* p1=A;
    ListNode* p2=B;

    while(p1 && p2){
        if(p1->val<=p2->val){
            ans->next=p1;
            p1=p1->next;
            ans=ans->next;
            ans->next=NULL;
        }
        else{
            ans->next=p2;
            p2=p2->next;
            ans=ans->next;
            ans->next=NULL;
        }
    }
    if (p1 != nullptr) {
        ans->next = p1;
    } 
    else if (p2 != nullptr) {
        ans->next = p2;
    }

    return head->next;
}



//Second Method :-
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(!A)
    {
        return B;
    }
    if(!B)
    {
        return A;
    }
    if(A->val>B->val)
    {
        return mergeTwoLists(B,A);
    }
    A->next=mergeTwoLists(A->next,B);
    return A;
}


//Third Method :-
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL) return(B);
    if(B==NULL) return(A);
    if(A->val < B->val){
        A->next=mergeTwoLists(A->next,B);
        return(A);
    }
    else{
        B->next=mergeTwoLists(A,B->next);
        return(B);
    }
}


//Fourth Method :-
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL) return B;
    if(B==NULL) return A;

    if(A->val>B->val) swap(A,B); //to ensure that A contains the smaller number always
    ListNode* res=A;  //for the result
    while(A!=NULL && B!=NULL){
        ListNode* tmp=NULL;
        
        while(A!=NULL && A->val<=B->val){
            tmp=A;
            A=A->next;
        }
        
        tmp->next=B;
        swap(A,B);
        
        
    }
    
    return res;
}


