Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

//Hint
Another pointer game. Traverse the list while maintaining two pointers( what should they represent?).

//Solution Approach :-
Maintain 2 pointers - one which maintains all nodes less than x and another which maintains nodes greater than or equal to x.
Keep going along our list. When we are at node that is greater than or equal to x, we remove this node from our list and move it to list of nodes greater than x.


// First Method :-
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* head=A;
    ListNode* before_head=new ListNode(0);
    ListNode* before=before_head;
    ListNode* after_head=new ListNode(0);
    ListNode* after=after_head;

    while(head!=NULL){
        if(head->val<B){
            before->next=head;
            before=before->next;
        }
        else{
            after->next=head;
            after=after->next;
        }
        head=head->next;
    }
    after->next=NULL;
    before->next=after_head->next;

    return before_head->next;
}

//Second Method :-
ListNode* Solution::partition(ListNode* A, int B) {
    vector<int>ans1;
    vector<int>ans2;
    ListNode* temp=A,*rem;
    int cnt=0;
    while(temp!=NULL)
    {
        rem=temp;
        cnt++;
        if(temp->val<B)
        {
            ans1.push_back(temp->val);
        }
        else if(temp->val>=B)
        {
            ans2.push_back(temp->val);
        }
        temp=temp->next;
        free(rem);
    }
    for(int i=0;i<ans2.size();i++)
    {
        ans1.push_back(ans2[i]);
    }
    ans2.clear();
     for(int i=0;i<cnt-1;i++){
     if(cnt==1)
     cout<<ans1[i]<<" ";
     else
     cout<<ans1[i]<<" "<<"->"<<" ";
 } 
  cout<<ans1[cnt-1]<<" ";
  return NULL;
}

//Third Method :-
void swap(ListNode* a,ListNode* b)
{
    int temp=a->val;
    a->val=b->val;
    b->val=temp;
}
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* i=NULL;
    ListNode* j=NULL;
    ListNode* k=NULL;
    ListNode* temp=A;
    int count=0;
    ListNode* b1=NULL;
    ListNode* b2=NULL;
    ListNode* b3=NULL;
    while(temp!=NULL)
    {
        if(temp->val<B)
        {
            if(b1==NULL)
            {
                b1=temp;
                i=b1;
            }
            else
            {
                i->next=temp;
                i=i->next;
            }
        }
        else
        {
            if(b3==NULL)
            {
                b3=temp;
                k=b3;
            }
            else
            {
                k->next=temp;
                k=k->next;
            }
        }
        temp=temp->next;
    }
    
    if(b1==NULL)
    {
        A=b3;
        if(k!=NULL)
            k=k->next;
    }
    else
    {
        A=b1;
        i->next=b3;
        if(k!=NULL)
            k->next=NULL;
    }
    return A;
}


//Fourth Solution :-
ListNode* Solution::partition(ListNode* head, int x) {
	queue q1;
	queue q2;
	ListNode* curr=head;
	int count=0;

	while(curr!=NULL){
		if(curr->val<x){
			q1.push(curr->val);
		}
		else{
			q2.push(curr->val);
		}
		curr=curr->next;
		count++;
	}

	curr=head;
	while(!q1.empty()){
		curr->val=q1.front();
		q1.pop();
		curr=curr->next;
	}
	while(!q2.empty()){
		curr->val=q2.front();
		q2.pop();
		curr=curr->next;
	}
	return head;
}