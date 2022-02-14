Given a string A consisting of lowercase characters.
We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.

Example Input:
Input 1:
 A = "abede"
Input 2:
 A = "aabb"

Example Output:
Output 1:
 2
Output 2:
 2


//Hint
Try to learn about LPS array used in KMP string matching algorithm. 
Modify your string and compute its LPS array to derive the answer.

//Solution Approach :-
Each index of LPS array contains the longest prefix which is also a suffix.
Now take the reverse of the string and the string and combine them with a sentinal character in between them and compute the LPS array of this combined string.
Now take the last value of the LPS array and subtract it with the length of the original string, This will give us the minimum number of insertions required in the begining of the string .
Example: Suppose A = “efaba”
Lets form another string B = reverse(A) + “$” + A = “abafe$efaba”
Compute LPS Array
So last value of lps array will be 3 which implie(“aba” is a palindrome)
So we need len(A)-3 appends i.e 2


// First Method :-
int Solution::solve(string A) {
    int n=A.size();
    int l=0, r=n-1;
    int temp=0;

    while(l<=r){
        if(A[l]!=A[r]){
            if(r==n-1){
                l++;
            }
            r=n-1;
            l=temp+1;
            temp=l;
        }
        else{
            l++;
            r--;
        }
    }
    return temp;
}


//Second Method :-
vector<int> computeLPSArray(string s){
    int n = s.length();
    vector<int> LPS(n);
 
    int j = 0;
    LPS[0] = 0; 
 
    
    int i = 1;
    while (i < n){
        if (s[i] == s[j]){
            j++;
            LPS[i] = j;
            i++;
        }
        else{
            if (j != 0){
                j = LPS[j-1];
            }
            else{
                LPS[i] = 0;
                i++;
            }
        }
    }
    return LPS;
}

int Solution::solve(string s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    string c = rs + "$" + s;
    vector<int> LPS = computeLPSArray(c);
    return (s.length() - LPS.back());
}


//Third Method :-
int Solution::solve(string A) {
	int n=A.size()-1;
	int i=0,j=n;
	int start=0,count=0;
	while(i<j){

	    if(A[i]!=A[j]){ 
	        i++;
	        if(count>0)i=start+1;
	        count=0;
	    }
	    if(A[i]==A[j]){
	        if(count==0) start=i;
	        i++;
	        j--;
	        count++;
	    }
	}
	return start;
}


//Fourth Method :-
int getMin(int id, string &s)
{
    if(id == s.length()-1) return 0;

    int j = s.length()-1;
    int i = id;
    bool pal = true;
    while(i < j)
    {
        if(s[i] != s[j])
        {
            pal = false;
            break;
        }
        i++,j--;
    }
    if(pal) return 0;

    return (i-id+1) + getMin(i+1, s);

}

int Solution::solve(string A) {

    return getMin(0, A);
}


//Fifth Method :-
//using KMP

int Solution::solve(string A) {
    int n= A.length();
    int m= 2*n +1; // lps array size
    vector<int> lps (m);
    string res= A;
    reverse(res.begin(),res.end());
    res= res +"$" + A;  // prefix which is also suffix , we will get the size of palindrome
    int i=1,len=0;
    lps[0]=0; // always zero
    while(i<m){
        if(res[len]==res[i]){
            len++;
            lps[i]= len;
            i++;
            continue;
        }
        else{
            if(len>0){
                len= lps[len-1];
                continue;
            }
            else{
                lps[i]=0;
                i++;
                continue;
            }
        }
    }
    
    return n-lps[m-1];
}


//Sixth Method -
int palindrome(string s)
{
    
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        return 0;
    }
    return 1;
}
int Solution::solve(string a) {
    int l=a.size();
    if(palindrome(a)==1)
    return 0;
    int c=0;
    while(l--)
    {
        string s=a.substr(++c);
        if(palindrome(s)==1)
        {
            break;
        }
    }
    return c;
}
