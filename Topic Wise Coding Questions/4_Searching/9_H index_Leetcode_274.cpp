int hIndex(vector<int> &citations){
	sort(citations.begin(),citations.end());

	int n=citations.size();
	if(n==0)
		return 0;

	if(citations[0]>=n){
		return n;
	}

	int low=0;
	int high=n-1;
	int mid;
	int candidate=0;

	while(low<=high){
		mid=low+(high-low)/2;
		if(citations[mid]>=n-mid){
			candidate=n-mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return candidate;
}




