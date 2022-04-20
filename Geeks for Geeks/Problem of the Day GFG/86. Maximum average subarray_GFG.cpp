Given an array Arr of size N and a positive integer K, find the sub-array of length K with the maximum average.

Example 1:
Input: K = 4, N = 6
Arr[] = {1, 12, -5, -6, 50, 3}
Output: 12 -5 -6 50
Explanation: Maximum average is (12 - 5 - 6 + 50)/4 = 51/4.

Example 2:
Input: K = 3, N = 7
Arr[] = {3, -435, 335, 10, -50, 100, 20}
Output: 335 10 -50
Explanation: Maximum average is (335 + 10 - 50)/3 = 295/3.




//Solution Approach :-
class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        int i=0,j=0,sum=0,maxm=INT_MIN,pos=-1;
        while(j<n){
            sum+=arr[j];
            if(j-i+1==k){
                if(sum>maxm){
                    maxm=sum;
                    pos=i;
                }
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return pos;
    }
};


//Second Solution :-
class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        int idx = 0, sum = 0, maxsum = 0;
        for(int i=0; i<k; i++)
            sum += arr[i];
        maxsum = sum;
        
        for(int i=k; i<n; i++) {
            sum += arr[i]-arr[i-k];
            if(sum > maxsum) {
                maxsum = sum;
                idx = i-k+1;
            }
        }
        
        return idx;
    }
};