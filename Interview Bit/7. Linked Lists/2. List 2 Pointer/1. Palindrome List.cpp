// Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.
// Notes:
// Expected solution is linear in time and constant in space.
// For example,
// List 1-->2-->1 is a palindrome.
// List 1-->2-->3 is not a palindrome.


//Hint :-
// We need to check if first half is equal to last half(when reversed). But you can not store different copy of reversed last half as this solution will not have constant space.
// Can you modify the original list to do the above task?

//Solution Approach :-
// To check palindrome, we just have to reverse latter half of linked list and then we can in (n/2) steps total can compare if all elements are same or not.
// For finding mid point, first we can in O(N) traverse whole list and calculate total number of elements.
// Reversing is again O(N).

// First Method :-
int Solution::lPalin(ListNode* A) {
    ListNode* curr=A;
    vector<int>v;
    while(curr!=NULL)
    {
        v.push_back(curr->val);
        curr=curr->next;
    }
    int n=v.size();
    for(int i=0;i<n/2;i++)
    {
        if(v[i]!=v[n-1-i]){
            return 0;
        }
        else{
            continue;
        }
    }
    return 1;
}


//Second Method :-
ListNode *llreverser(ListNode *head){
    ListNode *pre, *curr, *nex;
    pre = nex = NULL;
    curr = head;
    while (curr)
    {
        nex = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nex;
    }
    return pre;
}

ListNode *midFinder(ListNode *f)
{
    ListNode *fast, *slow;
    fast = slow = f;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int ans(ListNode *h1, ListNode *h2){
    int re=1;
    while(h1 && h2){
        if(h1->val !=h2->val){
            re=0;
            break;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return re;
}

int Solution::lPalin(ListNode* a) {
    ListNode *mid = midFinder(a);
    ListNode *hmid = llreverser(mid);
    int s = ans(a, hmid);
    return s;
}




//Third Method :-
int Solution::lPalin(ListNode* A) {
    stack<int>values;
    ListNode* temp=A;

    while(temp!=NULL)
    {
        values.push(temp->val);
        temp=temp->next;
    }
    temp=A;
    while(temp!=NULL)
    {
        if (temp->val != values.top()){
            return 0;
        }
        else{
            values.pop();
            temp=temp->next;
        }
    }
    return 1;
}


//Fourth Method :-
void check(ListNode** l, ListNode* r, int& ans){
    if(r == NULL)return;
    check(l, r->next, ans); // go to right
    if((*l)->val != r->val){ // not a plaindrome
        ans = 0;
    }
    (*l) = (*l)->next; // change left pointer during folding up of recursion
} 

int Solution::lPalin(ListNode* A) {
    if(A == NULL || A->next == NULL)return true; // trivial case
    ListNode* l = A; // pointer left
    ListNode* r = A->next; // pointer right
    int ans = 1; // result
    check(&l, r, ans);
    return ans;
}
