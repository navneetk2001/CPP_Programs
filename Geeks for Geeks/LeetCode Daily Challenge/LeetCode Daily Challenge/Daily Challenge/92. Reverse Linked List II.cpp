// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [5], left = 1, right = 1
// Output: [5]
 



//Solution Approach :-
//First locate the node before the m-th node (pre) and the m-th node (cur). Then movecur -> next to be after pre for n - m times.
class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       	ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       	dummy -> next = head;

       	for(int i = 0; i < m - 1; i++) {
           	pre = pre -> next;
       	}

       	cur = pre -> next;

       	for(int i = 0; i < n - m; i++) {
           	ListNode* temp = pre -> next;
           	pre -> next = cur -> next;
           	cur -> next = cur -> next -> next;
           	pre -> next -> next = temp;
       	}
       	return dummy -> next;
   }
};



//Solution :- 
class Solution{
public:
    struct Node* reverse(struct Node* head){   //function to reverse a linked list
    	struct Node* prev = NULL;
    	struct Node* curr = head;
    
    	while(curr){
    	    struct Node* next = curr->next;
    	    curr->next=prev;
    	    prev=curr;
    	    curr=next;
    	}
    	return prev;
    }

    Node* reverseBetween(Node* head, int m, int n){
        if(m==n){         //Base Case
        	return head;
        }
        
        //we will take 4 variables :- rev, rev_prev, rev_end, rev_end_next so that we can 
        //take out the sublist which we have to reverse and then again join them a/c to question
        Node* rev = NULL, *rev_prev=NULL;
        Node* revEnd = NULL, *revEnd_next=NULL;
        
        int i=1;
        Node* curr = head;
        while(curr && i<=n){
        	if(i<m){               //keep track of revs_prev so that we can later join this after reversing sublist
        		rev_prev=curr;
        	}
        	if(i==m){
        		rev=curr;       //keep track of revs pointer which is the starting node/head of the sublist to be reversed
        	}
        	if(i==n){
        		revEnd=curr;   //keep track of end of sublist
        		revEnd_next=curr->next;    //keep track of end->next so that we can finally join the sublist with remaining list
        	}
        	curr=curr->next;
        	i++;
        }
        
        revEnd->next=NULL;    //taking sublist out of whole list
        revEnd=reverse(rev);  //reversing the sublist
        
        if(rev_prev){         //if starting position was not head
        	rev_prev->next=revEnd;
        }
        else{                 //if starting position was head
        	head=revEnd;
        }
        
        rev->next=revEnd_next;    //finally connecting last of the sublist
        return head;
    }
};




//Second Solution :-
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *next = NULL, *current = head;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* current = head, *prev = NULL;
        int count = 1;
        while(count != left){
            prev = current;
            current = current->next;
            count++;
        }
        
        ListNode* start = current;
        while(count != right){
            current = current->next;
            count++;
        }
        
        ListNode* rest = current->next;
        current->next = NULL;
        
        ListNode* newHead = reverse(start);
        if (prev!=NULL){
            prev->next = newHead;

        }
        current = newHead;
        while(current->next!=NULL){
            current= current->next;
        }
        current->next = rest;
        if(left == 1){
            return newHead;
        }
        else{
            return head;
        }
    }
};




//Third Solution :- Brute Force
class Solution{
public:
   Node* reverseBetween(Node* head, int m, int n){
       vector<int>v;
       Node* a=head;
       while(a)
       {
           v.push_back(a->data);
           a=a->next;
       }
       Node* b=new Node(-1);
       a=b;
       int i;
       for(i=0;i<m-1;i++)
       {
           b->next=new Node(v[i]);
           b=b->next;
       }
       for(i=n-1;i>=m-1;i--)
       {
           b->next=new Node(v[i]);
           b=b->next;
       }
       for(i=n;i<v.size();i++)
       {
           b->next=new Node(v[i]);
           b=b->next;
       }
       return a->next;
   }
};