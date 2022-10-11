// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

// Example 1:
// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

// Example 2:
// Input: cardPoints = [2,2,2], k = 2
// Output: 4
// Explanation: Regardless of which two cards you take, your score will always be 4.

// Example 3:
// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55
// Explanation: You have to take all the cards. Your score is the sum of points of all cards.




//Solution Approach :-
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int currSum=0;
        for(int i=0;i<k;i++){
            currSum+=cardPoints[i];
        }
        
        int maxSum=currSum;
        int i=n-1, j=k-1;
        while(i>=0 && j>=0){
            currSum+=cardPoints[i--];
            currSum-=cardPoints[j--];
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};




//Second Solution :- ❌ Solution - I (Recursive Brute-Force) [Rejected]
//We can solve this question in a recursive manner by maintaining two pointers l and r. 
//For each (l, r), we can either take card[l] or card[r]. We will recursively explore both the option 
//and choose the one that leads to maximum score. This process will be repeated till k cards are chosen.

int maxScore(vector<int>& cp, int k) {
	return solve(cp, k, 0, size(cp) - 1);
}

int solve(vector<int>& cp, int k, int l, int r) {
	if(k == 0) return 0;
	return max(cp[l] + solve(cp, k - 1, l + 1, r), cp[r] + solve(cp, k - 1, l, r - 1));
}


