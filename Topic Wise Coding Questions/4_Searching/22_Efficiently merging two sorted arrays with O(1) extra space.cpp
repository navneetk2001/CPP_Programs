https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1




//Solution Approach :- 
class Solution{
public:
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) 
    { 
        int i = 0, j = n - 1;
	    while(j >= 0 and i < m)
	    {
	        if(arr1[j] > arr2[i]){
	            swap(arr1[j], arr2[i]);
	        }
	        j--;
	        i++;
	    }
	    sort(arr1, arr1 + n);
	    sort(arr2, arr2 + m);
    } 
};




//Second Solution :-
class Solution {
public:
	//Function to merge the arrays.
	void merge(long long arr1[], long long arr2[], int n, int m)
	{
		vector<int>v;
		for (int i = 0; i < n; i++){
			v.push_back(arr1[i]);
		}
		for (int i = 0; i < m; i++){
			v.push_back(arr2[i]);
		}

		//after push to merge array, sort the merge array
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++){
			arr1[i] = v[i]; 			//after arr1 vlaue equal to merge array index
		}
		for (int i = 0; i < m; i++){
			arr2[i] = v[n + i];    		//merge them after loop n stops
		}
	}
};




//Third SOlution :- GAP METHOD
void merge(long long arr1[], long long arr2[], int n, int m) { 
    float gap = ceil((float)(n + m)/2);

    while(gap != 0){
        int ptr1 = 0, ptr2 = gap;
        while(ptr2 != n + m){
            if(ptr2 < n){
                if(arr1[ptr1] > arr1[ptr2]){
                    swap(arr1[ptr1], arr1[ptr2]);
                    
                }
            }
            else if(ptr1 < n && ptr2 >= n){
                if(arr1[ptr1] > arr2[ptr2-n]){
                    swap(arr1[ptr1], arr2[ptr2-n]);
                    
                }
            }
            else if(ptr1 >= n&& ptr2 >= n){
                if(arr2[ptr1-n] > arr2[ptr2-n]){
                    swap(arr2[ptr1-n],arr2[ptr2-n]);
                    
                }
            } 
            ptr1++;
            ptr2++;
        }

        if(gap == 1){
            break;
        }
        gap = ceil((float)gap/2);
    }
} 



//Fourth Solution :-
void merge(int X[], int Y[], int m, int n)
{
    // Consider each element `X[i]` of array `X` and ignore the element if it is already in the correct order; otherwise, swap it with the next smaller
    // element, which happens to be the first element of `Y`.
    for (int i = 0; i < m; i++){
        if (X[i] > Y[0]){        // compare the current element of `X[]` with the first element of `Y[]`
            swap(X[i], Y[0]);
            int first = Y[0];
 
            // move `Y[0]` to its correct position to maintain the sorted order of `Y[]`. Note: `Y[1…n-1]` is already sorted
            int k;
            for(k = 1; k < n && Y[k] < first; k++) {
                Y[k - 1] = Y[k];
            }
 
            Y[k - 1] = first;
        }
    }
}