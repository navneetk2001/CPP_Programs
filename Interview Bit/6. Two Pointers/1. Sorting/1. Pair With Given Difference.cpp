// Given an one-dimensional unsorted array A containing N integers.
// You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.
// Return 1 if any such pair exists else return 0.

// Input 1:
// A = [5, 10, 3, 2, 50, 80]
// B = 78
// Output 1: 1
// Explanation 1: Pair (80, 2) gives a difference of 78.

// Input 2:
//  A = [-10, 20]
//  B = 30
// Output 2: 1
// Explanation 2: Pair (20, -10) gives a difference of 30 i.e 20 - (-10) => 20 + 10 => 30

//Hint 
//Create an empty hash table HT. Traverse the array, use array elements as hash keys and enter them in HT. Traverse the array again look for value B + A[i] in HT.

//Solution Approach :-
// Method 1: Brute Force
// The simplest method is to run two loops, the outer loop picks the first element (smaller element) and the inner loop looks for the element picked by outer loop plus B.
// Time complexity of this method is O(N2). This wil not work lets us look on an optimized method.

// Method 2: Sorting + Binary Search
// We can use sorting and Binary Search to improve time complexity to O(NLogN).
// The first step is to sort the array in ascending order.
// Once the array is sorted, traverse the array from left to right, and for each element A[i], binary search for A[i] + B in A[i+1..n-1]. If the element is found, return 1.
// Both first and second steps take O(NLogN). So overall complexity is O(NLogN).
// Time Complexity : O(NlogN + NlogN)

// Method 3: Sorting + Two Pointers
// The second step of the above algorithm can be improved to O(N). The first step remain same.
// The idea for second step:
// Take two index variables i and j, initialize them as 0 and 1 respectively.
// Now run a linear loop. If A[j] – A[i] is smaller than B, we need to look for greater A[j], so increment j.
// If A[j] – A[i] is greater than B, we need to look for greater A[i], so increment i.
// Time Complexity : O(NlogN + N)

// Methos 4: Hashing
// Create an empty hash table HT. Traverse the array, use array elements as hash keys and enter them in HT.
// Traverse the array again look for value B + A[i] in HT.
// Time Complexity: O(N) if we use unordered_map

//First Solution
int Solution::solve(vector<int> &A, int B) {
    if(A.size() == 0){
        return 0;
    }
    int n=A.size();
    sort(A.begin(),A.end());
    int i=0, j=1, diff=0;
    while(i<n && j<n){
        diff=A[j]-A[i];
        if(i!=j && diff==B) {
            return 1;
        }
        else if(diff<B) {
            j++;
        }
        else {
            i++;
        }
    }
    return 0;
}


//Second Solution
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>m;
    for(int i=0;i<A.size();i++){
        m[A[i]]=i;
    }

    for(auto it:A){
        if(m.find(it+B)!=m.end() && m[it+B]!=m[it]){
            return 1;
        }
    }
    return 0;
}

//Third Solution
int Solution::solve(vector<int> &A, int B) 
{
    int max=-99999;
    int min=99999;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i];
    }

    int* m;
    m=(int*)malloc((max-min+1)*sizeof(int));

    if(B>max-min) return 0;
    for(int i=0;i<max-min+1;i++) m[i]=0;
    for(int i=0;i<A.size();i++)
    {
        m[A[i]-min]=1;
    }

    for(int i=0;i<A.size();i++)
    {
        if((A[i]+B<=max) && (A[i]+B>=min)) m[A[i]-min+B]++;
    }

    for(int i=0;i<max-min+1;i++)
    {
        if(B==0)
        {
            if(m[i]>2) return 1;
        }
        else
        {
            if(m[i]>1) return 1; 
        }
    }
    return 0;
}



//Fourth Solution :-
int Solution::solve(vector &A, int B) {
	int n = A.size();
	sort(A.begin(), A.end());
	B = abs(B);

	for(int i=0; i<n-1; i++) {
	    int high = n-1;
	    int low = i+1;
	    int mid;

	    while(low<=high) {
	        mid = (low+high)/2;
	        if(A[mid] - A[i] > B) {
	            high = mid-1;
	        }
	        
	        else if(A[mid] - A[i] < B) {
	            low = mid+1;
	        }
	        
	        else {
	            return 1;
	        }
	    }
	}

	return 0;
}