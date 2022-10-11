https://practice.geeksforgeeks.org/problems/queue-reversal/1




//Solution Approach :-
queue<int> rev(queue<int> q)
{
   	stack<int> s;
   	while(!q.empty()){
       	s.push(q.front());
       	q.pop();
   	}
   	
   	while(!s.empty()){
       	q.push(s.top());
       	s.pop();
   	}
   	return q;
}



//Second Solution :- Using Recursion
void Reversal(queue<int>& q){
   	if(q.empty()){
   		return;
   	}
   
	int val = q.front();
	q.pop();

	Reversal(q);     //Recursion
	q.push(val);
}

queue<int> rev(queue<int> q){
	Reversal(q);
	return q;
}