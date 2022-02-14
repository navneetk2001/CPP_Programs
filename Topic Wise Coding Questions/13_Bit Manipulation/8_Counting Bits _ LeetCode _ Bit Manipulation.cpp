vector<int> countBits(int num){
	vector<int> res;
	for(int i=0;i<=num;i++){
		int cnt=0;
		int n=i;
		while(n){
			cnt++;
			n=n&(n-1);
		}
		res.push_back(cnt);
	}
	return res;
}