// You are given an array A having N integers.
// You have to perform the following steps in a given order.
// 1) generate all subarrays of A.
// 2) take the maximum element from each subarray of A and insert it into a new array G.
// 3) replace every element of G with the product of their divisors mod 1e9 + 7.
// 4 sort G in descending order

// You now need to perform Q queries
// In each query, you are given an integer K, where you have to find the Kth element in G.
// NOTE : Your solution will run on multiple test cases so do clear global variables after using them

//Hint 1
// A brute force solution to solve this problem is to do as instructed in the statement.
// But this will give time out.
// So can we reduce complexity?
// Can we do Binary Search for each query?
// do you know product of divisors of a number can be written as N D/2, where N is number and D is number of divisors of N.

//Solution Approach
// We can solve this problem by doing the binary search for each query.
// How?
// First, you need to find that how many times an element will appear in array G. i.e in how many subarrays an element is the greatest one.
// You can find that by finding the next greater element for the current element in both sides and then by multiplying them.
// Once you found the frequency of each element in an array G, you can sort the pairs(product_of_divisors_of_element, frequency) according to there value in descending order followed by taking the prefix sum of there frequencies you can do the binary search for each query.


// First Method :-
#define mod 1000000007
long long divisorProduct(int n) { 
    long long product = 1; 
    for(int i=1; i*i<=n; i++){ 
        if (n%i == 0){ 
            if (n/i == i) product = (product*i)%mod; 
            else{ 
                product = (product*i)%mod; 
                product = (product*(n/i))%mod; 
            } 
        } 
    } 
    return product; 
} 

bool compare(pair<int, long long> a, pair<int, long long> b){
    return a.first > b.first;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    vector<int> leftFreq(n, 1);
    vector<int> rightFreq(n, 1);
    for(int i=1; i<n; i++){
        int prev=i-1;
        while(prev>=0 && A[prev]<=A[i]){
            leftFreq[i] += leftFreq[prev];
            prev -= leftFreq[prev];
        }
    }
    for(int i=n-2; i>=0; i--){
        int next=i+1;
        while(next<n && A[next]<A[i]){
            rightFreq[i] += rightFreq[next];
            next += rightFreq[next];
        }
    }
    
    vector<pair<int, long long>> numFreq(n);
    for(int i=0; i<n; i++) numFreq[i] = {divisorProduct(A[i]), leftFreq[i]*rightFreq[i]};
    sort(numFreq.begin(), numFreq.end(), compare);
    vector<long long> cumFreq(n);
    cumFreq[0]=numFreq[0].second;
    for(int i=1; i<n; i++) cumFreq[i] = numFreq[i].second + cumFreq[i-1];
    
    vector<int> ans;
    for(int i=0; i<B.size(); i++){
        auto id=lower_bound(cumFreq.begin(), cumFreq.end(), B[i])-cumFreq.begin();
        ans.push_back(numFreq[id].first);
    }
    return ans;    
}


//Second Method :-

void put_max(vector<pair<int,int>> & v,int l,int r){
    long long mod = 1e9+7;
    stack<pair<int,int>> st;
    for(int i=l;i<=r;i++){
        while(st.size() && (v[i].first >= st.top().first)){
            st.pop(); 
        }
        v[i].second = st.empty() ? (i+1) : (i - st.top().second);
        st.push({v[i].first,i});
    }
    
    while(st.size())
        st.pop();
        
    for(int i=r;i>=l;i--){
        while(st.size() && v[i].first > st.top().first){
            st.pop();
        }
        int gt = r - i + 1;
        if(st.size()){
            gt = st.top().second - i;
        }
        v[i].second = (v[i].second * gt) % mod;
        st.push({v[i].first,i});
    }
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> v(A.size()),q;
    for(int i=0;i<A.size();i++){
        v[i] = {A[i],0};
    }
    put_max(v,0,A.size()-1);
    // for(auto & i:v){
    //     // cout << i.first << "," << i.second << " ";
    // }
    // cout << endl;
    long long mod = 1e9+7;
    int id = 1;
    for(auto & pr:v){
        int ele = pr.first;
        long long num=1;
        int i;
        for(i=1;i*i<ele;i++){
            if(ele%i==0){
                num = (num * i)%mod;
                num = (num * (ele/i))%mod;
            }
        }
        if((i*i)==ele)
            num = (num * i)%mod;
        pr.first = num;
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<B.size();i++){
        q.push_back({B[i],i});
    }
    sort(q.begin(),q.end());
    long long ind = 0,mind=v[0].second;
    for(auto & i:q){
        // cout << i.first << "," << i.second << " ";
        while(i.first > mind){
            mind+=v[++ind].second;
        }
        i.first = v[ind].first;
        swap(i.first,i.second);
    }
    // cout<< endl;
    sort(q.begin(),q.end());
    for(int i=0;i<B.size();i++){
        B[i] = q[i].second;
    }
    return B;
}



//Third Method :-
int lower_bound(vector<vector<long long int>>& arr,int search,int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid][1]<search) low=mid+1;
        else high=mid-1;
    }
    return low;
}
 
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int MOD=1000000007; 
    int n=(int) A.size();
 
  
    
    //2 find the no of subarray has max element A[i]
    vector<int> prev(n),next(n);
    stack<int> temp;
    for(int i=0;i<n;i++){
        while(!temp.empty() && A[temp.top()]<=A[i]) temp.pop();
        
        if(temp.empty()==true) prev[i]=-1;
        else prev[i]=temp.top();
        
        temp.push(i);
    }
    
    while(!temp.empty()) temp.pop();
    
    for(int i=n-1;i>=0;i--){
        while(!temp.empty() && A[temp.top()]<A[i]) temp.pop();
        if(temp.empty()==true) next[i]=n;
        else next[i]=temp.top();
        
        temp.push(i);
    }
    
    
    
     //3 find the divisor product
    int mx=*max_element(A.begin(),A.end());
    vector<int> proDiv(mx+1);
    for(int i=0;i<=mx;i++) proDiv[i]=i;
    
    for(int i=2;i<=mx;i++){
        for(int j=2*i;j<=mx;j+=i){
            proDiv[j]=((long long) proDiv[j]*i)%MOD;
        }
    }
    
 
    vector<vector<long long int>> arr(n);
    //fill the array with {divisor_product, count_of_element}
    for(int i=0;i<n;i++){
        arr[i]={proDiv[A[i]],(i-prev[i])*(next[i]-i)};
    }
    
    //4 sort in descending order according to divisor product
    sort(arr.begin(),arr.end(),greater<vector<long long int>>());
    
  
    // prefix sum count for binary search
    for(int i=1;i<n;i++)
     arr[i][1]+=arr[i-1][1];
     
    //query part 
    vector<int> ans;
    for(int val:B){
        //binary search based on count
        int index= lower_bound(arr,val,n);
        ans.push_back(arr[index][0]);
    }
    return ans;
}