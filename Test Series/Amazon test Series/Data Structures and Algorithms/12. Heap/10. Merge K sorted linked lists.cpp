// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

// Example 1:
// Input: K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation: The test case has 4 sorted linked list of size 3, 2, 2, 2
// 1st    list     1 -> 2-> 3
// 2nd   list      4->5
// 3rd    list      5->6
// 4th    list      7->8
// The merged list will be 1->2->3->4->5->5->6->7->8.

// Example 2:
// Input: K = 3
// value = {{1,3},{4,5,6},{8}}
// Output: 1 3 4 5 6 8
// Explanation: The test case has 3 sorted linked list of size 2, 3, 1.
// 1st list 1 -> 3
// 2nd list 4 -> 5 -> 6
// 3rd list 8
// The merged list will be 1->3->4->5->6->8.




//Solution Approach :-
class mycompare{
	public:
	bool operator()(const Node* a,const Node* b){
        return (a->data>b->data);
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *lists[], int K)
    {
        Node *head = new Node(0);
        Node *temp=head;
        priority_queue<Node*,vector<Node*>,mycompare> pq;
        for(int i=0;i<K;i++){
            if(lists[i]!=NULL)
             pq.push(lists[i]);
        }

        while(!pq.empty()){
            auto least=pq.top();
            pq.pop();

            temp->next=least;
            temp=temp->next;
            
            if(least->next){
            	pq.push(least->next);
            }
        }   
        return head->next;
    }
};



//Second Solution :-
Node* merge(Node* a,Node*b){
    Node* res = NULL;
    if(!a){
        return b;
    }
    else if(!b)
        return a;
    
    if(a->data <= b->data){
        res = a;
        res->next = merge(a->next,b);
    }
    else{
        res = b;
        res->next = merge(a,b->next);
    }
    return res;
}
Node * mergeKLists(Node *arr[], int K)
{
    for(int i=1;i<K;i++){
        arr[0] = merge(arr[0],arr[i]);
    }
    return arr[0];
}



