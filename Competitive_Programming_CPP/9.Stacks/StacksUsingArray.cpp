#include<iostream>
using namespace std;
#include<climits>

class StackUsingArray
{
	int *data;
	int nextIndex;
	int capacity;


public:
	StackUsingArray(int TotalSize)
	{
		data=new int[TotalSize];
		nextIndex=0;
		capacity=TotalSize;
	}

	int size()
	{
		return nextIndex;
	}

	bool isEmpty()
	{
		return nextIndex==0;
	}

    void push (int element)
    {
    	if(nextIndex==capacity)
    	{
    		cout<<"Stack is Full !"<<endl;
    		return;
    	}

    	data[nextIndex]=element;
    	nextIndex++;
    }


    int pop()
    {
    	if(isEmpty())
    	{
    		cout<<"Stack Empty !"<<endl;
    		return INT_MIN;
    	}
    	nextIndex--;
    	return data[nextIndex];
    }

    int top()
    {
    	if(isEmpty())
    	{
    		cout<<"Stack Empty !"<<endl;
    		return INT_MIN;
    	}
    	return data[nextIndex-1];
    }
};