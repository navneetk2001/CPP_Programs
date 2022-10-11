https://leetcode.com/problems/median-of-two-sorted-arrays/




//Solution Approach : -
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n=nums1.size(), m=nums2.size();
		vector<int> merge(n+m);
		int i=0,j=0,k=0;
		
		while(i<n && j<m)
		{
			if(nums1[i]<=nums2[j]){
				merge[k++] = nums1[i++];
			}
			else{
				merge[k++] = nums2[j++];
			}
		}

		while(i<n){
			merge[k++] = nums1[i++];
		}
		while(j<m){
			merge[k++] = nums2[j++];
		}

		if((n+m)&1){
			return merge[(n+m)/2];
		}
		return (double)(merge[(n+m)/2]+merge[(n+m)/2-1])/2.0;
	}
};




//Solution 2: Optimised Naive Approach   :- We can optimize in space complexity.
// Approach :
// Similar to the naive approach, instead of storing the final merged sorted array, we can keep a counter to keep track of the required position where the median will exist. First, using the median formula, get a position where the median will exist. Then, follow the above approach and instead of storing elements in another array, we will increase the counter value. When the counter value is equal to the median positions, return element.

// Time Complexity : O(m+n)
// Reason – We are still traversing both the arrays linearly.

// Space Complexity: O(1)
// Reason – We do not use any extra array.




//Solution 3: Efficient solution
// Intuition :
// We came up with a naive solution because of the hint that two arrays are sorted and we want elements from merged sorted arrays. If we look into the word “sorted arrays”, we can think of a binary solution. Hence, we move to an efficient solution using binary search. But how to apply binary search? Let’s look into the thought process.
// We know that we will get answers only from the final merged sorted arrays. We figured it out with the naive approach discussed above. We will partition both the arrays in such a way that the left half of the partition will contain elements, which will be there when we merge them, till the median element and rest in the other right half. This partitioning of both arrays will be done by binary search.

// Approach :
// We will do a binary search in one of the arrays which have a minimum size among the two. 
// Firstly, calculate the median position with (n+1)/2. Point two-pointer, say low and high, equal to 0 and size of the array on which we are applying binary search respectively. Find the partition of the array. Check if the left half has a total number of elements equal to the median position. If not, get the remaining elements from the second array. Now, check if partitioning is valid. This is only when l1<=r2 and l2<=r1. If valid, return max(l1,l2)(when odd number of elements present) else return (max(l1,l2)+min(r1,r2))/2.
// If partitioning is not valid, move ranges. When l1>r2, move left and perform the above operations again. When l2>r2, move right and perform the above operations.


//LeetCode :-
class Solution {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
       int n = A.size(), m = B.size();
        if(n > m){
            return findMedianSortedArrays(B, A);        // as we are doing partition with respect to A hence all index in A will be found in B
        }

        int cut1, cut2;
        int l = 0, h = n;

        while(l <= h){
            cut1 = (l + h)/2;                              // length of 1st partition
            cut2=((m + n )/2) - cut1;                   // length of 2nd partition

            int l1, r1, l2, r2;
            l1 = (cut1 == 0) ? INT_MIN : A[cut1-1];        //left cut of first half
            l2 = (cut2 == 0) ? INT_MIN : B[cut2-1];        //left cut of second half
            r1 = (cut1 == n) ? INT_MAX : A[cut1];          //right cut of first half
            r2 = (cut2 == m) ? INT_MAX : B[cut2];          //right cut of second half
            
            if(l1 > r2){
                h = cut1 - 1;
            }
            else if(l2 > r1){
                l = cut1 + 1;
            } 
            else{                               //cond :- if(l1 <= r2 and l2 <= r1)   
                if((m + n) % 2 == 0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                else{
                    return min(r1, r2)*1.0;
                }
                break;
            }
        }
        return 0.0;
    }
};




//Fourth Solution  : -
//Binary search. Call 2 times getkth and k is about half of (m + n). Every time call getkth can reduce the scale k to its half. So the time complexity is log(m + n).

class Solution {
public:
    int getkth(int s[], int m, int l[], int n, int k){
        // let m <= n
        if (m > n) {
            return getkth(l, n, s, m, k);
        }
        if (m == 0){
            return l[k - 1];
        }
        if (k == 1){
            return min(s[0], l[0]);
        }

        int i = min(m, k / 2), j = min(n, k / 2);
        if (s[i - 1] > l[j - 1]){
            return getkth(s, m, l + j, n - j, k - j);
        }
        else{
            return getkth(s + i, m - i, l, n, k - i);
        }
        return 0;
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return (getkth(A, m ,B, n, l) + getkth(A, m, B, n, r)) / 2.0;
    }
};