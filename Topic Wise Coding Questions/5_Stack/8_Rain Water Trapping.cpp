https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1



//Solution Approach -
class Solution{
public:
    // Function to find the trapped water between the blocks.
    long long trappingWater(int A[], int n){
        int maxL[n];    //maximum from left
        int maxR[n];    //maximum from right
        int water[n];   //water in each tank
        long long sum=0;
    
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
};



//Second Solution :-  Using two pointers Approach 
class Solution{
public:
    // Function to find the trapped water between the blocks.
    long long trappingWater(int A[], int n){
        int l = 0, r = n - 1;
        long long ans = 0;
        int lm = 0, rm = 0;
        
        while(l < r){
            if(A[l] < A[r]){
                lm = max(lm, A[l]);
                ans += lm - A[l];
                l++;
            }
            else{
                rm = max(rm, A[r]);
                ans += rm - A[r];
                r--;
            }
        }
        return ans;
    }
};




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