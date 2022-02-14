#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"
using namespace std;


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


void printTreeNodeWise(BinaryTreeNode<int>*root)    //It prints data NodeWise.......
{
    if(root==NULL)                                  //It is an edge case not a base case...
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



/*

//Given a binary tree having N nodes and an integer M you have to return the level of node M.
long long nodeAtLevel(BinaryTreeNode<int> *root, int node,int level)
{
    if (root == NULL)
        return 0;
 
    if (root -> data == node)
    {
        return level;
    }

    int result=nodeAtLevel(root->left,node,level+1) ;
    if(result!=0)
    { 
        return result;
    }

    result=nodeAtLevel(root->right,node,level+1);
    return result;
}


//Given the root of a binary tree, return the sum of all left leaves.
int sumOfLeftLeaves(BinaryTreeNode<int>* root) 
{
    if(root==NULL)
    {
        return 0;
    }

    if (root->left == NULL)
    {
        return sumOfLeftLeaves(root->right);
    }
    else if (root->left->left == NULL && root->left->right == NULL)
    {
        return root->left->data + sumOfLeftLeaves(root->right);
    }         
    else
    {
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
            
}

//Second Approach :Given the root of a binary tree, return the sum of all left leaves.
// int sumOfLeftLeaves(BinaryTreeNode<int>* root) 
// {
//     if(root==NULL)
//     {
//         return 0;
//     }
//     int sum=0;

//     if(root->left!=NULL and root->left->left==NULL and root->left->right==NULL)
//     {
//         sum+=root->left->data;
//         return sum;
//     }

//     int lS=sumOfLeftLeaves(root->left);
//     int rS=sumOfLeftLeaves(root->right);

//     return sum+lS+rS;
// }


*/

// Given a binary tree having N nodes and an integer M, you have to return the postorder successor of M.
//Return -1 if there is no postorder successor of M.
int solve(BinaryTreeNode<int> *root, int node)
{
    //  Write your code here.
}



// Tree Input LevelWise: 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main()
{

    BinaryTreeNode<int>* root=takeInputLevelWise();
    cout<<endl;

    cout<<endl;
    cout<<"Printing Nodes NodeWise: "<<endl;
    printTreeNodeWise(root);
    cout<<endl;

    // int node;
    // cout<<"Enter the node to find the level of that node: ";
    // cin>>node;
    // int Level=nodeAtLevel(root,node,1);
    // cout<<"Node "<<node<<" is present at level :"<<Level;
    // cout<<endl;

    // int sumLeftNodes=sumOfLeftLeaves(root);
    // cout<<"Total sum of all the left Nodes of this tree is :"<<sumLeftNodes<<endl;

    int node;
    cout<<"Enter the node to find the successive postorder of that node: ";
    cin>>node;
    int Level=nodeAtLevel(root,node,1);
    cout<<"Node "<<node<<" is present at level :"<<Level;
    cout<<endl;



    delete root;
}