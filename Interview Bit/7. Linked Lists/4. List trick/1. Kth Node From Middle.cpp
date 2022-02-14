// Given a linked list A of length N and an integer B.
// You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.
// If no such element exists, then return -1.
// NOTE:
// Position of middle node is: (N/2)+1, where N is the total number of nodes in the list.


// First Method :-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode* temp=A;
    
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    int mid=(len/2)+1;
    
    if(B>=mid){
        return -1;
    }
    else{
        for(int i=1;i<mid-B;i++){
            A=A->next;
        }
    } 
    return A->val;
}



//Second Method :-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode *fast = A, *slow = A;
    if(A==NULL){
        return -1;
    }

    int count =1;
    while(fast && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }

    //slow is the  middle element
    if(count<=B)
        return -1;
    
    fast = A;
    int k = count-B-1;
    while(k){
        fast = fast->next;
        k--;
    }

    return fast->val;
}



//Third Method :-
int Solution::solve(ListNode* A, int B) {
    ListNode* rem;
    vector<int> p;
    while(A->next!=NULL)
    {   rem=A;
        p.push_back(A->val);
        A=A->next;
        free (rem);
    }
    p.push_back(A->val);
    int n=p.size();
    int m=n/2;
    if(m-B>=0)
        return p[m-B];
    else 
        return -1;
}



//Fourth Method :-

