// Given an array A containing N integers.
// You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.
// If no such triplet exist return 0.

// Input 1: A = [2, 5, 3, 1, 4, 9]
// Output 1: 16
// Explanation 1: All possible triplets are:-
//     2 3 4 => sum = 9
//     2 5 9 => sum = 16
//     2 3 9 => sum = 14
//     3 4 9 => sum = 16
//     1 4 9 => sum = 14
//   Maximum sum = 16

// Input 2: A = [1, 2, 3]
// Output 2: 6
// Explanation 2: All possible triplets are:- 1 2 3 => sum = 6
//  Maximum sum = 6



//Solution Approach
// Simple Approach is to traverse for every triplet with three nested ‘for loops’ and find update the sum of all triplets one by one. Time complexity of this approach is O(N3) which is not sufficient for larger value of ‘N’.

// Better approach is to make further optimization in above approach.
// Instead of traversing through every triplets with three nested loops, we can traverse through two nested loops.
// While traversing through each number(assume as middle element(Aj)), find maximum number(Ai) smaller than Aj preceding it and maximum number(Ak) greater than Aj beyond it.
// Now after that, update the maximum answer with calculated sum of Ai + Aj + Ak.
// Time complexity: O(N2)
// Auxiliary space: O(1)
// This approach is also that much efficient we are looking for.

// Best Approach:
// Best and efficient approach is use the concept of maximum suffix-array and binary search.
// For finding maximum number greater than given number beyond it, we can maintain a maximum suffix-array array such that for any number(suffix[i]) it would contain maximum number from index i, i+1, … N-1. Suffix array can be calculated in O(N) time.
// For finding maximum number smaller than the given number preceding it, we can maintain a sorted list of numbers before a given number such we can simply perform a binary search to find a number which is just smaller than the given number. In C++ language, we can perform this by using set associative container of STL library.
// Time complexity: O(NlogN)
// Auxiliary space: O(N)




//First Method :-
int Solution::solve(vector<int> &A) {
    int n=A.size();
    int ans=0;
    
    vector<int>right(n+1);    //right suffix array
    right[n] = 0; 
    for(int i=n-1;i>=0;i--){
        right[i] = max(right[i + 1], A[i]); 
        // if(i==n-1)right[i]==A[i];
        // else{
        //     right[i]=max(right[i+1],A[i]);   //best on right side
        // }
    }
    
    //best on left side
    set<int>s;
    s.insert(A[0]);
    for(int i=1;i<n;i++){
        s.insert(A[i]);
        // 2 5 3 1 4 9
        // set : {2,5}
        auto it=s.find(A[i]);
        if(it!=s.begin() && right[i]!=A[i])
            ans=max(ans,(*--it)+A[i]+right[i]);
    }
    return ans;
}


//Second Method :-
int Solution::solve(vector<int> &A) {
    int n= A.size();
    if(n<3)
    return 0;
   int mx=0, ans=0;
   for(int i=n-1;i>1;i--)
   {
       if(A[i]<mx)
       continue;
    int x=-1,y=-1;
        for(int j=i-1; j>=0; j--){
            if(A[j]<A[i]){
                if(x==-1)x=A[j];
                else{
                    if(A[j]>x){
                        y=-1;
                        x=A[j];
                    }
                    else if(A[j]>y && A[j]!=x)y=A[j];
                }
            }
            if(x!=-1&&y!=-1)ans=max(ans,A[i]+x+y);
        }
        
        mx = max(mx,A[i]);
    }
    return ans;
}


//Third Method :-
int maxTripletSum(int arr[], int n){
	int ans = 0;

	for (int i = 1; i < n - 1; ++i) {
		int max1 = 0, max2 = 0;

		// find maximum value(less than arr[i]) from 0 to i-1
		for (int j = 0; j < i; ++j){
			if (arr[j] < arr[i]){
				max1 = max(max1, arr[j]);
            }
        }

		// find maximum value(greater than arr[i]) from i+1 to n-1
		for (int j = i + 1; j < n; ++j){
			if (arr[j] > arr[i]){
				max2 = max(max2, arr[j]);
            }
        }

		// store maximum answer
		if(max1 && max2){
			ans=max(ans,max1+arr[i]+max2);
        }
	}

	return ans;
}

