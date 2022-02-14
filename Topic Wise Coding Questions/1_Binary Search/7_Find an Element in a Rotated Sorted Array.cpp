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
