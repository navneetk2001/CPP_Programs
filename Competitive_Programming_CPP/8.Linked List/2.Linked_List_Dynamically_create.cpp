#include<iostream>
using namespace std;
#include"Node.cpp"


// Node* takeInput()      // This function has time complexity of order of N^2.
// {
// 	int data;
// 	cin>>data;

// 	Node* head=NULL;
// 	while(data!=-1)
// 	{
// 		Node* newNode=new Node(data);
// 		if(head==NULL)
// 		{
// 			head=newNode;
// 		}
// 		else
// 		{
// 			Node* temp=head;
// 			while(temp->next!=NULL)
// 			{
// 				temp=temp->next;
// 			}
// 			temp->next=newNode;
// 		}
// 		cin>>data;
// 	}
// 	return head;
// }


Node* takeInput_Better()      // This function has time complexity of order of N.
{
	int data;
	cin>>data;

	Node* head=NULL;
	Node* tail=NULL;

	while(data!=-1)
	{
		Node* newNode=new Node(data);
		if(head==NULL)
		{
			head=newNode;
			tail=newNode;
		}
		else
		{
			tail->next=newNode;
			tail=tail->next;
		}
		cin>>data;
	}
	return head;
}	

// Node* insertNode(Node *head,int pos,int data)    //Insertion of element at any position
// {
// 	Node* newNode=new Node(data);
// 	int count=0;
// 	Node* temp=head;

// 	if(pos==0)
// 	{
// 		newNode->next=head;
// 		head=newNode;
// 		return head;
// 	}

// 	while(temp!=NULL && count<pos-1)
// 	{
// 		temp=temp->next;
// 		count++;
// 	}

// 	if(temp!=NULL)
// 	{
// 		Node* a= temp->next;
// 		temp->next=newNode;
//         newNode->next=a;
// 	}
// 	return head;
// }


// Node* delete_Node(Node *head,int pos)    //Deletion of element at any position
// {
// 	int count=0;
// 	Node* temp=head;

// 	if(pos==0)
// 	{
// 		Node* a=head;
// 		head=head->next;
// 		delete a;
// 		return head;
// 	}

// 	while(temp!=NULL && count<pos-1)
// 	{
// 		temp=temp->next;
// 		count++;
// 	}
// 	if (temp==NULL)
// 	{
// 		return head;
// 	}

// 	else
// 	{
// 		Node* a=temp->next;
// 	    Node* b=a->next;
// 	    delete a;
// 	    temp->next=b;	
// 	}
// 	return head;
// }


// Node *findMiddle(Node *head) {       // This function has complexity of order n.
//     Node *p = head;
//     int numberOfNodes = 1;
//     while (p->next != NULL) {
//         numberOfNodes++;
//         p = p->next;
//     }

//     int mid = numberOfNodes / 2;

//     Node *ptr = head;
//     while (mid--) {
//         ptr = ptr->next;
//     }
//     return ptr;
// }


// Node *findMiddle(Node *head) {        // This function has complexity of order n/2.
//     if (head == NULL) {
//         return head;
//     }

//     if (head->next == NULL) {
//         return head;
//     }

//     Node *fast = head;
//     Node *slow = head;

//     while (fast != NULL && fast->next != NULL) {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return slow;
// }


// Node* Merge_2_Sorted_LL(Node* head1, Node* head2)
// {
// 	if (head1 == NULL) 
// 	{
//         return head2;
//     } 
//     else if (head2 == NULL)
//     {
//         return head1;
//     }

// 	Node* finalHead=NULL;

// 	if(head1->data <= head2->data)
// 	{
// 		finalHead=head1;
// 		head1=head1->next;
// 	}
// 	else
// 	{
// 		finalHead=head2;
// 		head2=head2->next;
// 	}

// 	Node* finalTail=finalHead;

// 	while( head1!=NULL && head2!=NULL )
// 	{
// 		Node* temp=NULL;

// 		if(head1->data <= head2->data)
// 	    {
// 		    temp=head1;
// 		    head1=head1->next;
// 	    }
// 	    else
// 	    {
// 		    temp=head2;
// 		    head2=head2->next;
// 	    }

// 	    finalTail->next=temp;
// 	    finalTail=temp;
// 	}

//     if (head1 != NULL) 
//     {
//         finalTail->next = head1;
//     } 
//     else if (head2 != NULL )
//     {
//         finalTail->next = head2;
//     }

//     return finalHead;
// }


// Node *findMiddle(Node *head) {       // This function has complexity of order n.
//     Node *p = head;
//     int numberOfNodes = 0;
//     while (p->next != NULL) {
//         numberOfNodes++;
//         p = p->next;
//     }

//     int mid = numberOfNodes / 2;

//     Node *ptr = head;
//     while (mid--) {
//         ptr = ptr->next;
//     }
//     return ptr;
// }


// Node* merge(Node *head1, Node *head2) {
// 	if(head1 == NULL) {
// 		return head2;
// 	}
// 	if(head2 == NULL) {
// 		return head1;
// 	}
// 	Node *head = NULL, *tail = NULL;

// 	if(head1 -> data < head2 -> data) {
// 		head = head1;
// 		tail = head1;
// 		head1 = head1 -> next;
// 	}
// 	else {
// 		head = head2;
// 		tail = head2;
// 		head2 = head2 -> next;
// 	}

// 	while(head1 != NULL && head2 != NULL) {
// 		if(head1 -> data < head2 -> data) {
// 			tail -> next = head1;
// 			tail = head1;
// 			head1 = head1 -> next;
// 		}
// 		else {
// 			tail -> next = head2;
// 			tail = head2;
// 			head2 = head2 -> next;
// 		}
// 	}
// 	if(head1 != NULL) {
// 		tail -> next = head1;
// 	}
// 	if(head2 != NULL) {
// 		tail -> next = head2;
// 	}
// 	return head;
// }


// Node* MergeSort(Node* head)
// {
// 	if (head == NULL || head -> next == NULL) 
// 	{
//         return head;
//     }

//     Node* mid=findMiddle(head);

//     Node* half1=head;
//     Node* half2=mid->next;
//     mid -> next = NULL;
    
//     half1 = MergeSort(half1);
// 	half2 = MergeSort(half2);

// 	Node *finalHead = merge(half1, half2);

// 	return finalHead;	
// }



Node* reverseLL(Node* head)
{
	Node* prev=NULL;
	Node* curr=head;

	while(curr!=NULL)
	{
		Node* next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}

	return prev;
}


void Print(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}


int main()
{
	// Node* head=takeInput_Better();
	// head=MergeSort(head);
	// Print(head);

    // Node *head1=takeInput_Better();
    // Node *head2=takeInput_Better();

    // Node *head=Merge_2_Sorted_LL(head1,head2);
	// Print(head);

    // int pos,data;
    // cin>>pos>>data;
	// head=insertNode(head,pos,data);
	// Print(head);

    // int position;
	// cin>>position;
	// head=delete_Node(head,position);
    // Print(head);

	// head=midpoint_Node(head);

	// cout<<endl;
	// Node* mid=findMiddle(head);
	// cout<<mid->data<<endl;

    Node* head=takeInput_Better();
	head=reverseLL(head);
	Print(head);

}


