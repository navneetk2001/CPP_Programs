https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=3



//First Solution :- 
#include<bits/stdc++.h>
int solve(vector<int>&a,int n){
    int ans=0;
    vector<int> ls(n);
    vector<int> rs(n);

    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(s.empty()){
            ls[i]=0;
        }
        else{
            ls[i]=s.top()+1;
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(s.empty()){
            rs[i]=n+1;
        }
        else{
            rs[i]=s.top()+1;
        }
        s.push(i);
    }

    for(int i=0;i<n;i++){
        ans=max(ans,(rs[i]-ls[i]-1)*a[i]);
    }
    return ans;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    int ans=0;
    vector<int> a(m);
    for(int i=0;i<m;i++){
        a[i]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                a[j]=0;
            }
            else{
                a[j]+=mat[i][j];
            }
        }
        int k = solve(a,m);
        ans = max(ans,k);
    }
    return ans;
}




//Second Solution :-
#include<bits/stdc++.h>
vector<int> leftSmallestIndex(vector<int>&arr, int n){
    vector<int> ans(n);
    stack<pair<int,int>>stk;
    
    for(int i=0; i<n; ++i){
        int x = arr[i];
        if(stk.empty()){
            ans[i] = -1;
        }
        else{
            while((!stk.empty()) && stk.top().first >= arr[i]){
                stk.pop();
            }
            
            if(stk.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = stk.top().second;
            }
        }
        stk.push(make_pair(x, i));
    }
    return ans;
}

vector<int> rightSmallestIndex(vector<int>&arr, int n){
    vector<int> ans(n);
    stack<pair<int,int>> stk;
    
    for(int i=n-1; i>=0; i--){
        if(stk.empty()){
            ans[i] = n;
        }
        else{
            while((!stk.empty()) && stk.top().first >= arr[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = stk.top().second;
            }
        }
        stk.push(make_pair(arr[i], i));
    }
    return ans;
}

int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    vector<int> leftIdx(n), rightIdx(n), width(n), area(n);
    
    leftIdx = leftSmallestIndex(arr, n);
    rightIdx = rightSmallestIndex(arr, n);
    
    for(auto i=0; i<n; ++i){
        width[i] = rightIdx[i] - leftIdx[i] - 1;
    }
    for(auto i=0; i<n ; ++i){
        area[i] = width[i] * arr[i];
    } 

    int ans = *max_element(area.begin(),area.end());
    return ans;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    vector<int> ans;
    vector<int> hist(m, 0);
    
    for(auto arr :mat){
        for(auto i=0; i< m; ++i){
            if(arr[i]){
                hist[i] += 1;
            }
            else{
                hist[i] = 0;
            }
        }
        ans.push_back(largestRectangleArea(hist));
    }
    return *max_element(ans.begin(),ans.end());
}