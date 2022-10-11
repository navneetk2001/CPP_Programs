https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1



//Solution Approach :- 
int minElements(int arr[], int n){
	int halfSum = 0;      	// calculating HALF of array sum
	for(int i = 0; i < n; i++){
		halfSum = halfSum + arr[i];
	}
	halfSum = halfSum / 2;

	sort(arr, arr + n, greater<int>());   	// sort the array in descending order.

	int res = 0, curr_sum = 0;
	for(int i = 0; i < n; i++){
		curr_sum += arr[i];
		res++;
		if (curr_sum > halfSum){       		// current sum greater than sum	
			return res;
		}
	}
	return res;
}




//Second Solution :-
  int minSubset(vector<int> &Arr,int N){
       
       long long int sum=0;
       for(auto x:Arr)
       sum+=x;
       
       sort(Arr.begin(),Arr.end());
       
       long long int temp=0;
       for(int i=N-1;i>=0;i--)
       {
           temp+=Arr[i];
           if(sum<(2*temp))
               return N-i;
       }
       
       return N;
   }

