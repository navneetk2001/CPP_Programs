#include<iostream>
using namespace std;
#include<climits>


class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};


class StackUsingLinkedList
{
	Node *head;
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
    	Node *newNode= new Node(element);
        newNode->next=head;
        head=newNode;
        size++;
    }


    int pop()
    {
    	if(isEmpty())
    	{
    		cout<<"Stack Empty !"<<endl;
    		return 0;
    	}
    	int ans=head->data;

        Node *temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

    int top()
    {
    	if(isEmpty())
    	{
    		cout<<"Stack Empty !"<<endl;
    		return INT_MIN;
    	}
    	return head->data;
    }
};