// Given a singly linked list and an integer K, reverses the nodes of the
// list K at a time and returns modified linked list.
// NOTE : The length of the list is divisible by K
// Example :
// Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
// You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5
// Try to solve the problem using constant extra space.


//Solution Approach
//Split the list into buckets of length K and then reverse each of them. After this you have to concatenate the buckets and return the list. To split the list into buckets of length K, use 2 pointers that are K elements afar. To reverse a linked list check this.


// First Method :-
ListNode* reverseKGroup(ListNode* head, int k){
	ListNode *dummy = new ListNode(0);
	dummy->next = head;

	ListNode *curr = dummy, *nex=dummy, *prev=dummy;
	int count = 0;

	while(curr->next!=NULL){
		curr = curr ->next;
		count++;
	}

	while(count>=k){
		curr = prev->next;
		nex = curr->next;
		for(int i=1;i<k;i++){
			curr->next = nex ->next;
			nex->next = prev ->next;
			prev->next = nex;
			nex = curr->next;
		}
		pre =  curr;
		count -= k;
	}
    return dummy->next;
}


//Second Method :- Recursive
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode *curr = A, *prev=NULL;
    ListNode *nex;
    int count = 0;

    while(curr!=NULL && count<B){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        count++;
    }
    
    if(nex!=NULL){
        A->next =reverseList(nex,B);
    }

    return prev;
}


//Third Method :-
int length(ListNode *x){
    int l=0;
    while(x){
        l++;
        x=x->next;
    }
    return l;
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    int l=length(A); 
    ListNode *k,*head=A;
    int d,r;
    d=l/B;
    r=l%B;

    stack<int> s;
    for(int i=0;i<d;i++){ 
    	k=A;
        for(int j=0;j<B;j++){
           s.push(A->val);
           A=A->next;
        }

        A=k;
        for(int j=0;j<B;j++){
	        A->val=s.top();
	        s.pop();
	        A=A->next;
        }
    }

    k=A;
    while(A){
        s.push(A->val);
        A=A->next;
    }

    A=k;
    while(A){
        A->val=s.top();
        s.pop();
        A=A->next;
    }

    return head;
}



//Fourth Method :-
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    ListNode* ptr=A;
    vector<int>temp;
    while(ptr)
    {
        temp.push_back(ptr->val);
        ptr=ptr->next;
    }

    for(int i=0;i<int(temp.size());i=i+B)
    {
        reverse(temp.begin() + i, temp.begin() + i+B);
    }
    ptr=A;
    for(int i=0;i<int(temp.size());i++)
    {
        ptr->val=temp[i];
        ptr=ptr->next;
    }
    return A;
    
}





