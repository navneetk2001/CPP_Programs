#include<iostream>
using namespace std;
#include<climits>

template<typename T>
class Node
{
public:
    T data;
    Node <T>*next;

    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
};

template<typename T>
class StackUsingLinkedList
{
	Node <T>*head;
    int size;


public:
	StackUsingLinkedList()
	{
		head=NULL;
        size=0;
	}

	int getsize()
	{
		return size;
	}

	bool isEmpty()
	{
		return size==0;
	}

    void push (int element)
    {
    	Node <T>*newNode= new Node<T>(element);
        newNode->next=head;
        head=newNode;
        size++;
    }


   T pop()
    {
    	if(isEmpty())
    	{
    		cout<<"Stack Empty !"<<endl;
    		return 0;
    	}
    	T ans=head->data;

        Node <T>*temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

  T top()
    {
    	if(isEmpty())
    	{
    		cout<<"Stack Empty !"<<endl;
    		return 0;
    	}
    	return head->data;
    }
};