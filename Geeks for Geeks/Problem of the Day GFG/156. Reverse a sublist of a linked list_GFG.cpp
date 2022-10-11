// Given a linked list and positions m and n. Reverse the linked list from position m to n.

// Example 1:
// Input :
// N = 10
// Linked List = 1->7->5->3->9->8->10->2->2->5->NULL
// m = 1, n = 8
// Output : 2 10 8 9 3 5 7 1 2 5 
// Explanation :The nodes from position 1 to 8 are reversed, resulting in 2 10 8 9 3 5 7 1 2 5.

// Example 2:
// Input:
// N = 6
// Linked List = 1->2->3->4->5->6->NULL
// m = 2, n = 4
// Output: 1 4 3 2 5 6
// Explanation: Nodes from position 2 to 4 are reversed resulting in 1 4 3 2 5 6.



//Solution Approach :- Part by Part
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
        Node* curr=head;
        while(curr&&i<=n){
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
        
        revEnd->next=NULL;   //taking sublist out of whole list
        revEnd=reverse(rev);  //reversing the sublist
        
        if(rev_prev){    //if starting position was not head
        	rev_prev->next=revEnd;
        }
        else{        //if starting position was head
        	head=revEnd;
        }
        
        rev->next=revEnd_next;    //finally connecting last of the sublist
        return head;
    }
};




//Second Solution :-
class Solution{
public:  
    Node* reverseBetween(Node* head, int l, int r){
       	Node* dummy = new Node(0);
       	Node* prev = dummy;  prev->next = head;
        for(int i=1;i<l;i++){
            prev = prev->next;
        }
        Node* tail = prev->next;

        for(int i=1;i<=r-l;i++){
            Node* temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
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
