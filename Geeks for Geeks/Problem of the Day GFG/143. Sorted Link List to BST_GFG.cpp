// Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
// Note: There might be nodes with same value.

// Example 1:
// Input: Linked List: 1->2->3->4->5->6->7
// Output: 4 2 1 3 6 5 7
// Explanation : The BST formed using elements of the linked list is,
//         4
//       /   \
//      2     6
//    /  \   / \
//   1   3  5   7  
// Hence, preorder traversal of this tree is 4 2 1 3 6 5 7

// Example 2:
// Input: Linked List : 1->2->3->4
// Ouput: 3 2 1 4
// Exaplanation: The BST formed using elements of the linked list is,
//       3   
//     /  \  
//    2    4 
//  / 
// 1
// Hence, the preorder traversal of this tree is 3 2 1 4


//First Solution :-
class Solution{
public:
    TNode* sortedListToBST(LNode *head) {
        return makeBST(head,NULL);
    }

    TNode* makeBST(LNode* head, LNode* tail){
        if(head==tail){
        	return NULL;
        }

        LNode *slow=head, *fast=head;
        while(fast!=tail && fast->next!=tail){   //mid find
            slow=slow->next;
            fast=fast->next->next;
        }

        TNode* root=new TNode(slow->data);
        root->left=makeBST(head,slow);
        root->right=makeBST(slow->next,tail);
        return root;
    }
};



//Second Solution :-
TNode* sortedListToBST(LNode *head) {
    if(head == NULL){
   		return NULL;
    }

   	LNode *slow = head, *fast = head;
    LNode *prev_slow = NULL;
    while(fast!= NULL && fast->next!=NULL){
       	prev_slow = slow;
       	slow = slow->next;
       	fast = fast->next->next;
    }
   
   	TNode* mid =  new TNode(slow->data);     //slow points to the middle element
   
    if(prev_slow != NULL){
        prev_slow->next = NULL;                    /*disconnect the last connection to middle so that only elements to the left of middle are used*/
        mid->left = sortedListToBST(head);
    }
    mid->right = sortedListToBST(slow->next);
    return mid;
}



//Third Solution :-
TNode* sortedListToBST(LNode *head) {
    vector<int>v;
    int count =0;
    while(head){   
    	v.push_back(head->data);
        head=head->next;
        count++;
    }
    int start = 0;
    int end = count-1;
    return bst(v,start,end);
} 

TNode* bst(vector<int>&v, int s, int e){   
    if(s>e){
    	return NULL;
    }
    int m = (s+e+1)/2; 
    TNode* temp = new TNode(v[m]);
    temp->left = bst(v,s,m-1);
    temp->right = bst(v,m+1,e);
    return temp;
}