https://leetcode.com/problems/can-place-flowers/




//Solution Approach :-  (Greedy Approach)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);

        for(int i = 1; i < flowerbed.size()-1; ++i){
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0){
                --n;
                ++i;
            }
        }
        return n <=0;
    }
};




//Second Solution :- Solution: Check and Place
// Just Check each position i sequentially whether a flower can be placed
// If not, just go on
// if ok, just place a flower at i
// n = n - 1
// flowerbed[i] = 1
// note that we change the flowerbed, so the next 0 cannot place.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        for(int i = 0; i < flowerbed.size(); i ++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) { // can place?
                -- n;
                if(n == 0){
                    return true;
                }
                flowerbed[i] = 1; // place!
            }
        }
        return false;
    }
};




//Third Solution :- DP Solution 
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zeros = 1, ans = 0; // Easier handling of prefixes, just initialize zeros to 1
        for (int i = 0; i < flowerbed.size(); i ++) {
            if (flowerbed[i] == 0) {
                ++ zeros;
            } 
            else {
                ans += (zeros - 1) / 2;
                zeros = 0;
            }
        }
        return ans + zeros / 2 >= n; // Note that suffix zeros need not -1
    }
};