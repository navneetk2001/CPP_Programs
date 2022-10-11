// You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:
// LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
// RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
// Write a program to find the maximum special product of any integer in the array.
// NOTE:  As the answer can be large, output your answer modulo 10^9 + 7.

// Input 1:
//  A = [1, 4, 3, 4]
// Output 1:
//  3

// Input 2:
//  A = [10, 7, 100]
// Output 2:
//  0

//Hint :-
// We need to solve only one of the task of calculating LeftSpecialValue.
// RightSpecialValue calculation will follow similar approach.
// Try to think with the help of stack. How can you process every element such that it is being pushed and popped out of stack at max one time?

//Solution Approach :-
// Ok, lets try to calculate LeftSpecialValue.

// Lets make a stack A.
// We will keep elements in strictly decreasing order in stack A.
// When processing the ith element remove all the elements from the stack which have value less than or equal to ith element.
// Now whatever element will remain at the top of index will give the index corresponding to LeftSpecialValue. If no element is at top then take it as 0.
// Push ith element in stack A now.
// You can see each element is pushed and popped for atmax one time. Hence the solution runs in O(n) time.
// Do the similar thing for RightSpecialValue.


//First Solution :-
int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<long long> prod(A.size());
    prod[0] = 0;
    prod[n-1] = 0;
    
    //Left Greater Element
    stack<pair<int,int>> s;
    s.push({A[0],0});
    for(int i=1;i<n-1;i++){
        while(!s.empty() && s.top().first <= A[i]){
            s.pop();
        }
        if(s.empty()){
            prod[i] = 0;
            s.push({A[i],i});
        }
        else{
            prod[i] = s.top().second;
            s.push({A[i],i});
        }
    }
    
    //Right Greater Element
    stack<pair<int,int>>().swap(s);
    s.push({A[n-1],n-1});
    for(int i=n-2;i>0;i--){
        while(!s.empty() && s.top().first <= A[i]){
            s.pop();
        }
        if(s.empty()){
            prod[i] = 0;
            s.push({A[i],i});
        }
        else{
            if(prod[i] != 0) prod[i] *= s.top().second;
            s.push({A[i],i});
        }
    }

    int index = max_element(prod.begin(),prod.end()) - prod.begin();
    return prod[index] % 1000000007;
}



//Second Solution :-  Similar to Max Area Histogram (finding nearest greater to right and left
#define mod 1000000007

int Solution::maxSpecialProduct(vector<int> &A){
    stack<long long int> st1, st2;
    vector<long long int> ngl, ngr;
    for(int i=0; i<A.size(); i++){
        while(!st1.empty() && A[st1.top()]<=A[i]) st1.pop();
        if(st1.empty()) ngl.push_back(0);
        else{
            ngl.push_back(st1.top());
        }
        st1.push(i);
    }
    for(int i=A.size()-1; i>=0; i--){
        while(!st2.empty() && A[st2.top()]<=A[i]) st2.pop();
        if(st2.empty()) ngr.push_back(0);
        else{
            ngr.push_back(st2.top());
        }
        st2.push(i);
    }
    reverse(ngr.begin(), ngr.end());
    long long mx=LONG_MIN;
    for(int i=0; i<ngl.size(); i++){
        long long prod= (ngl[i])*(ngr[i]);
        mx=max(prod, mx);
    }
    return mx%mod;
}


//Third Solution :-
typedef long long ll;

int Solution::maxSpecialProduct(vector &A) {
	int n = A.size();

	if(n<=2)
	    return 0;

	vector<int> prefix(n, 0);
	vector<int> suffix(n, 0);

	for(int i=1; i<n-1; i++) {
	    if(A[i-1] == A[i]) {
	        prefix[i] = prefix[i-1];
	    }
	    else if(A[i-1] < A[i]) {
	        int index = prefix[i-1];
	        while(true) {
	            if(A[index] > A[i]) {
	                prefix[i] = index;
	                break;
	            }
	            if(index == 0)
	                break;
	            index = prefix[index];
	        }
	    }
	    else {
	        prefix[i] = i-1;
	    }
	}

	for(int i=n-2; i>=1; i--) {
	    if(A[i] == A[i+1]) {
	        suffix[i] = suffix[i+1];
	    }
	    else if(A[i+1] < A[i]) {
	        int index = suffix[i+1];
	        while(true) {
	            if(A[index] > A[i]) {
	                suffix[i] = index;
	                break;
	            }
	            if(index == 0)
	                break;
	            index = suffix[index];
	        }
	    }
	    else {
	        suffix[i] = i+1;
	    }
	}

	ll product = 0;

	for(int i=1; i<n-1; i++) {
	    ll temp = (ll)(prefix[i]) * (ll)(suffix[i]);
	    if(temp > product) {
	        product = temp;
	    }
	}

	return product % 1000000007;
}



//Fourth Solution :-
int Solution::maxSpecialProduct(vector<int> &A) {
    long long int start = 0, end = 0;
    long long int ans = 0;
    long long int l = 0, r = 0;
    bool flag = true;
    for(end = 1; end < A.size()-1; end++)
    {
        if(A[start] > A[end])
        {
            l = start;
            flag = false;
        }
        if(A[end-1] > A[end])
        {
            start = end-1;
            l = start;
            flag = false;
        }
        if(flag) {
            start = start + 1;
        }
        if(A[end + 1] > A[end])
        {
            r = end + 1;
        }
        if(ans < l*r)
        {
            ans = l*r;
        }
        flag = true;
        l = r = 0;
    }
    return ans%1000000007;
}


//Fifth Solution :-
int Solution::maxSpecialProduct(vector<int> &A) {
	long long int maxL,maxR,prod,max=0,j,m;
	if(A.size()<2){
	    return 0;
	}
	for(j=A.size()-2;j>A.size()/2;j--){
	    maxL=0;maxR=0;
	    
	    //maxR
	    for( m=j+1;m<A.size();m++){
	      if(A[m]>A[j]){
	          maxR = m;
	          break;
	      }  
	    }
	    //maxL
	     for(m=j-1;m>=0;m--){
	      if(A[m]>A[j]){
	          maxL = m;
	          break;
	      }  
	    }
	    //Product and Max
	    prod = maxL*maxR;
	    if(prod>max){
	        max=prod;
	    }
	}
	return max%1000000007;
}