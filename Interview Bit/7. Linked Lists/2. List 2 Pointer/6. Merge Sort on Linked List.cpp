/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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

