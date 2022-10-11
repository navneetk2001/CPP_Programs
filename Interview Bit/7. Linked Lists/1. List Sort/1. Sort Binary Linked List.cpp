// Given a Linked List A consisting of N nodes.
// The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.
// You need to sort the linked list and return the new linked list.
// NOTE:
// Try to do it in constant space.




// First Method :-
ListNode* Solution::solve(ListNode* A) {
    if(!A) {
        return A;
    }
    ListNode *head = A, *prev = A, *temp = A->next;
    while(temp){
        if(temp->val == 1)
        {
            prev = prev->next;
            temp = temp->next;
        }
        else
        {
            prev->next = temp->next;
            temp->next = head;
            head = temp;
            temp = prev->next;
        }
    }
    return head;
}


//Second Method :-
ListNode* Solution::solve(ListNode* A) {
    ListNode *i=A;
    ListNode *j=A;
    while(j!=NULL){
        if(i->val!=1){
            i=i->next;
        }
        else if(i->val==1 and j->val==0){
            int temp=i->val;
            i->val=j->val;
            j->val=temp;
            i=i->next;
        }
        j=j->next;
    }
    return A;
}


//Third Method :-
ListNode* Solution::solve(ListNode* A) {
    ListNode *p=A,*q=A;
    while(p!=NULL){
        if(p->val==0){
            int t=p->val;
            p->val=q->val;
            q->val=t;
            q=q->next;
        }
        p=p->next;
    }
    return A;
}


//Fourth Solution :-
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL||A->next==NULL){
        return A;
    }
    ListNode* count = A;
    ListNode* curr = A;
    while(curr!=NULL){
        if(curr->val!=1){
            swap(curr->val , count->val);
            count = count->next;
        }
        curr = curr->next;
    }
    return A;
}



//Fifth Solution :-
ListNode* Solution::solve(ListNode* A) {
    if ((A == NULL) || (A->next == NULL)) {
        return A;
    }
    ListNode* temp=A;
    int ones=0, zeros=0;
    while(temp!=NULL){
        if(temp->val==0){
            zeros++;
        }
        else{
            ones++;
        }
        temp=temp->next;
    }

    while(A!=NULL){
        if(zeros>0){
            A->val=0;
            zeros--;
        }
        else{
            A->val=1;
        }
        A=A->next;
    }
    return A;
}
