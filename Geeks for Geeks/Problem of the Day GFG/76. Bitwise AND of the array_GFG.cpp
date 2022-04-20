// Given an array A[ ] of N integers and an integer X. In one operation, you can change the ith element of the array to any integer value where 1 ≤ i ≤ N. Calculate minimum number of such operations required such that the bitwise AND of all the elements of the array is strictly greater than X.

// Example 1:
// Input:
// N = 4, X = 2
// A[] = {3, 1, 2, 7}
// Output: 2
// Explanation: 
// After performing two operations:
// Modified array: {3, 3, 11, 7} 
// Now, Bitwise AND of all the elements is 3 & 3 & 11 & 7 = 3 

// Example 2:
// Input:
// N = 3, X = 1
// A[] = {2, 2, 2}
// Output: 0


//Solution Approach :-
// Explanation : Here idea is simply to check from the 31st bit that is the most significant bit, 
// keep checking whether that bit is set in X or not if it is set then we will set that bit in 
// our p variable also so that p variable have all the msbs of X set till ith bit. And if ith bit in 
// X is not set then it is our chance to make the p greater than X so we will create a number whose 
// all the bits that are set in p till now will be set as well as its ith bit will also be set so that 
// total & of all elements in array can become strictly greater than x. And then we will simply find out 
// how many elements are present in given array whose & with current value of p is equal to p means whose 
// all the bits that are set in p are set as well as the ith bit is also set, and by this intuition we can 
// say that if a element is having all the bits set which are set in p till now and ith bit then that element 
// will not contribute to any problem because its & will be contributing to make the total & of all elements in 
// array strictly greater than X, so we will count all the good numbers according to the current value of p and store 
// in a variable cnt and we will keep updating our ans with value N-cnt (bad elements means numbers contributing to 
// make our total & smaller or equal to X), For better understanding dry run the given test case.

int count(int N, vector<int> A,int X){
   int p = 0, ans = N;
   for(int i=31; i >= 0; i--){
       int bit = (X>>i) & 1;
       if(bit == 1){
           p = p | (1<<i);
       }
       else{
           int temp = p | (1<<i);
           int cnt = 0;
           for(auto ele: A){
               if((ele&temp) == temp){
                   cnt++;
               }
           }
           
           ans = min(ans,N-cnt);
       }
   }
   return (ans);
}


//Second Solution :-
int count(int N, vector<int> A,int X){
    int ans = N;         //worstcase change all bits of all nos to 1
    int mask = 0;
    for(int i=30; i>=0; i--){
        if((X>>i)&1){
            mask ^= (1<<i);//these ones are compulsory to make atleast equal to X
            continue;
        }
        int alternate_mask = (mask^(1<<i)); //this alternate_mask is greater than X
        int cnt = 0;
        for(int j=0; j<N; j++){
            if((A[j]&alternate_mask) != alternate_mask){
                cnt += 1;//this no bit positions are to be changed
            }
        }
        ans = min(ans,cnt);
    }
    return ans;
}