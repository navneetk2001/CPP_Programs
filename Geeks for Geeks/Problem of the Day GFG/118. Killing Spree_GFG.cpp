// There are Infinite People Standing in a row, indexed from 1.
// A person having index 'i' has strength of (i*i).
// You have Strength 'P'. You need to tell what is the maximum number of People You can Kill With your Strength P.
// You can only Kill a person with strength 'X' if P >= 'X'  and after killing him, Your Strength decreases by 'X'. 
 
// Example 1:
// Input:
// N = 14
// Output: 3
// Explanation: The strengths of people is 1, 4, 9, 16, .... and so on. WE can kill the first 3 person , after which our Power becomes 0 and we cant kill anyone else. So answer is 3
 

// Example 2:
// Input: N = 10
// Output: 2




//Solution Approach :- Naive Approach :-
class Solution {
public:
    long long int killinSpree(long long int n){
        long long int count=0;
        long long int i=1;
        
        while(n>=(i*i)){
            count++;
            n = n-(i*i);
            i++;
        }
        return count;
    }
};



//Second Solution :- Binary Search 
long long int killinSpree(long long int n){   
	long long int low=1, high=sqrt(n),mid;
    
    while(low<=high){
        mid=low+(high-low)/2;
        long long int curr=(mid*(mid+1)*(2*mid+1))/6;
        if(curr==n){
        	return mid;
        }
        else if(curr<n){
        	low=mid+1;
        }
        else{
        	high=mid-1;
        }
    }
    return low-1;
}


//Third Solution :- 
long long int fun(long long int n){
   long long int ans;
   ans=(n*(n+1)*(2*n+1))/6;
   return ans;
}

long long int killinSpree(long long int n){
    if(n==1){
    	return 1;
    }
    long long int low,high,mid,ans;
    low=1,high=1e5;
    
    while(low<=high){
        mid=low+(high-low)/2;
        
        if(fun(mid)==n){
        	return mid;
        }
        if(fun(mid)<n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}