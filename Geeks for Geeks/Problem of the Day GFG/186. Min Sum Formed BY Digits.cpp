// Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of given array must be used to form the two numbers.

// Example 1:
// Input:
// N = 6
// arr[] = {6, 8, 4, 5, 2, 3}
// Output: 604
// Explanation: The minimum sum is formed by numbers 358 and 246
 

// Example 2:
// Input:
// N = 5
// arr[] = {5, 3, 0, 7, 4}
// Output: 82
// Explanation: The minimum sum is formed by numbers 35 and 047





//Solution Approach :-
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        long long int num1 = 0, num2 = 0;
        
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                num1 = (num1*10)+arr[i];
            }
            else{
                num2 = (num2*10)+arr[i];
            }
        }
        return num1 + num2;
    }
};
