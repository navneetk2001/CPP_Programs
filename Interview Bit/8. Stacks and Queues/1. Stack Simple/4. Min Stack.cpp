//Here minimum stack size not equal to normal stack

stack<int> s; // Normal stack for storing value
stack<int> m; // Stack for storing minimum value up to that
MinStack::MinStack() {
    stack<int>().swap(s);
    stack<int>().swap(m);
}

void MinStack::push(int x) {
    if(s.empty()) m.push(x);
    else if(x <= m.top()) m.push(x);
    s.push(x);
}

void MinStack::pop() {
    if(!s.empty() && !m.empty() && s.top() == m.top()) m.pop();
    if(!s.empty()) s.pop();
}

int MinStack::top() {
    if(!s.empty()) return s.top();
    return -1;
}

int MinStack::getMin() {
    if(!m.empty()) return m.top();
    return -1;
}


//Hint :-
Lets look at solution number 1.
What if you maintained 2 queues. One which stored the actual stack of element, and the other which stored the minimum of elements.
So when pushing new element,
min = min(top of minimum stack, current value) which is pushed to minimum stack.
However, this uses 2N memory.
Can you think of slight optimizations to this ?


//Solution Approach :-
What if you maintaned the current minimum in a variable and only stored the places where the minimum changes or the element is same as the minimum.
pop() becomes a little trickier in such a case.
You only pop() from the min stack if the top() of min stack is same as the current minimum.
Space complexity : O(N + X) where X = number of places where minimum changes or the element is same as the minimum


//First Solution :-
stack<pair<int,int>> S;
int minEle;

MinStack::MinStack() {
    while(S.size()) 
        S.pop();
    minEle = INT_MAX;
}

void MinStack::push(int x) {
    S.push({x,minEle});
    minEle = min(x,minEle);
}

void MinStack::pop() {
    if(S.empty()) return;
    minEle = S.top().second;
    S.pop();
}

int MinStack::top() {
    if(S.empty()) return -1;
    return S.top().first;
}

int MinStack::getMin() {
    if(S.empty()) return -1;
    return minEle;
}


//Second Solution :-
//Here minimum stack size not equal to normal stack

stack<int> s; // Normal stack for storing value
stack<int> m; // Stack for storing minimum value up to that
MinStack::MinStack() {
    stack<int>().swap(s);
    stack<int>().swap(m);
}

void MinStack::push(int x) {
    if(s.empty()) m.push(x);
    else if(x <= m.top()) m.push(x);
    s.push(x);
}

void MinStack::pop() {
    if(!s.empty() && !m.empty() && s.top() == m.top()) m.pop();
    if(!s.empty()) s.pop();
}

int MinStack::top() {
    if(!s.empty()) return s.top();
    return -1;
}

int MinStack::getMin() {
    if(!m.empty()) return m.top();
    return -1;
}


//Third Solution :-
class MinStack {
    int stack[10000];
    int min[10000];
    int topPtr;
    int minPtr;
public:
    /** initialize your data structure here. */
    MinStack() {
        topPtr = -1;
        minPtr = -1;
    }
    
    void push(int x) {
        if(topPtr >= 10000)
            return;
        
        stack[++topPtr] = x;
        
        if(minPtr >= 0)
        {
            if(min[minPtr] > x)
                min[++minPtr] = x;
            else
            {
                min[minPtr+1] = min[minPtr];
                minPtr += 1;
            }
        }
        else
            min[++minPtr] = x;
    }
    
    void pop() {
        if(topPtr < 0)      //Underflow
            return;
        
        topPtr -= 1;
        minPtr -= 1;
    }
    
    int top() {        
        return stack[topPtr];
    }
    
    int getMin() {
        return min[minPtr];
    }
};


//Fourth Solution :-
int arr[5000005];
int idx;
int mini[500005];
MinStack::MinStack() {
    idx=-1;
    for(int i=0;i<500005;i++)mini[i]=INT_MAX;
}

void MinStack::push(int x) {
	arr[++idx]=x;
	if(idx>0)
	    mini[idx] = min(mini[idx-1],x);
	else
	    mini[idx]=x;
}

void MinStack::pop() {
    if(idx>=0)
        idx--;
}

int MinStack::top() {
    if(idx==-1)return -1;
    return arr[idx];
}

int MinStack::getMin() {
    if(idx==-1) return -1;
    return mini[idx];
}


