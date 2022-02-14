// You are given two strings A and B.
// Check whether there exists any permutation of both A and B such that they are equal.
// Return a single integer 1 if its exists, 0 otherwise.


//Solution Approach
For any permutation of a given string, the frequency of each character will never change.
So, if we check the frequency all the characters of both the strings.
We can find out if they can be permuted to form an equal string.
We can simply do this by keeping an auxillary array to keep the count of the characters.
And checking if all the indexes have equal frequency.



// First Method :-
int Solution::permuteStrings(string A, string B) {
    int m=A.size();
    int n=B.size();
    if(m!=n){
        return 0;
    }
    vector<int>freq(26,0);
    for(int i=0;A[i]!='\0';i++){
        freq[A[i]-'a']+=1;
    }

    for(int i=0;B[i]!='\0';i++){
        if(freq[B[i]-'a']==0){
            return 0;
        }
        freq[B[i]-'a']-=1;
    }
    return 1;
}


//Second Method :-
int Solution::permuteStrings(string A, string B) {
	if(A.length()!=B.length()){
		return 0;
	}

	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(int i=0;i<A.length();i++)
	{
	    if(A[i]!=B[i])
	    {
	        return 0;
	    }
	}
	return 1;
}

//Third Method :-
int Solution::permuteStrings(string A, string B) {
    int lena=A.size();
    int lenb=B.size();
    if(lena!=lenb) return 0;
    int map[26]={0};
    for(int i=0;i<lena;i++){
        if(!A[i]) map[A[i]-'a']=1;
        else map[A[i]-'a']++;
        map[B[i]-'a']--;
    }
    for(int j=0;j<26;j++){
        if(map[j]!=0) return 0;
    }
    return 1;
}


//Fourth Method :-
int Solution::permuteStrings(string a, string b) {
  int n=a.length();
  int m=b.length();
  if(n!=m)
    return 0;
    vector<int>arr(26,0);
    vector<int>brr(26,0);
        for(int i=0;i<n;i++)
        {
            arr[a[i]-'a']++;
        }
        for(int j=0;j<m;j++)
        {
            brr[b[j]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=brr[i])
              return 0;
        }
        return 1;   
}





