// Given a linked list A of length N and an integer B.
// You need to reverse every alternate B nodes in the linked list A.

// Example Input
// Input 1:
//  A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
//  B = 3

//  Input 2:
//  A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
//  B = 2

// Example Output
// Output 1:
//  7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
// Output 2:
//  4 -> 1 -> 6 -> 6 -> 10 -> 4

//Hint :-
// Process 2k nodes and recursively call for rest of the list.
// Please solve this before solve this question.

//Solution Approach :-
// Method 1:((Process 2k nodes and recursively call for rest of the list).
// kAltReverse(ListNode *head, int k)
// Reverse first k nodes.
// In the modified list head points to the kth node. So change next of head to (k+1)th node
// Move the current pointer to skip next k nodes.
// Call the kAltReverse() recursively for rest of the n - 2k nodes.
// Return new head of the list.
// Time Complexity: O(N)


// Method 2:(Process k nodes and recursively call for rest of the list)
// The method 1 reverses the first k node and then moves the pointer to k nodes ahead. So method 1 uses two while loops and processes 2k nodes in one recursive call.
// This method processes only k nodes in a recursive call. It uses a third bool parameter b which decides whether to reverse the k elements or simply move the pointer.
// _kAltReverse(ListNode *head, int k, bool b)

// If b is true, then reverse first k nodes.
// If b is false, then move the pointer k nodes ahead.
// Call the kAltReverse() recursively for rest of the n - k nodes and link rest of the modified list with end of first k nodes.
// Return new head of the list.
//Time Complexity: O(N)



// First Method :-
ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* current = A;
    ListNode* next;
    ListNode* prev = NULL;
    int count = 0;
 
    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < B){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* 2) Now head points to the kth node. So change next  of head to (k+1)th node*/
    if(A != NULL)
        A->next = current;
 
    /* 3) We do not want to reverse next k nodes. So move the current pointer to skip next k nodes */
    count = 0;
    while(count < B-1 && current != NULL ){
        current = current->next;
        count++;
    }
 
    /* 4) Recursively call for the list starting from current->next. And make rest of the list as next of first node */
    if(current != NULL){
        current->next = solve(current->next, B);
    }
 
    /* 5) prev is new head of the input list */
    return prev;
}



//Second Method :-
/* Function to reverse alternate k nodes and return the pointer to the new head node */
Node* kAltReverse(struct Node* head, int k)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;
    Node* tail = NULL;
    Node* newHead = NULL;
    Node* join = NULL;
    int t = 0;
 
    // Traverse till the end of the linked list
    while (curr) {
        t = k;
        join = curr;
        prev = NULL;
 
        /* Reverse alternative group of k nodes
        // of the given linked list */
        while (curr && t--) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
 
        // Sets the new head of the input list
        if (!newHead)
            newHead = prev;
 
        /* Tail pointer keeps track of the last node
        of the k-reversed linked list. The tail pointer
        is then joined with the first node of the
        next k-nodes of the linked list */
        if (tail)
            tail->next = prev;
 
        tail = join;
        tail->next = curr;
 
        t = k;
 
        /* Traverse through the next k nodes
        which will not be reversed */
        while (curr && t--) {
            prev = curr;
            curr = curr->next;
        }
 
        /* Tail pointer keeps track of the last
        node of the k nodes traversed above */
        tail = prev;
    }
 
    // newHead is new head of the modified list
    return newHead;
}


//Third Method :-
ListNode* Solution::solve(ListNode* A, int B) {
	ListNode* cur=A;
	ListNode* prev=NULL;
	ListNode* next=NULL;
	ListNode* prev1=NULL;

	if(cur==NULL) 
		return cur;

	int cnt=0;
	while(cur!=NULL && cnt<2*B){
		next=cur->next;
		if(cnt<B)
			cur->next=prev;
		if(cnt<B)
			prev=cur;
		prev1=cur;
		cur=next;
		cnt++;

		if(cnt==B){
			A->next=cur;
		}
	}

	if(prev1->next && cnt==2*B)
		prev1->next=solve(cur, B);

	return prev;
}

//Fourth Method :-
ListNode* Solution::solve(ListNode* A, int b) {
    if(A == NULL) return NULL;
    ListNode *head,*curr,*next,*prev;
    curr = A; prev = NULL;
    for(int i = 0; i<b;i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    A->next = curr;
    if(curr==NULL) return head;
    
    for(int i = 0; i<b-1;i++)
    curr = curr->next;
    
    curr->next = solve(curr->next,b);
    return head;
}



