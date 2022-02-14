void reverse(node* head){
	node* prev=NULL;
	node* curr=head;
	node* next_ptr;

	while(curr!=NULL){
		//save the next node
		next_ptr = curr->next;
		//make the current node points to previous
		curr->next = prev;

		//update prev and curr take them one step forward
		prev = curr;
		curr = next;
	}
	head = prev;
}



//Recursively Reverse a Linked List
node* recReverse(node* head){
	//smallest linked list
	if(head==NULL or head->next==NULL){
		return head;
	}
	//rec case
	node* shead = recReverse(head->next);

	node* temp=shead;

	while(temp!=NULL){
		temp=temp->next;
	}

	head->next = NULL;
	temp->next=head;

	return shead;
}




//Recursively Reverse a Linked List :- Optimised Code
node* recReverse(node* head){
	//smallest linked list
	if(head==NULL or head->next==NULL){
		return head;
	}
	//rec case
	node* shead = recReverse(head->next);

	node* temp=head->next;
	temp->next=head;
	head->next = NULL;


	//         or 
	// head->next->next = head;
	// head->next=NULL;

	return shead;
}