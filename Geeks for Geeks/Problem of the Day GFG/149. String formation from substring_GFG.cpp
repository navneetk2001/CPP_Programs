// Given a string s, the task is to check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 

// Example 1:
// Input: s = "ababab"
// Output: 1
// Explanation: It is contructed by 
// appending "ab" 3 times

// Example 2:
// Input: s = "ababac"
// Output: 0
// Explanation: Not possible to construct



//Solution Approach :-
// 1. check all sizes which are divisor of size n of string ( number of divisors are very small for even very big numbers, you can check it yourself. 
// 2. for every divisor, take string's starting of that length.
// 3. add this substring n/size times to get n sized repeated string.
// 4. if this is equal to original string, return 1. If no string is found which when repeated produces original string, return 0.

int isRepeat(string& s){
    int n = s.size();
    for(int size=1; size<n; size++){
        if(n%size){     //if size is not a divisor of n
            continue;
        }
        string t = s.substr(0,size);     // for every divisor, taking starting substring of that length
        string b;
        for(int i=0; i<n/size; i++){     //add this substring n/size times to get n sized repeated string
            b += t;
        }
        if(b == s){
            return 1;
        }
    }
    return 0;
}



//Second Solution :- 
int isRepeat(string s)
{
  int i=1, j=0;
  int n= s.length();
  while(i<s.length())
  {
      if(s[j]==s[i]){
          i++;
          j++;
      }
      else{
          i=i-j+1;
          j=0;
      }
  }
 if(j==0)return 0;
 return n%(n-j)==0;
}



//Third Solution :- Using KMP Algo
int isRepeat(string& s){
    int lps[s.length()] = {0};
	int i = 1;
	int len = 0;
	int n = s.length();
	int res  = 0;

	while(i < s.length() ){
	    int k = i;
	    while(s[i] == s[len]){
	        lps[i] = len + 1;
	        res = max(res,lps[i]);
	        len++;i++;
	        }
	     if(s[i] != s[len]){
	        if(len == 0){
	            lps[i] = 0;i++;
	        }else{
	            len = lps[len - 1];
	        }
	    }
	}

	if(res == 0) return 0;
	string t = s.substr(0,n - res);
	string ans = "";
	int k = n/t.length();
	while(k--){
	   ans += t;
	}
	if(ans == s) return 1;
	return 0;
}


