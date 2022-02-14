Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Example 1:
Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the pairs which sum to 9.

Example 2:
Input:
A[] = {-1, -2, 4, -6, 5, 7}
B[] = {6, 3, 4, 0} 
X = 8 
Output:
4 4 
5 3


//Solution :-
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        unordered_set<int>hash;
        sort(A,A+N);
        vector<pair<int,int>>ans;

        for(int i=0;i<M;i++){
        	hash.insert(B[i]);
        }  

        for(int i=0;i<N;i++){
        	if(hash.find(X-A[i]) != hash.end()){  //O(N)
        		ans.push_back({A[i], X-A[i]});
        	}
        }

        return ans;  
    }
};



