#include<iostream>
#include"TreeNode.h"
using namespace std;

void printTree(TreeNode<int>*root)   //It is not an efficient method to print a tree....
{
	cout<<root->data<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		printTree(root->children[i]);
	}
}


int main()
{
	TreeNode<int>*root=new TreeNode<int>(1);     //It creates a node of Tree type
	TreeNode<int>*node1=new TreeNode<int>(2);
	TreeNode<int>*node2=new TreeNode<int>(3);

	root->children.push_back(node1);       //Push_back is used to make a connection between parent and child;
	root->children.push_back(node2);

	printTree(root);

}