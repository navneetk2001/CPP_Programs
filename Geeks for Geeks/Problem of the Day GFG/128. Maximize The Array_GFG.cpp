// Given two integer arrays Arr1 and Arr2 of size N. Use the greatest elements from the given arrays to create a new array of size N such that it consists of only unique elements and the sum of all its elements is maximum.
// The created elements should contain the elements of Arr2 followed by elements of Arr1 in order of their appearance.


// Example 1:
// Input:
// N = 5
// Arr1 = {7, 4, 8, 0, 1}
// Arr2 = {9, 7, 2, 3, 6}
// Output: 9 7 6 4 8
// Explanation: 9, 7, 6 are from 2nd array and 4, 8 from 1st array.

// Example 2:
// Input: N = 4
// Arr1 = {6, 7, 5, 3}
// Arr2 = {5, 6, 2, 9} 
// Output: 5 6 9 7 
// Explanation: 5, 6, 9 are from 2nd array and 7 from 1st array.



//Solution Approach :-
class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
        set<int> st;
        for(int i =0;i<n;i++){
            st.insert(arr2[i]);
            st.insert(arr1[i]);
        }
        
        while(st.size() > n){
            st.erase(st.begin());
        }
        
       vector<int> ans;
       for(int i =0;i<n;i++){
           if(st.find(arr2[i]) != st.end()){
               auto pos = st.find(arr2[i]);
               st.erase(*pos);
               ans.push_back(arr2[i]);
               
           }
       }
       for(int i =0;i<n;i++){
           if(st.find(arr1[i]) != st.end()){
                auto pos = st.find(arr1[i]);
               st.erase(*pos);
               ans.push_back(arr1[i]);
           }
       }
       return ans;
    }
};



//Second Solution :- 
class Solution {
    static bool comp(pair<int,int> &p1,pair<int,int> &p2)
    {
        return p1.second<p2.second;
    }

public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
        set<int> s;
        int i;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(i=0;i<n;i++){
            if(s.find(arr2[i])==s.end()){
                pq.push({arr2[i],i});
                s.insert(arr2[i]);
            }
        }

        for(i=0;i<n;i++){
            if(s.find(arr1[i])==s.end()){
                pq.push({arr1[i],n+i});
                s.insert(arr1[i]);
            }
            if(pq.size()>n) pq.pop();
        }
        
        vector<int> ans;
        vector<pair<int,int>> v;
        while(!pq.empty())
        {
            v.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        
        sort(v.begin(),v.end(),comp);
        for(i=0;i<v.size();i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};