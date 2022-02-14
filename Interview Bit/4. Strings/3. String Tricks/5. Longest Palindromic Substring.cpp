Given a string A of size N, find and return the longest palindromic substring in A.
Substring of string A is A[i...j] where 0 <= i <= j < len(A)

Palindrome string:
A string which reads the same backwards. More formally, A is palindrome if reverse(A) = A.
Incase of conflict, return the substring which occurs first ( with the least starting index).

Example Input
A = "aaaabaaa"

Example Output
"aaabaaa"

//Hint :-
A common mistake:
Some people will be tempted to come up with a quick solution, which is unfortunately flawed (however can be corrected easily):
Reverse S and become S’. Find the longest common substring between S and S’, which must also be the longest palindromic substring.
This seemed to work, let’s see some examples below.
For example,
S = “caba” 
S’ = “abac”
The longest common substring between S and S’ is “aba”, which is the answer.

Let’s try another example:
S = “abacdfgdcaba”
S’ = “abacdgfdcaba”
The longest common substring between S and S’ is “abacd”. Clearly, this is not a valid palindrome.
We could see that the longest common substring method fails when there exists a reversed copy of a non-palindromic substring in some other part of S. To rectify this, each time we find a longest common substring candidate, we check if the substring’s indices are the same as the reversed substring’s original indices. If it is, then we attempt to update the longest palindrome found so far; if not, we skip this and find the next candidate.
This gives us a O(N2) DP solution which uses O(N2) space (could be improved to use O(N) space). Please read more about Longest Common Substring here.

Brute force solution, O(N3):
The obvious brute force solution is to pick all possible starting and ending positions for a substring, and verify if it is a palindrome. There are a total of C(N, 2) such substrings (excluding the trivial solution where a character itself is a palindrome).
Since verifying each substring takes O(N) time, the run time complexity is O(N3).

Dynamic programming solution, O(N2) time and O(N2) space:
To improve over the brute force solution from a DP approach, first think how we can avoid unnecessary re-computation in validating palindromes. Consider the case “ababa”. If we already knew that “bab” is a palindrome, it is obvious that “ababa” must be a palindrome since the two left and right end letters are the same.

Stated more formally below:
Define P[ i, j ] ← true iff the substring Si … Sj is a palindrome, otherwise false.
Therefore,
P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj )
The base cases are:
P[ i, i ] ← true
P[ i, i+1 ] ← ( Si = Si+1 )
This yields a straight forward DP solution, which we first initialize the one and two letters palindromes, and work our way up finding all three letters palindromes, and so on…
Can you come up with a O(N^2) time complexity and O(1) space solution ?



//Solution Approach :-



// First Method :-
string Solution::longestPalindrome(string A) {
    int max=0;
    string ans;
	int n=A.length();
	for(int i=0;i<n;i++){
		//odd length
		int l=i;
		int r=i;
		while(l>=0 && r<n && A[l]==A[r]){
			int curr_l=r-l+1;
			if(curr_l>max){
				max=curr_l;
                ans=A.substr(l,r-l+1);
			}
			l--;
			r++;
		}
		
		//even length
		l=i;
		r=i+1;
		while(l>=0 && r<n && A[l]==A[r]){
			int curr_l=r-l+1;
			if(curr_l>max){
				max=curr_l;
                ans=A.substr(l,r-l+1);
			}
			l--;
			r++;
		}	
	}
    return ans;
}


//Second Method :-
string Solution::longestPalindrome(string A) {
	int s=0,e=0;
	int n=A.length();
	vector<vector<bool>>dp(n,vector<bool>(n,0));
	for(int i=0;i<n;i++){
	    dp[i][i]=true;
	}
	for(int l=2;l<=n;l++){
	    for(int i=0;i<=n-l;i++){
	        int j=i+l-1;
	        if(A[i]==A[j]){
	            if(l==2){
	                dp[i][j]=true;
	            }else{
	                dp[i][j]=dp[i+1][j-1];
	            }
	        }else{
	            dp[i][j]=0;
	        }
	        if(dp[i][j]==true){
	            if(j-i>e-s){
	                s=i;
	                e=j;
	            }
	        }
	    }
	}
	string ans="";
	for(int i=s;i<=e;i++){
	    ans+=A[i];
	}
	return ans;
}


//Third Method :-
string Solution::longestPalindrome(string s) {
    int m = s.size();
    string ans = "";
    for (int k = 0; k < m; k++) {
        string a = s.substr(k);
        string temp = a;
        reverse(temp.begin(), temp.end());
        a = a + '~' + temp;
        int n = a.size();
        vector<int> lps(n);
        lps[0] = 0;
        int i = 0, j = 1;
        while (j < n) {
            if (a[i] == a[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                if (i == 0) {
                    lps[j++] = 0;
                } else {
                    i = lps[i - 1];
                }
            }
        }
        int len = lps[n - 1];
        if (len > ans.size()) {
            ans = a.substr(0, len);
        }
    }
    return ans;
}


//Fourth Solution :-
string inserthash(string A){
    int len = A.size();
    string s = "";
    for(int i = 0; i< len; i++){
        s.insert(s.size(), 1, '#');
        s.insert(s.size(),1,A[i]);
    }
    s.insert(s.size(), 1, '#');
    return s;
}
string removehash(string B){
    int len = B.size();
    string s="";
    for(int i =0 ; i<len; i++){
        if(B[i]!='#'){
            s.insert(s.size(),1,B[i]);
        }
    }
    return s;
}
string Solution::longestPalindrome(string A) {
    int n=A.length();
    int s=0,f=0;
    int mx=1;
    int l=0,r=-1;
    vector<int> d1(n,0),d2(n,0);
    for(int i=0; i<n; i++)
    {
	    int k=(i>r)?1:min(d1[l+(r-i)],r-i+1);
	    while(i-k>=0&&i+k<n&&A[i-k]==A[i+k])
	        k++;
	    d1[i]=k;
	    k--;
	    if(2*k+1>mx||(2*k+1==mx&&i-k<s))
	    {
	        s=i-k;
	        f=i+k;
	        mx=2*k+1;
	    }
	    if(i+k>r)
	    {
	        l=i-k;
	        r=i+k;
	    }
	}

    l=0;
    r=-1;
    for(int i=0; i<n; i++)
    {
		int k=(i>r)?0:min(d2[l+(r-i)+1],r-i+1);
	    while(i-k-1>=0&&i+k<n&&A[i-k-1]==A[i+k])
	        k++;
	    d2[i]=k;
	    k--;
	    if(2*k+2>mx||(2*k+2==mx&&i-k-1<s))
	    {
	        s=i-k-1;
	        f=i+k;
	        mx=2*k+2;
	    }

	    if(i+k>r)
	    {
	        l=i-k-1;
	        r=i+k;
	    }
	}
    return A.substr(s,mx);
}




