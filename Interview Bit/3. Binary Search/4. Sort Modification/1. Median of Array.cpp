// There are two sorted arrays A and B of size m and n respectively.
// Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).
// The overall run time complexity should be O(log (m+n)).


//Hint 1
The expected time complexity gives away binary search in this case.
We are going to do binary search for the answer in this case.

Given a sorted array A of length m, we can split it into two parts:
{ A[0], A[1], … , A[i - 1] }	{ A[i], A[i + 1], … , A[m - 1] }
All elements in right part are greater than elements in the left part.

The left part has i elements, and right part has m - i elements.
There are m + 1 kinds of splits.
(i = 0 ~ m)
When i = 0, the left part has “0” elements, the right part has “m” elements.
When i = m, the left part has “m” elements, right part has “0” elements.

For the array B, we can split it in the same way:
{ B[0], B[1], … , B[j - 1] }	{ B[j], B[j + 1], … , B[n - 1] }
The left part has “j” elements, and right part has “n - j” elements.

Put A’s left part and B’s left part into one set. (Let’s name this set “LeftPart”)
Put A’s right part and B’s right part into one set. (Let’s name this set”RightPart”)

        LeftPart           |            RightPart
{ A[0], A[1], … , A[i - 1] }	{ A[i], A[i + 1], … , A[m - 1] }
{ B[0], B[1], … , B[j - 1] }	{ B[j], B[j + 1], … , B[n - 1] }
If we can ensure the following:
LeftPart’s length == RightPart’s length (or RightPart’s length + 1)
All elements in RightPart is greater than elements in LeftPart,
then we can split all elements in {A, B} into two parts with equal length, and one part is always greater than the other part.

Then the median can thus be easily found.

Based on condition 1, can you derive the value of j if value of i is known?
Can you binary search on i ?


// First Method :-
double Solution::findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    if (n > m) return findMedianSortedArrays(nums2, nums1);
        
    int l = 0, h = n;
    
    while(l <= h)
    {
        int cut1 = (l + h) / 2;
        int cut2 = ((m + n) / 2) - cut1;
        
        
        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
        
        int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];
        
        if(l1 > r2) h = cut1 - 1;
        else if(l2 > r1) l = cut1 + 1;
        else
        {
            if((m + n) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / (2.0);
            }
            else
            {
                return min(r1, r2) * 1.0;
            }
            break;
        }
    }
}



//Second Method :-
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n1=A.size(), n2=B.size();
    if(n1>n2){
    	return findMedianSortedArrays(B,A);
    }

    int low=0, high=n1;   //to find where to cut the first array so all elements in one side becomes sorted

    while(low<=high){
        int cut1=(low+high)/2;  // cutting in left array
        int cut2=((n1+n2)/2) - cut1; //cutting in right array
        
        int left1 = (cut1 == 0) ? INT_MIN : A[cut1-1];  // finding rightmost element in first array
        int left2 = (cut2 == 0) ? INT_MIN : B[cut2-1];  // finding rightmost element in second array

        int right1 = (cut1 == n1) ? INT_MAX : A[cut1];  // finding lefttmost element in first array
        int right2 = (cut2 == n2) ? INT_MAX : B[cut2];  // finding lefttmost element in second array

        if(left1 > right2){   
        	high=cut1-1;
        }
        else if(left2 > right1){
        	low=cut1+1;
        }
        else{   //checking for right cut as our elements are in correct order or not
        	if((n1+n2) % 2 == 0){   //if even
        		// int mx=max(left1,left2);
                // int mn=min(right1,right2);
                // return mx+mn/2.0;
                return (max(left1, left2) + min(right1, right2)) / (2.0);
            }  
        	else{   //if odd
        		return min(right1,right2)*1.0;
            }
        }
    }
    return 0.0;
}



//Third Method :-
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0;
        int j=0;
        int k=0;
        
        vector<double>output;
        while(i<m&&j<n)
        {
            if(nums1[i]<nums2[j])
            {
                output.push_back(nums1[i]);
                i++;
            }
            else
            {
               output.push_back(nums2[j]);
               j++; 
            }
        }
        
        while(i<m)
        {
            output.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            output.push_back(nums2[j]);
            j++;
        }
        
        int index=output.size();
        double median;
        if(index%2==0)
        {
            median=(output[index/2]+output[(index/2)-1])/2;
            return median;
        }
        else
        {
            median=output[index/2];
            return median;
        }
    }
};


