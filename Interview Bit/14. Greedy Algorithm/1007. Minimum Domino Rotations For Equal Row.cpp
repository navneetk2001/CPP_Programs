https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/



//Solution Approach :-
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> countA(7), countB(7), countSame(7);
        int n = A.size();
        
        for(int i = 0; i < n; i++){
            int a = A[i], b = B[i];
            countA[a] += 1;            //increment the frequency of element in array A at ith position
            countB[b] += 1;            //increment the frequency of element in array B at ith position
            if(a == b){                //if both are same then increment countSame
            	countSame[a] += 1;
            }
        }

        int ans = n;
        for(int v = 1; v <= 6; v++){
            if(countA[v] + countB[v] - countSame[v] == n){
                int minSwap = min(countA[v], countB[v]) - countSame[v];
                ans = min(ans, minSwap);
            }
        }   
        return ans == n ? -1 : ans;
    }
};


