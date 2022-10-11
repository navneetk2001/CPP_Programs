// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// Example:
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem


// First Method :-
int Solution::isPalindrome(string A) {
    string s="";
    int n=0;
    while(A[n]!='\0'){
        n++;
    }
    
    for(int i=0;i<n;i++)
    {
        if((A[i]>='A'&&A[i]<='Z')||(A[i]>='0'&&A[i]<='9'))
        {
            s+=A[i];
            continue;
        }
        else if((A[i]>='a'&&A[i]<='z'))
        {
            s+= A[i]-32;
        }        
    }

    int l = 0;
    while(s[l]!='\0'){
        l++;
    }
    
    int i=0,j=l-1;
    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
            return 0;
    }
    return 1;
}

//Second Method :-
int Solution::isPalindrome(string a) {
	int n=a.length();
	stack<char>s;
	queue<char>q;
	for(int i=0;i<n;i++){
		if(isupper(a[i])){
			a[i]=tolower(a[i]);
		}
		if(a[i]<='z' && a[i]>='a' || a[i]>=48 && a[i]<=57){
			s.push(a[i]);
			q.push(a[i]);
		}
	}

	int ans=1;
	while(!s.empty()){
		if(s.top()!=q.front()){
			ans=0;
			return ans;
		}
		s.pop();
		q.pop();
	}
	return ans;
}


//Third Method :-
class Solution {
    public:
        bool isPalindrome(string s) {
            int i = 0, j = (int)s.size() - 1;
            while(i < j)
            {
                while(i < j && !isalnum(s[i])) i++;
                while(i < j && !isalnum(s[j])) j--;
                if (toupper(s[i]) != toupper(s[j])) return false; 
                i++;
                j--;
            }
            return true;
        }

};


//Fourth method :-
int Solution::isPalindrome(string A) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str = "";
    for(int i = 0; i < A.length(); i++)
    {
        if( (A[i] >= 'a' and A[i] <= 'z') or (A[i] >= 'A' and A[i] <= 'Z') or (A[i] >= '0' and A[i] <= '9') )
        {   
            str+=A[i];
        }
    }
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'A' and str[i] <= 'Z')
            str[i] = str[i]-'A'+'a';
    }
    string tmp = str;
    reverse(str.begin(), str.end());
    if(tmp == str)
        return 1;
    return 0;
}


