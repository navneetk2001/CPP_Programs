https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/





// Follow the steps mentioned below to implement the idea:  

// Use a recursive function to implement binary search to find the key:
// Find middle-point mid = (l + h)/2 
// If the key is present at the middle point, return mid.
// Else if the value at l is less than the one at mid then arr[l . . . mid] is sorted
// If the key to be searched lies in the range from arr[l] to arr[mid], recur for arr[l . . . mid].
// Else recur for arr[mid+1 . . . h]  
// Else arr[mid+1. . . h] is sorted: 
// If the key to be searched lies in the range from arr[mid+1] to arr[h], recur for arr[mid+1. . . h].
// Else recur for arr[l. . . mid] 



//Approach :- 
int search(int arr[], int lo, int hi, int key){
    // l: The starting index
    // h: The ending index, you have to search the key in this range
    
    //complete the function here
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==key) return mid;
        else if(arr[lo]<=arr[mid]){
            if(arr[lo]<=key && key<arr[mid]){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }else{
            if(arr[mid]<=key && key<arr[hi]){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
    }
    return -1;
}





//Solution :- 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int start=0;
        int end = nums.size()-1;
        if (n==1)
            return nums[0];
        while (start<=end){
            int mid= start+ (end-start)/2;
            int prev=(mid+n-1)%n;
            int next= (mid+1)%n;
            if (nums[mid]<nums[prev] && nums[mid]<nums[next])
                return nums[mid];
            else if(nums[end]<nums[mid])
                start = mid+1;
            else 
                end= mid-1;
        }
        return -1;
    }
};




// Second Method :-
int Solution::search(const vector<int> &arr, int B) {
    int start = 0, end = arr.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==B) return mid;
        if(arr[mid]>arr[start]){
            if(arr[mid]>B && arr[start]<=B) end = mid-1;
            else start =mid+1;
        }
        else{
            if(arr[mid]<B && arr[end]>=B) start = mid+1;
            else end = mid-1;
        }
    }
    
    return -1;
}





