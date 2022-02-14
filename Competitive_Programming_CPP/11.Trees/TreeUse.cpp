#include<iostream>
#include<queue>
#include"TreeNode.h"
using namespace std;


// void printTree(TreeNode<int>*root)    //It prints data NodeWise.......
// {
// 	if(root==NULL)                       //It is an edge case not a base case...
// 	{
// 		return;
// 	}

// 	cout<<root->data<<":";

// 	for(int i=0;i<root->children.size();i++)
// 	{
// 		cout<<root->children[i]->data<<",";
// 	}

//     cout<<endl;
// 	for(int i=0;i<root->children.size();i++)
// 	{
// 		printTree(root->children[i]);
// 	}
// }


// TreeNode<int>* takeInput()       //It takes input NodeWise
// {
// 	int rootData;
// 	cout<<"Enter Data: ";
// 	cin>>rootData;
    
//     TreeNode<int>*root=new TreeNode<int>(rootData); 

//     int numChild;
//     cout<<"Enter number of children of "<<rootData<<": ";
//     cin>>numChild;

//     for(int i=0;i<numChild;i++)
//     {
//     	TreeNode<int>* child=takeInput();
//     	root->children.push_back(child); 
//     }
//     return root;
// }


TreeNode<int>* takeInputLevelWise()       //It takes input LevelWise
{
	int rootData;
	cout<<"Enter root Data: ";
	cin>>rootData;
    
    TreeNode<int>*root=new TreeNode<int>(rootData); 

    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
    	TreeNode<int>*front=pendingNodes.front();
    	pendingNodes.pop();

    	int numChild;
        cout<<"Enter number of children of "<<front->data<<": ";
        cin>>numChild;

        for(int i=0;i<numChild;i++)
        {
        	int childData;
        	cout<<"Enter "<<i<<"th child of "<<front->data<<": ";
        	cin>>childData;
    	    TreeNode<int>* child=new TreeNode<int>(childData);
    	    front->children.push_back(child);
    	    pendingNodes.push(child); 
        }
    }   
    return root;
}


void printTreeLevelWise(TreeNode<int>*root)     //It will print data levelwise...
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return;
	}

	queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
    	TreeNode<int>*front=pendingNodes.front();
    	cout<<front->data<<":";
    	pendingNodes.pop();

    	for(int i=0;i<front->children.size();i++)
	    {
		    cout<<front->children[i]->data<<",";
		    pendingNodes.push(front->children[i]);
	    }
        cout<<endl;
    }   
}


int numNodes(TreeNode<int>*root)
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return 0;
	}

	int ans=1;
	for(int i=0;i<root->children.size();i++)
	{
		ans+=numNodes(root->children[i]);
	}
	return ans;
}


void printAtLevelK(TreeNode<int>*root,int k)
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return;
	}
    if(k==0)
    {
    	cout<<root->data<<" ";
    	return;
    }
    for(int i=0;i<root->children.size();i++)
	{
		printAtLevelK(root->children[i],k-1);
	}
}

int numLeafNodes(TreeNode<int>*root)
{
	if(root==NULL)
	{
        return 0;
	}
    if(root->children.size()==0)
    {
        return 1;
    }

    int smallAns=0;
    for(int i=0;i<root->children.size();i++)
    {
        smallAns+=numLeafNodes(root->children[i]);
    }
    return smallAns;
}


int height(TreeNode<int>* root) 
{
    if(root==NULL)
    {
        return 0;
    }

    int max = 0;
    
    for(int i=0;i<root->children.size();i++)
    {
        int temp = height(root->children[i]);
        if(temp>max)
        {
            max=temp;
        }
    }
    return max+1;
}


void deleteTree(TreeNode<int>* root)
{
	for(int i=0;i<root->children.size();i++)
	{
		deleteTree(root->children[i]);
	}
	delete root;
}

void preOrder(TreeNode<int>*root)
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return;
	}
    cout<<root->data<<" ";

    for(int i=0;i<root->children.size();i++)
	{
		preOrder(root->children[i]);
	}
}

void postOrder(TreeNode<int>*root)
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return;
	}

    for(int i=0;i<root->children.size();i++)
	{
		postOrder(root->children[i]);
	}
	cout<<root->data<<" ";
}



int main()
{
	
    TreeNode<int>* root=takeInputLevelWise();
    cout<<endl;

    cout<<"Printing Nodes LevelWise: "<<endl;
	printTreeLevelWise(root);
	cout<<endl;

	int count=numNodes(root);
	cout<<"No.of Nodes in this Tree: "<<count<<endl;
	cout<<endl;

	int k;
	cout<<"Enter Level to print nodes: ";
	cin>>k;
	cout<<"Nodes at level "<<k<<": ";
    printAtLevelK(root,k);
    cout<<endl;
    
    cout<<endl;
    int LeafNodes=numLeafNodes(root);
    cout<<"No of Leaf Nodes :"<<LeafNodes<<endl;

    cout<<endl;
    int Height=height(root);
    cout<<"Height of this tree: "<<Height<<endl;

    // deleteTree(root)
   
    cout<<endl;
    cout<<"PreOrder Traversal : ";
    preOrder(root);
    cout<<endl;

    cout<<endl;
    cout<<"PostOrder Traversal : ";
    postOrder(root);
    cout<<endl;

    delete root;

}
