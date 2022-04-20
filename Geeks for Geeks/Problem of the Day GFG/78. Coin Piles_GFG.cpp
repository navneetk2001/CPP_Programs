There are N piles of coins each containing  Ai (1<=i<=N) coins. Find the minimum number of coins to be removed such that the absolute difference of coins in any two piles is at most K.
Note: You can also remove a pile by removing all the coins of that pile.

Example 1:
Input:
N = 4, K = 0
arr[] = {2, 2, 2, 2}
Output:
0
Explanation: For any two piles the difference in the number of coins is <=0. So no need to remove any coins. 

Example 2:
Input: N = 6, K = 3
arr[] = {1, 5, 1, 2, 5, 1} 
Output : 2
Explanation:
If we remove one coin each from both the piles containing 5 coins , then
for any two piles the absolute difference in the number of coins is <=3. 


// Here's the intuition 

// 1.If you could limit the numbers within a certain max and min , such that max-min is k , you can be sure k is the max diff btw any pair .Hence sorting is obvious .
// 2.Now after a little brain storming one may conclude that every arr[i] can be treated as the min , and its corresponding max is arr[i]+k ,check point 1.

// Under this assumption ,we have three regions ,
// unsafe1 [0,i-1]
// safe[i,point where element is arr[i]+k]
// unsafe2 [point where element is arr[i]+k,n]

// we are interested in reserving the safe and eliminating the unsafe r.
// 3.What's the best way to eliminate unsafe region ?
//   delete all ? won't give optimal ans ,right?
//   hence we replace all elements in that region unsafe 2 with arr[i]+k , 
//   the difference is what we need to remove .
  
//   and about the elements in region unsafe1 , those are of no use ,since 
//   safe region has atmost diff of k , so obviously if you push min to 
//   even more minimum , the gets diff>k .So simply eliminate these     elements.


//Solution Approach :- 
class Solution {
  public:
    int minSteps(int a[], int n, int k) {
      sort(a,a+n);
      int csum_till[n];
      memset(csum_till,0,sizeof(csum_till));

      for(int i=0;i<n;i++){    //Prefix Sum
          csum_till[i]=(i-1<0)?a[i]:csum_till[i-1]+a[i];
      }
      
      int ans=csum_till[n-1];
      for(int i=0;i<n;i++){
          int safe_till =upper_bound(a,a+n,a[i]+k)-a;
        
          int extras =(csum_till[n-1]-(safe_till-1<0?0:csum_till[safe_till-1])-(n-safe_till)*(a[i]+k));
          int on_left_can_t_exist_so_remove =i-1<0?0:csum_till[i-1];
          ans=min(ans,extras+ on_left_can_t_exist_so_remove);
      }
      return ans;
    }
};




//Second Approach :-
int minSteps(int arr[], int n, int k) {
    sort(arr, arr + n);    
    vector<int> prefix_sum(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(prefix_sum[i] >= ans)
	        return ans;
        
        int pos = upper_bound(arr + i + 1, arr + n, arr[i] + k) - arr;
        int actual_sum = prefix_sum[n] - prefix_sum[pos];
        int required_sum = (n - pos) * (arr[i] + k);
        int min_deletion = actual_sum - required_sum + prefix_sum[i];
        ans = min(ans, min_deletion);
    }
    
    return ans;
}


//Third Solution :-
class Solution {
  public:
    int minSteps(int a[], int n, int k) {
        sort(a, a+n);
        vector<int> pa(n+1, 0);
        
        for(int i=1; i<=n; i++)
            pa[i] = pa[i-1]+a[i-1];
            
        int res = 1e9;
        for(int i=0; i<n; i++) {
            int j = upper_bound(a,a+n,a[i]+k)-a;
            res = min(res, pa[i]+(pa[n]-pa[j]-(n-j)*(a[i]+k)));
        }
        
        return res;
    }
};