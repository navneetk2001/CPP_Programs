// You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
// Return true if you can make this square and false otherwise.

// Example 1:
// Input: matchsticks = [1,1,2,2,2]
// Output: true
// Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

// Example 2:
// Input: matchsticks = [3,3,3,3,4]
// Output: false
// Explanation: You cannot find a way to form a square with all the matchsticks.





//Solution Approach :-
class Solution {
public:
    bool dfs(vector<int> matchsticks, int target, vector<int> &sides, int idx){
        if(idx == matchsticks.size()){         // base case
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]){     //If all sides of square are equal, then return true else return false          
                return true;
            }
            return false;
        }
        
        for(int i = 0; i < 4; i++){
            if (sides[i] + matchsticks[idx] > target){  //optimization - 1   :-> If one side of square is greater than target, then continue for other
                continue;
            }

            int j = i - 1;  //optimization - 3 :-> If we have previously called dfs then break out of loop, there is no need to do it again
            while (j>=0){
                if(sides[j] == sides[i]){
                    break;
                }
                j -= 1;
            }
            
            if(j != -1){
                continue;
            }
            
            
            sides[i] += matchsticks[idx];               //add the matchstick length to ith side of square
            if( dfs(matchsticks, target, sides, idx+1) ){
                return true;
            }
            sides[i] -= matchsticks[idx];            //backtrack for next condition
        }
        
        return false;
    }
    
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() == 0){
            return false;
        }
        
        int sum = 0;
        for(int i = 0; i < matchsticks.size() ; i++){
            sum += matchsticks[i];
        }
        
        int target = sum / 4;           //:-> This represents the length of each side of square, in any condition, length can't exceed than target
        vector<int> sides(4,0);         //:-> this is to store the size of each side of square 
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // optimization 2 :-> If one side of square is greater than target, then continue for other

        return dfs(matchsticks, target, sides, 0);
    }
};





//Second Solution :-
//Trivial Solution :-> Without pruning, this solution TLEs at 11th test case.

class Solution {
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index) {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty()) return false;
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0);
    }
};



// First Optimization:
// each matchstick must be used exactly one time.
// The description says we need to use every single match exactly once, so we can get the length of each side of the square if there is one.
// if the current length is larger than target length, we don't need to go any further.
// if (sidesLength[i] + matches[index] > target) continue; by adding this line of code into dfs function, solution get TLE at 147th test case.


// Second Optimization:
// After reading the description again, I realize that the length of a single match can be very long. If they put long ones after short ones, it will take a long time before my algorithm return false.
// So I sort all the matches to avoid the worst case:sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;});. After putting this line before my algorithm, solution passed all cases and beats 50% solutions. I saw someone's algorithm is amazingly fast, they even make me reconsider wether the problem is NP or not.


// Third Optimization:
// Because their solutions is so fast, I need think about if I can use DP to solve the problem. It turns out that it's still a NP problem, which makes happy again. But I can actually use the concept of DP in optimization: if I have checked the same length before, why do I need to bother checking again?
// Although we only have 4 sides in a square, we can still check if we have encountered the same length with the current match. After I add this to my code:

// int j = i;
// while (--j >= 0)
//     if (sidesLength[i] == sidesLength[j]) 
//         break;
// if (j != -1) continue;
// It passed all test case in 6ms.




//Third Solution :- bit masking + DP solution with detailed comments
//This is a solution inspired by a friend who doesn't do leetcode. I am just posting his solution with the best explanation I can give. 
//The bitmasking technique may look sophisticated but the idea is actually pretty straightforward because it uses brute force with some optimizations. 
//A bitmask is used as a representation of a subset. For example if nums = {1,1,2,2,2}, then a bitmask = 01100 represents the subset {1,2}.

bool makesquare(vector<int>& nums) {
    int n = nums.size();

    long sum = accumulate(nums.begin(), nums.end(), 0l);
    if (sum % 4)
        return false;
    long sideLen = sum / 4;
    // need to solve the problem of partitioning nums into four equal subsets each having
    // sum equal to sideLen
    vector<int> usedMasks;
    // validHalfSubsets[i] == true iff the subset represented by bitmask i
    // has sum == 2*sideLen, AND the subset represented by i can be further partitioned into
    // two equal subsets. See below for how it is used.
    vector<bool> validHalfSubsets(1<<n, false);

    // E.g., if n = 5, (1 << 5 - 1) = 11111 represents the whole set
    int all = (1 << n) - 1;
    // go through all possible subsets each represented by a bitmask
    for (int mask = 0; mask <= all; mask++) {
        long subsetSum = 0;
        // calculate the sum of this subset
        for (int i = 0; i < 32; i++) {
	    if ((mask >> i) & 1)
		subsetSum += nums[i];
        }
	// if this subset has what we want
	if (subsetSum == sideLen) {
	    for (int usedMask : usedMasks) {
	    // if this mask and usedMask are mutually exclusive
	        if ((usedMask & mask) == 0) {
		    // then they form a valid half subset whose sum is 2 * sideLen,
                    // that can be further partitioned into two equal subsets (usedMask and mask)
		    int validHalf = usedMask | mask;
		    validHalfSubsets[validHalf] = true;
		    // if in the past we concluded that the other half is also a valid
		    // half subset, DONE!
		    if (validHalfSubsets[all ^ validHalf])
		        return true;
	        }
            }
	    usedMasks.push_back(mask);
        }
    }
    return false;
}