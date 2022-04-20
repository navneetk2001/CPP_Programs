// Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// Input 1:
//  A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
// Output 1:
//  6

//Hint :-
Take a close look at any particular bin. How high can this hold water? If you can compute the answer of the above question for every bin you are done.
Every bin will store water which will depend on some prefix and suffix quantity. Can you figure it out now?

//Solution Approach :-
instead of calculating area by height*width, we can think it in a cumulative way. In other words, sum water amount of each bin(width=1). Search from left to right and maintain a max height of left and right separately, which is like a one-side wall of partial container. Fix the higher one and flow water from the lower part. For example, if current height of left is lower, we fill water in the left bin. Until left meets right, we filled the whole container.

//First Solution :-
int Solution::trap(const vector<int> &A) {
    int n=A.size();
    int maxL[n];    //maximum from left
    int maxR[n];    //maximum from right
    int water[n];   //water in each tank
    int sum=0;

    maxL[0]=A[0];
    for (int i = 1; i < n; ++i)
    {
	    maxL[i]=max(maxL[i-1],A[i]);     //storing all the maximum values from the left
    }

    maxR[n-1]=A[n-1];
    for (int i = n-2; i >= 0; --i)
    {
	    maxR[i]=max(maxR[i+1],A[i]);     //storing all the maximum values from the right
    }

    for(int i=0;i<n;i++){
	    water[i]=min(maxL[i],maxR[i])-A[i];  //taking minimum of each value from maximum and minimum and finding water stored
	    sum+=water[i];
    }

    return sum;
}


//Second Solution :-  Using two pointers Approach 
int Solution::trap(const vector<int> &A) {
    int l=0,r=A.size()-1;
    int ans=0,lm=0,rm=0;
    while(l<r){
        if(A[l]<A[r]){
            lm=max(lm,A[l]);
            ans+=lm-A[l];
            l++;
        }
        else{
            rm=max(rm,A[r]);
            ans+=rm-A[r];
            r--;
        }
    }
    return ans;
}


//Third Solution :- Tried an innovative solution (stack+queue combined xD)
int Solution::trap(const vector<int> &A) {
    queue<int> left;
    stack<int> right;
    int sum = 0;
    int N = A.size();
    int lmax = INT_MIN;
    int rmax = INT_MIN;
    
    for(int i = 0; i<N; i++){
        lmax = max(lmax, A[i]);
        left.push(lmax);
    }
    for(int i = N-1; i>=0; i--){
        rmax = max(rmax, A[i]);
        right.push(rmax);
    }
    for(int i = 0; i<N; i++){
        int a = left.front(); left.pop();
        int b = right.top(); right.pop();
        sum += min(a, b) - A[i];
    }
    return sum;
}


//Fourth Solution :- Using Stack 
int Solution::trap(const vector<int> &A) {
    stack<int>s;
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        while(!s.empty() && A[i] > A[s.top()])
        {
            int height= A[s.top()];
            s.pop();
            if(s.empty()) break;
            int distance=i-1-s.top();
            int min_height=min(A[s.top()],A[i])-height;
            ans+=distance*min_height;
        }
        s.push(i);
    }
    return ans;
}