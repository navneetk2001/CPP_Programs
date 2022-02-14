Given an array arr[] of N weights. Find the least weight capacity of a boat to ship all weights within D days.
The ith weight has a weight of arr[i]. Each day, we load the boat with weights given by arr[i].We may not load more weight than the maximum weight capacity of the ship.

Note: You have to load weights on the boat in the given order.
Example 1:
Input:
N = 3
arr[] = {1, 2, 1}
D = 2
Output:
3
Explanation:
We can ship the weights in 2 days
in the following way:-
Day 1- 1,2
Day 2- 1

Example 2:
Input:
N = 3
arr[] = {9, 8, 10}
D = 3
Output:
10
Explanation:
We can ship the weights in 3 days
in the following way:-
Day 1- 9
Day 2- 8
Day 3- 10


bool isPossible(int A[], int N, int mid, int B){
    int d=1;  //No.of days required
    int sum=0;  
    for(int i=0;i<N;i++){
        sum+=A[i];

        if(sum>mid){
            d++;
            sum=A[i];
        }
    }
    return d<=B;
}

class Solution {
  public:
    int leastWeightCapacity(int A[], int N, int B) {
        int mx=0;
        int sum=0;
    
        for(int i=0;i<N;i++){
            sum+=A[i];
            mx=max(A[i],mx);
        }
    
        if(N==B){
            return mx;
        }
    
        int lo=mx;
        int hi=sum;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
    
            if(isPossible(A,N,mid,B)==true){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};