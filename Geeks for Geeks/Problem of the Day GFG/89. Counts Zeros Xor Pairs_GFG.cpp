// Given an array A[] of size N. Find the number of pairs (i, j) such that
// Ai XOR Aj = 0, and 1 ≤ i < j ≤ N.

// Example 1:
// Input : arr[ ] = {1, 3, 4, 1, 4}
// Output : 2
// Explanation: Index( 0, 3 ) and (2 , 4 ) are only pairs whose xors is zero so count is 2.

// Example 2:
// Input : arr[ ] = {2, 2, 2} 
// Output :  3



//Solution Approach :-
long long int calculate(int a[], int n)
{
    unordered_map<int,int>mp;
    long long int ans = 0;
    for(int i=0;i<n;i++){
    	mp[a[i]]++;
    }
    
    for(auto it:mp){
    	if(it.second>1){
    		ans+=(it.second*(it.second-1))/2;
    	}
    }
    return ans;
}


//Second Approach :-  Without extra space
long long int calculate(int a[], int n)
{
    sort(a,a+n);
    long long int count=1,sum=0;
    for(int i=0;i<n-1;i++){
      if(a[i]==a[i+1])
       count++;
      else{
          sum+=(count-1)*count/2;
          count=1;
      }
    }
    sum+=(count-1)*count/2;   //this is for last count b/c it will never go to else part
    return sum;
}






