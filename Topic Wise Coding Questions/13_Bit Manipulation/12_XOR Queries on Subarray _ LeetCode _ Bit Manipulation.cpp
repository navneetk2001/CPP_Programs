vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){
	int n=arr.size();

	int pre[n];
	pre[0]=arr[0];
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]^arr[i];
	}

	vector<int>res;
	for(int i=0;i<queries.size();i++){
		int L=queries[i][0];
		int R=queries[i][1];

		if(L==0) res.push_back(pre[R]);
		else res.push_back(pre[R] ^ pre[L-1]);
	}
	return res;
}