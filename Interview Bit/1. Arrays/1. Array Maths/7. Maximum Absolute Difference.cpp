// You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.

// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.


//Solution Approach
f(i, j) = |A[i] - A[j]| + |i - j| can be written in 4 ways (Since we are looking at max value, we don’t even care if the value becomes negative as long as we are also covering the max value in some way).

(A[i] + i) - (A[j] + j)
-(A[i] - i) + (A[j] - j) 
(A[i] - i) - (A[j] - j) 
(-A[i] - i) + (A[j] + j) = -(A[i] + i) + (A[j] + j)
Note that case 1 and 4 are equivalent and so are case 2 and 3.

We can construct two arrays with values: A[i] + i and A[i] - i. Then, for above 2 cases, we find the maximum value possible. For that, we just have to store minimum and maximum values of expressions A[i] + i and A[i] - i for all i.



//First Method :-
int Solution::maxArr(vector<int> &A) {
    int n=A.size();
   int max1=INT_MIN,max2=INT_MIN;
   int min1=INT_MAX,min2=INT_MAX;
   for(int i=0;i<n;i++)
   {
      max1=max(max1,A[i]+i);
      max2=max(max2,A[i]-i);
      min1=min(min1,A[i]+i);
      min2=min(min2,A[i]-i);  
   }
    return max(abs(max1-min1),abs(max2-min2));
}




//Second Method :-

 
    // int n=A.size();
    // int maxSum=0;
    // int currSum=0;    
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         currSum=abs(A[j]-A[i])+abs(j-i);
    //         maxSum=max(currSum,maxSum);
    //     }
    // }
    // return maxSum;