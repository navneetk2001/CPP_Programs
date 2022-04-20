// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [1]
// Output: [1]



//Solution Approach :- 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0);
        ListNode* prev=temp;
        ListNode* curr=head;
        temp->next= head;

        while(curr!=NULL and curr->next!=NULL){
        	prev->next = curr->next;
        	curr->next = curr->next->next;
        	prev->next->next = curr;
        	curr = curr->next;
        	prev = prev->next->next;
        }
        return temp->next;
    }
};


//Another Approach :- 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        
        while(temp!=NULL && temp->next!=NULL)
        {
            swap(temp->val,temp->next->val);
            temp=temp->next->next;
        }
        return head;
    }
};


