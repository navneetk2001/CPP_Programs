int firstBadVersion(int n){
	int low=1;
	int high=n;

	int mid;
	int result=n;
	while(low<=high){
		mid = low +(high-low)/2;
		if(isBadVersion(mid)){
			result=mid;
			high=mid-1;
		}
		else{
			low=mid+!;
		}
	}
	return result;
}