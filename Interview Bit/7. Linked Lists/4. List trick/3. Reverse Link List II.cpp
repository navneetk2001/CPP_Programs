Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.

//Hint :-
Lets first look at the problem of reversing the linked list.
a -> b -> c should become
a <- b <- c
Obviously at every instant, you need to know about the previous of the node, so that you can link it to the next of the node.
Can you think along the lines of maintaining a previousNode, curNode and nextNode ?
Now once you know how to reverse a linked List, how can you apply it to the current problem ?


//Solution Approach :-
If you are still stuck at reversing the full linked list problem,
then would maintaining curNode, nextNode and a tmpNode help ?

Maybe at every step, you do something like this :

    tmp = nextNode->next;
            nextNode->next = cur;
            cur = nextNode;
            nextNode = tmp;
Now, lets say you did solve the problem of reversing the linked list and are stuck at applying it to current problem.
What if your function reverses the linked list and returns the endNode of the list.
You can simply do
prevNodeOfFirstNode->next = everseLinkedList(curNode, n - m + 1);


// First Method :-
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* dummy=new ListNode(0);
    dummy->next=A;

    ListNode* prev= dummy;
    while(B>1){
        prev=prev->next;
        B--;
        C--;
    }

    ListNode* curr=prev->next;
    ListNode* tail=prev->next;
    ListNode* p=NULL;

    while(C>0){
        auto temp=curr->next;
        curr->next=p;
        p=curr;
        curr=temp;
        C--;
    }

    tail->next=curr;
    prev->next=p;
    return dummy->next;
}

//Second Method :-
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B != 1){ // if B is not the first element 
        A->next = reverseBetween(A->next, B-1, C-1);// pass the next element decreasing B and C
        return A;
    }
    else{ // if B is the first element
        ListNode *prev=NULL, *curr=A, *next=NULL;
        int count=0;
        while(count<C){ // reverse the list till C 
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        A->next = curr;// Append the first list element to the C+1 element
        return prev;// return the new start
    }
}

//Third Method :-
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    int i=1;
    
    ListNode *start, *end, *prev, *next;
    
    ListNode *temp=new ListNode(0);
    
    temp->next=A;
    
    ListNode *curr=temp;
    
    while(i != (B)){
        curr=curr->next;
        i++;
    }
    
    
    start=curr;
    end=curr->next;
    curr=curr->next;
    prev=NULL;
    
    while(i != (C+1)){
        next=curr->next;
        curr->next=prev;
        
        prev=curr;
        curr=next;
        
        i++;
    }
    
    start->next=prev;
    end->next=curr;
    
    return temp->next;
    
}




