stack<int> s;
stack<int> ss;  //supporting stack to push only min element 


void Push(int a){
	s.push(a);
	if(ss.size()==0 || ss.top() >=a){
		ss.push(a);
	}
	return;
}

int Pop(){
	if(s.size()==0)
		return -1;

	int ans = s.top();
	s.pop();

	if(ss.top()==ans){
		ss.pop();
	}
	return ans;
}

int getmin(){
	if(ss.size()==0)
		return -1;
	return ss.top();
}