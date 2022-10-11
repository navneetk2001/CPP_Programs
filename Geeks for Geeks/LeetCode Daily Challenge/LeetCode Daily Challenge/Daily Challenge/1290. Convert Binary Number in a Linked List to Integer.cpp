Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.

Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:
Input: head = [0]
Output: 0
 

//Solution Approach :-
int getDecimalValue(ListNode* head) {
    int num=0;
    ListNode* curr=head;
    while(curr!=NULL)
    {
        num*=2;
        num+=(curr->val);
        curr=curr->next;
    }
    return num;
}


//First Approach :- Reverse the linked list and then multiply it by power of 2
//Second Approach :- Find the length of the linked list and then calculate it by multiplying with 2^len-i;
