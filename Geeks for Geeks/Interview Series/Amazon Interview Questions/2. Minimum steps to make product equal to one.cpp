// Given an array arr[] containing N integers. In one step, any element of the array can either be increased or decreased by one. Find minimum steps required such that the product of the array elements becomes 1.

// Example 1:
// Input:
// N = 3
// arr[] = {-2, 4, 0}
// Output:
// 5
// Explanation:
// We can change -2 to -1, 0 to -1 and 4 to 1.
// So, a total of 5 steps are required
// to update the elements such that the product of the final array is 1. 

// Example 2:
// Input:
// N = 3
// arr[] = {-1, 1, -1} 
// Output :
// 0
// Explanation:
// Product of the array is already 1.
// So, we don't need to change anything.


class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        int steps=0;
        int negative_numbers=0;
        int zeros=0;

        for(int i=0;i<N;i++){
        	if(arr[i]==0){
        		zeros+=1;
        	}
        	else if (arr[i] > 0){
        		steps+=(arr[i]-1);
        	}
        	else{
        		negative_numbers+=1;
        		steps+=(-1-arr[i]);
        	}
        }
        steps += zeros;

        if(negative_numbers % 2 != 0 and zeros==0){
        	steps+=2;
        }

        return steps;
    }
};

