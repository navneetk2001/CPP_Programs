Given a linked list, the task is to move all 0s to the front of the linked list. The order of all another element except 0 should be same after rearrangement.

Example 1:
Input:  0 -> 4 -> 0 -> 5 -> 0
Output: 0 -> 0 -> 0 -> 4 -> 5
Explanation: After moving all 0s of the given list to the front, the list is: 0 -> 0 -> 0 -> 4 -> 5

Example 2:
Input: 0 -> 1 -> 0 -> 1 -> 2
Output: 0 -> 0 -> 1 -> 1 -> 2


//Solution Approach :-

/* Linked List Node structure
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    Node* prev=*head;
    Node* curr=(*head)->next;
    while(curr!=NULL){
    	if(curr->data==0){
    		prev->next=curr->next;
    		curr->next=*head;
    		*head=curr;
    		curr=prev->next; 
    	}
    	else{
    		prev=curr;
    		curr=curr->next;
    	}
    }
}



//Second Solution :-
Approach :→ 
Create 2 dummy nodes.
Store all the zeroes nodes in first node pointer.
Store all the non-zeroes nodes in second node pointer.
Link the zeroes last pointer to next of non-zeroes pointer.

// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    Node* curr = *head;  // To iterate in each nodes. 
    
    Node *zeroes = new Node(-1), *non_zeroes = new Node(-1); // Dummy Nodes. 
    Node  *p1 = zeroes, *p2 = non_zeroes; // To iterate and create new link. 
    while (curr != NULL){
        if (curr->data == 0){
            p1->next = curr; // Here linking with zeroes,
            p1 = p1->next;
        }
        else {
            p2->next = curr;    // For the non-zeroes linkage
            p2 = p2->next;
        }
        curr = curr->next;
    }
    p2->next = NULL;    // Here because it might be the case when 1->0-> 2-> 0-> 0
    p1->next = non_zeroes->next; // p1->next demonstrates the last pointer in zeroes and 
                                // then n->next because 1st node is dummy node 
                                // so its count will start from second node. 
    *head = zeroes->next; 
}