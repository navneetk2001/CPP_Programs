bool canConstruct(string ransomNote, string magazine){
	vector<int>magazineHash(26,0);
	for(int i=0;magazine[i]!='\0';i++){
		magazineHash[magazine[i]-'a']+=1;
	}

	for(int i=0;ransomNote[i]!='\0';i++){
		if(magazineHash[ransomNote[i]-'a']==0)
			return false;
		magazineHash[ransomNote[i]-'a']-=1;
	}
	return true;
}