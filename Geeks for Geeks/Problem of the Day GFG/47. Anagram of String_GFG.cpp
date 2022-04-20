// Given two strings S1 and S2 in lowercase, the task is to make them anagram. The only allowed operation is to remove a character from any string. Find the minimum number of characters to be deleted to make both the strings anagram. Two strings are called anagram of each other if one of them can be converted into another by rearranging its letters.

// Example 1:
// Input:
// S1 = bcadeh
// S2 = hea
// Output: 3
// Explanation: We need to remove b, c and d from S1.

// Example 2:
// Input:
// S1 = cddgk
// S2 = gcd
// Output: 2
// Explanation: We need to remove d and k from S1.



// function to calculate minimum numbers of characters to be removed to make two strings anagram
int remAnagram(string str1, string str2){
	vector<int> f1(26,0), f2(26,0);
	for(auto e:s1){
		f1[e-'a']++;
	}
	for(auto e:s2){
		f2[e-'a']++;
	}
	int ans=0;
	for(int i=0;i<26;i++){
		ans+=abs(f1[i] - f2[i]);
	}

	return ans;
}



//Approach :- Sorting 
int remAnagram(string s , string t){
   int i = 0 , j = 0 ;
   int m = s.size() , n = t.size() ;
   
   sort(s.begin(),s.end()) ;
   sort(t.begin(),t.end()) ;
   
   int ans = 0 ;
   
   while(i<m && j<n)
   {
       if(s[i]==t[j])
       {
           i++ ; j++ ; 
       }
       else if(s[i]<t[j])
       {
           i++ ; ans++ ;
       }
       else
       {
           j++ ; ans++ ;
       }
   }
   
   ans+=(m-i) ; ans+=(n-j) ;
   
   return ans ;
   
}