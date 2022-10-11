https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/




//Time Complexity : O(n)
//Auxiliary Space : O(1)
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i=0;
        int j=0;
        long sum=0;
        long mx=INT_MIN;
        
        while(j<N){
            sum += Arr[j];             // do calculation to reduse tc
            if(j-i+1 < K){             //window size :- j-i+1
                j++;                   // increament j upto when the size of the size of window is not equal to required size
            }
            else if ((j-i+1) == K){    // when sindow size hit to the required window size
                mx = max(mx, sum);     // selecting ans from the candidates
                sum -= Arr[i];         // start removing from the first
                i++;
                j++;
            }
        }
        return mx;
    }
};





//Second Solution :-
long maximumSumSubarray(int K, vector<int> &Arr , int N){
       if(N==1) return Arr[0];
       
       long long curr_sum=0,max_sum=0;
       
       for(int i=0;i<K;i++){
           curr_sum+=Arr[i];
       }
       
       int i=0,j=i+K;
       
       while(i<=N-K){
           if(curr_sum>max_sum){
               max_sum=curr_sum;
           }
           curr_sum=curr_sum-Arr[i]+Arr[j];
           i++;
           j++;
       }
       return max_sum;

}