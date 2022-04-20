// Implement a Queue using 2 stacks s1 and s2 .
// A Query Q is of 2 Types
// (i) 1 x (a query of this type means  pushing 'x' into the queue)
// (ii) 2   (a query of this type means to pop element from queue and print the poped element)

// Example 1:
// Input:
// 5
// 1 2 1 3 2 1 4 2

// Output: 
// 2 3

// Explanation: 
// In the first testcase
// 1 2 the queue will be {2}
// 1 3 the queue will be {2 3}
// 2   poped element will be 2 the queue 
//     will be {3}
// 1 4 the queue will be {3 4}
// 2   poped element will be 3.

// Example 2:
// Input:
// 4
// 1 2 2 2 1 4

// Output: 
// 2 -1

// Explanation: 
// In the second testcase 
// 1 2 the queue will be {2}
// 2   poped element will be 2 and 
//     then the queue will be empty
// 2   the queue is empty and hence -1
// 1 4 the queue will be {4}.



//Solution Approach :-
//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty() and s2.empty()) return -1;
    if(!s2.empty()){
    	int tp=s2.top();
    	s2.pop();
    	return tp;
    }
    else{
    	while(!s1.empty()){
    		s2.push(s1.top());
    		s1.pop();
    	}
    	int tp=s2.top();
    	s2.pop();
    	return tp;
    }      
}

//Second Solution :-
//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x){
    while(!s1.empty()){
        int tmp=s1.top();
        s2.push(tmp);
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        int tmp=s2.top();
        s1.push(tmp);
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
    if(s1.empty())return -1;
    int res=s1.top();
    s1.pop();
    return res;
}