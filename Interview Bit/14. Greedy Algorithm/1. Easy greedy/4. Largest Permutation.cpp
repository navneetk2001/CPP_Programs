// Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.
// Return the largest lexicographical value array that can be created by executing atmost B swaps.

// Input 1:
//  A = [1, 2, 3, 4]
//  B = 1

// Output 1: [4, 2, 3, 1]
// Explanation 1: In one swap we can swap (1, 4) so that the array becomes : [4, 2, 3, 1].

// Input 2:
//  A = [3, 2, 1]
//  B = 2

// Output 2: [3, 2, 1]
// Explanation 2: Array is already the largest lexicographical value array.


//Hint :-
// The key point is to observe the answer. If we have B swaps, what does the starting of the permutation look like?
// The permutation starts with N for sure and continues with (n-1), (n-2), …, (n-B+1).
// Use greedy approach to make the largest lexicographical value array.

//Solution Approach :- 
// The key point is to observe the answer. If we have B swaps, what does the starting of the permutation look like?
// The permutation starts with N for sure and continues with (n-1), (n-2), …, (n-B+1).
// The best permutation we can make by making B swaps is by putting the B largest elements at the begining of the permutation in decreasing order.
// We can simply store the index of each element in an auxillary array let’s say idx and with each iteration if at ith position, A[i] = N-i (i stating from 0)then we need not to swap that value, else make a swap and update the index array(idx) accordingly.
// Do this atmost B times, if there are no more swaps return the largest array till now.


//First Solution :-
vector<int> Solution::solve(vector<int> &A, int B) {
    map<int,int>m;
    for(int i=0;i<A.size();i++){
        m[A[i]]=i;
    }
    
    int i=0;
    while(i<A.size() && B){
        int x=A.size()-i;
        if(A[i]==x){
            i++;
            continue;
        }
        int loc=m[x];
        m[A[i]]=loc;
        swap(A[i],A[loc]);
        i++,B--;
    }
    return A;
}

//Second Solution :-
vector<int> Solution::solve(vector<int> &A, int B) {
    int j = 0, N = A.size(), swaps = 0;
    vector<int> idx(N + 1, 0);
    for(int i = 0; i < N; i++) {
        idx[A[i]] = i;
    }
    while(swaps < B && j < A.size()) {
        if(A[j] != N - j) {
            swap(A[j], A[idx[N - j]]);
            swap(idx[A[j]], idx[A[idx[N - j]]]);
            swaps++;
        }
        j++;
    }
    return A;
}



//Third Solution :- 
void swap(int *a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
vector&lt;int&gt; Solution::solve(vector&lt;int&gt; &amp;A, int B) {
    int N = A.size();
    int n = N;
    vector&lt;int&gt; res;
    int sCount = 0;
    // int iit = 0;
    for(int i=0;i&lt;A.size();i++){
        // if(sCount == B &amp;&amp; iit == 0) iit = i;
        if(sCount &lt; B){
            res.push_back(n);
            int ind = i;
            while(A[ind] &gt;= n){
                if(A[ind] == n) break;
                ind = N - A[ind];
            }
            if(A[ind] &lt; n) sCount++;
            n--;
        }else{
            if(A[i] &gt; n){
                int ind = N - A[i];
                while(A[ind] &gt; n){
                    ind = N - A[ind];
                }
                res.push_back(A[ind]);
            }else{
                res.push_back(A[i]);
            }
        }
    }
    // cout&lt;&lt;iit&lt;&lt;", "&lt;&lt;sCount&lt;&lt;", "&lt;&lt;n&lt;&lt;endl;
    return res;
}

    // int count = 0;
    // for(int j=0;j&lt;A.size()-1 &amp;&amp; count &lt; B;j++){
    //     int max = INT_MIN;
    //     int maxInd = -1;
    //     for(int i=j;i&lt;A.size();i++){
    //         if(max &lt;= A[i]){
    //             max = A[i];
    //             maxInd = i;
    //         }
    //     }
    //     if(maxInd == j) continue;
    //     swap(&amp;A[j],&amp;A[maxInd]);
    //     count++;
    // }




