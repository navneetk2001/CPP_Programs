// Given a linked list, swap every two adjacent nodes and return its head.
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed


//Solution Approach :-
// Lets first look at the problem of swapping 2 nodes.

// Method 1: Just swap the values in the 2 nodes. In most cases, this won’t be a permissible solution.
// Method 2: Move around the pointers.


// First Method :-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if( A ==NULL) return NULL;
    struct ListNode *curr = A->next;
    struct ListNode *prev= A;

    if( curr ==NULL ) return A;

    while( curr->next && curr->next->next){
        swap( curr->val, prev->val);
        struct ListNode *temp= curr->next ;
        prev= temp;
        curr= prev->next;
    }
    if( curr && prev ) 
        swap(curr->val, prev->val );

    return A;
}



//Second Method :-
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* start = new ListNode(0); //make head no longer a special case
        start->next = head;

        ListNode *cur = start;
        while (cur->next != NULL && cur->next->next != NULL) {
            cur->next = swap(cur->next, cur->next->next);
            cur = cur->next->next;
        }
        return start->next;
    }
    ListNode* swap(ListNode* next1, ListNode* next2) {
        next1->next = next2->next;
        next2->next = next1;
        return next2;
    }
};


//Third Method :-
class Solution{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if(!head or !head->next){
            return head;
        }
        
        Node *dummy = new Node(-1);
        Node *prevNode = dummy;
        Node *currNode = head;
        
        while(currNode!=NULL && currNode->next!=NULL)
        {
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;
            
            prevNode = currNode;
            currNode = currNode->next;
        }
        
        return dummy->next;
    }
};





