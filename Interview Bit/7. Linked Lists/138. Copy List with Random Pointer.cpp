https://leetcode.com/problems/copy-list-with-random-pointer/




//Solution Approach :- With Extra Space
Node* copyRandomList(Node* head) {
    map<Node*,Node*> mp;        // this map points to the clone of the original node
        
    Node* temp = head;
    
    // 1st Pass - Creation of Nodes and no wiring
    while(temp!=NULL){
        Node *copy = new Node(temp->val);        // Pointing the original node to its clone node. Now I can access the clone node in O(1)
        mp[temp] = copy;
        temp = temp->next;
    }
    
    // 2nd pass - Filling the next and random pointers
    temp = head;         //Again point temp to head
    
    while(temp!=NULL){
        // mp[ptr] is the clone node and its next is the next original node's clone node. 
        // mp[ptr->next] refers to the clone node of ptr->next;
        mp[temp]->next= mp[temp->next]; 
        mp[temp]->random=mp[temp->random];                   // similar thing for the random pointer
        
        temp = temp->next;
    }
    return mp[head];
}



//Second Solution :- Without Extra Space
class Solution {
public:
    void copy_merge(Node* head){
        Node* curr=head;
        Node* next=head->next;

        while(curr!=NULL){
            Node* copy=new Node(curr->val);
            curr->next=copy;
            copy->next=next;
            curr=next;
            if(next!=NULL){
                next=next->next;
            }
        }
    }
    
    void handle_random(Node* head){
        Node* curr=head;
        while(curr!=NULL){
            if(curr->random!=NULL){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
    }
    
    Node* detach(Node* head){
        Node* curr=head;
        Node* dummy=new Node(-1);
        Node* tail=dummy;
        while(curr!=NULL){
            tail->next=curr->next;
            tail=tail->next;
            curr->next=tail->next;
            curr=curr->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }

        copy_merge(head);
        handle_random(head);
        
        return detach(head);
    }
};




//Third Solution  :- 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // STEP 1: PASS 1
        // Creating a copy (except random pointer) of each old node and insert it next to the old node it's copied from.
        // That is, it will create new alternative nodes which are a copy (except random pointer) of its previous node.
        Node* node=head;
        while(node){
            Node* temp=node->next;
            node->next=new Node(node->val);
            node->next->next=temp;
            node=temp;
        }
        
        // STEP 2: PASS 2
        // Now copy the random pointer (if exists) of the old nodes to their copy new nodes.
        node=head;
        while(node){
            if(node->random)
                node->next->random=node->random->next;
            node=node->next->next; // go to next old node
        }
        
        //STEP 3: PASS 3
        // Copy the alternative nodes into "ans" link list using the "helper" pointer along with restoring the old link list.
        Node* ans=new Node(0); // first node is a dummy node
        Node* helper=ans;
    
        while(head){
            // Copy the alternate added nodes from the old linklist
            helper->next=head->next;
            helper=helper->next;
            
            // Restoring the old linklist, by removing the alternative newly added nodes
            head->next=head->next->next;
            head=head->next; // go to next alternate node   
        }
        return ans->next; // Since first node is a dummy node
    }
};




//Fourth Solution :- Using memoization
class Solution {
public:
    unordered_map <RandomListNode*, RandomListNode*> mp;
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(!head) return NULL;
        if(mp[head]!=NULL) return mp[head];
        mp[head] = new RandomListNode(head->label);
        mp[head] -> next = copyRandomList(head->next);
        mp[head] -> random = copyRandomList(head->random);
        return mp[head];
    }
};