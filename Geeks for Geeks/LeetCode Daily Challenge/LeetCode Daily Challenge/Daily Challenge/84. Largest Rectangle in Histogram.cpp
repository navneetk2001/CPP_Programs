// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1. The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:
// Input: heights = [2,4]
// Output: 4




//Solution Approach :-
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        stack<int> st;
        // construct lb[i]: idx of first col on the left that is lower than height[i]
        vector<int> lb(N);
        for (int i(0); i < N; ++i)
        {
                while (!st.empty() and heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    lb[i] = -1;
                    st.push(i);
                }
                else {
                    lb[i] = st.top();
                    st.push(i);
                }
        }
        
        // clear stack
        while (!st.empty()){ 
        	st.pop();
        }
        
        // construct rb[i]: idx of first col on the right that is lower than height[i]
        vector<int> rb(N);
        for (int i(N-1); i >= 0; --i) {
            while (!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                rb[i] = N;
                st.push(i);
            }
            else {
                rb[i] = st.top();
                st.push(i);
            }
        }
        
        // scan each col and get max area
        int rst = 0;
        for (int i(0); i < N; ++i) {
            rst = max(rst, heights[i] * (rb[i] - lb[i] - 1));
        }
        return rst;
    }
};




//Second Solution :-
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;
        stack<pair<int,int>> s;
        for(int i=0; i<n; i++){
            int start = i;
            while(!s.empty() and s.top().second > heights[i]){
                int index = s.top().first;
                int height = s.top().second;
                s.pop();
                max_area = max(max_area, (i - index)*height);
                start = index;
            }
            s.push({start, heights[i]});
        }
        while(!s.empty()){
            max_area = max(max_area, s.top().second * (n-s.top().first));
            s.pop();
        }
        return max_area;
    }
};



//Third Solution :-
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        if(!n) return 0;
        int ans = 0;
        
        //find the leftest height and the rightest height which greater (include eaqual) than current height:height[i];
        // so current area with height[i] will be:(r-l+1)*height[i]
        // how to find the l  and r, it can be implemented with jumping steps
        vector<int> L(n,0);
        vector<int> R(n,0);
        for(int i=0; i<n; i++){
            int l = i-1;
            while(l>=0 && height[l]>=height[i]) l=(L[l]-1);
            L[i] = l+1;
        }
        for(int i=n-1; i>=0; i--){
            int r=i+1;
            while(r<n && height[r]>=height[i]) r=(R[r]+1);
            R[i] = r-1;
            ans = max(ans,(R[i]-L[i]+1)*height[i]);
        }
        
        return ans;
    }
};



