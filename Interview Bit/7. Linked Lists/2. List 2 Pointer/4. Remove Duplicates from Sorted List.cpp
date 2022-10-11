// Given a sorted linked list, delete all duplicates such that each element appear only once.
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

//Solution Approach :-
// Skip the node where head->next != NULL && head->val == head->next->val.

// Make sure you take care of corner cases :
// 1) Do you handle repetitions at the end ? ex : 1 -> 1
// 2) Do you handle cases where there is just one element ? ex : 1
// 3) Do you handle cases where there is just one element repeated numerous times ? 1->1->1->1->1->1


// First Method :-
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* curr = A;
    while(curr->next !=NULL){
        if(curr->val == curr->next->val){
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
    return A;
}



//Second Method :-
ListNode* Solution::deleteDuplicates(ListNode* A) {
	ListNode* t1 = A;
	if(A == NULL)
		return A;

	while (t1->next != NULL){
		if (t1->val == t1->next->val){      
		    t1->next = t1->next->next;
		}
		else{
		    t1 = t1->next;
		}
	}
	return A;
}


//Third Method :-
ListNode* Solution::deleteDuplicates(ListNode* A) {

    vector<int>ans;
        ListNode* temp=A,*rem;
        while(temp!=NULL)
        {
            rem=temp;
            ans.push_back(temp->val);
            temp=temp->next;
            free(rem);
        }
        //sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        if(ans.size()==1)
        {
            cout<<ans[0]<<" ";
            return NULL;
        }
        else
        for(int i=0;i<ans.size()-1;i++)
        {
            cout<<ans[i]<<" "<<"->"<<" ";
        }
        cout<<ans[ans.size()-1]<<" ";
        
        return NULL;
}


//Recursive Solution :-
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A->next == NULL){
        return A;
    }
    if(A->val == A->next->val){          // skip this node
        return deleteDuplicates(A->next);
    }
    else{              // attach this node to rest of the list
        A->next = deleteDuplicates(A->next);
        return A;
    }
}


