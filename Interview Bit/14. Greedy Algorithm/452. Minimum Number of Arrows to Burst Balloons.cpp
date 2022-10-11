https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/





//Solution Approach :-
// Problem Understanding :- 
// There is some misleading in the description of the problem, points are not points but line segments, so I just modify points to segments.
// There are several segments on the one-dimensional coordinate axis, find out the minimum number of arrows which are orthogonal to the coordinate axis so that each segment can be shot through by at least one arrow.

// Approach :- 
// Sort the segments by the end
// put an arrow at the end of the 1-st segment
// from the 2-nd segment, we check whether the current arrow pass through the current segment, if not add an arrow, put it at the end of the current segment


bool cmp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:  
    int findMinArrowShots(vector<vector<int>>& segments) {
        sort(segments.begin(), segments.end(), cmp);
        int ans = 0, arrow = 0;
        
        for(int i = 0; i < segments.size(); i++){
            if(ans == 0 || segments[i][0] > arrow){
                ans ++;
                arrow = segments[i][1];
            }
        }
        return ans;
    }
};



//Second Solution :-
