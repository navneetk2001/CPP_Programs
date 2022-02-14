#include<iostream>
using namespace std;
#include<queue>
#include"BinaryTreeNode.h"
#include"BinarySearchTreeClass.h"


int main()
{
	// ONLINE_JUDGE
	#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif 

	BST b;

	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);

	b.printTree();
	cout<<endl;

	b.deleteData(10);
	cout<<"After Deleting a node from the BST: "<<endl;
	b.printTree();
	cout<<endl;
}
