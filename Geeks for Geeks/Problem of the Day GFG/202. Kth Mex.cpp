https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-2-for-amazon-alexa/problems/


// You are given an array A of N integers. Find the Kth MEX of A.
// The Kth MEX of an array is equal to the Kth smallest non-negative integer that is not present in the array. 

// Example 1:
// Input:
// N = 4, K = 3,
// A = { 7, 5, 7, 1 }
// Output: 3
// Explanation: The values which are not present in A are: 0, 2, 3, 4, 5..., out of which the 3rd samllest value is 3.

// Example 2:
// Input:
// N = 1, K = 1,
// A = { 2 }
// Output: 0
// Explanation: The values which are not present in A are: 0, 1, 3, 4, 5..., out of which 0 is the samllest value.




//Solution Approach :- 
int kthMex(int N, int k, int A[]) {
    unordered_map<int,int> mp;
    
    for(int i=0; i<N; i++){   //iterate for all the elements and insert it in map
    	mp[A[i]]++;
    }
    
    for(int i=0; ;i++){      //start checking from 0 and see if it's present in map or not
    	if(!mp[i]){          //if not present in map then decrement the vount of k
    		k--;
    	}
    	if(k==0){
    		return i;
    	}
    }
    return -1;    //if kth smallest not present then return -1
}



//Second Solution :- 
//K will always be from 0 to 2*N, so we can also do it using an array of size 2*N
int kthMex(int N, int k, int A[]) {
    int mp[2*N + 2] = {0};
    
    for(int i=0; i<N; i++){   //iterate for all the elements and insert it in map
    	if(A[i] <= 2*N){
    		mp[A[i]]++;
    	}
    }
    
    for(int i=0; ;i++){      //start checking from 0 and see if it's present in map or not
    	if(!mp[i]){          //if not present in map then decrement the vount of k
    		k--;
    	}
    	if(k==0){
    		return i;
    	}
    }
    return -1;    //if kth smallest not present then return -1
}