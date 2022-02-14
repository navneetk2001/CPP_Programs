#include<iostream>
#include<climits>
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


void printTreeLevelWise(BinaryTreeNode<int>*root)     //It will print data levelwise...
{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return;
	}

	queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
    	BinaryTreeNode<int>*front=pendingNodes.front();
    	cout<<front->data<<":";
    	pendingNodes.pop();

        if (front->left != NULL)
        {
            cout<<"L"<<front->left->data<<" ";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout<<"R"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }   
}


// bool Search(BinaryTreeNode<int>*root,int node)
// {
// 	if(root==NULL)                              //It is an edge case not a base case...
// 	{
// 		return false;
// 	}
// 	bool output;
// 	if(root->data==node)
// 	{
// 		return true;
// 	}
// 	else if(root->data > node)
// 	{
// 	    output=Search(root->left,node);
// 	}
// 	else
// 	{
// 	    output=Search(root->right,node);	
// 	}
// 	return output;
// }


// void elements_in_range(BinaryTreeNode<int>*root,int sI, int eI)
// {
// 	if(root==NULL)
// 	{                            
// 		return;
// 	}

//     if(root->data > sI)
//     {
//     	elements_in_range(root->left, sI,eI);
//     }
//     if(root->data >= sI && root->data <= eI)
//     {
//         cout<<root->data<<" ";
//     }
//     if(root->data < eI)
//     {
//         elements_in_range(root->right,sI,eI);
//     }
// }


// int minimum(BinaryTreeNode<int>*root)
// {
// 	if (root==NULL)
// 	{
// 		return INT_MAX;
// 	}
// 	return min(root->data, min( minimum(root->left), minimum(root->right)));
// }


// int maximum(BinaryTreeNode<int>*root)
// {
// 	if (root==NULL)
// 	{
// 		return INT_MIN;
// 	}
// 	return max(root->data, max( maximum(root->left), maximum(root->right)));
// }


// bool isBST_1(BinaryTreeNode<int>*root)
// {
// 	if (root==NULL)
// 	{
// 		return true;
// 	}
// 	int leftMax= maximum(root->left);
// 	int rightMin= minimum(root->right);

// 	bool output= (root->data > leftMax) && (root->data < rightMin) && isBST_1(root->left) && isBST_1(root->right);

// 	return output;
// }



// class isBST_return
// {
// public:
// 	bool isBST;
// 	int minimum;
// 	int maximum;
// };

// isBST_return isBST_2(BinaryTreeNode<int>*root)
// {
//     if (root==NULL)
// 	{
// 		isBST_return output;
// 		output.isBST=true;
// 		output.minimum=INT_MAX;
// 		output.maximum=INT_MIN;
// 		return output;
// 	}	

// 	isBST_return leftOutput=isBST_2(root->left);
// 	isBST_return rightOutput=isBST_2(root->right);
//     int minimum=min(root->data, min( leftOutput.minimum, rightOutput.minimum));
//     int maximum=max(root->data, max( leftOutput.maximum, rightOutput.maximum));
    
//     bool isBST_final= (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);

//     isBST_return output;
//     output.minimum= minimum;
//     output.maximum= maximum;
//     output.isBST= isBST_final;
//     return output;
// }



// bool isBST_3(BinaryTreeNode<int>*root, int min= INT_MIN, int max= INT_MAX)
// {
// 	if(root==NULL)
// 	{
// 		return true;
// 	}
// 	if(root->data < min || root->data >max)
// 	{
// 		return false;
// 	}
// 	bool isLeftOk= isBST_3(root->left, min, root->data-1);
// 	bool isRightOk= isBST_3(root->right, root->data, max);

// 	return isLeftOk && isRightOk;
// }


BinaryTreeNode<int>* construct_BST_from_Sorted_Array(int arr[], int sI, int eI)
{
	if(sI > eI)
	{
		return NULL;
	}
	int mid=(sI+eI)/2;
	int data=arr[mid];

	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(data);

	root->left=construct_BST_from_Sorted_Array(arr,sI,mid-1);
	root->right=construct_BST_from_Sorted_Array(arr,mid+1,eI);

	return root;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1




int main()
{
    // #ifndef ONLINE_JUDGE

    // freopen("inputf.in", "r", stdin);

    // freopen("outputf.in", "w", stdout);

    // #endif // ONLINE_JUDGE

	// BinaryTreeNode<int>* root=takeInputLevelWise();
 //    cout<<endl;

 //    cout<<endl;
 //    cout<<"Printing Nodes LevelWise: "<<endl;
	// printTreeLevelWise(root);
	// cout<<endl;

 //    int node;
 //    cin>>node;
 //    bool output=Search(root,node);
 //    cout<<output<<endl;

 //    int sI, eI;
 //    cin>>sI>>eI;
 //    elements_in_range(root,sI,eI);
 //    cout<<endl;
 
 //    bool output_1=isBST_1(root);
 //    cout<<output_1<<endl;

 //    isBST_return output_2=isBST_2(root);
 //    cout<<output_2.isBST<<endl;

    // bool output_3=isBST_3(root);
    // cout<<output_3<<endl;

    int arr[]={1,2,3,4,5,6,7};
    BinaryTreeNode<int>* root=construct_BST_from_Sorted_Array(arr,0,6);
    cout<<endl;

    cout<<endl;
    cout<<"Printing Nodes LevelWise: "<<endl;
	printTreeLevelWise(root);
	cout<<endl;

	delete root;
}
