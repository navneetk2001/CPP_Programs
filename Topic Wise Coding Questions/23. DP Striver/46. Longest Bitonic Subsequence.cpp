https://www.codingninjas.com/codestudio/problem-details/longest-bitonic-sequence_1062688



//First Solution :- Tabulation
#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    
    vector<int> dp1(n,1);    //For i=0 to i=n-1
    for(int i=0; i < n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && 1 + dp1[j] > dp1[i]){
                dp1[i] = 1 + dp1[j];
            }
        }
    }
    
    vector<int> dp2(n,1);   //For i=n-1 to i=0
    for(int i=n-1; i >= 0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i] > arr[j] && 1 + dp2[j] > dp2[i]){
                dp2[i] = 1 + dp2[j];
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, dp1[i]+ dp2[i] -1);
    }
    return ans;
}