// You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.
// For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.
// Return the head of the modified linked list.


// Example 1:
// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
// Explanation: 
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 3 + 1 = 4.
// - The sum of the nodes marked in red: 4 + 5 + 2 = 11.

// Example 2:
// Input: head = [0,1,0,3,0,2,2,0]
// Output: [1,3,4]
// Explanation: 
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 1 = 1.
// - The sum of the nodes marked in red: 3 = 3.
// - The sum of the nodes marked in yellow: 2 + 2 = 4.
 

// Constraints:

// The number of nodes in the list is in the range [3, 2 * 105].
// 0 <= Node.val <= 1000
// There are no two consecutive nodes with Node.val == 0.
// The beginning and end of the linked list have Node.val == 0.



//Solution :- 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;    
        ListNode* dummy=new ListNode(0); //creating a dummy node
        ListNode* node=dummy;          
        int sum=0;
        while(temp->next)       //As given last node will have 0 so stopping before
        {
            if(temp->val==0)    //As given first node will have 0 so first update temp and then traverse
            {
                temp=temp->next;
                while(temp->val!=0) //going till we dont encounter next zero 
                {
                    sum+=temp->val;    
                    temp=temp->next;
                }
                dummy->next=new ListNode(sum);  
                sum=0;
                dummy=dummy->next;
            }
        }
        return node->next;
    }
};





//Solution Approach :-
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p = head;
        while(p->next!=NULL){
            if(p->val==0){
                ListNode* temp = p->next;
                int n = 0;
                while(temp!=NULL and temp->next->val!=0 ){
                    n += temp->val;
                    temp = temp->next;
                }
                temp->val += n;
                p->next = temp;
            }
            p = p->next;
        }
        while(head->val==0){
            head = head->next;
        }
        p = head;
        while(p!=NULL and p->next!=NULL){
            p->next = p->next->next;
            p = p->next;
        }
        return head;
    }
};



// Solution :- Using stack O(N) time , O(1) space
// Simply add the node values between zeroes
// Store the first zero in the stack. Now , till another zero occurs, we will traverse the linked list, and keep adding the value of the nodes to a single node. As soon as another zero is encountered, we will pop from the stack and add the new node to the next of dummy head and move the traversing pointer forward.
// Finally, after the operation is done return the new head's next of the linked list which initially referred to the dummy node.

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;
        stack<int>p;
		//make a dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead = dummy;
        ListNode* temp = head;
        bool flag = false;
        int sum = 0;
        while(temp){
		//when this is the first zero 
            if(temp -> val == 0 && p.empty() == true){
                p.push(0);
            }
			//now another zero occurs so pop and make the new list
            else if(temp->val == 0 && p.empty() == false){
                p.pop();
                ListNode* newnode = new ListNode(sum);
                dummy -> next = newnode;
                dummy = dummy -> next;
                sum = 0;
				//remember to push this zero as the start for other range
                p.push(0);
            }
            else{
			//keep adding the node values
                sum += temp -> val;
            }
            temp = temp -> next;
        }
		//return the new head
        return newHead -> next;
    }
};

