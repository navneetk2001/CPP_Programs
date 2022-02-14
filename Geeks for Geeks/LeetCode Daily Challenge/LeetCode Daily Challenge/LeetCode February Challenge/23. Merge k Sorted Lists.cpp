// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []


//First Approach :- K Sorted Linked List :- Merge all k linked list in one and apply merge sort
//It will take O(nlogn)



//Second Approach :- It will be very much similar with merge 2 sorted list
//First, We will merge 2 lists and push it in one list and then again repeat the process

//Solution :- Time Complexity :- O(n*K)
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


//Third Approach :- Using Priority Queue :- Time Complexity :- O(n*log(k))
// We will make min heap :- we will push one element into priority queue at each time
class comp
{
public:
    bool operator() (const ListNode* l, const ListNode* r)
    {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    	for(auto l : lists){
            if(l){
                pq.push(l);
            }
        }

        if(pq.empty()) return NULL;
        
        ListNode* result=pq.top();
        pq.pop();
        if(result->next!=NULL){
        	pq.push(result->next);
        }
        
        ListNode* dummy=result;
        while(!pq.empty()){
            dummy->next = pq.top();
            pq.pop();
            dummy = dummy->next;
            if(dummy->next != nullptr)
                pq.push(dummy->next);
        }
        
        return result;
    }
};



//Fourth Sol :-
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Detect the edge cases straight away and return the correct answer
    if (0 == lists.size()) return nullptr;  // No lists given
    if (1 == lists.size()) return lists[0]; // One list given, and it's already sorted

    // Populate the todo queue
    queue<ListNode *> todo;
    for (auto list: lists) todo.push(list);

    // While we have at least 2 lists in the queue then merge them.
    // If we have only 1 list then we can return it as that will bere result
    while (todo.size() > 1) {
      // We will have first node of the combined answer list sacrificial.
      // The very first node is sacrificial as the algorim updates the 'next' value and not copying
      // the content (val), so first node is here only to point out to the real first node
      ListNode answer;
      ListNode *node = &answer;

      ListNode *left = todo.front();
      todo.pop();

      ListNode *right = todo.front();
      todo.pop();

      // Repeat merging until both left and right lists are at the end
      while (left != nullptr || right != nullptr) {
        ListNode *smaller = nullptr;
        
        // Find the smallest node, take into consideration that
        // the left or right can be already nullptr.
        // When smallest is choosen then it will progress the list 
        // where it was taken from (take from right, progress right etc...)
        if (left == nullptr) {
          smaller = right;
          right = right->next;
        } else {
          if (right == nullptr) {
            smaller = left;
            left = left->next;
          } else {
            if (left->val < right->val) {
              smaller = left;
              left = left->next;
            } else {
              smaller = right;
              right = right->next;
            }
          }
        }

        // The smallest node will go to our 'answer' list
        node->next = smaller;
        node       = node->next;
      }
      //      ans->next = nullptr; // when working correctly they should have nullptr already

      // We finished merging and are putting result to the back of the queue
      // so it might be merged later again, or use it as result if this was the very last
      // 2 lists to get merged.
        
      // Use the answer.next as that is the 'real' first node of the ordered list
      todo.push(answer.next); 
    }

    // We have only 1 list in the queue, that is the answer, just return it
    return(todo.front());
  }
};