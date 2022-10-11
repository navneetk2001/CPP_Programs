https://www.codingninjas.com/codestudio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- For Printing Purpose  
//Using the Code of LIS

#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    
    vector<int> dp(n,1), hash(n);
    int lastIndex = 0;
    int maxi = 1;   //store maximum ans

    for(int i=0; i < n; i++){
        hash[i] = i;
        for(int prev=0; prev<i; prev++){
            if(arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(),ans.end());

    return ans;
}