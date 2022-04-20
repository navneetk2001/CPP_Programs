// Given a binary array A and a number B, we need to find length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.

// Input:
//  A = [1, 0, 0, 1, 1, 0, 1]
//  B = 1
// Output 1:
//  4
// Explanation 1:
//  Here, we should only change 1 zero(0). Maximum possible length we can get is by changing the 3rd zero in the array,
//  we get a[] = {1, 0, 0, 1, 1, 1, 1}

//Hint 
We can solve this problem using two pointers technique.
Let us take a subarray [l, r] which contains at most k zeroes

//Solution Approach :-
Let us take a subarray [l, r] which contains at most k zeroes.
Let our left pointer be l and right pointer be r. We always maintain our subsegment [l, r] to contain no more than k zeroes by moving the left pointer l.
Check at every step for maximum size (i.e, r-l+1).
Space Complexity: O(1)
Time Complexity: O(N)

//First Solution
int Solution::solve(vector<int> &A, int B) {
    int flips=0;   //no of flips done till yet
    int ans=0;
    int i=0;   //for moving forward
    int j=0;   // unflipping when required
    int n=A.size();

    while(i<n){
        if(A[i]==0){
            flips++;
        }
        while(flips > B){
            //unflip previous 0 because you can't move forward
            if(A[j]==0){
                flips--;
            }
            j++;
        }
        
        //length of subsegment will be :- i-j+1
        ans=max(ans,i-j+1);
        i++;
    }
    return ans;
}


//Second Solution  :- Sliding window Approach :- 
#define ll long long int
int Solution::solve(vector &a, int k) {
	ll n = a.size() ;
	ll l=0, r=0, len=0, ans = INT_MIN ;
	// run as a sliding window type
	while(l<n && r<n){
	    if(a[r] == 1){
	        r++; // just move the right pointer ahead
	        len++ ;
	    }
	    else{ // a[r] == 0 case
	        // here also 2 case arises
	        if(k){
	            k-- ; // decrease k by 1 and make the flip happen
	            r++ ;
	            len++ ;
	        }
	        else{ // now we have to move our l pointer ahead this time
	            if(a[l] == 0){
	                k++ ;
	                l++ ;
	                len-- ;
	            }
	            else{ // a[l] == 1 case
	                len-- ;
	                l++ ;
	            }
	        }
	    }	    
	    ans = max(ans, len) ;
	}
	ans = max(ans, len) ;
	return ans ;
}

//Third Solution
int Solution::solve(vector &A, int B) {
	vector<int>zeros;
	int ans = 0;
	for(int i = 0; i<A.size(); i++){
		if(A[i]==0) 
			zeros.push_back(i);
		if(zeros.size()<=B) 
			ans = max(ans, i+1);
		else 
			ans = max(ans, i-zeros[zeros.size()-B-1]);
	}
	return ans;
}




