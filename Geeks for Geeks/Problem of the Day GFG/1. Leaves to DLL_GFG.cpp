// Given a Binary Tree of size N, extract all its leaf nodes to form a 
// Doubly Link List starting from the left most leaf. Modify the original 
// tree to make the DLL thus removing the leaf nodes from the tree. 
// Consider the left and right pointers of the tree to be the previous 
// and next pointer of the DLL respectively.



Example 1:

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7

Explanation:
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.


//Function starts :-
Node* tail;
Node* head;

Node* preorder(Node* root){
	if(root==NULL){
		return root;
	}

	if(root->left==NULL && root->right==NULL){  //root is the left node
		if(tail==NULL){     //if no element present in Doubly Linked List
			head=root;
			tail=root;
		}
		else{                 //If DLL exist then connect other elements
			tail->right=root;
			root->left=tail;
			tail=root;
		}
		return NULL;     //update the tree by making leaves node as NULL
	}
	root->left=preorder(root->left);
	root->right=preorder(root->right);
	return root;
}


Node* convertToDLL(Node* root){
	tail=NULL;
	head=NULL;
	preorder(root);
	return head;
}
//Function ends :-






//Whole Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
Node* tail;
Node* head;

Node* preorder(Node* root){
	if(root==NULL){
		return root;
	}

	if(root->left==NULL && root->right==NULL){  //root is the left node
		if(tail==NULL){     //if no element present in Doubly Linked List
			head=root;
			tail=root;
		}
		else{                 //If DLL exist then connect other elements
			tail->right=root;
			root->left=tail;
			tail=root;
		}
		return NULL;     //update the tree by making leaves node as NULL
	}
	root->left=preorder(root->left);
	root->right=preorder(root->right);
	return root;
}

// return the head of the DLL and remove those node from the tree as well.
Node* convertToDLL(Node* root){
	tail=NULL;
	head=NULL;
	preorder(root);
	return head;
}


// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Node* head = convertToDLL(root);
        inOrder(root);
        cout << "\n";
        Node *curr = head, *last = head;
        while (curr) {
            cout << curr->data << " ";
            last = curr;
            curr = curr->right;
        }
        cout << "\n";
        curr = last;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->left;
        }
        cout << "\n";
    }
    return 0;
}

  // } Driver Code Ends