The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them.

Example 1:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:
Input: x = 3, y = 1
Output: 1


//Solution Approach :-
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};


//Second Solution :-
class Solution {
public:
    int hammingDistance(int x, int y) {
	    return __builtin_popcount((x ^ y));
    }
};


//Third Solution :-
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while(x!=0 || y!=0) {
            int lastBit_x=x&1;
            int lastBit_y=y&1;
            ans+=(lastBit_x==lastBit_y)?0:1;
            x=x>>1; y=y>>1;
        }
        return ans;
    }
};

