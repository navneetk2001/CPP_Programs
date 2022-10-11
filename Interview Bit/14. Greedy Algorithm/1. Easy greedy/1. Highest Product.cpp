// Given an array A, of N integers A.
// Return the highest product possible by multiplying 3 numbers from the array.
// NOTE:  Solution will fit in a 32-bit signed integer.

// Input 1: A = [1, 2, 3, 4]
// Output 1: 24
// Explanation 1: 2 * 3 * 4 = 24

// Input 2: A = [0, -1, 3, 100, 70, 50]
// Output 2: 350000
// Explanation 2: 70 * 50 * 100 = 350000


//Hint :-
//There are only two possibilites for the maximum number 2 negatives and one postive or 3 positives,take the max of both the cases.

//Solution Approach :- 
// Do we need to consider all the elements from the array ?
// Is it enough to consider just the 3 maximum numbers from the array ? Obviously No. Product of 2 negative numbers is positive. So, Negative numbers with higher absolute value might also be of interest.
// How about maximum 3 elements, and 2 negative elements with the highest absolute value ?


//First Solution :-
int Solution::maxp3(vector<int> &A) {
    sort(A.begin(),A.end());
    int N = A.size();
    return max(A[0]*A[1]*A[N-1] , A[N-1]*A[N-2]*A[N-3]);
}


//Second Solution :-
int Solution::maxp3(vector&lt;int&gt; &amp;arr) {
    int n=arr.size();
    
    if(n &lt; 3){    // if size is less than 3, no triplet exists
        return -1;
    }
 
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;    // Initialize Maximum, second maximum and third maximum element     
    int minA = INT_MAX, minB = INT_MAX;      // Initialize Minimum and second mimimum element
 
    for(int i = 0; i &lt; n; i++){
        if(arr[i] &gt; maxA){         // Update Maximum, second maximum and third maximum element
            maxC = maxB;
            maxB = maxA;
            maxA = arr[i];
        }
        else if(arr[i] &gt; maxB){           // Update second maximum and third maximum element
            maxC = maxB;
            maxB = arr[i];
        }
        else if(arr[i] &gt; maxC){             // Update third maximum element
            maxC = arr[i];
        }
 
        if(arr[i] &lt; minA){         // Update Minimum and second mimimum element
            minB = minA;
            minA = arr[i];
        }
        else if(arr[i] &lt; minB){       // Update second mimimum element
            minB = arr[i];
        }
    }

    return max(minA * minB * maxA, maxA * maxB * maxC);
}


//Third Solution :- 
int Solution::maxp3(vector<int> &A) {
    int size=A.size();
    int i;
    int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
    int neg1=0,neg2=0;
    
    for(i=0;i<size;i++){
        if(A[i]>=max1){
            max3=max2;
            max2=max1;
            max1=A[i];
        }
        else if(A[i]>=max2){
            max3=max2;
            max2=A[i];
        }
        else if(A[i]>=max3){
	        max3=A[i];
        }

        if(A[i]<0){
            if(A[i]<=neg1){
                neg2=neg1;
                neg1=A[i];
            }
            else if(A[i]<=neg2){
                neg2=A[i];
            }
        }
    }

    if(neg1 && neg2){
        return max(neg1*neg2*max1,max1*max2*max3);
    }
    else{ 
    	return max1*max2*max3;
    }
}


