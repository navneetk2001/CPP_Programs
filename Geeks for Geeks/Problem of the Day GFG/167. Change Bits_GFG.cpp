// Given a number N, complete the following tasks,
// Task 1. Generate a new number from N by changing the zeroes in the binary representation of N to 1.
// Task  2. Find the difference between N and the newly generated number.

// Example 1:
// Input: N = 8 
// Output: 7 15
// Explanation: There are 3 zeroes in binary representation of 8. Changing them to 1 will give 15. Difference between these two is 7.

// Example 2:
// Input: N = 6 
// Output: 1 7
// Explanation: There is 1 zero in binary representation of 6. Changing it to 1 will give 7. Difference between these two is 1.
 




//Solution Approach :-
class Solution {
  public:
    vector<int> changeBits(int N) {
        int bits = log2(N) + 1;
        int val = (1 << bits) - 1;
        return {val - N, val};
    }
};



//Second Solution :-
vector<int> changeBits(int N) {
   	int x=N;
   	int val=N, curr=1;
   	while(x>0)
   	{
       	int temp=x & 1;
       	if(temp==0){
           	val=val|curr;
       	}
       	x=x>>1;
       	curr=curr<<1;
   	}
   	return {val-N,val};
}



//Third Solution :-
class Solution{
public:
    vector<int> changeBits(int N) {
        int count=0,aux = N;
        while(N>0){
            count++;
            N = N/2;
        }
        vector<int> ans;
        int ans2 = (pow(2,count)-1);
        int ans1 = ans2-aux;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};



//Fourth Solution :-
vector<int> changeBits(int N) {
   	int newNum = 0, i = 0, temp = N;
   	while(temp){
       	newNum += (1 << i++);
       	temp /= 2;
   	}
   	return vector<int>{newNum - N,newNum};
}

