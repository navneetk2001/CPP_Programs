void counting_sort(vector<int> &A, int n){
    int n=A.size();
	//largest in the array assuming no > 0
	int largest=-1;
	for (int i = 0; i < n; ++i)
	{
		largest=max(largest,A[i]);
	}

	//create a freq array
	int *freq = new int[largest+1]{0};
	for (int i = 0; i < n; ++i)
	{
		freq[a[i]]++;
	}

	//put the elements back into the array a by reading freq array
	int j=0;
	for (int i = 0; i <= largest; ++i)
	{
		if(freq[i]>0){
			while(freq[i]>0){
				a[j]=i;
				freq--;
				j++;
			}
		}
	}
}