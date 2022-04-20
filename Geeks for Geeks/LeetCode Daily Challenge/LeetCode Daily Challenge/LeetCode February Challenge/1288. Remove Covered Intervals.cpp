// Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
// The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
// Return the number of remaining intervals.


// Example 1:
// Input: intervals = [[1,4],[3,6],[2,8]]
// Output: 2
// Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

// Example 2:
// Input: intervals = [[1,4],[2,3]]
// Output: 1



//Solution Approach :- 
//Intuition :- we will use sorting  , first we will sort on the basis of start interval 
//and if its same then we will sort on the basis of decreasing ending time
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y){
            return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];
        });

        int covered_intervals = 0, maximum_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= maximum_end) {
                covered_intervals++;
            }
            maximum_end = max(maximum_end, intervals[i][1]);
        }
        return intervals.size() - covered_intervals;
    }
};


//Solution :- 
class Solution {
public:
    typedef vector<int> vi;
    static bool cmp(vi a, vi b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int mx = 0;
        for (auto x : intervals)
        {
            if (x[1] > mx)
            {
                ++ans;
                mx = x[1];
            }
        }
        return ans;
    }
};



//Approach :- 
// Here firstly sort the intervals
// if 1st element of intervals are equal then sort non-increasingly according to second element of interval
// then simply check the second element of interval if it is greater then ignore just increase pointer
// otherwise increase the count of non overlapping pair

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }else{
            return a[1]>b[1];
        }
    });

    int cnt=1;
    int i=0,j=1;
    int n=intervals.size();    
    while(j<n){
        if(intervals[i][1]>=intervals[j][1]){
            j++;
        }else{
            i=j;
            j++;
            cnt++;
        }
    }
    return cnt;
}