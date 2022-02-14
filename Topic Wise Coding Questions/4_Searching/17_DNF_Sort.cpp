//Sort an arrays of 0s, 1s & 2s

void dnf_sort(int a[], int n){
	//inplace sorting
	int lo=0;
	int hi=n-1;
	int mid=0;

	while(mid<=hi){
		if(a[mid]==0){
			swap(a[mid],a[lo]);
			lo++;
			mid++;
		}
		if(a[mid]==1){
			mid++;
		}
		if(a[mid]==2){
			swap(a[mid],a[hi]);
			hi--;
		}
	}
}