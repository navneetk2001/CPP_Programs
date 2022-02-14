//Sort an arrays in wave form

void Wave_sort(int arr[], int n){
	//inplace sorting
	for(int i=0;i<n;i+=2){
		//prev element
		if(i!=0 && arr[i]<arr[i-1]){
			swap(arr[i],arr[i-1]);
		}
		//next element
		if(i!=(n-1) && arr[i]<arr[i+1]){
			swap(arr[i], arr[i+1])
		}
	}
}


// a- {1,3,4,2,7,5}

//One Approach :-
//sort and swap the alternate element