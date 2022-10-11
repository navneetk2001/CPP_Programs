https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1



//Solution Approach :-
bool isKPartitionPossible(int a[], int n, int k){
    sort(a, a+n);
    
    int sum=0; 
    for(int i=0; i<n; i++){
    	sum += a[i];
    }
    
    if(sum % k != 0){
    	return false;
    }

    sum=sum/k;     //target sum
   
    for(int i=1; i<=k; i++){
        int cur = 0;
        for(int i=n-1; i>=0; i--){
            if(a[i] + cur <= sum){
                cur += a[i];
                a[i] = 0;
            }
            
            if(cur == sum){
            	break;
            }
        }
        if(cur < sum){
        	return false;
        }
    }
   return true;
}



//Second Solution :-
class Solution{
    bool solve(int a[],int n,vector<int> &groups,int sum){
        if(n < 0){
            return true;
        }
        for(int i=0; i<groups.size(); i++){
            if(groups[i] + a[n] > sum){
                continue;
            }
            groups[i] += a[n];
            if(solve(a,n-1,groups,sum)){
                return 1;
            }
            groups[i]-=a[n];    //backtrack
        }
        return false;
    }
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum=accumulate(a,a+n,0);
        if(sum%k!=0){
            return false;
        }
        sum/=k;
        vector<int> groups(k,0);
        return solve(a,n-1,groups,sum);
    }
};


//Third Solution :-
bool helper(int sum, int s, int k, bool arr[], int ind, int n, int a[]){
    if(k == 1){
        return true;
    }
    if(sum > s){
        return false;
    }
    if(sum == s){
        return helper(0, s, k - 1, arr, 0, n, a);
    }
    for(int i  = ind;i < n ; i ++){
        if(arr[i] == false){
            arr[i] = true;
            if(helper(sum + a[i],s,k,arr,i + 1,n,a)){
                return true;
            }
            else{
            	arr[i] = false;
            }
        }
    }
    return false;
}

bool isKPartitionPossible(int a[], int n, int k){
    if(k == 0){
        return 0;
    }
    if(k == 1){
        return 1;
    }
    int sum = 0;
    for(int i = 0; i < n ; i ++){
        sum += a[i];
    }

    if(sum % k != 0){
    	return false;
    }
    bool arr[n] = {false};
    
    return helper(0, sum/k, k, arr, 0, n, a);
}



//Fourth Solution :-
int subsetSum[11];
   
bool helper(int a[],int n,int ind,int k){
   if(ind == n){
       for(int i = 1; i < k; i++){
           if(subsetSum[i] != subsetSum[i-1]) return (false);
       }
       return (true);
   }
   
   for(int i = 0; i < k; i++){
       if(subsetSum[i]){
           subsetSum[i] += a[ind];
           if(helper(a,n,ind+1,k)){
               return (true);
           }
           subsetSum[i] -= a[ind];}
       else{
           subsetSum[i] += a[ind];
           if(helper(a,n,ind+1,k)){
               return (true);
           }
           subsetSum[i] -= a[ind];
           break;
       }
   }
   
   return (false);
}

bool isKPartitionPossible(int a[], int n, int k){
   if(k <= 0 || k > n) return (false);
   if(k == 1) return (true);
   
   int sum = 0;
   for(int i = 0; i < n; i++)
       sum += a[i];
   
   if(sum % k) return (false);
   
   for(int i = 0; i < k; i++){
       subsetSum[i] = 0;
   }
   return helper(a,n,0,k);
}



//Fifth Solution :- Dp Solution
class Solution{
 public:
   bool isKPartitionPossible(int a[], int n, int k)
   {
        int range=0; // variable to store the sum of all array elements
        for(int i=0; i<n; ++i) range+=a[i];
        int sum = range/k; // 'sum' here is the target sum for the array
        
        int* x = max_element(a, a+n);
        if(*x>sum) return false; // largest array element cannot be larger than target sum
        if(range%k!=0) return false; // target sum must be an integer
        if(k==1) return true;
        else{
           int dp[n+1][sum+1]; // can be of bool type
           for(int j=0; j<=sum; ++j){
               dp[0][j]=0;
           }
           for(int i=0; i<=n; ++i){
               dp[i][0]=1;
           }
           // dp logic is similar to equal sum partition problem
           for(int i=1; i<=n; ++i){
               for(int j=1; j<=sum; ++j){
                   if(a[i-1]<=j){
                       if(dp[i-1][j] || dp[i-1][j-a[i-1]]){
                           dp[i][j]=1;
                       }
                       else{
                           dp[i][j]=0;
                       }
                   }
                   else{
                       dp[i][j]=dp[i-1][j];
                   }
               }
           }
           if(dp[n][sum]) return true;
           else return false;
        }
   }
};   
