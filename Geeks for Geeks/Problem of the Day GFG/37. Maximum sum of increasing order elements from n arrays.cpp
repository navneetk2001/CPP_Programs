// Given n arrays of size m each. Find maximum sum obtained by selecting a number from each array such that the element selected from the i-th array is more than the element selected from (i-1)-th array. If maximum sum cannot be obtained then return 0.

// Example 1:
// Input : arr[ ] = {{1,7,4,3}, {4,2,5,1}, {9,5,1,8}}
// Output : 18
// Explanation:
// We can select 4 from the first array,
// 5 from second array and 9 from the third array.

// Example 2:
// Input : arr[ ] = {{9,8,7}, {6,5,4}, {3,2,1}} 
// Output :  0



//Solution :-
int maximumSum(int n, int m, vector<vector<int>>&a){
	for(int i=0;i<n;i++){
		sort(a[i].begin(), a[i].end());   //sort all arrays
	}

	int start=a[n-1][m-1];  //taking last element of last row as starting element for finding sum as it will be the largest element
	int end=m-1;            //taking column number to be last
	int sum=a[n-1][m-1];    //first, sum will be the starting element and then we will keep on increasing

	for(int i=n-2;i>=0;i--){   
		if(a[i][m-1]<start){   //if starting element is greater than the greatest element of previous row
			sum+=a[i][m-1];    //add that number in the sum itself 
			start=a[i][m-1];   // and then make it as starting element for next row
		}
		else{                 //if starting element is less than the greatest element of previous row
			while(a[i][end]>=start && end>=0){   //then we will keep on decreasing the colum number till we find such number
				end--;
			}
			if(end<0){       //if we reach tothe end of column then return 0, as no such sum found
				return 0;
			}
			else{            //else add it to sum 
				sum+=a[i][end];
				start=a[i][end];
				end=m-1;
			}
		}
	}
	return sum;
}


//Second Solution :-
//Short and crisp without sorting
int maximumSum( int n,int m, vector<vector<int>> &a) {

    // Complete the function
    int sum=0,temp=INT_MAX;
    for(int i=n-1;i>=0;i--){
        int maxe=INT_MIN;
        for(int j=m-1;j>=0;j--){
            if(a[i][j]<temp)
            maxe = max(maxe, a[i][j]);
        }
        if(maxe == INT_MIN)
        return 0;
        temp = maxe;
        sum += maxe;
    }
    return sum;
}