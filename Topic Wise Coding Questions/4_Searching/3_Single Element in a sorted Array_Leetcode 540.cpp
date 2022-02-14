Array :- [1,1,2,2,3,4,4]
         return 3;

->array is guaranteed to have unique element
-> Array is in non-decreasing order(Ascending)

// First Approach :- TAke xor of each element it will return single sorted element        


//Second Approach :- Binary Search 
(1) Bounary check
(2) Pair Index Property
(3) Unique element Property
(4) Partition Property


int singleNonDuplicate(vector<int>&nums){
	int high=nums.size()-1;
	int low=0;
	int mid;

	//Boundary Cases
	if(high==0){
		return nums[0];
	}
	else if(nums[0]!=nums[1]){
		return nums[0];
	}
	else if(nums[high]!=nums[high-1]){
		return nums[high];
	}

	while(low<=high){
		mid =low +(high-low)/2;
		//unique element condition
		if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
			return nums[mid];

		if((mid%2==0 && nums[mid]!=nums[mid+1]) || (mid%2==1 && nums[mid]!=nums[mid-1]))
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}