// Given two polynomial numbers represented by a linked list. The task is to complete the function addPolynomial() that adds these lists meaning adds the coefficients who have the same variable powers.
// Note:  Given polynomials are sorted in decreasing order of power.

// Example 1:
// Input:
// LinkedList1:  (1,x2) 
// LinkedList2:  (1,x3)
// Output: 1x^3 + 1x^2 
// Explanation: Since, x2 and x3 both have different powers as 2 and 3. So, their coefficient can't be added up.

// Example 2: 
// Input:
// LinkedList1:  (1,x3) -> (2,x2)
// LinkedList2:  (3,x3) -> (4,x2)
// Output: 4x^3 + 6x^2
// Explanation: Since, x3 has two different coefficients as 3 and 1. Adding them up will lead to 4x3. Also, x2 has two coefficients as 4 and 2. So, adding them up will give 6x2.





//Solution Approach :-
Node* addPolynomial(Node *p1, Node *p2)
{
    Node *sum = new Node(0, 0);
    Node *sumRef = sum;

    while((p1 != NULL) && (p2 != NULL)){
        if(p1->pow == p2->pow){
            sum->next = new Node(p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->pow > p2->pow){
            sum->next = new Node(p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else{
            sum->next = new Node(p2->coeff, p2->pow);
            p2 = p2->next;
        }
        sum = sum->next;
    }
    
    if(p1){
        sum->next = p1;
    }
    else if(p2){
        sum->next = p2;
    }
    return sumRef->next;
}




//Second Solution :- Recursive Code 
class Solution{
  public:
    Node* addPolynomial(Node *p1, Node *p2){
        if(p1==NULL) return p2;
        if(p2==NULL) return p1;
        
        if(p1->pow == p2->pow){
            p1->coeff = p1->coeff + p2->coeff;
            p1->next = addPolynomial(p1->next, p2->next);
            return p1;
        }
        else if(p1->pow > p2->pow){
            p1->next = addPolynomial(p1->next,p2);
            return p1;
        }
        else{
            p2->next=addPolynomial(p1,p2->next);
            return p2;
        }
    }
};




//Third Solution :-
class Solution{
  public:
    Node* addPolynomial(Node *p1, Node *p2){
        if(p1->pow < p2->pow){
            swap(p1, p2);
        }
            
        Node *res = p1;
        
        while(p1){
            Node *temp = p1;
            
            while(p1 and p2 and p1->pow >= p2->pow){
                if(p1->pow == p2->pow){
                    p1->coeff += p2->coeff;
                    p2 = p2->next;
                }
                temp = p1;
                p1 = p1->next;
            }
            
            temp->next = p2;
            swap(p1, p2);
        }
        
        return res;
    }
};




//Fourth Solution :-
Node* addPolynomial(Node *p1, Node *p2)
{   
    Node* fakeNode = new Node(-1 , -1);
    Node* head=fakeNode;

    while(p1 && p2){
        
        while(p1 && p2 && (p1->pow > p2->pow)){
            head->next = p1;
            head=head->next;
            
            p1=p1->next;
        }
        while(p1 && p2 && (p1->pow < p2->pow)){
            head->next= p2;
            head=head->next;
            
            p2=p2->next;
        }
        
        if(p1 && p2 && (p1->pow == p2->pow)){
            
            p1->coeff= p1->coeff + p2->coeff;
            head->next=p1;
            head=head->next;
            
            p1=p1->next;
            p2=p2->next;
        }
        
    }
    
    if(p1!=NULL)
     head->next=p1;
    
    if(p2!=NULL)
     head->next=p2;
    
    return fakeNode->next;
 
}



//Fifth Solution :-
Node* addPolynomial(Node *p1, Node *p2)
{
    if(p1 == NULL){
        return p2;
    }
    if(p2 == NULL){
        return p1;
    }
    Node* curr1 = p1->pow >= p2->pow ? p1 : p2;
    Node* curr2 = p1->pow >= p2->pow ? p2 : p1;
    Node* prev = NULL;
    while(curr1 != NULL && curr2 != NULL){
        if(curr1->pow == curr2->pow){
            curr1->coeff += curr2->coeff;
            prev = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if(curr1->pow > curr2->pow){
            prev = curr1;
            curr1 = curr1->next;
        }
        else{
            if(prev != NULL)
                prev->next = curr2;
                prev = curr2;
                Node* next = curr2->next;
                curr2->next = curr1;
                curr2 = next;
        }
    }
    while(curr2 != NULL){
        prev->next = curr2;
        prev = prev->next;
        curr2 = curr2->next;
    }
    return p1->pow >= p2->pow ? p1 : p2;
}


