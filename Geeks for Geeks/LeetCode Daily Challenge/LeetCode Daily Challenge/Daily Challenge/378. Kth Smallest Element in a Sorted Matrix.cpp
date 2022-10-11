// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.
// You must find a solution with a memory complexity better than O(n2).

 

// Example 1:
// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

// Example 2:
// Input: matrix = [[-5]], k = 1
// Output: -5
 




//Solution Approach :- 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while(low < high){
            int mid = low + (high - low)/2;
            int count = 0;
            for(int i = 0; i < n; i++){    //check in each row how many elements are less than mid value as we know each row is sorted so we will use uppper bound
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();   //adding each element less than mid for each row
            }
            
            if(count < k){    //check if the total count of mid value is less than k them increase the value of low
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        
        return low;
    }
};




//Second Solution :-
int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq; //max heap
    
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            pq.push(matrix[i][j]);
            if (pq.size() > k){
                pq.pop();        
            }
        }
    }
    return pq.top();
}




//Third Solution :- Priority queue solution O(klogn)
class Solution {
public:
    struct compare{
        bool operator()(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
            return a.first > b.first;
        }
    };

    int kthSmallest(vector<vector<int>>& arr, int k) {
        int n=arr.size(), m=arr[0].size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, compare> p;
        
        for(int i=0;i<n;i++){
            p.push(make_pair(arr[i][0],make_pair(i,0)));
        }
        
        int x = k, ans;
        while(x--){
            int e = p.top().first;           //element itself
            int i = p.top().second.first;    //ith row 
            int j = p.top().second.second;   //jth element in ith row

            ans = e;       //one possible answer
            p.pop(); 

            if(j != m - 1){
                p.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
            }
        }
        return ans;
        
    }
};