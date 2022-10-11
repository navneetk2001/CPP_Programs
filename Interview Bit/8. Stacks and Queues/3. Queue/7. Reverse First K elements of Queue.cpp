https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1




//Solution Approach :-
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    queue<int> p;

    while(k--){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        p.push(s.top());
        s.pop();
    }

    while(!q.empty()){
        p.push(q.front());
        q.pop();
    }
	return p;
}




//Second Solution :-
void helper(queue<int> &q, int k){
    if(q.empty() || k==0){
    	return;
    }

    int x=q.front();
    q.pop();
    
    helper(q,k-1);
    q.push(x);
}

queue<int> modifyQueue(queue<int> q, int k) {
    int n=q.size() - k;
    helper(q, k);

    while(n--){
       q.push(q.front());
       q.pop();
    }

    return q;
}