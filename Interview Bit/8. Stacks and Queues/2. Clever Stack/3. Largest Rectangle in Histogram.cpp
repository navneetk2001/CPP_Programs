// Given an array of integers A .
// A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.
// Find the area of the largest rectangle formed by the histogram.
// Input 1:
//  A = [2, 1, 5, 6, 2, 3]            
// Output 1:
//  10
// Explanation 1:
// The largest rectangle has area = 10 unit. Formed by A[3] to A[4].

// Input 2:
//  A = [2]
// Output 2:
//  2
// Explanation 2:
// Largest rectangle has area 2.


//Hint :-
// Whats the brute force approach here?
// We know that the height of the largest rectange will be one of the heights of the histogram (Think about why?)
// If that is the case, we can iterate on all the histograms, and for each histogram H, we try to create the maximum rectange with H as the height.
// To do that, we keep going left L and right R till we encounter a histogram with height less than H.
// Now, (R - L - 1) * H is one of the possibilities for the largest rectangle.
// Doing this for all the histograms will give us the right solution.
// Following is a rough pseudocode for the approach mentioned above :
// max_rectangle = 0 
// for index = 0 to all_histograms.length
//   H = all_histograms[index]
//   L = index, R = index
//   while L >= 0 AND all_histograms[L] >= H
//     L = L - 1
//   while R < all_histograms.length AND all_histograms[R] >= H
//     R = R + 1
//   max_rectangle = MAX(max_rectangle, (R - L - 1) * H)
// return max_rectangle
// This approach is however O(N^2) time complexity in the worst case. How can we do better than this approach?
// Hint : Think in terms of using a stack ?

// As discussed in the previous hint, height of the maximum rectangle will be height of one of the histograms. For each histogram H, we need to know index of the first smaller (smaller than H) bar on left of H (lets call it L) and index of first smaller bar on right of H.
// We already tried the brute force approach. How can we do better?
// Important observation:
// Lets consider 2 consecutive histograms H[i] and H[i+1]. Lets assume H[i+1] < H[i]
// In such a case, for all histograms X with index > i + 1 when traversing left for L, there is no point looking at H[i] after looking at H[i+1]. If H[i+1] > X, obviously H[i] > X as we already know H[i] > H[i+1]
// Then, whats the next entry we would want to look at? We would want to look at the first histogram left of H[i+1] with height less than H[i+1].
// Can you think of a stack based approach based on the above observation?

// //Solution Approach :-
// From our previous observation, we already know that when I traverse left, I only need entries in decreasing order.
// We traverse all histograms from left to right, maintain a stack of histograms. Every histogram is pushed to stack once. A histogram is popped from stack when a histogram of smaller height is seen. When a histogram is popped, we calculate the area with the popped histogram as smallest histogram. How do we get left and right indexes of the popped histogram – the current index tells us the ‘right index’ R and index of previous item in stack is the ‘left index’ L. Following is a rough pseudocode.
// max_rectangle = 0
// stack = an instance of empty stack
// for index = 0 to all_histograms.length
//     if stack.empty OR H[index] > H[stack.top]
//         Push index to the stack
//     if H[index] < H[stack.top]
//         while !stack.empty && H[stack.top] > H[index]
//             h = H[stack.pop]
//             # Calculate the area with h as the smallest height. 
//             R = index
//             L = stack.top
//             max_rectangle = MAX(max_rectangle, (R - L - 1) * h)
//         Push index to the stack
// if stack is not empty
//     Repeat the process of removing entries one by one from stack and calculating the max_rectangle as done earlier


//First Solution :-
int Solution::largestRectangleArea(vector<int> &arr) {
    int n=arr.size();
    vector<int> left,right;    //one for smaller to left and other for smaller to right
    stack<pair<int,int>> s1,s2;

    int pseudo_index =-1;   //Nearest smaller to left
    for (int i=0;i<n;i++)
    {
        if(s1.size()==0){
            left.push_back(pseudo_index);
        }
        else if(s1.size()>0 && s1.top().first<arr[i]){
            left.push_back(s1.top().second);
        }
        else if(s1.size()>0 && s1.top().first>=arr[i]){
            while(s1.size()>0 && s1.top().first>=arr[i]){
                s1.pop();
            }
            if (s1.size()==0){
                left.push_back(pseudo_index);
            }
            else{
                left.push_back(s1.top().second);
            }
        }
        s1.push({arr[i],i});
    }

    int pseudo_index1 = n;     //Nearest smaller to right
    for (int i=n-1;i>=0;i--)
    {
        if(s2.size()==0){
            right.push_back(pseudo_index1);
        }
        else if(s2.size()>0 && s2.top().first<arr[i]){
            right.push_back(s2.top().second);
        }
        else if (s2.size()>0 && s2.top().first >= arr[i]){
            while(s2.size()>0 && s2.top().first >= arr[i]){
                s2.pop();
            }
            if (s2.size()==0){
                right.push_back(pseudo_index1);
            }
            else{
                right.push_back(s2.top().second);
            }
        }
        s2.push({arr[i],i});
    }
    reverse(right.begin(),right.end());    //reverse the obtained array

    long long ans=INT_MIN;         //calculate the Solution
    long long curr_ans;
    for(long long i=0;i<n;i++)
    {
        curr_ans = (long)(right[i]-left[i]-1)*arr[i];
        ans=max(ans,curr_ans); // taking max after finding area
    }
    return ans;
}

//Second Solution :-
class Solution{
public:
  int largestRectangleArea(vector<int>& a){
  	int n=a.size(), ans=0, i=0;
    stack<int>st;
    a.push_back(0);

    while(i<n){
    	while(!st.empty() and a[st.top()] > a[i]){
    		int t=st.top();
    		int h=a[i];
    		st.pop();
    		if(st.empty()){
    			ans = max(ans, h*i);
    		}
    		else{
    			int len = i-st.top()-1;
    			ans=max(ans, h*len);
    		}
    	}
    	st.push(i);
    	i++;
    }
    return ans;
  }
};


//Third Solution :-   BruteForce
int Solution::largestRectangleArea(vector<int> &histo) {
	int ans=0, n=a.size();
	for(int i=0;i<n;i++){
		int minh=INT_MAX;
		for(int j=i;j<n;j++){
			minh=min(a[j],minh);
			int len=j-i+1;
			ans=max(ans,len*minh);
		}
	}
	return ans;
}

//Fourth Solution :-
int Solution::largestRectangleArea(vector<int> &histo) {
    int n=histo.size();
    stack<int>st;
    int maxA=0;
    int width=1;
    
    for(int i=0;i<=n;i++){
	    while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
            int height=histo[st.top()];
	        st.pop();
	        if(st.empty()){
	        	width=i;
	        }
	        else{ 
	        	width=i-st.top()-1;
	        }
	        maxA=max(maxA, width*height);
	    }
	    st.push(i);
	}
	return maxA;
}


//Fifth Solution :-
int Solution::largestRectangleArea(vector<int> &A) {
    
    stack<int> st;
    int res = 0;
    int n = A.size();
    
    for(int i = 0; i < n; i++){
        
        while(!st.empty() && A[st.top()] >= A[i]){
            
            int tp = st.top();
            st.pop();
            int curr = A[tp] * (st.empty() ? i : (i - st.top() - 1));
            res = max(res, curr);
        }
        
        st.push(i);
    }
    
    while(!st.empty()){
        
        int tp = st.top();
        st.pop();
        
        int curr = A[tp] * (st.empty() ? n : (n - st.top() - 1));
        res = max(res, curr);
    }
    
    return res;
}