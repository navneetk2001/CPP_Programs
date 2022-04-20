N light bulbs are connected by a wire.
Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.
Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.
You can press the same switch multiple times.
Note : 0 represents the bulb is off and 1 represents the bulb is on.

Input 1:  A = [1]
Output 1: 0
Explanation 1: There is no need to turn any switches as all the bulbs are already on.

Input 2: A = [0 1 0 1]
Output 2: 4
Explanation 2:
	press switch 0 : [1 0 1 0]
	press switch 1 : [1 1 0 1]
	press switch 2 : [1 1 1 0]
	press switch 3 : [1 1 1 1]

//Hint :-
You will never need to press the same switch twice. Why? Because it is equivalent to not pressing the switch and you will end up with the same state as before. So we can always solve the problem in at most n switch flips.

//Solution Approach :- 
The order in which you press the switch does not affect the final state.
Example:
Input : [0 1 0 1]
Case 1:
	Press switch 0 : [1 0 1 0]
	Press switch 1 : [1 1 0 1]
	
Case 2:
	Press switch 1 : [0 0 1 0]
	Press switch 0 : [1 1 0 1]	
Therefore we can choose a particular order. To make things easier lets go from left to right. At the current position if the bulb is on we move to the right, else we switch it on. This works because changing any switch to the right of it will not affect it anymore.


//First Solution :-
int Solution::bulbs(vector<int> &A) {
	int k=0,ans=0;
	for(int i=0;i<A.size();i++){
	    if(k==A[i]){
	        if(k==0) k=1;
	        else k=0;
	        ans++;
	    }
	}
	return ans;
}

//Second Solution :-
int Solution::bulbs(vector<int> &A) {
    int n = A.size();
    int c = 0;
    int f = 0;
    for(int i = 0; i < n; i++)
    {
        if(f == 0 && A[i] == 0)
        {
            c++;
            f = 1;
        }
        if(f == 1 && A[i] == 1)
        {
            c++;
            f = 0;
        }
    }
    return c;
}


//Third Solution :- 
int Solution::bulbs(vector &A) {
	int res=0;
	int n=A.size();
	int count=0;
	for(int i=0;i<n;i++){
		if(count==0){
			if(A[i]==0){
				res++;
				count=1;
			}
		}
		else{
			if(A[i]==1){
				res++;
				count=0;
			}
		}
	}
	return res;
}



