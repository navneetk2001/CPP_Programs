Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.
Example 1:

Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

Example 2:

Input:
4 4
4 3 2 1

Output: 
1 2 3 4

Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.

//Soln :-
queue<int> modify(queue<int>q, int k){
	stack<int>st;
	for(int i=0;i<k;i++){
		st.push(q.front());
		q.pop();
	}

	queue<int>q2;
	while(!st.empty()){
		q2.push(st.top());
		st.pop();
	}

	while(!q.empty()){
		q2.push(q.front());
		q.pop();
	}
	return q2;
}


