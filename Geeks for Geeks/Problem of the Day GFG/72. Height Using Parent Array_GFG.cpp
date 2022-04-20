// Given a parent array arr[] of a binary tree of N nodes. Element at index i in the array arr[] represents the parent of ith node, i.e, arr[i] = parent(i). Find the height of this binary tree.
// Note: There will be a node in the array arr[], where arr[i] = -1, which means this node is the root of binary tree.

// Example 1:
// Input: N = 7
// arr = {-1, 0, 0, 1, 1, 3, 5}
// Output: 5
// Explanation: Tree formed is:
//                     0
//                    / \
//                   1   2
//                  / \
//                 3   4
//                /
//               5
//              /
//             6      Height of the tree= 5



//Solution Approach :-   
//Parent = arr[i]

class Solution{
public:
    int findHeight(int N, int arr[]){
        vector<int>level(N+1);
        level[0]=1;
        int ans=0;
        for(int i=1;i<N;i++){
        	level[i]=level[arr[i]]+1; //level[child]=leel[parent]+1;
        	ans=max(ans,level[i]);
        }
        return ans;
    }
};            



//BruteForce Approach :-
//Brute Force Solution that works in O(n*n)   | C++
//Approach: Iterate array from beginning to end, calculate height taking current node as the end (or depth of current node to be accurate) and simply return the max of those values since max depth and height of a tree are same.

class Solution{
public:
    int findHeight(int N, int arr[]){
        if (N <= 1) return N;
        int maxHeight{1};
        for (int i = 0; i < N; i++) {
            int curr = i, currHeight{1};
            while (arr[curr] != -1) { 
                curr = arr[curr];
                currHeight++;
            }
            maxHeight = max(maxHeight, currHeight);
        }
        return maxHeight;
    }
};            


//Third Solution :-
int findHeight(int n, int arr[]){
   int ans=1,k=n-1;
   while(arr[k]!=-1)
   {
       ans++;
       k=arr[k];
   }
   return ans;
}
