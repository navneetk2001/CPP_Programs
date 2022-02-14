#include<iostream>
using namespace std;
#include"Node.cpp"



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

// Node* insertNode_Recursively(Node *head,int pos,int data)    //Insertion of element at any position except last
// {
// 	Node* newNode=new Node(data);


// 	if (head==NULL)
// 	{
// 		return head;
// 	}

// 	if (pos==0)
// 	{
// 		newNode->next=head;
// 		head=newNode;
// 		return head;
// 	}

// 	head->next=insertNode_Recursively(head->next,pos-1,data);

// 	return head;
// }


// Node* delete_Node_Recursively(Node *head,int pos)    //Deletion of element at any position
// {

//     if (head==NULL)
// 	{
// 		return head;
// 	}

// 	if(pos==0)
// 	{
// 		Node* a=head;
// 		head=head->next;
// 		delete a;
// 		return head;
// 	}

	
// 	head->next=delete_Node_Recursively(head->next,pos-1);
// 	return head;
// }


// Node* sortTwoLists(Node* first, Node* second) 
// {
//     if(!first)
//     {
//         return second;
//     }
//     if(!second)
//     {
//         return first;
//     }

//     if((first -> data) < (second ->data))
//     {
//         first -> next = sortTwoLists(first -> next, second);
//         return first;
//     }
//     else
//     {
//         second -> next = sortTwoLists(first, second -> next);
//         return second;
//     }
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


// Node* reverseLL(Node* head)
// {
// 	if(head==NULL || head->next==NULL)
// 	{
// 		return head;
// 	}

// 	Node* smallAns=reverseLL(head->next);

// 	Node* temp=smallAns;
// 	while(temp->next!=NULL)
// 	{
// 		temp=temp->next;
// 	}
// 	temp->next=head;
// 	head->next=NULL;
// 	return smallAns;
// }


// class Pair{           //Whenever we need to return multiple values from a function, we need to create a class
// 	public:
// 	Node* head;
// 	Node* tail;
// };

// Pair reverseLL_2(Node* head)
// {
// 	if(head==NULL || head->next==NULL)
// 	{
// 		Pair ans;
// 		ans.head=head;
// 		ans.tail=head;
// 		return ans;
// 	}

// 	Pair smallAns=reverseLL_2(head->next);

// 	smallAns.tail->next=head;
// 	head->next=NULL;

// 	Pair ans;
// 	ans.head=smallAns.head;
// 	ans.tail=head;
// 	return ans;
// }


// Node* reverseLL_Better(Node* head)
// {
// 	return reverseLL_2(head).head;
// }


// Node* reverseLL_3(Node* head)
// {
// 	if(head==NULL || head->next==NULL)
// 	{
// 		return head;
// 	}

// 	Node* smallAns=reverseLL_3(head->next);

// 	Node* tail=head->next;
// 	tail->next=head;
// 	head->next=NULL;
// 	return smallAns;
// }



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
    // Node *head=takeInput_Better();
	// Print(head);

    // int pos,data;
    // cin>>pos>>data;
	// head=insertNode_Recursively(head,pos,data);
	// Print(head);

    // int position;
	// cin>>position;
	// head=delete_Node_Recursively(head,position);
    // Print(head);

    
    // Node *first=takeInput_Better();
    // Node *second=takeInput_Better();
    // Node *head=sortTwoLists(first,second);
    // Print(head);
    
    // Node* head=takeInput_Better();
	// head=MergeSort(head);
	// Print(head);

	// Node* head=takeInput_Better();
	// head=reverseLL_3(head);
	// Print(head);

	


}


