// Given an array containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

// Example 1:
// Input:
// A[] = {2, 7, 6, 1, 4, 5}
// K = 3
// Output: 4
// Explanation:The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.

// Example 2:
// Input:
// A[] = {-2, 2, -5, 12, -11, -1, 7}
// K = 3
// Output: 5
// Explanation: The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.




//Solution Approach :-
// Find sum from 0 to x1 is s1 lets say, and its remainder when divided by k is r1.
// Then we need to find an index from 0 to x1-1, say x2, where sum from 0 till x2 is s2 and s2 % k = r1.
// When we subtract sum from 0 to x2  from 0 to x1, we get array x2+1….x1 whose sum of elements is divisible by k. We just need to store the earliest index where sum of elements  % k is found. 

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k){
	    int ans=0;
	    unordered_map<int,int> mp;
	    long long sum=0;
	    mp[0]=-1;
	    for(int i=0;i<n;i++){
	        sum=(sum+arr[i])%k;
	        if(sum<0){
	            sum=(sum+k)%k;
	        }
	        if(mp.find(sum) != mp.end()){
	            ans=max(i-mp[sum], ans);
	        }
	        else{
	            mp[sum]=i;
	        }
	    }
	    return ans;
	}
};




//Second Solution :-
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k){
	    int sum=0,rem,mx=0;
	    unordered_map<int,int> mp;

	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        rem=sum%k;

	        if(rem==0){
	            mx=max(mx,i+1); 
	        }
	        if(rem<0){    //if remainder is negative add +k to make it positive
	        	rem+=k;
	        }
	        if(mp.find(rem) != mp.end()){
	            mx=max(i-mp[rem], mx);
	        }
	        else{
	            mp[rem]=i;
	        }
	    }
	    return mx;
	}
};
