#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"
using namespace std;


void printTreeNodeWise(BinaryTreeNode<int>*root)    //It prints data NodeWise.......
{
	if(root==NULL)                       //It is an edge case not a base case...
	{
		return;
	}

	cout<<root->data<<":";

	if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data<<" ";
    }


    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data<<" ";
    }

    cout<<endl;
    printTreeNodeWise(root->left);
    printTreeNodeWise(root->right);
}


// BinaryTreeNode<int>* takeInputNodeWise()            //It takes input NodeWise
// {
// 	int rootData;
// 	cout<<"Enter Data: ";
// 	cin>>rootData;

//     if(rootData==-1)                       //It is an edge case not a base case...
//     {
//         return NULL;
//     }
    
//     BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData); 
//     BinaryTreeNode<int>*leftChild=takeInputNodeWise();
//     BinaryTreeNode<int>*rightChild=takeInputNodeWise();

//     return root;
// }


BinaryTreeNode<int>* takeInputLevelWise()       //It takes input LevelWise
{
	int rootData;
	cout<<"Enter root Data: ";
	cin>>rootData;
    
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData); 

    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
    	BinaryTreeNode<int>*front=pendingNodes.front();
    	pendingNodes.pop();

    	cout<<"Enter Left Child of "<<front->data<<": ";
        int leftChildData;
        cin>>leftChildData;

        if(leftChildData!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child); 
        }

        cout<<"Enter Right Child of "<<front->data<<": ";
        int rightChildData;
        cin>>rightChildData;

        if(rightChildData!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child); 
        }
    }   
    return root;
}


// void printTreeLevelWise(BinaryTreeNode<int>*root)     //It will print data levelwise...
// {
// 	if(root==NULL)                              //It is an edge case not a base case...
// 	{
// 		return;
// 	}

// 	queue<TreeNode<int>*>pendingNodes;
//     pendingNodes.push(root);

//     while(pendingNodes.size()!=0)
//     {
//     	TreeNode<int>*front=pendingNodes.front();
//     	cout<<front->data<<":";
//     	pendingNodes.pop();

//     	for(int i=0;i<front->children.size();i++)
// 	    {
// 		    cout<<front->children[i]->data<<",";
// 		    pendingNodes.push(front->children[i]);
// 	    }
//         cout<<endl;
//     }   
// }


int numNodes(BinaryTreeNode<int>*root)
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return 0;
	}

	return 1 + numNodes(root->left) + numNodes(root->right);
}


void printAtLevelK(BinaryTreeNode<int>*root,int k)
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
	
    printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
}

int numLeafNodes(BinaryTreeNode<int>*root)
{
	if(root==NULL)
	{
        return 0;
	}
    if(root->left==NULL  && root->right==NULL)
    {
        return 1;
    }

    return numLeafNodes(root->left) + numLeafNodes(root->right);
}


int height(BinaryTreeNode<int>* root) 
{
    if(root==NULL)
    {
        return 0;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    int Height=0;
    if(leftHeight>rightHeight)
    {
        Height=leftHeight;
    }
    else
    {
        Height=rightHeight;
    }

    return Height+1;
}

void preOrder(BinaryTreeNode<int>*root)
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return;
	}

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int>*root)
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return;
	}

	postOrder(root->left);
    postOrder(root->right);
	cout<<root->data<<" ";
}

void InOrder(BinaryTreeNode<int>*root)
{
    if(root==NULL)                              //It is an edge case not a base case...
    {
        return;
    }

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

long long sumOfNodes(BinaryTreeNode<int> *root, int k)
{
    if(root==NULL)                    
    {
        return 0;
    }
    int sum=0;
    if(k==0)
    {
        return root->data;
    }
    return sum + sumOfNodes(root->left,k-1) + sumOfNodes(root->right,k-1);
}


// void deleteTree(BinaryTreeNode<int>* root)
// {
//     deleteTree(root->left);
//     deleteTree(root->right);
//     delete root;
// }

// Tree Input NodeWise: 
// Tree Input LevelWise: 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main()
{

    // BinaryTreeNode<int>* root=takeInputNodeWise();
	
    BinaryTreeNode<int>* root=takeInputLevelWise();
    cout<<endl;

    cout<<endl;
    cout<<"Printing Nodes NodeWise: "<<endl;
    printTreeNodeWise(root);
    cout<<endl;

    // cout<<endl;
    // cout<<"Printing Nodes LevelWise: "<<endl;
	// printTreeLevelWise(root);
	// cout<<endl;

	int count=numNodes(root);
	cout<<"No.of Nodes in this Binary Tree: "<<count<<endl;
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
    cout<<"Height of this Binary tree: "<<Height<<endl;
   
    cout<<endl;
    cout<<"PreOrder Traversal : ";
    preOrder(root);
    cout<<endl;

    cout<<endl;
    cout<<"InOrder Traversal : ";
    InOrder(root);
    cout<<endl;

    cout<<endl;
    cout<<"PostOrder Traversal : ";
    postOrder(root);
    cout<<endl;

    int totalSum=sumOfNodes(root,1);
    cout<<"Total Sum of Nodes at "<<k<<"th level :"<<totalSum;


    delete root;

    // deleteTree(root)

}
