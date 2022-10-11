// You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
// horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7. 

// Example 1:
// Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
// Output: 4 
// Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

// Example 2:
// Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
// Output: 6
// Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

// Example 3:
// Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
// Output: 9




// Solution Approach :-
//The biggest piece is formed by the biggest vertical, and the biggest horizontal gap between cuts.
//So, we sort cuts, and find the maximum gap. The gap for the first and the last cut is defined by the cake's edge.

int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
    sort(begin(hCuts), end(hCuts));
    sort(begin(vCuts), end(vCuts));

    auto max_h = max(hCuts[0], h - hCuts.back());
    auto max_v = max(vCuts[0], w - vCuts.back());

    for (auto i = 0; i < hCuts.size() - 1; ++i){
        max_h = max(max_h, hCuts[i + 1] - hCuts[i]);
    }
    for (auto i = 0; i < vCuts.size() - 1; ++i){
        max_v = max(max_v, vCuts[i + 1] - vCuts[i]);        
    }
    return (long)max_h * max_v % 1000000007;
}



//Second Solution :- ✔️ Solution (Sort & Find Max Gaps)
// We are required to find the maximum area of a piece of cake after applying the cuts. It should be obvious that maximum area in a rectangle can be obtained by maximizing its height and width.
// So, we just need to maximize the height and width of a piece of cake. For this, just sort the cuts and iterate through them to get the maximum gap between two consecutive cuts. It's better to consider the case of length of piece before the first cut and after the last cut separately outside the loop just to keep the loop simple.

int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
	return long(getMaxGap(H, h)) * getMaxGap(V, w) % 1000000007;
}

int getMaxGap(vector<int>& nums, int max_size) {
	sort(begin(nums), end(nums));
	int maxGap = max(nums[0], max_size - nums.back());      // handling the case of first and last piece of cake
	for(int i = 1; i < size(nums); i++){
		maxGap = max(maxGap, nums[i] - nums[i - 1]);
	}
	return maxGap;
}




//Third Solution :-
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        int maxh = 0, maxv = 0;
                
        hC.push_back(0);
        hC.push_back(h);
        sort(hC.begin(), hC.end());
        for(int i=1; i<hC.size(); i++){
            maxh = max(maxh, hC[i] - hC[i-1]);
        }
        
        vC.push_back(0);
        vC.push_back(w);
        sort(vC.begin(), vC.end());
        for(int i=1; i<vC.size(); i++){
            maxv = max(maxv, vC[i] - vC[i-1]);
        }
        return (1LL*maxh*maxv) % 1000000007; //1LL used to make the product long long or integer sign overflow will occur.
    }
};