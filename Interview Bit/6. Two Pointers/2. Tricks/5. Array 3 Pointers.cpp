// You are given 3 arrays A, B and C. All 3 of the arrays are sorted.
// Find i, j, k such that :
// max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
// Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))
// **abs(x) is absolute value of x and is implemented in the following manner : **
//       if (x < 0) return -x;
//       else return x;

// Example :
// Input : 
//         A : [1, 4, 10]
//         B : [2, 15, 20]
//         C : [10, 12]

// Output : 5 
//          With 10 from A, 15 from B and 10 from C. 


//Hint 
// The bruteforce solution is to pick one element each from a, b and c in a loop. O(N^3).
// Obviously something better is required in this case .
// A better approach might be to:
// Iterate over all elements of a,
// Binary search for element just smaller than or equal to in b and c, and note the difference.
// Repeat the process for b and c. O(n log n).
// *Note: As we move over the element in a, the elements in b and c that we are trying to find will also move forward. *

//Solution Approach :-
// Windowing strategy works here.
// Lets say the arrays are A,B and C.

// Take 3 pointers X, Y and Z
// Initialize them to point to the start of arrays A, B and C
// Find min of X, Y and Z.
// Compute max(X, Y, Z) - min(X, Y, Z).
// If new result is less than current result, change it to the new result.
// Increment the pointer of the array which contains the minimum.
// Note that we increment the pointer of the array which has the minimum, because our goal is to decrease the difference. Increasing the maximum pointer is definitely going to increase the difference. Increase the second maximum pointer can potentially increase the difference ( however, it certainly will not decrease the difference ).

//First Solution
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int ans=INT_MAX;
    int p1=0, p2=0, p3=0;   //pointers for traversing these 3 arrays
    while(p1<A.size() and p2<B.size() and p3<C.size()){
        ans=min(ans, max(abs(A[p1]-B[p2]), max(abs(B[p2]-C[p3]), abs(C[p3]-A[p1]))));
        if(A[p1]<=B[p2] and A[p1]<=C[p3]){
            p1++;
        }
        else if(B[p2]<=A[p1] and B[p2]<=C[p3]){
            p2++;
        }
        else{
            p3++;
        }
    }
    return ans;
}


//Second Solution
class Solution {
public:
    int minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
        int diff = INT_MAX;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int i, j, k;
        for(i = 0, j = 0, k = 0; i < a.size() && j < b.size() && k < c.size();) {
            minimum = min(a[i], min(b[j], c[k]));
            maximum = max(a[i], max(b[j], c[k]));
            diff = min(diff, max - min);
            if (diff == 0) break;
            if (a[i] == minimum) i++;
            else if (b[j] == minimum) j++;
            else k++;
        }
        return diff;
    }
};

//Third Solution
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int a,b,c,x,y,z,diff1,diff2,diff3,temp;
	a = 0; b = 0; c = 0;
	x = A.size();
	y = B.size();
	z = C.size();
	int ans = INT_MAX;
	
	while(a<x && b<y && c<z){
	   diff1 = abs(A[a]-B[b]);
	   diff2 = abs(B[b]-C[c]);
	   diff3 = abs(C[c]-A[a]);
	   ans = min(ans,max(diff1,max(diff2,diff3)));
	   temp = max(diff1,max(diff2,diff3));
	   if(temp==diff1){
	     if(A[a]==min(A[a],B[b])) 
	       a++;
	     else
	       b++;
	   }
	   else if(temp==diff2){
	         if(B[b]==min(B[b],C[c]))
	          b++;
	         else
	          c++;
	   }
	   else{
	     if(C[c]==min(C[c],A[a]))
	      c++;
	     else
	      a++;
	   }
	}
	return ans;
}



