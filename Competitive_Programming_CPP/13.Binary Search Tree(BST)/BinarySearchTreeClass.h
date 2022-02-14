class BST
{
	BinaryTreeNode<int>* root;

public:
	BST()
	{
		root=NULL;
	}

	~BST()
	{
		delete root;
	}

private:
	bool hasData(int data, BinaryTreeNode<int>* node)
	{
	if(root==NULL)                              //It is an edge case not a base case...
	{
		return false;
	}
	if(node->data==data)
	{
		return true;
	}
	else if(data < node->data)
	{
	    return hasData(data,node->left);
	}
	else
	{
	    return hasData(data,node->right);	
	}
	}

public:
	bool hasData(int data)
	{
		return hasData(data,root);
	}



private:
	BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>*node)
	{
		if(node==NULL)
		{
			BinaryTreeNode<int>* newNode=new BinaryTreeNode<int>(data);
			return newNode;
		}
		if(data<node->data)
		{
			node->left=insert(data,node->left);
		}
		else
		{
			node->right=insert(data,node->right);
		}
		return node;
	}

public:
	void insert(int data)
	{
		this->root=insert(data,this->root);
	}



private:
	BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node)
	{
		if(node==NULL)
		{
			return NULL;
		}
		if(data > node->data)
		{
			node->right=deleteData(data,node->right);
			return node;
		}
		else if (data < node->data)
		{
			node->left=deleteData(data,node->left);
			return node;
		}
		else
		{
			if(node->left==NULL && node->right== NULL)
			{
				delete node;
				return NULL;
			}
			else if(node->left==NULL)
			{
				BinaryTreeNode<int>* temp=node->right;
				node->right=NULL;
				delete node;
				return temp;
			}
			else if(node->right==NULL)
			{
				BinaryTreeNode<int>* temp=node->left;
				node->left=NULL;
				delete node;
				return temp;
			}
			else
			{
				BinaryTreeNode<int>* minNode= node->right;
				while(minNode->left != NULL)
				{
					minNode=minNode->left;
				}
				int rightMin=minNode->data;
				node->data=rightMin;
				node->right=deleteData(rightMin,node->right);
				return node;
			}
		}
	}

public:
	void deleteData(int data)
	{
		root=deleteData(data,root);
	}


private:
	void printTree(BinaryTreeNode<int>*root)     //It will print data levelwise...
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

public:
	void printTree()
	{
		printTree(root);
	}
};