Sort a linked list using insertion sort.
We have explained Insertion Sort at Slide 7 of Arrays
Insertion Sort Wiki has some details on Insertion Sort as well.

Example :
Input : 1 -> 3 -> 2
Return 1 -> 2 -> 3


//Solution Approach :-
This is very much a simulation problem.
The only trick is how do you move a node from ith position to jth position.
How do you move the pointers to do so ? Would having a temporary node help ?


// First Method :-
ListNode* Solution::insertionSortList(ListNode* head) {
	ListNode* summy = new ListNode(10000);

	while(head){
		ListNode* next=head->next;
		ListNode* temp=dummy;

		while(temp->next && temp->next->val<head->val){
			temp=temp->next;
		}
		head->next=temp->next;
		temp->next=head;
		head=next;
	}
	return dummy->next;
}


//Second Method :-
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *start = new ListNode(0);
    ListNode *head = A;
    start->next = head;
    ListNode *i = head, *prev = start;
    
    while(i != NULL){
        if(i->next && (i->val > i->next->val)){
            while(prev->next && (prev->next->val < i->next->val)) prev = prev->next;
            //insert btw prev and prev->next
            ListNode *temp = prev->next;
            prev->next = i->next;
            i->next = i->next->next;
            prev->next->next = temp;
            prev = start;
        } else {
            i = i->next;
        }
    }
    return start->next; 
}


//Third Method :-
void insertSmallerElement(ListNode* dummy, ListNode* curr)
{
    ListNode* trav = dummy;
    while (trav)
    {
        if (trav->next == NULL || curr->val < trav->next->val)
        {
            curr->next = trav->next;
            trav->next = curr;
            break;
        }
        trav = trav->next;
    }
}
 
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* dummy = new ListNode(-1);
    
    ListNode* curr = A;
    ListNode* next;
    
    while (curr)
    {
        next = curr->next;
        insertSmallerElement(dummy, curr);
        curr = next;
    }
    
    return dummy->next;
}





