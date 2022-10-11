The king of Geekland has ordered to build a Colosseum for fighting. 

For the inauguration fight, he asks his minister to bring in 3*N fighters. Each fighter is denoted by a roll number from 1 to 3*N. An array A of length 3*N is given such that ith element denotes the strength of the fighter with ith roll number.

// From these fighters, N fighters will be removed. The remaining 2*N will be divided into two groups based on their roll numbers. N fighters with the smallest roll numbers will be put in group1 and the N fighters with the largest roll numbers will be group2. The two groups will then fight each other.
// Let the total sum of the strength of group1 be S1 and the total sum of the strength of group2 be S2. The fight will be interesting if S1 - S2 is as large as possible. Find the maximum value of S1 - S2.

// Example 1: 
// Input:
// N = 2
// A[] = {1, 3, 5, 2, 1, 1}
// Output: 6
// Explanation: Fighter 1 and 4 will be removed. Then S1=(3+5)=8 and S2=(1+1)=2. s1-s2 = 8-2 = 6.

// Example 2: 
// Input:
// N = 2
// A[] = {1, 1, 5, 3, 7, 7}
// Output: -4 
// Explanation: The best way is to remove Fighter 1 and 5. S1 - S2 = (1+5) - (3+7) = -4.




//Solution Approach :-
long long colosseum(int N,vector<int> A) {
    int n = A.size();
    
    // find possible s1 and s2 in array A
    long long prefixMaxS1[n];
    long long suffixMinS2[n];
    
    priority_queue<int, vector<int>, greater<int>> pq1;
    long long sum = 0;
    
    for(int i = 0; i < n; i++){
        if(pq1.size() < N){
            pq1.push(A[i]);
            sum += A[i];
        }
        else if(pq1.size() == N && pq1.top() < A[i]){
            sum -= pq1.top();
            pq1.pop();
            pq1.push(A[i]);
            sum += A[i];
        }
        prefixMaxS1[i] = sum;
    }
    
    //similarly fill suffixMinS2
    priority_queue<int> pq2;
    sum = 0;
    
    for(int i = n-1; i >= 0; i--){
        if(pq2.size() < N){
            pq2.push(A[i]);
            sum += A[i];
        }
        else if(pq2.size() == N && pq2.top() > A[i]){
            sum -= pq2.top();
            pq2.pop();
            pq2.push(A[i]);
            sum += A[i];
        }
        suffixMinS2[i] = sum;
    }
    
    // Now check all possible s1 and s2;
    long long maxi = -1e18;
    for(int i = N-1; i < n-N ; i++ ){  // i = N-1 means one side has N elements onlythat is must
        long long d = prefixMaxS1[i] - suffixMinS2[i + 1];
        maxi = max(maxi, d);
    }
    return maxi;
}





//Second Solution :-
 long long colosseum(int N,vector<int> A) {
       
      priority_queue<long long,vector<long long>,greater<long long>> pq;
      vector<long long>prefMax;
      long long sum = A[0];
      pq.push(A[0]);
      for(int i=1;i<2*N;i++)
      {
         if(pq.size() < N) {
             sum+=A[i];
             pq.push(A[i]);
         }
         else if(pq.size() == N && pq.top() < A[i]) {
             sum-=pq.top();
             pq.pop();
             pq.push(A[i]);
             sum+=A[i];
         }
         
         if(pq.size() == N) {
             prefMax.push_back(sum);
         }
         
      }
      
      vector<long long> suffixMin;
      sum = A[3*N-1];
      priority_queue<long long > pq2;
      pq2.push(sum);
      for(int i=3*N-2;i >= N;i--)
      {
         if(pq2.size() < N) {
             sum+=A[i];
             pq2.push(A[i]);
         }
         else if(pq2.size() == N && pq2.top() > A[i]) {
             sum-=pq2.top();
             pq2.pop();
             pq2.push(A[i]);
             sum+=A[i];
         }
         if(pq2.size() == N) {
             suffixMin.push_back(sum);
         }
         
      }
      
      long long ans = INT_MIN;
      int prefixIndex = 0;
      int suffixIndex = suffixMin.size()-1;
      while(prefixIndex < prefMax.size() && suffixIndex >= 0)
      {
          long long curr_ans = prefMax[prefixIndex]-suffixMin[suffixIndex];
          ans = max(ans,curr_ans);
          prefixIndex++;
          suffixIndex--;
      }
      
      return ans;
    
   }


//Third Solution :- Official GFG
class Solution {
public:
   long long colosseum(int N, vector<int> a) {

      vector<long long> L(N * 3 + 1), R(N * 3 + 1); // create 
      for (int i = 0; i <= 3 * N; ++i) {
         L[i] = -1e18, R[i] = 1e18;
      }

      priority_queue<long long, vector<long long>, greater<long long> > minHeap;

      long long sum = 0;
      for (int i = 0; i < 3 * N; ++i) {
         minHeap.push(a[i]);// push in queue untill the priority_queue size is less than or equal to N
         sum += a[i];
         if(minHeap.size() > N) { // now pop the top of priority_queue if size exceed 
            long long v = minHeap.top();
            minHeap.pop();
            sum -= v;
         }
         if(minHeap.size() == N) L[i + 1] = sum;
      }

      priority_queue<long long> maxHeap;
      sum = 0;
      for (int j = 0; j < 3 * N; ++j) { // same thing we will do here from back
         int i = 3 * N - 1 - j;
         maxHeap.push(a[i]);
         sum += a[i];
         if(maxHeap.size() > N) {
            long long v = maxHeap.top();
            maxHeap.pop();
            sum -= v;
         }
         if(maxHeap.size() == N) R[j + 1] = sum;
      }

      long long ans = -1e18;
      // iterate over L and R and find the maximum possible value
      for (int a = 0; a <= 3 * N; ++a) {
         int b = 3 * N - a;
         ans=max(ans,L[a] - R[b]);
      }
      return ans;
   }
};