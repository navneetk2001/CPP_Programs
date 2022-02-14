#include<iostream>
using namespace std;
#include"Node.cpp"

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
	Node n1(1);
    Node* head=&n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);

    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n5.next=&n6;

    Print(head);

    return 0;
	
}