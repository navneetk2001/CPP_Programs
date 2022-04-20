// Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.

// Example 1:
// Input:
// n = 3, e = 2
// A[] = {1, 2, 1, 3}
// B[] = {1, 3, 1, 2}
// Output: 1
// Explanation:
//    1          1
//  / \        /  \
// 2   3      3    2 
// As we can clearly see, the second tree is mirror image of the first.

// Example 2:
// Input:
// n = 3, e = 2
// A[] = {1, 2, 1, 3}
// B[] = {1, 2, 1, 3}
// Output: 0
// Explanation:
//    1          1
//  / \        /  \
// 2   3      2    3 
// As we can clearly see, the second tree isn't mirror image of the first.



//Solution Approach :-
class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,stack<int>> mp;
        for(int i=0;i<2*e;i+=2){
            mp[A[i]].push(A[i+1]);
        }
        for(int i=0;i<2*e;i+=2){
            if(mp[B[i]].top()!=B[i+1]){
                return 0;
            }
            mp[B[i]].pop();
        }
        return 1;
    }
};



//Second Solution :-
class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int, vector<int>> a, b;
        for(int i = 0; i < 2 * e; i += 2) {
            a[A[i]].push_back(A[i + 1]);
            b[B[i]].push_back(B[i + 1]);
        }
        
        for(auto it: a) {
            auto cur = b[it.first];
            reverse(cur.begin(), cur.end());
            if(cur != it.second) return 0;
        }
        
        return 1;
    }
};