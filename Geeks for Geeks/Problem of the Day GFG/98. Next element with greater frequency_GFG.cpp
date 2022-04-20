// Given an array arr[ ] of n integers, for every element, find the closest element on it's right that has a greater frequency than its own frequency.
// Frequency is the number of times the element appears in the array.

// Example 1:
// Input:
// n = 6
// arr[] = {2 1 1 3 2 1}
// Output: 1 -1 -1 2 1 -1 
// Explanation:
// 1 appears 3 times.
// 2 appears 2 times.
// 3 appears 1 time. 
// For arr[0] ie, 2 arr[1] ie 1 is the closest element on its right which has greater frequency than the frequency of 2. For the arr[1] and arr[2] no element 
// on the right has greater frequency than 1, so -1 will be printed. and so on. 

// Example 2:
// Input:
// n = 10
// arr[] = {5 1 2 3 2 5 5 4 5 2}
// Output: -1 2 5 2 5 -1 -1 5 -1 -1



//Solution Approach :-
vector<int> print_next_greater_freq(int arr[],int n){
   unordered_map<int,int> m;
   for(int i=0; i<n; i++){
   	m[arr[i]]++;
   }

   stack<int> st;

   vector<int> ans(n);
   for(int i=n-1; i>=0; i--){
       while(!st.empty() && m[st.top()] <= m[arr[i]]){
           st.pop();
       }
       if(st.empty()){ 
       	ans[i] = -1;
       }
       else{ 
       	ans[i] = st.top();
       }
       st.push(arr[i]);
   }
   return ans;
}


//Second Solution :-
class Solution{
public:
   vector<int> print_next_greater_freq(int arr[],int n)
   {
       unordered_map<int,int> hash;  
       for(int i = 0; i < n; ++i) {
           hash[arr[i]]++; 
       }
       stack<pair<int,int>> st; 
       vector<int> result;  
       
       for(int i = n-1; i >= 0; --i) {
           if(st.empty()) {
               result.push_back(-1);  
           }else{ 
               while(!st.empty() && st.top().second <= hash[arr[i]]) {
                   st.pop();
               }
               if(st.empty()) {
                   result.push_back(-1);
               }else {
                   result.push_back(st.top().first);  
               }
           }
           st.push({arr[i], hash[arr[i]]}); 
       }
       reverse(result.begin(), result.end()); 
       return result; 
   }
};


