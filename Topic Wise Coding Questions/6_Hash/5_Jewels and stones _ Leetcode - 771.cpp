int numJewelsInStones(string J, string S){
	unordered_map<char,int>mymap;
	for(int i=0;J[i]!='\0';i++){
		mymap[j[i]]++;
	}

	int count=0;
	for(int i=0;S[i]!='\0';i++){
		if(mymap.find(S[i])!=mymap.end()){
			count+=1;
		}
	}
	return count;
}