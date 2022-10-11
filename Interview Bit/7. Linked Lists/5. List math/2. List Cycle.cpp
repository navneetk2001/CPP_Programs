// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// Try solving it using constant additional space.

//Hint 1
//Lets first look at detection of a cycle in the list.

// Following are different ways of doing this

// 1) Use Hashing:
// What if you could maintain a list of nodes already visited. As soon as you visit a node already visited, you know that there is a cycle.

// 2) 2 pointer approach ( Floyd’s Cycle-Finding Algorithm ) :
// What if you have 2 pointers which are going at different speed. For arguments sake, lets just say one pointer is going at double the speed of the other.
// Would they meet if there is a cycle ? Are they guaranteed to meet if there is a cycle ?
// What happens if there is no cycle ?

// Once you detect a cycle, think about finding the starting point.


//Solution Approach
// Lets now look at the starting point.
// If we were using hashing, the first repetition we get is the starting point. Simple!

// What happens with the 2 pointer approach ?

// Method 1 :
// If you detect a cycle, the meeting point is definitely a point within the cycle.

// Can you determine the size of the cycle ? ( Easy ) Let the size be k.
// Fix one pointer on the head, and another pointer to kth node from head.
// Now move them simulataneously one step at a time. They will meet at the starting point of the cycle.
// Method 2 :
// This might be slightly more complicated. It involves a bit of maths and is not as intuitive as method 1.
// Suppose the first meet at step k,the distance between the start node of list and the start node of cycle is s, and the distance between the start node of cycle and the first meeting node is m.
// Then
// 2k = (s + m + n1r)
// 2(s + m + n2r) = (s + m + n1r)
// s + m = nr where n is an integer.
// s = nr - m
// s = (r - m) + (n-1)r

// So, if we have one pointer on the head and another pointer at the meeting point. Note that since the distance between start node of cycle and the first meeting node is m, therefore if the pointer moves (r - m) steps, it will reach the start of the cycle. When the pointer at the head moves s steps, the second pointer moves (r-m) + (n-1)r steps which both points to the start of the cycle. In other words, both pointers meet first at the start of the cycle.



// First Method :-
ListNode* Solution::detectCycle(ListNode* A) {
    while(A)
    {
        if(A->val<0)
        {
            A->val=-1*A->val;
            return A;
        }
        else if(A->val>0)
        {
            A->val=-1*(A->val);
        }
        A=A->next;
    }
    return NULL;
}



//Second Method :-
public ListNode detectCycle(ListNode a) {
    ListNode slow = a; // slow pointer
    ListNode fast = a; // fast pointer
    while(fast != null && fast.next != null) { // check for cycle
        slow = slow.next;
        fast = fast.next.next;
        if(slow == fast) { // cycle present
            slow = a;
            while(slow != fast) { // find the required node
                slow = slow.next;
                fast = fast.next;
            }
            return slow; // return node
        }
    }
    return null; // no cycle, return null
}

// Space Complexity = O(1) constant space using only 2 pointers --> slow and fast
// Time Complexity = O(n+p) where n for outer while loop and p for inner while loop i.e 
// worst case time complexity is O(n + n) = O(2n) == O(n) --> linear time complexity.



//Third Method :-
ListNode* Solution::detectCycle(ListNode* A) {
    //Node Address at which it 
    map<ListNode*, int> mp;
    while(A!=NULL){
        if(mp[A] != 0){
            return A;
        }
        
         mp[A] = 1;
         A= A->next;
    }
    return NULL;
}


//Fourth Method :-
public ListNode detectCycle(ListNode A) {

 ListNode p = A, q = A;
 
 // first we initialize two pointer p & q and increment one by two node 
 // and another node by one node
 // break at the point when both p & q become equals
 while(true) {
     
     if(q.next == null || q.next.next == null) return null;
     
     q = q.next.next;
     p = p.next;
     
     if(p == q) break;
 }
 
 // then initialize one of the pointer to head
 q = A;
 
 while(true) {
     
     // fist check if both pointer p & q is equals or not
     // to avoid the case where cycle occur at head
     if(p == q) return p;
     
     // now increment both pointer by only one node
     q = q.next;
     p = p.next;
 }


 //Fifth Method :
ListNode* Solution::detectCycle(ListNode* A) {
    set<ListNode*> s;
    while(A){
        if(s.find(A)!=s.end()){
            return A;
        }
        s.insert(A);
        A = A->next;
    }
    return NULL;
}`