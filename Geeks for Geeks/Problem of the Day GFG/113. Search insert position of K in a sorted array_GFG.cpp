// Given a sorted array Arr[](0-index based) consisting of N distinct integers and an integer k, the task is to find the index of k, if it’s present in the array Arr[]. Otherwise, find the index where k must be inserted to keep the array sorted.

// Example 1:
// Input:
// N = 4
// Arr = {1 , 3, 5, 6}
// k = 5
// Output: 2
// Explaination: Since 5 is found at index 2 as arr[2] = 5, the output is 2.

// Example 2:
// Input:
// N = 4
// Arr = {1, 3, 5, 6}
// k = 2
// Output: 1
// Explaination: Since 2 is not present in the array but can be inserted at index 1 to make the array sorted.



//Solution Approach :-
class Solution{
    public:
    int searchInsertK(vector<int>nums, int N, int K)
    {
        int low=0;
        int high=N-1;
        int mid;
        while(low<=high)
        {
                mid=low+(high-low)/2;
                if(nums[mid]==K)
                {
                    return mid;
                }
                else if(nums[mid]<K)
                {
                    low=mid+1;
                }
                else
                {
                     high=mid-1;
                }
        }
        return low;
    }
};


//Second Solution :-
int searchInsertK(vector<int>arr, int n, int k){ 
    int val= lower_bound(arr.begin(),arr.end(),k)- arr.begin();
    return val;
}



//Third Solution :-
class Solution{
    int search(vector<int> &c, int key) {
	    int mid, l = 0, e = c.size();
	    bool flag = true;
	    while (l <= e) {
			mid = l + (e - l) / 2;
			if (c[mid] == key) {
				flag = false;
				break;
			} 
			else if (c[mid] < key) {
				l = mid + 1;
			} else {
				e = mid - 1;
			}
	    }

	    if (flag == true) {
			if (c[mid] > key && c[mid - 1] < key) {
				return mid;
			} 
			else if (c[mid] < key && c[mid + 1] > key) {
				return mid + 1;
			}
	    }
	    return mid;
	}
    
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
       return (search(Arr, k)); 
    }
};