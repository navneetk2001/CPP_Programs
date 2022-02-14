stack<int> s;
int minEle=0;

void Push(int a){
	if(s.size()==0){
		s.push(x);
		minEle=x;
	}
	else{
		if(x>=minEle){
			s.push(x);
		}
		else if(x<minEle){
			s.push(2*x-minEle);
			minEle=x;
		}
	}
}

void Pop(){
	if(s.size()==0){
		return -1;
	}
	else{
		if(s.top()>=minEle){
			s.pop();
		}
		else if(s.top()<minEle){
			minEle=2*minEle-s.top();
			s.pop();
		}
	}
}

int top(){
	if(s.size()==0){
		return -1;
	}
	else{
		if(s.top()>=minEle){
			return s.top();
		}
		else if(s.top()<minEle){
			return minEle;
		}
	}
}

int getmin(){
	if(s.size()==0)
		return -1;
	return minEle;
}

