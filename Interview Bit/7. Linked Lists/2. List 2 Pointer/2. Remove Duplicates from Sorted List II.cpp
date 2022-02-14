








//Hint
Maintain a pointer for distinct element encountered before current block. When to skip the current block? How can maintaining the pointer before current block can help you?
Also, take care of corner cases if any.

//Solution Approach :-
Skip the node where head->next != NULL && head->val == head->next->val. Maintain a “pre” node which is the node just previous to the block of head you are checking.

Make sure you take care of corner cases :
1) Do you handle repetitions at the end ? ex : 1 -> 1
2) Do you handle cases where there is just one element ? ex : 1
3) Do you handle cases where there is just one element repeated numerous times ? 1->1->1->1->1->1



// First Method :-
ListNode* deleteDuplicates(ListNode* head){
	ListNode* dummy=new ListNode(0,head);
	ListNode* prev=dummy;

	while(head!=NULL){
		if(head->next!=NULL and head->val==head->next->val){
			//skip thenodes whose value are equal
			while(head->next!=NULL and head->val==head->next->val){
				head=head->next;
			}
			prev->next=head->next;
		}
		else{
			prev=prev->next;
		}
		head=head->next;
	}
	return dummy->next;
}



//Second Method :-
ListNode* Solution::deleteDuplicates(ListNode* A) {
	if(A == NULL || A->next == NULL)
		return A;
	
	map<int,int> mappy;
	ListNode* temp = A;
	while(temp!=NULL) { // store all values in maps along with the number of times they occur
		mappy[temp->val]++;
		temp = temp -> next;
	}
	ListNode* head = NULL;
	ListNode* last = NULL;

	for(auto it = mappy.begin(); it != mappy.end(); it++) {
		if(it->second == 1) { // just add those values to the list which occur once
			if(head == NULL) { // this case is for the first time a unique number is encountered
				head = new ListNode(it->first);
				last = head;
			}
			else {
				ListNode* tempy = new ListNode(it->first);
				last -> next = tempy;
				last = tempy;
			}
		}
		else
			continue;
	}
	return head;
}


//Third Method :-
ListNode* Solution::deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* pre = fakeHead;
        ListNode* cur = head;
        while (cur != NULL) {
            while (cur->next != NULL && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if (pre->next == cur) {
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return fakeHead->next;
    }


