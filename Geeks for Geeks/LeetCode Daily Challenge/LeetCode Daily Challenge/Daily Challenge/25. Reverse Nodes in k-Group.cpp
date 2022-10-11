https://leetcode.com/problems/reverse-nodes-in-k-group/





//Solution Approach :- Recursive solution
//Recursive solution has O(n) space complexity because of call stacks.

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cursor = head;
    for(int i = 0; i < k; i++){     //checking for a group of k, i.e. it doesn't become NULL before length k
        if(cursor == nullptr){
        	return head;
        }
        cursor = cursor->next;
    }

    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* nxt = nullptr;

    for(int i = 0; i < k; i++){    //code for reverse a k length linked list
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    head->next = reverseKGroup(curr, k);
    return prev;
}





//Second Solution :- Iterative solution
//Iterative solution has O(1) space complexity.

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* before = dummy;
    ListNode* after = head;
    ListNode* curr = nullptr;
    ListNode* prev = nullptr;
    ListNode* nxt = nullptr;

    while(true){
        ListNode* cursor = after;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr){
            	return dummy->next;
            }
            cursor = cursor->next;
        }

        curr = after;
        prev = before;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        after->next = curr;
        before->next = prev;
        before = after;
        after = curr;
    }
}




//Third Solution :-  Iterative
class Solution {
    int getLengthOfLinkedList(ListNode *head)
    {
        ListNode *ptr = head;
        int cnt=0;
        while(ptr)
        {
            cnt++;
            ptr=ptr->next;
        }
        return cnt;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
    
        int len = getLengthOfLinkedList(head);
        if(len<k)
            return head;
        
        int numberOfGroupsToReverse = len/k;
        
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *start = dummyNode;

        ListNode *pre,*remaining,*next;
        for(int i=0;i<numberOfGroupsToReverse;i++)
        {
            pre = NULL;
            remaining = head;
            for(int j=0;j<k;j++)
            {
                next = head->next;
                head->next = pre;
                pre=head;
                head=next;
            }
            start->next = pre;
            remaining->next = head;
            start = remaining;
        }
        
        return dummyNode->next;
    }
};