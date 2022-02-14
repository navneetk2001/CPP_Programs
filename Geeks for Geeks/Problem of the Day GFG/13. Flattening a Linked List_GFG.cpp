Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->20->22->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)






Node *flatten(Node* root){
	if(root==NULL || root->next==NULL){
		return root;
	}
	root->next=flatten(root->next);
	root=merge(root, root->next);
	return root;
}

Node *merge(Node *a, Node *b){
	Node* curr=new Node(-1);
	Node* res=curr;

	while(a!=NULL && b!=NULL){
		if(a->data<=b->data){
			curr->bottom=a;
			curr=curr->bottom;
			a=a->bottom;
		}
		else{
			curr->bottom=b;
			curr=curr->bottom;
			b=b->bottom;
		}
	}

	if(a==NULL){
		curr->bottom=b;
	}
	else{
		curr->bottom=a;
	}

	return res->bottom;
}




//Another Soln :-

// An utility function to merge two sorted
// linked lists
Node* merge(Node* a, Node* b)
{
    
    // If first linked list is empty then second
    // is the answer
    if (a == NULL)
        return b;

    // If second linked list is empty then first
    // is the result
    if (b == NULL)
        return a;

    // Compare the data members of the two linked 
    // lists and put the larger one in the result
    Node* result;

    if (a->data < b->data) 
    {
        result = a;
        result->down = merge(a->down, b);
    }

    else 
    {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}

Node* flatten(Node* root)
{
    
    // Base Cases
    if (root == NULL || root->right == NULL)
        return root;

    // Recur for list on right
    root->right = flatten(root->right);

    // Now merge
    root = merge(root, root->right);

    // Return the root
    // it will be in turn merged with its left
    return root;
}