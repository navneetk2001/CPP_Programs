// Given an 1D integer array A of size N you have to find and return the B largest elements of the array A.
// NOTE:
// 	Return the largest B elements in any order you like.

// Input 2:
//  A = [11, 3, 4, 6]
//  B = 3
// Output 2:
//  [4, 6, 11]
// Explanation 2:
//  The three largest elements of A are 11, 4 and 6


//Hint :-
Build a minHeap of size k and maintain the k largest in it or think of using max heap or sorting.

//Solution Approach :- 
Method 1(Use Sorting)
1, Sort the elements in descending order in O(nLogn)
2, Print the first k numbers of the sorted array O(k).

Time complexity: O(nlogn)
Method 2 (Use Max Heap)
Build a Max Heap tree in O(n)
Use Extract Max k times to get k maximum elements from the Max Heap O(klogn)
Time complexity: O(n + klogn)

Method 3(Use Oder Statistics)
Use order statistic algorithm to find the kth largest element.
Use QuickSort Partition algorithm to partition around the kth largest number O(n).
Sort the k-1 elements (elements greater than the kth largest element) O(kLogk). This step is needed only if sorted output is required.
Time complexity: O(n) if we don’t need the sorted output, otherwise O(n+kLogk)

Method 4 (Use Min Heap)
Build a Min Heap MH of the first k elements (A[0] to A[k-1]) of the given array. O(k)
For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
If the element is greater than the root then make it root and call heapify for MH
Else ignore it.
The step 2 is O((n-k)*logk)
Finally, MH has k largest elements and root of the MH is the kth largest element.
Time Complexity: O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)

All of the above methods can also be used to find the kth largest (or smallest) element.


//First Solution :-
vector<int> Solution::solve(vector<int> &nums, int k) {
    priority_queue<int,vector<int>,greater<int>> minh;
    vector<int>ans;
    int n= nums.size();
    for(int i=0;i<n;i++)
    {
        minh.push(nums[i]);
        {
            if (minh.size()>k)
                minh.pop();
        }
    }
    
    while(minh.size()>0){
        ans.push_back(minh.top());
        minh.pop();
    }
    return ans;
}


//Second Solution :-
vector<int> Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end(), greater<int>());
    A.erase(A.begin() + B, A.end());
    return A;
}


//Third Solution :- 
vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> res;
    priority_queue<int> pq;
    for(int i: A) pq.push(i);
    while(B--){
        int ans = pq.top(); pq.pop();
        res.push_back(ans);
    }
    return res;
}

