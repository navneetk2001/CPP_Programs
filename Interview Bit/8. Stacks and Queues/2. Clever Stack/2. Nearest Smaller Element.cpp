// Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
// More formally,
//     G[i] for an element A[i] = an element A[j] such that 
//     j is maximum possible AND 
//     j < i AND
//     A[j] < A[i]
// Elements for which no smaller element exist, consider next smaller element as -1.

// Input 1:
//     A = [4, 5, 2, 10, 8]
// Output 1:
//     G = [-1, 4, -1, 2, 2]
// Explaination 1:
//     index 1: No element less than 4 in left of 4, G[1] = -1
//     index 2: A[1] is only element less than A[2], G[2] = A[1]
//     index 3: No element less than 2 in left of 2, G[3] = -1
//     index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
//     index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]

//Hint :-
Naive Solution O(N^2)

A naive solution would be to take a nested loop, and for every element keep iterating back till we find a smaller element.
This can be O(N^2) in worst case.
Better solution hint
The naive solution would look something like :
  for i = 0 to size(A):
    G[i] = -1
    for j = i - 1 to 0:
        if A[j] < A[i]:
            G[i] = A[j]
            break
Now look at A[i-1]. All elements with index smaller than i - 1 and greater than A[i-1] are useless to us because they would never qualify for G[i], G[i+1], ...
Can you use the above fact to come up with a solution ?
Hint : Stack

//Solution Approach :-
// 1) Create a new empty stack st
// 2) Iterate over array `A`,
//    where `i` goes from `0` to `size(A) - 1`.
//     a) We are looking for value just smaller than `A[i]`. So keep popping from `st` till elements in `st.top() >= A[i]` or st becomes empty.
//     b) If `st` is non empty, then the top element is our previous element. Else the previous element does not exist. 
//     c) push `A[i]` onto st


//First Solution :-
vector<int> Solution::prevSmaller(vector<int> &arr) {
    vector<int>near_small_ele;  //to store neaest smaller elements to the left
    stack<int>st;               //stack to traverse the array
    for(int i=0;i<arr.size();i++){
        if(st.size()==0){       // if stack is empty, means there is no smaller element to the left
            near_small_ele.push_back(-1);
        }
        else if(st.size()>0 && st.top()<arr[i]){   //if nearest smaller element in the left, store it in the vector
            near_small_ele.push_back(st.top());
        }
        else if(st.size()>0 && st.top()>=arr[i]){  //if not found
            while(st.size()>0 && st.top()>=arr[i]){
                st.pop();
            }
            if(st.size()==0){
                near_small_ele.push_back(-1);
            }
            else{
                near_small_ele.push_back(st.top());
            }
        }
        st.push(arr[i]);    //push all elements in the stack
    }
    return near_small_ele;
}

//Second Solution :-
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans;
    ans.resize(A.size());

    stack<int> st;
    
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) st.pop();
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}


//Third Solution :- Using-Only-Map
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int,int> mp;
    vector<int> result;
    for(int i=0;i<A.size();i++) mp[A[i]]=1;
    for(int i=0;i<B.size();i++){
        if(mp.count(B[i])){
            if(mp[B[i]]==1) mp[B[i]]=4;
        }
        else mp[B[i]]=2;
    }
    for(int i=0;i<C.size();i++){
        if(mp.count(C[i])){
            if(mp[C[i]]==2 || mp[C[i]]==1) mp[C[i]]=4;
        }
        else mp[C[i]]=3;
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        if(i->second==4) result.push_back(i->first);
    }
    return result;
}

//Fourth S0lution :- Very easy simplle brute force approch using left max array and right min array
int Solution::perfectPeak(vector<int> &A) {
    vector<int>l;
    l.push_back(A[0]);
    int prev=A[0];
    for(int i=1;i<A.size();i++)
    {
       if(prev<A[i])
       {
           prev=A[i];
       }
       l.push_back(prev);
    }
    int n=A.size();
    vector<int> r;
    r.push_back(A[n-1]);
    prev=A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(prev>A[i])
        prev=A[i];
        r.push_back(prev);
    }
    reverse(r.begin(),r.end());
    for(int i=1;i<n-1;i++)
    {
        if(A[i]>l[i-1]&&A[i]<r[i+1])
        return 1;
    }
    return 0;
}
