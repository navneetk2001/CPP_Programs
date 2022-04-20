// Given two equally sized 1-D arrays A, B containing N integers each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum C valid sum combinations from all the possible sum combinations.

// Input 2:

//  A = [1, 4, 2, 3]
//  B = [2, 5, 1, 6]
//  C = 4

// Output 2:
//  [10, 9, 9, 8]
// Explanation 2:
//  10   (A : 4) + (B : 6)
//  9   (A : 4) + (B : 5)
//  9   (A : 3) + (B : 6)
//  8   (A : 3) + (B : 5)


//Hint :-
Sort both the arrays in increasing order and maintain a max heap.
Add last two elements in the heap and keep moving along the array from the back.

//Solution Approach :- 
Approach 1 (Naive Algorithm) :
We can use Brute force through all the possible combinations that can be made by taking one element from array A and another from array B and inserting them to a max heap. In a max heap maximum element is at the root node so whenever we pop from max heap we get the maximum element present in the heap. After inserting all the sum combinations we take out K elements from max heap and display it.
Time Complexity : O(N2)
This will not pass under given constraints.

Approach 2 (Sorting, Max heap, Map) :
Instead of brute forcing through all the possible sum combinations we should find a way to limit our search space to possible candidate sum combinations.
Sort both arrays array A and array B.
Create a max heap i.e priority_queue in C++ to store the sum combinations along with the indices of elements from both arrays A and B which make up the sum. Heap is ordered by the sum.
Initialize the heap with the maximum possible sum combination i.e (A[N – 1] + B[N – 1] where N is the size of array) and with the indices of elements from both arrays (N – 1, N – 1). The tuple inside max heap will be (A[N-1] + B[N – 1], N – 1, N – 1). Heap is ordered by first value i.e sum of both elements.
Pop the heap to get the current largest sum and along with the indices of the element that make up the sum. Let the tuple be (sum, i, j).
Next insert (A[i – 1] + B[j], i – 1, j) and (A[i] + B[j – 1], i, j – 1) into the max heap but make sure that the pair of indices i.e (i – 1, j) and (i, j – 1) are not
already present in the max heap. To check this we can use set in C++.
Go back to 4 until K times.
Time Complexity : O(NlogN) assuming C <= N


//First Solution :-
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<pair<int, pair<int, int>>> pq;  // first int is the value itself, next 2 int are the position of val's constituent vals in A and B
    set<pair<int, int>> s; //  position of val's constituent vals in A and B :-> used to not allow repeat indices
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    pq.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    s.insert(make_pair(n-1, n-1));    // sum of last ele of A and B is largest. Push it
    
    vector<int> ans;
    int k = C; // we want only k ie. n elements in ans.
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
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.rbegin() , A.rend());
    sort(B.rbegin() , B.rend());
    int n = A.size();
    priority_queue<tuple<int,int,int> > pq;
    for(int i=0; i<n; i++)
    {
        pq.push({A[i] + B[0], i , 0});
    }
    vector<int> ans;
    while(C--)
    {
        auto [sum, i , j] = pq.top();
        //cout<<sum<<endl;
        pq.pop();
        ans.push_back(sum);
        pq.push({A[i] + B[j+1] ,i , j+1});
    }
    return ans;
}


//Third Solution :- 
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
   int n=A.size();
    sort(A.begin(),A.end(),greater<int> ());
    sort(B.begin(),B.end(),greater<int> ());
    vector<int> S;
    
    int end=A[0]+B[0];
    int beg=A[n-1]+B[n-1];
    
    while(beg<end){
        int md=(beg+end+1)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum>=C) break;
            if(A[i]>=md){
                sum+=n;
                continue;
            }
            auto itr=lower_bound(B.rbegin(),B.rend(),md-A[i]);
            if(itr==B.rend()) break;
            sum+=(B.rend()-itr);
        }
        
        int check=(sum>=C);
        
        if(check==1) beg=md;
        else end=md-1;
        
    }
    
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i]+B[j]<beg) break;
            v.push_back(A[i]+B[j]);
        }
    }
    
    sort(v.begin(),v.end(),greater<int> ());
    return vector<int> (v.begin(),v.begin()+C);
}


//Fourth Solution :-
bool pred(int mid, vector<int>& a, vector<int>& b, int x)
{
    int cnt=0;
    for(int i=0; i<a.size();i++)
    {
        int el = a[i];
        cnt+=upper_bound(b.begin(),b.end(),mid-el,greater<int>())-b.begin();
    }
    // cout<<mid<<" "<<cnt<<endl;
    return cnt>=x;
}
vector<int> Solution::solve(vector<int> &a, vector<int> &b, int x) 
{
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int n=a.size();
    int lo = a[n-1]+b[n-1];
    int hi = a[0]+b[0];
    int mid; //guess for the lowest number
    while(hi-lo>3)
    {
        mid=lo+(hi-lo)/2;
        bool ax = pred(mid,a,b,x);
        bool bx = pred(mid+1,a,b,x);
        if(ax and !bx) goto done;
        if(ax) lo=mid;
        else hi=mid;
    }
    for(int i=hi; i>=lo;i--)
    {
        if(pred(i,a,b,x))
        {
            mid=i;
            goto done;
        }
    }
    done:
    vector<int> ans;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n;j++)
        {
            if(a[i]+b[j]<=mid) break;
            else ans.push_back(a[i]+b[j]);
        }
    }
    while(ans.size()!=x) ans.push_back(mid);
    sort(ans.begin(),ans.end(),greater<int>());
    return ans;
}

