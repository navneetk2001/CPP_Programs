// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.

// Example 1:
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:
// Input: head = [2,1], x = 2
// Output: [1,2]




//Solution Approach :-
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode(0);
        ListNode* list2 = new ListNode(0);

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(head){
        	if(head->val < x){    // if value is less than x, then attach it in list1
        		l1->next = head;
        		l1 = l1->next;
        	}
        	else{                   //else attach it in list2
        		l2->next = head;
        		l2 = l2->next;
        	}
        	head = head->next;
        }
        l1->next = list2->next;
        l2->next = NULL; 

        return list1->next;
    }
};


