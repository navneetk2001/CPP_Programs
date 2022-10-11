// Given an array of integers A.  There is a sliding window of size B which 
// is moving from the very left of the array to the very right. 
// You can only see the w numbers in the window. Each time the sliding window moves 
// rightwards by one position. You have to find the maximum for each window. 
// The following example will give you more clarity.
// The array A is [1 3 -1 -3 5 3 6 7], and B is 3.
// Window position	Max
// ———————————-	————————-
// [1  3  -1] -3  5  3  6  7	3
// 1 [3  -1  -3] 5  3  6  7	3
// 1  3 [-1  -3  5] 3  6  7	5
// 1  3  -1 [-3  5  3] 6  7	5
// 1  3  -1  -3 [5  3  6] 7	6
// 1  3  -1  -3  5 [3  6  7]	7
// Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].
// Note: If B > length of the array, return 1 element with the max of the array.
// Input 1:
//     A = [1, 3, -1, -3, 5, 3, 6, 7]
//     B = 3
// Output 1:
//     C = [3, 3, 5, 5, 6, 7]


//Hint :-
// Approach 1 :
// The obvious brute force solution with run time complexity of O(nw) is definitely not efficient enough. Every time the window is moved, you have to search for a total of w elements in the window.

// Approach 2:
// A heap data structure quickly comes to mind. We could boost the run time to approximately O(n lg w) (Note that I said approximately because the size of the heap changes constantly and averages about w). Insert operation takes O(lg w) time, where w is the size of the heap. However, getting the maximum value is cheap, it merely takes constant time as the maximum value is always kept in the root (head) of the heap.
// As the window slides to the right, some elements in the heap might not be valid anymore (range is outside of the current window). How should you remove them? You would need to be somewhat careful here. Since you only remove elements that are out of the window’s range, you would need to keep track of the elements’ indices too.
// TIme complexity : O ( n log n ). Not good enough.

// Approach 3 :
// A double-ended queue should do the trick here.
// The double-ended queue is the perfect data structure for this problem. It supports insertion/deletion from the front and back. The trick is to find a way such that the largest element in the window would always appear in the front of the queue. How would you maintain this requirement as you push and pop elements in and out of the queue?


//Solution Approach :-
// The double-ended queue is the perfect data structure for this problem. It supports insertion/deletion from the front and back. The trick is to find a way such that the largest element in the window would always appear in the front of the queue. How would you maintain this requirement as you push and pop elements in and out of the queue?
// You might notice that there are some redundant elements in the queue that we shouldn’t even consider about. For example, if the current queue has the elements: [10 5 3], and a new element in the window has the element 11. Now, we could have emptied the queue without considering elements 10, 5, and 3, and insert only element 11 into the queue.
// A natural way most people would think is to try to maintain the queue size the same as the window’s size. Try to break away from this thought and try to think outside of the box. Removing redundant elements and storing only elements that need to be considered in the queue is the key to achieve the efficient O(n) solution.


//First Solution :- //using deque ( or diubly linked list)
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    deque<int> l;     //to traverse the array
    int i=0;
    int j=0;
    
    if(B>A.size()) // edge case
    {
        ans.push_back(*max_element(l.begin(),l.end()));
        return ans;
    }
    
    while (j<A.size())
    {
        while(l.size()>0 && l.back() <A[j])
        {
            l.pop_back();
        }
        l.push_back(A[j]);
        if ((j-i+1)<B)        //if window size is less than B increment further till it reaches a window size
            j++;
        else if (j-i+1==B)    //if window size is equal to B
        {
            ans.push_back(l.front());
            if (l.front()==A[i])
                l.pop_front();
            i++;
            j++;
        }
        
    }
    return ans;
}


//Second Solution :- using Max_Heap Solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Pair<int,int> contains (nums[i],index)
        priority_queue<pair<int,int>> heap; //Max_Heap to find maximum in a sliding window
        vector<int> ans;    //Stores all maximum values for all sliding windows
        
        for(int i=0;i<nums.size();++i)
        {
            while(!heap.empty() and heap.top().second<=(i-k))  //Pop the root (max_element),if it is out of sliding window
                heap.pop();

            heap.push(make_pair(nums[i],i));    //Push current element (along with its index) into the heap
            if(i>=k-1)      //Store max in the window if we have a valid window (based on size K)
                ans.push_back(heap.top().first);       
        }
        return ans;
    }
};


//Third Solution :- DeQue Solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Pair<int,int> contains (nums[i],index)
        deque<pair<int,int>> dq;  //We will store elements in the deque only inside our current window
        vector<int> ans;
        
        for(int i=0;i<nums.size();++i)
        {
            if(!dq.empty() and dq.front().second<=(i-k))    //Remove front element if it goes out of window size
                dq.pop_front();
            while(!dq.empty() and dq.back().first<nums[i])  //Maintain elements in DSC order
                dq.pop_back();
            dq.push_back(make_pair(nums[i],i));     //Push current NODE
            if(i>=(k-1))
                ans.push_back(dq.front().first);    //Include maximum of cuurrent window
        }
        return ans;
    }
};

//Fourth Solution :- 
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> v;
    deque<int> dq;

    for(auto i=0; i<A.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-B)
            dq.pop_front();        

        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();

        dq.push_back(i);    
        if(i >= B-1) v.push_back(A[dq.front()]);
    }
    return v;
}


//