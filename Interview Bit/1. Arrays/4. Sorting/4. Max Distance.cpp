



//Hint 1
This problem seems easy, maybe because it is easy to understand. But is it straightforward to solve?

Let us first look at the trivial bruteforce. Run two loops. In the outer loop, pick elements one by one from left. In the inner loop, compare the picked element with the elements starting from right side. Stop the inner loop when you see an element greater than the picked element and keep updating the maximum j-i so far.
The bruteforce is O(n^2) which is obviously not good enough.

Let us look to improve.

If you are thinking of a straightforward solution, think again. Try to come up with a solution with run time complexity of O(n log n). Can you do better than that?

How about sorting the array?


//Hint 2
Let us say we sort the array. Note that we cannot just blindly sort the array. We need to make sure that we also store the original index of the values when we are sorting the array.

Now iterate over every element in the sorted array as A[i]. Let us say index[i] stores the actual index of A[i].

Now we are looking for all values of A[j] which are bigger than A[i]. Since the array is sorted, all the elements to the right of A[i] will qualify for being A[j].
Since we want to maximize index[j] - index[i], and index[i] is fixed, we are essentially looking at max index[j] for all j > i.

This seems much easier. Can you think of a solution from this point?


//Solution Approach
Continuing from the previous hint :

It is important to note that while sorting the array we must also store the original index of the values instead of blindly sorting it.

Now iterate over every element in the sorted array as A[i].

Let us say index[i] stores the actual index of A[i].

Now, we are looking for all values of A[j] which are bigger than A[i].

Since the array is sorted, the values will be all the elements to the right of A[i].

Since we want to maximize index[j] - index[i], and index[i] is fixed,
we are essentially looking at max index[j] for all j > i.

The problem concludes to finding the max in all the suffix of the array.

We can preprocess the index array and let indexMax[i] store the maximum of index[i….len]

This is how we can calculate max of all the suffix in O(n) :

       int maxIndex = INT_MIN; // -Infinity
           for (int i = len - 1; i >= 0; i--) {
            maxIndex = max(maxIndex, index[i]);
            indexMax[i] = maxIndex;
        }



// First Method :-

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<int> suffix(n);
    suffix[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--)
        suffix[i] = max(suffix[i+1], A[i]);

    int j=0;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        while(j<n && suffix[j] >= A[i])
        {
            ans = max(ans, j-i);
            j++;
        }
        if(j==n) return ans;
    }
    return ans;
}




//Second Method :-
class Solution {
    public:
        int maximumGap(const vector<int> &num) {
            if (num.size() == 0) return -1;
            if (num.size() == 1) return 0;
            vector<pair<int, int> > toSort; 
            for (int i = 0; i < num.size(); i++) {
                toSort.push_back(make_pair(num[i], i));
            }
            sort(toSort.begin(), toSort.end());
            int len = toSort.size();
            int maxIndex = toSort[len - 1].second;
            int ans = 0;
            for (int i = len - 2; i >= 0; i--) {
                ans = max(ans, maxIndex - toSort[i].second);
                maxIndex = max(maxIndex, toSort[i].second);
            }
            return ans;
        }



//Third Solution :-
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int right[n];
    right[n-1] = A[n-1];
    for(int i=n-2; i>=0; i--){ 
        right[i] = max(right[i+1], A[i]);
    }
    int ans = 0;
    int i = 0; int j=0;
    while( i<n && j<n ){
        if( A[i] <= right[j]){
        ans = max(ans, j-i);
        j++;
        }
        else i++;
    }
    return ans;
}