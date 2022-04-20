// Given two integers arrays A and B of size N each.
// Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

// Input 1:
//  A = [1, 4, 2, 3]
//  B = [2, 5, 1, 6]

// Input 2:
//  A = [2, 4, 1, 1]
//  B = [-2, -3, 2, 4]

// Output 1:
//  [10, 9, 9, 8]
// Output 2:
//  [8, 6, 6, 5]

// Explanation 1:
//  4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
// Explanation 2:
//  4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).


//Hint :-
Brute force is to find all combinations pair sum O(N Square) and return top N max elements.
Can Sorting Work better?

//Solution Approach :- 
Sort both the arrays in ascending order.
Let us take priority queue (heap).
First max element is going to be the sum of the last two elements of array A and B i.e. (A[n-1] + B[n-1]).
Insert that in heap with indices of both array i.e (n-1, n-1).
Start popping from heap (n-iterations).
And insert the sum (A[L-1]+A[R]) and (A[L]+B[R-1]).
Take care that repeating indices should not be there in the heap (use map for that).


//First Solution :-
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int, pair<int, int>>> pq;  // first int is the value itself, next 2 int are the position of val's constituent vals in A and B
    set<pair<int, int>> s; //  position of val's constituent vals in A and B :-> used to not allow repeat indices
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    pq.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    s.insert(make_pair(n-1, n-1));    // sum of last ele of A and B is largest. Push it
    
    vector<int> ans;
    int k = n; // we want only k ie. n elements in ans.
    while(k--){
        pair<int, pair<int, int>> top = pq.top(); 
        pq.pop();
        ans.push_back(top.first); // only the largest value 
        int L = top.second.first; // index of consitutent ele in A
        int R = top.second.second; // same but in B
        
        if(R>0 && L>= 0 && s.find(make_pair(L, R-1)) == s.end()){   // if this pair has not been created before
            pq.push(make_pair(A[L]+B[R-1], make_pair(L, R-1)));
            s.insert(make_pair(L,R-1));
        }

        if(R>=0 && L>0 && s.find(make_pair(L-1, R)) == s.end()){   // if this pair has not been created before
            pq.push(make_pair(A[L-1]+B[R], make_pair(L-1, R)));
            s.insert(make_pair(L-1,R));
        }
    }
    return ans;    
}


//Second Solution :-
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.rbegin() , A.rend());
    sort(B.rbegin() , B.rend());
    int n = A.size();
    
    priority_queue<tuple<int,int,int> > pq;
    for(int i=0; i<n; i++){
        pq.push({A[i] + B[0], i , 0});
    }
    vector<int> ans;
    while(n--)
    {
        auto [sum, i , j] = pq.top();
        pq.pop();
        ans.push_back(sum);
        pq.push({A[i] + B[j+1] ,i , j+1});
    }
    return ans;
}


//Third Solution :- 
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {     
    unordered_map<int,int> mp1,mp2;
    for(auto x:A)mp1[x]++;
    for(auto x:B)mp2[x]++;
    map<int,int>mp;
    vector<int> ans;
    for(auto x:mp1){
        for(auto y:mp2){
            int sum=x.first+y.first;
            int fre=min(x.second*1LL*y.second,1000000LL);
            mp[sum]+=fre;
        }
    }
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        if(ans.size()==A.size())break;
        for(int i=0;i<it->second;i++){
            ans.push_back(it->first);
            if(ans.size()==A.size())break;
        }
    }
    return ans;
}


