https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//First Solution :- Tabulation
//Using the Code of LIS

#include<bits/stdc++.h>
bool checkPossible(string &s1, string &s2){
    if(s1.size() != s2.size()+1) return false;
    int first = 0, second = 0; 
    while(first < s1.size()){
        if(s1[first] == s2[second]){
            first++, second++;
        }
        else{
            first++;
        }
    }
    if(first == s1.size() && second == s2.size()){
        return true;
    }
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end(),comp);
    
    vector<int> dp(n,1);
    int maxi = 1;       //store maximum ans

    for(int i=0; i < n; i++){
        for(int j=0; j<i; j++){
            if(checkPossible(arr[i], arr[j]) && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    
    return maxi;
}



// Approch 2 - Using Unordered MAP to keep the track of every string after removing exactly one character
class Solution {
public:
    static bool comp(string &a,string &b){
        return (a.size()<b.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);

        unordered_map<string,int>m;
        int c = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                string t = words[i].substr(0,j) + words[i].substr(j+1);
                if(m.find(t)!=m.end()){
                    m[words[i]] = max(m[words[i]],m[t]+1);
                }
                else{
                    m[words[i]] = max(m[words[i]],1);
                }
            }
            c = max(c,m[words[i]]);
        }
        return c;
    }
};




//Third Solution :- BFS
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        queue<pair<string,int>> q;
        unordered_map<string,int> map1;
        for(auto itr :words)
        {
            q.push({itr,1});
            map1[itr]=1;
        }
        unordered_set<string> s1(words.begin(),words.end());
        int res=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto p1=q.front();
                q.pop();
                res=max(res,p1.second);
                string s=p1.first;
                for(int j=0;j<s.length();j++)
                {
                    string temp=s;
                    temp.erase(temp.begin()+j,temp.begin()+j+1);
                    if(s1.find(temp)!=s1.end() && p1.second+1>map1[temp])
                    {
                        q.push({temp,p1.second+1});
                        map1[temp]=p1.second+1;
                    }
                }
            }
        }
        return res;
    }
};