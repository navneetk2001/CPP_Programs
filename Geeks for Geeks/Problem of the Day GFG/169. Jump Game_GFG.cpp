// Given an positive integer N and a list of N integers A[]. Each element in the array denotes the maximum length of jump you can cover. Find out if you can make it to the last index if you start at the first index of the list.

// Example 1:
// Input: N = 6
// A[] = {1, 2, 0, 3, 0, 0} 
// Output: 1
// Explanation: Jump 1 step from first index to second index. Then jump 2 steps to reach 4th index, and now jump 2 steps to reach the end.

// Example 2:
// Input: N = 3
// A[] =  {1, 0, 2}
// Output: 0
// Explanation: You can't reach the end of the array.



//Solution Approach :-
//We will start iterating from last index and try to reach starting index

class Solution {
  public:
    int canReach(int nums[], int N) {
        int index = N-1;  //store index of last element of array

        for(int i = N-1; i>=0; i--){
        	if(nums[i] + i >= index){   //if currentindex + currJumpsAllowed >= indexToBeReached
        		index = i;              //Update the indexToBeReached
        	}
        }
        
        if(index == 0){               //if already reached to starting index, then return true
        	return true;
        }
        else{
        	return false;
        }
    }
};



//Second Solution :-
class Solution {
public:
    int canReach(int A[], int N) {
        int index = 0;
        int maxi = 0;
        for(int i = 0;i<N;i++){
            maxi = max(maxi,A[i]+i);
            if(index==i){
                index = maxi;
            }
        }
        if(index >= N-1){
        	return 1;
        }
        return 0;
    }
};



//Third Solution :-
class Solution {
  public:
    int canReach(int A[], int N) {
        int range = A[0];
        
        for(int i = 1; i < N; i++) {
            if(i <= range) {
                range = max(range, i + A[i]);
            }
        }
        
        return (range >= N - 1 ? 1 : 0);
    }
};


