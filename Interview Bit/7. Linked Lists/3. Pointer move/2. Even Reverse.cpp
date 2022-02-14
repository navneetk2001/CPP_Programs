//Given a linked list A , reverse the order of all nodes at even positions.
Example Input :-
Input 1:
A = 1 -> 2 -> 3 -> 4
Input 2:
A = 1 -> 2 -> 3

Example Output
Output 1:
 1 -> 4 -> 3 -> 2
Output 2:
 1 -> 2 -> 3


//Solution Approach
Store the even positioned and odd positioned
nodes in 2 vectors. now reverse the even position vectors
and then Recombine them to form a linked list.
All of this will happen in O(n) time.


//First Method :-
ListNode* Solution::solve(ListNode* A) {
	int i ,len=0;
	vector<int>v;
	ListNode *head=A;
	while(head!=NULL){
		v.push_back(head->val);
		len++;
		head=head->next;
	}

	if(len%2==0){
		for(i=1;i<(len/2+1);i=i+2){
			swap(v[i],v[len-i]);
		}
	}
	else{
		for(i=1;i<(len/2+1);i=i+2){
			swap(v[i],v[len-1-i]) ;
		}
	}

	head=A;
	int j=0;
	while(head!=NULL){
		head->val=v[j];
		head=head->next;
		j++;
	}
	return A;
}



//Another Method:-
ListNode* Solution::solve(ListNode* A) {
    ListNode* odd = head;
    //If 3 or less elemnts are present in the linked list nothing to be done
    if(odd == NULL or odd->next==NULL or odd->next->next==NULL){
        return A;
    }
    
    //Initialize the start of even list
    ListNode* even=NULL;

    //Traverse the list :- Step 1
    while(odd and odd->next){
        //store the even node in a temp variable
        ListNode* temp=odd->next;

        //remove the even node
        odd->next=temp->next;

        //Add the even node stored in the temp variable at the beginning of even list
        temp->next=even;
        even=temp;

        //Move odd to the next odd node
        odd=odd->next;
    }

    //Reset odd to head
    odd=head;

    //Step2 of the problem
    //Add the reversed elements of the even list to the odd list
    while(even){
        //store the pointer to the next even node in temp variable
        ListNode* temp=even->next;

        //Insert the even node between two odd nodes
        even->next=odd->next;
        odd->next=even;

        //move the head to the next odd nodes
        odd=odd->next->next;

        //set the even pointer to the next even node in the even list
        even=temp;
    }
    return A;
}



//Second Method :-
ListNode* recReverse(ListNode* head){
	//smallest linked list
	if(head==NULL or head->next==NULL){
		return head;
	}
	//rec case
	ListNode* shead = recReverse(head->next);

	ListNode* temp=head->next;
	temp->next=head;
	head->next = NULL;

	return shead;
}

ListNode* Solution::solve(ListNode* A) {
    ListNode *p, *q;
	vector<int>v;
	int len=0;

	p=A;
	while(p!=NULL){
		if(len%2==1){
			v.push_back(p->val);
		}
		len++;
		p=p->next;
	}
	int idx=0;
	q=recReverse(A);
	p=q;

	if(len%2==1){
		q=q->next;
	}
	while(q!=NULL){
		q->val=v[idx];
		idx++;
		q=q->next->next;
	}
	p=recReverse(p);
	return p;
}



//Third Method :-
ListNode* reverse(ListNode* A){
    ListNode *p, *c, *n;
    p=NULL;
    c=A;
    while(c!=NULL){
        n= c->next;
        c->next =p;
        p=c;
        c=n;
    }
    return p;
} 
 

ListNode* merge(ListNode* ehead, ListNode *ohead){
    ListNode *head = new ListNode(0);
    int c =1;
    ListNode *t1, *t2, *cur;
    t1= ohead;
    t2 = ehead;
    cur= head;
    while(t1!=NULL || t2!=NULL){
        if(c%2==1){
            cur->next =t1;
            t1=t1->next;
        }
        else {
            cur->next = t2;
            t2=t2->next;
        }
        cur = cur->next;
        c++;
    }
    return head->next;
} 
 
ListNode* Solution::solve(ListNode* A) {
    ListNode *ohead, *ehead, *o1, *e1, *t;
    t =A;
    ohead = new ListNode(0);
    ehead = new ListNode(0);
    o1= ohead;
    e1= ehead;
    int c =1;
    while(t!=NULL){
        if(c%2==1){
            o1->next=t;
            o1=o1->next;
        }
        else{
            e1->next = t;
            e1=e1->next;
        }
        t=t->next;
        c++;
    }
    o1->next =NULL;
    e1->next = NULL;
    return merge(reverse(ehead->next), ohead->next);
}





// Fourth Method :-
ListNode * reverseList(ListNode * head){
    if(!head||!head->next)return head;
    ListNode * previous = nullptr;
    ListNode * next ;
    while(head){
        next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
} 
 
ListNode* Solution::solve(ListNode* A) {
    if(!A||!A->next||!A->next->next||!A->next->next->next)return A;
    
    ListNode * head = A;
    ListNode * slow = A;
    ListNode * fast = A->next;
    ListNode * brk = nullptr;

    while(fast&&fast->next){
        slow = slow->next ;
        fast = fast->next->next;
    }

    bool even = fast?false:true;
    brk = slow;
    fast = reverseList(slow->next);
    slow = A->next;
    head = fast;
    if(even)fast = fast->next;
    even = true;
    
    while(fast){
        if(even){
            swap(slow->val,fast->val);
        }
        even = !even;
        slow = slow->next;
        fast = fast->next;
    }
    brk->next = reverseList(head);
    brk = brk->next;
    return A;
}
