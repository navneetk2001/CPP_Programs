https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Tabulation
#include<bits/stdc++.h>
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp1(n,1), cnt(n,1); 

    int maxi = 1;   
    for(int i=0; i < n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && 1 + dp1[j] > dp1[i]){
                dp1[i] = 1 + dp1[j];
                cnt[i] = cnt[j];
            }
            else if(arr[i] > arr[j] && 1 + dp1[j] == dp1[i]){
                cnt[i] += cnt[j];
            }
        }
        maxi = max(maxi, dp1[i]);
    }

    int num = 0;
    for(int i=0;i<n;i++){
        if(dp1[i] == maxi){
            num += cnt[i];
        }
    }
    
    return num;
}