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
//idea
    //x= p*k+ rem;--------------let x be total sum till i
    //y=q*k+rem;---------------let y be cany prefix  sum before i let sat at j
    //x-y=(p-q)*k;-------------then from j to i =x-y  is  divisble by k
    //conclusion : x-y is divisble by k so we need to just store remainders
    
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum=0,rem,mx=0;
	    unordered_map<int,int> mp;

	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        rem=sum%k;

	        if(rem==0){
	            mx=max(mx,i+1);
	        }
	        if(rem<0){    //if remainder is negative add +k to make it positive (e.g. -4 whose remainder will be -1 when divided by 3)
	        	rem+=k;
	        }
	        if(mp.find(rem) != mp.end()){   //if rem is already found in map
	            mx=max(i-mp[rem], mx);
	        }
	        else{
	            mp[rem]=i;
	        }
	    }
	    return mx;
	}
};