https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1



//Solution Approach :- 
node *partition(node *root, node *end){
    node *pivot = root, *curr = root->next;
    while (curr){
        if (curr->data <= pivot->data){
            swap(curr->data, pivot->data);
        }
        curr = curr->next;
    }
    return pivot;
}


void quick_sort(node *root, node *end = NULL)
{
    if (!root || !root->next || root == end){
        return;
    }

    node *mid = partition(root, end);
    quick_sort(root, mid);
    quick_sort(mid->next, end);
}


void quickSort(struct node **headRef){
    quick_sort(*headRef);
}



//Second Solution :-
node* getTail(node *head){
   	node *temp =head;
   	while(temp != NULL && temp->next != NULL){
       	temp=temp->next;
   	}

   	return temp;
}

node* partition(node *head, node *tail){
   node *pivot = head;             //pivot=0;
   node *curr = head->next;
   node *prev = head;

   	while(curr != tail->next){                              //for(int i=0;j=1;j<=r;j++)
       	if(pivot->data > curr->data){                       //if(a[pivot]>a[j])
           	swap(prev->next->data, curr->data);              //swap(a[i+1],a[j])
          	prev = prev->next;                               //i+=i;
       	}
       	curr = curr->next;
   	}
   	swap(prev->data, pivot->data);             //swap(a[pivot],a[i]);
   	return prev;                               //new pivot
}

void solveSort(node *head,node *tail){
   	if(head == NULL || tail == NULL ||head==tail){
       	return;
   	}
   	//l<r
   	node *pivot=partition(head,tail);
   	solveSort(head,pivot);
   	solveSort(pivot->next,tail);
}

void quickSort(struct node **headRef) {
   	node *head=*headRef;
   	if(head==NULL || head->next==NULL){
       	return;
   	}
   	node* tail = getTail(head); //tail
   	
   	solveSort(head,tail);
}



