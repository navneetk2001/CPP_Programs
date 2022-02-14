// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
//     342 + 465 = 807
// Make sure there are no trailing zeros in the output list
// So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.




// First Method :-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *res=new ListNode(0);
    ListNode *curr=res;
    
    ListNode *p=A;
    ListNode *q=B;
    
    int carry=0;
    
    while(p != NULL || q!= NULL)
    {
        int x=(p!=NULL) ? p->val :0;
        int y=(q!=NULL) ? q->val :0;
        int sum=carry+x+y;
        carry=sum/10;
        curr->next=new ListNode(sum%10);
        curr=curr->next;
        if(p!=NULL) p=p->next;
        if(q!=NULL) q=q->next;
    }
    if(carry>0)
    {
        curr->next=new ListNode(carry);
    }
    return res->next;
}


//Second Method :-
class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            if(!l1)
                return l2;
            if(!l2)
                return l1;

            int carry = (l1->val + l2->val) / 10;
            ListNode *l3 = new ListNode((l1->val + l2->val) % 10);
            ListNode *tail = l3;
            l1 = l1->next;
            l2 = l2->next;

            while(l1 || l2 || carry)
            {
                int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
                ListNode *t  = new ListNode(sum % 10);
                carry = sum / 10;                                          

                if(l1)
                    l1 = l1->next;
                if(l2)
                    l2 = l2->next;
                tail->next = t;
                tail = t;
            }

            return l3;
        }
};






