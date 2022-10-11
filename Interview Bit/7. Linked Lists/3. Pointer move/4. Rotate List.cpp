// Given a list, rotate the list to the right by k places, where k is non-negative.
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.


//Hint 1
// Note 1: n may be a number larger than the size of the list.
// Note 2: Try to figure out the steps for the rotation if you know the new start node, the actual end node and the node previous to the new start node.

//Solution Approach
// Since n may be a large number compared to the length of list. So we need to know the length of linked list. After that, move the list after the (l-n % l )th node to the front to finish the rotation.
// Ex: {1,2,3} k = 2 Move the list after the 1st node to the front
// Ex: {1,2,3} k = 5, In this case Move the list after (3-5 % 3=1)st node to the front.
// So the code has three parts.
// 1) Get the length
// 2 Move to the (l-n%l)th node
// 3 Do the rotation


// First Method :-
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A == NULL){
        return A;
    }
    
    int len = 1;
    ListNode* temp=A;
    while(temp->next!=NULL){    //reach to last element so that first of all we connect last->next to head.
        len++;
        temp=temp->next;
    }

    temp->next = A;   //connect last element with head of linked list
    if(B > len){
        B=B%len;
    }

    //Now we have to break the connection from len-k and make it null
    for(int i = 0; i < len-B; i++){
        temp= temp->next;
    }
        
    ListNode *ans = temp->next;
    temp->next = NULL;
    return ans;
}


//Second Method :-
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy, *slow = dummy;

        int sizeOfList = 0; 
        while (fast->next != NULL) {
            fast = fast->next;
            sizeOfList++;
        }

        int firstNodePos = sizeOfList - (k % sizeOfList);
        for (int i = 0; i < firstNodePos; i++) {
            slow = slow->next;
        }

        fast->next = dummy->next;
        dummy->next = slow->next; 
        slow->next = NULL;

        return dummy->next;
    }
};


//Third Method :-
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n = 0;
    ListNode* head = A;

    while(head!=NULL)
    {
        n++;
        head = (*head).next;
    }
    B = B%n;
    if(B==n || B==0)
        return A;
        
    ListNode* l2 = A;
    ListNode* l1 = A;
    for(int i=0;i<(n-B);i++)
    {
        l2 = (*l2).next;
    }
    
    for(int i = 0;i<(n-B-1);i++)
    {
        l1 = (*l1).next;
    }
    (*l1).next = NULL;
    ListNode* h = l2;
    for(int i = 0;i<(B-1);i++)
    {
        h = (*h).next;
    }
    (*h).next = A;
    return l2;
}







//Fourth Method :-
//Given a linked list of length N and an integer K , append the last K elements of a linked list to the front. Note that K can be greater than N.
node *appendK(node *head, int k)
{
    node *oldHead = head;
    node *fast = head;
    node *slow = head;

    for (int i = 0; i < k && fast->next != NULL; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}