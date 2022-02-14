Given an array arr[] of N elements. Find the number of non-empty subsets whose product of elements is less than or equal to a given integer K.
Example 1:
Input:
N = 4
arr[] = {2, 4, 5, 3}
K = 12
Output:
8
Explanation:
All possible subsets whose 
products are less than 12 are:
(2), (4), (5), (3), (2, 4), (2, 5), (2, 3), (4, 3)

Example 2:
Input:
N = 3
arr[] = {9, 8, 3}
K = 2 
Output:
0
Explanation:
There is no subsets with product less
than or equal to 2.




Steps:-
//Concept of meet in the middle
//1. Partition in 2 parts on middle as :- A1 with multiplication subsets(a1, a2, a3, etc.) 
// and A2 with multiplication subsets(b1, b2, b3, etc. (b1<b2<b3)
// we need to maintain a1 * b1 <= k
// k = subset1[i] * subset2[j]

int numOfSubsets(int arr[], int n, int k){
	//declare four vector for dividing array into two haves
	//and storing product value for possble subsets for them
	vector<int> vect1, vect2, subset1, subset2;

	//ignore elements greater than k and divide array in 2 halves
	for(int i=0;i<n;i++){
		//ignore element if greater than k
		if(arr[i]>k){
			continue;
		}
		if(i<=n/2){
			vect1.push_back(arr[i]);
		}
		else{
			vect2.push_back(arr[i]);
		}
	}

	//generate all subsets for first half (vect1)
	for(int i=0;i<(1<<vect1.size());i++){
		int value=1;
		for(int j=0;j<vect1.size();j++){
			if(i & (1<<j))
				value*=vect1[j];
			if(value>k)
				break;
		}

		//push only in case subset product is less than or equal to k
		if(value<=k){
			subset1.push_back(value);
		}
	}

	//generate all subsets for second half (vect2)
	for(int i=0;i<(1<<vect2.size());i++){
		int value=1;
		for(int j=0;j<vect2.size();j++){
			if(i & (1<<j))
				value*=vect2[j];
			if(value>k)
				break;
		}

		//push only in case subset product is less than or equal to k
		if(value<=k){
			subset2.push_back(value);
		}
	}

	//sort subset2
	sort(subset2.begin(), subset2.end());
    
    //count no.of elements 
	int count=0;
	for(int i=0;i<subset1.size();i++){
    	count+=upper_bound(subset2.begin(), subset2.end(), (k/subset1[i])) - subset2.begin();
    }

	//for null subset, decrement the value of count
	count--;

	//return count;
	return count;
}




