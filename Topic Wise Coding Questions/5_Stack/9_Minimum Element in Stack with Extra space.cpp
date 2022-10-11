https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1



//Solution Approach :-
class Solution{
    int minEle;
    stack<int> s;
    stack<int>ss;    //supporting stack to hold minimum

public:
    /*returns min element from stack*/
    int getMin(){
        if(ss.size()==0){
	        return -1;
        }
        return ss.top();
    }
   
    /*returns poped element from stack*/
    int pop(){
        if(s.size()==0){
    		return -1;
        }
    
    	int ans = s.top();
    	s.pop();
    
    	if(ss.top()==ans){
    		ss.pop();
    	}
    	return ans;
    }
   
    /*push element x into the stack*/
    void push(int a){
        s.push(a);
    	if(ss.size()==0 || ss.top() >=a){
    		ss.push(a);
    	}
    	return;
    }
};




//Second Solution :-
stack<pair<int,int>> s;
public:
   /*returns min element from stack*/
   int getMin(){
       if(s.empty()) return -1;
       return s.top().second;
   }
   /*returns poped element from stack*/
   int pop(){
       if(s.size()==0) return -1;
       int val=s.top().first;
       s.pop();
       return val;  
   }
   /*push element x into the stack*/
   void push(int x){   
       if(s.size()==0) s.push({x,x});
       else{
            int minEle=min(s.top().second,x);
            s.push({x,minEle});
       }
   }