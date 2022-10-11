https://leetcode.com/problems/intersection-of-two-linked-lists/



ListNode* getIntersectionNode(ListNode* A, ListNode*B){
	if(A==NULL || B==NULL){
		return NULL;
	}

	ListNode* head1=A;
	ListNode* head2=B;

	while(head1!=head2){
		if(head1==NULL){
			head1=B;
		}
		else{
			head1=head1->next;
		}

		if(head2==NULL){
			head2=A;
		}
		else{
			head2=head2->next;
		}
	}
	return head1;
}



//Second Method :-
class Solution {
public:

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* A=headA,*B=headB;
    int lenA=0,lenB=0;
    while(A!=NULL)
    {
        lenA++;
        A=A->next;
    }
    while(B!=NULL)
    {
        lenB++;
        B=B->next;
    }
    if(lenA>lenB)
    {
        A=headA;
        B=headB;
    }
    else{
        A=headB;
        B=headA;
    }
    int cnt=abs(lenA-lenB);
    while(cnt){
        A=A->next;
        cnt--;
    }
    while(A!=NULL && B!=NULL){
        if(A==B) return A;
        A=A->next,B=B->next;
    }
    return NULL;
}
};



// Approach 3 : 
//Using Floyad cylcle in Linked list(little bit of tricky but easy to understand and interesting solution)

// Steps :
// 1 find tail of any LL
// 2 link tail of LL you have found to the head of another LL
// 3 create 2 ptr slow and fast and move them
// slow = slow->next , fast = fast->next->next
// 4 whenever your slow and fast pointer meets that means there is a cycle present and a intersection point also.
// 5 again bring slow pointer to the starting position and move both pointer by one position untill both meet again
// 6 the point where they will meet that will be your intersection point
// 7 after finding ans Node make LL unchanged by removing connection of head and tail



class Solution {
public:
// floyd cycle algo
ListNode* floyad(ListNode* head){
        //base case
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            break;
        }
    }
    
    if(slow != fast){
        return NULL;
    }
    slow = head;
    
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL){    // base case
        return NULL;
    }
    
    // Traverse through LL_1
    ListNode* tail = headA;
    while(tail->next != NULL){
        tail = tail->next;
    }
    
    // connection of LL_1 tail and LL_2  head
    tail->next = headB;
    
    ListNode* ansNode = floyad(headA);
    
    // dissconnect LL again
    tail->next = NULL;

    return ansNode;
}
};