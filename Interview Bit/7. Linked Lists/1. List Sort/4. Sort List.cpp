// Sort a linked list in O(n log n) time using constant space complexity.

// Example :
// Input : 1 -> 5 -> 4 -> 3
// Returned list : 1 -> 3 -> 4 -> 5


//Hint :-
// Merge sort is usually quicker and easier to implement when it comes to implementing sorting in O(nlogn).
// Think recursively. You will end up breaking the problems into small pieces.


//Solution Approach :-
// Can implement either merge sort or qsort.
// Lets look at merge sort. Traverse the linked list to find the mid point of the list. Now sort the first half and second half separatly by calling the function on them. Then merge the 2 lists ( Note that we already have solved a problem to merge 2 lists ).


// First Method :-  //Merge Sort

//Function to merge 2 linked list
ListNode* merge(ListNode* a, ListNode* b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}

	//take a head pointer
	ListNode* c;
	if(a->val<b->val){
		c=a;
		c->next=merge(a->next,b);
	}
	else{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}

//Function to calcualate mid of a linked list
ListNode* midpoint(ListNode* head){  
	if(head==NULL or head->next==NULL){
		return head;
	}

	ListNode* slow=head;
	ListNode* fast=head->next;

	while(fast!=NULL and fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

ListNode* Solution::sortList(ListNode* A) {
    ListNode* head=A;
    //base case
	if(head==NULL or head->next==NULL){
		return head;
	}

	//rec case
	//1. Break in 2 parts on basis of mid
	ListNode* mid= midpoint(head);
	ListNode* a = head;
	ListNode* b = mid->next;
	mid->next=NULL;

	//2. rec sort the two parts
	a=sortList(a);
	b=sortList(b);

	//3. merge them
	ListNode* c=merge(a,b);
	return c;
}

//Second Method :-
ListNode* Solution::sortList(ListNode* a) {
	ListNode *temp=a;
	vector<int>v;
	while(temp!=NULL)
	{
		v.push_back(temp->val);
		temp=temp->next;
	}
	sort(v.begin(),v.end());
	temp=a;
	int i=0;
	while(temp!=NULL)
	{
		temp->val=v[i++];
		temp=temp->next;
	}
	return a;
}


//Third Method :-//Quick Sort

typedef ListNode node;
node* partition(node* A, node* s, node* e){
	node* h=s;
	int cur=e->val;

	while(s!=e){
	    if(s->val<=cur){
	        swap(s->val, h->val);
	        h=h->next;
	    }
	    s=s->next;
	}
	swap(h->val, e->val);
	return h;
}


node* quicksort(node* A, node* s, node* e){
	int count1=1;
	int count2=1;

	node* h=A;
	while(h!=s){
	    h=h->next;
	    count1++;
	}
	h=A;
	while(h!=e){
	    h=h->next;
	    count2++;
	}
	if(count2-count1<=0) return A;

	node* index=partition(A, s, e);

	h=A;
	while(h->next && h->next!=index){
	    h=h->next;
	}
	if(s && h) quicksort(A, s, h);

	if(index->next && e) quicksort(A, index->next, e);

	return A;
}


ListNode* Solution::sortList(ListNode* A) {
	if(A==NULL || A->next==NULL) return A;
	node* s=A;
	node* e=A;
	while(e->next){
	    e=e->next;
	}

	A=quicksort(A, s, e);

	return A;
}





