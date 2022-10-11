https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1




//Solution Approach :- GFG :-> O(1) space complexity
int minEle;
stack<int> s;
public:

/*returns min element from stack*/
int getMin(){
   	if(s.size() == 0){
   		return -1;
   	}
   	return minEle;
}

/*returns poped element from stack*/
int pop(){
   	if(s.empty()){
   		return -1;
   	}
   
   	if(s.top() >= minEle){
       	int ans = s.top();
       	s.pop();
       	return ans;
   	}
   	else if(s.top() < minEle){
       	int ans = minEle;
       	minEle = 2*minEle-s.top();
       	s.pop();
       	return ans;
   	}
}

/*push element x into the stack*/
void push(int x){
   	if(s.size() == 0){
       	s.push(x);
       	minEle = x;
   	}
   	else{
       	if(x >= minEle){
           	s.push(x);
       	}
       	else{
           	s.push(2*x-minEle);
           	minEle = x;
       	}
   	}
}





//Second Solution :-
class Solution{
   int minEle;
   stack<int> s;
   public:
   
      /*returns min element from stack*/
      int getMin(){
          
          //Write your code here
          if(s.empty()) return -1;
          return minEle;
      }
      
      /*returns poped element from stack*/
      int pop(){
           int res;
          //Write your code here
           if(s.empty()) return -1;
           if(s.top() < 0) 
           {
               res = minEle;
               minEle = s.top() * -1 - minEle; 
           }
           else res = s.top() - minEle;    //the minimum is the same if the value is positive
           s.pop();
           return res;
      }
      
      /*push element x into the stack*/
      void push(int x){
          
          //Write your code here
           if(s.empty()) 
           {
                minEle = x;   
                s.push(-x);   
           }
           // let's keep the minimum with value
           else if(x < minEle) 
           {
                s.push((x + minEle) * -1);  //negative value if new minimum
                minEle = x;   
           }
           else s.push(x + minEle);         //positive value if the same minimum
       }
};




//Third Solution :- LeetCode
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

