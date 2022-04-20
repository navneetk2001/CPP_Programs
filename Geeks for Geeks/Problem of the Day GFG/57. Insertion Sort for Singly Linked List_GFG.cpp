// Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

// Example 1:

// Input:
// N = 10
// Linked List = 30->23->28->30->11->14->
//               19->16->21->25 
// Output : 11 14 16 19 21 23 25 28 30 30 
// Explanation :
// The resultant linked list is sorted.
// Example 2:

// Input : 
// N = 7
// Linked List=19->20->16->24->12->29->30 
// Output : 12 16 19 20 24 29 30 
// Explanation : 
// The resultant linked list is sorted.

// Expected Time Complexity : O(n2)
// Expected Auxiliary Space : O(1)



//Solution Approach :-
//Find insertion point for incoming element
//Insert into that point

class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        struct Node* dummy = new Node(10000);

    	while(head){
    		struct Node* next=head->next;
    		struct Node* temp=dummy;
    
    		while(temp->next && temp->next->data<head->data){
    			temp=temp->next;
    		}
    		head->next=temp->next;
    		temp->next=head;
    		head=next;
    	}
    	return dummy->next;
    }
    
};


//Second Method :-
class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
         Node *ans=new Node(0);
         Node *h=head;
         while(h!=NULL)
         {
            Node *curr=ans;Node *prev=NULL;
            while(curr!=NULL&&(curr->data)<(h->data))
            {
                prev=curr;
                curr=curr->next;
            }
            Node *hnext=h->next;
            Node *temp=curr;prev->next=h;h->next=temp;
            h=hnext;
         }
         return ans->next;
    }
    
};


//Third Solution :- Using deque
Node* insertionSort(struct Node* head_ref)
    {
        Node* temp=head_ref;
        deque<int> q;
        q.push_back(temp->data);
        temp=temp->next;
        while(temp!=NULL){
            stack<int> s;
            if(q.back()>temp->data){
                while(!q.empty() && q.back()>temp->data){
                    s.push(q.back());
                    q.pop_back();
                }
                q.push_back(temp->data);
                while(!s.empty()){
                    q.push_back(s.top());
                    s.pop();
                }
            }
            else if(q.back()<=temp->data){
                q.push_back(temp->data);
            }
            temp=temp->next;
        }
        Node* dummy=new Node(-1);
        Node* ans=dummy;
        while(!q.empty()){
            ans->next=new Node(q.front());
            ans=ans->next;
            q.pop_front();
        }
        return dummy->next;
    }

