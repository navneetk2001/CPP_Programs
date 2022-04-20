You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list: 1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []




//Solution Approach :- Min Heap
class mycompare{
	public:
	bool operator()(const ListNode* a,const ListNode* b){
        return (a->val>b->val);
    }
};
	
class Solution {
	public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=new ListNode(0);
        ListNode *temp=head;
        priority_queue<ListNode*,vector<ListNode*>,mycompare> pq;
        for(int i=0;i<lists.size();i++){
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


//Second Approach :-
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};



3rd Approach
Using Divide & Conquer Strategy
Time Complexity = O(N * logK)
Space Complexity = O(max(k.length))

Idea : divide the list, take two pointers one from start, another from last, and merge the lists of both start and end index, and store into the start index and increment start by 1 and decrement end by 1, so in the last will be having the all k lists at 0th index in sorted form.

class Solution {
private:
    // Recursive Approach to merge the sorted lists
    // Time Complexity = O(max(first, second))
    // Space Complexity = O(max(first, second)), bcz of stack trace
    ListNode* mergeTwoLists(ListNode* first, ListNode* second){
        if(!first) return second;
        if(!second) return first;        
        
        if(first->val < second->val){
            first->next = mergeTwoLists(first->next, second);
            return first;
        }
        else{
            second->next = mergeTwoLists(first, second->next);
            return second;
        }
    }
    
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // base case
        if(lists.size() == 0) return NULL;
        
        // start will always start from 0th node, and end will start from last node
        int start = 0, end = lists.size()-1;
        
        while(end > 0){
            
            // intialize start to 0 everytime
            start = 0;
            
            // run the loop till the time, start is less than the end
            while(start < end){
                
                // merge the start index and end index node and store the merged list into the start index
                lists[start] = mergeTwoLists(lists[start], lists[end]);
                
                // increment start by 1
                start++;
                
                // decrement end by 1
                end--;
            }
        }
        
        // at the end will be having the all merged nodes on the 0th index
        return lists[0];
    }
};