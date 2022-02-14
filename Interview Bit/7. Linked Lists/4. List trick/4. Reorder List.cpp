// Given a singly linked list
//     L: L0 → L1 → … → Ln-1 → Ln,
// reorder it to:
//     L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// You must do this in-place without altering the nodes’ values.
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.


//Hint :-
Note that moving in the reverse order in the list is not feasible unless you use additional memory. This indicates that we need to reverse some part of the list.
Can you figure out a solution reversing a part of the list ?

//Solution Approach :-
1 Break the list from middle into 2 lists.
2) Reverse the latter half of the list.
3) Now merge the lists so that the nodes alternate.


// First Method :-
ListNode* Solution::reorderList(ListNode* A) {
    vector<int>V;
    ListNode* node = A;
    int i=0;
    while(node!=NULL)
    {
        V.push_back(node->val);
        node = node->next;
        i++;
    }
    ListNode* tail = A;
    int j=0;
    int y=0;
    int q=0;
    while(j<i)
    {
        if(j%2 == 0)
        {
            tail->val = V[y];
            y++;
        }
        else
        {
            tail->val = V[V.size()-1-q];
            q++;
        }
        tail = tail->next;
        j++;
    }
    return(A);
}


//Second Method :-
ListNode* reverse(ListNode* A){
	ListNode* p=NULL;
	ListNode* c=A;
	ListNode* n=NULL;

	while(c!=NULL){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	return p;
}


ListNode* Solution::reorderList(ListNode* A) {
	if(A==NULL){
		return NULL;
	}

	ListNode* slow=A;
	ListNode* fast=A->next;

	while(fast!=NULL && fast->next!=NULL){  //for finding mid
		slow=slow->next;
		fast=fast->next->next;
	}

	ListNode* mid=slow;
	ListNode* h2=reverse(mid->next); //for reverse after mid
	mid->next=NULL;

	ListNode* h1=A;
	while(h1!=NULL && h2!=NULL){   //changing links
		ListNode* th2= h2->next;
		ListNode* th1= h1->next;
		h1->next=h2;
		h2->next=th1;
		h1=th1;
		h2=th2;
	}
	return A;
}


//Third Method :- Reverse-Second-Half-And-Merge-Both-Halves-Alternatively
ListNode* Solution::reorderList(ListNode* A) {
	if(A==NULL || A->next==NULL)return A;
	ListNode* slow=A;
	ListNode* fast=A->next;
	while(fast && fast->next)
	{
	    slow=slow->next;
	    fast=fast->next->next;
	}
	ListNode* cur=slow->next;
	ListNode* prev=NULL;
	slow->next=NULL;
	while(cur)
	{
	    ListNode* next=cur->next;
	    cur->next=prev;
	    prev=cur;
	    cur=next;
	}

	ListNode* res=new ListNode(0);
	ListNode* ans=res;
	ListNode* head=A;
	int i=0;
	while(prev || head )
	{
	    if(i%2==0)
	    {
	        res->next=head;
	        head=head->next;
	        res=res->next;
	    }
	    else
	    {
	        res->next=prev;
	        prev=prev->next;
	        res=res->next;
	    }
	    i++;
	}
	return ans->next;
}


//Fourth Solution :-
ListNode* Solution::reorderList(ListNode* A) {
	stack<ListNode*> s;
	ListNode * a=A;
	int n=0;
	while(a){
		s.push(a);
		a=a->next;
		n++;
	}
	ListNode* b=A;
	for(int i=0;i<n/2;i++){
		ListNode * temp=b->next;
		b->next=s.top();
		s.top()->next=temp;
		s.pop();
		b=temp;
	}
	b->next=NULL;
	
	return A;
}



//
//n= 6
//0 - 1 - 2 - 3 - 4 - 5
  
//
ListNode* Solution::reorderList(ListNode* A) 
{
    int length=0;
    ListNode *temp=A;
    if(length==2)
    return A;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    int mid=(length-1)/2;
    temp=A;
    while(mid--)
    temp=temp->next;
    
    ListNode *prev=NULL,*curr=temp->next,*nxt;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    temp->next=prev;
    //0 - 1 - 2 - 5 - 4 - 3
    //0 - 5 - (start)1 - 2 - 5,  (rev)4 - 3 
    //0 - 5 - 1 - 4 - (start)2 - 5, (rev)3
    //0 - 5 - 1 - 4 - 2 - 3 - 5
    ListNode *start=A;
    ListNode *rev=temp->next;
    temp->next=NULL;
    while(rev!=NULL)
    {
        ListNode *tmp=start->next;
        start->next=rev;
        ListNode *tmp2=rev->next;
        rev->next=tmp;
        start=tmp;
        rev=tmp2;
    }
    return A;
}
