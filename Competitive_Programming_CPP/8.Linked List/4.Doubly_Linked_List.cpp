#include<iostream>
using namespace std;
#include"Node_doubly.cpp"


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


