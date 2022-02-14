#include <cstddef>

class Node
{
	public:
	int data;
	Node* prev;
	Node* next;
   

	Node(int data)
	{
		this->data=data;
		prev=NULL;
		next=NULL;

	}
};