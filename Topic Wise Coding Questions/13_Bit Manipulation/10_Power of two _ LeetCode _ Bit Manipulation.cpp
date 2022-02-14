bool isPowerOfTwo(int n){
	if(n<0) return false;

	int cnt=0;
	while(n){
		cnt++;
		n=n&(n-1);
	}
	if(cnt==1) return true;
	else return false;
}


//Second approach :- 
bool isPowerOfTwo(int n){
	if(n<0) return false;

	if((n &(n-1)) == 0) return true;
	else return false;
}