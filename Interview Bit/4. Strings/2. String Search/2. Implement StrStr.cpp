// Another question which belongs to the category of questions which are intentionally stated vaguely.
// Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

// Implement strStr().
// strstr - locate a substring ( needle ) in a string ( haystack ).
// Try not to use standard library string functions for this question.
// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// NOTE: String A is haystack, B is needle.
// Good clarification questions:
// What should be the return value if the needle is empty?
// What if both haystack and needle are empty?
// For the purpose of this problem, assume that the return value should be -1 in both cases.


//Solution Approach :-
Let us first think about a simpler problem. How do you find out if 2 strings are equal?
Implementing strstr is just plain simple simulation.
Consider every index i for the answer. Find if the following 2 strings are equal:
1 Needle string and,
2 String haystack from index i with length the same as needle’s length
Note that the complexity of this solution is O(M*N) where M is length of haystack and N is length of needle.
If you are feeling more adventurous, try solving it in O(M).
*Hint: KMP Algorithm**



// First Method :-
int Solution::strStr(const string A, const string B) {
    int n = A.size();
    int m = B.size();

    int ans = -1;
    for(int i=0;i<n;i++){
        int j = 0;
        int k = i;
        while(A[k]==B[j]){
            if(j==m-1){
                return i;
            }
            j++;
            k++;
        }
    }
    return ans;
}




//Second Method :- Solution using substr
int Solution::strStr(const string A, const string B) {
	char ch = B[0];
	int i=0;
	while(i<A.size()){
		if(A[i]==ch){
			string b = A.substr(i,B.size());
			if(b==B){
				return i;
			}
		}
	    i++;
	}
	return -1;
}


//Third Method :-  Simple c++ stl solution
int Solution::strStr(const string A, const string B) {
	if(A.find(B)!=string::npos)
	{
		int a=A.find(B);
		return a;
	}
	return -1;
}



//Fourth Solution :- C++ KMP Approach
vector<int> prefix(string str)
{
	int n=str.length();
	vector<int> lcs(n);
	int i;
	int temp = 0;
	lcs.push_back(0);
	for(i=1;i<n;i++)
	{
	    int j=lcs[i-1];
	    while(j>0 && str[i]!=str[j])
	    {
	        j=lcs[j-1];
	    }
	    if(str[i]==str[j])
	        j++;
	    lcs[i]=j;
	    
	    
	}
	return lcs;
}

int KMP(string text,string pattern)
{
	int m=text.length(),n=pattern.length();
	vector<int> lcs = prefix(pattern);
	int i=0,j=0;
	while(i<m && j<n)
	{
	    if(text[i]==pattern[j])
	    {
	        i++;
	        j++;
	    }
	    else
	    {
	        if(j!=0)
	            j=lcs[j-1];
	        else
	            i++;
	    }
	}
	if(j==n)
	{
	    return i-n;
	}
	return -1;
}

int Solution::strStr(const string A, const string B) {
	int index = KMP(A,B);
	return index;
}


//Fifth Solution :-
int Solution::strStr(const string A, const string B) {
    int start=0,temp_start=start,j=0;
    while(temp_start<A.size() && j<B.size())
    {
        if(A[temp_start]==B[j])
        {
            temp_start++,j++;
        }
        else
        {
            j=0,temp_start=++start;
        }
        if(j==B.size()) return start;
    }
    return -1;
}



//Sixth Solution :-
int Solution::strStr(const string &haystack, const string &needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n,m,flag,i,j,ans;
    n=haystack.length();
    m=needle.length();
    
    if((m==0)||(n==0))
     return -1;
    
    flag=0;
    for(i=0;i<(n-m+1);i++)
    {
        for(j=0;j<m;j++)
        {
            if(haystack[i+j]==needle[j])
                continue;
            else
                break;
        }
        if(j==m)
        {
            flag=1;
            ans=i;
            break;
        }
    }
    
    if(flag)
        return ans;
    
    return -1;
    
}




//Another Solution :-
int Solution::strStr(const string A, const string B) {

//A is the haystack and the B is the needle 
//we have to find the first index of needle in the haystack and return it 

//first we need to find whether needle exists in haystack or not
// we can create a window that checks whether the string in the window is the correct or not

int size_of_window=B.size();
int n=A.size();

int i=0,j=0;
int index=0;

int flag=0;
while(i<n)
{
    if(A[i]!=B[j])
    {
        j=0;
        // int temp=i;
        i=index+1;
        index=i;
        continue;
    }
    else
        j++; 
    if(j==B.size())
       { flag=1;break;}
    i++;
}

if(index>=n || flag==0)
    return -1;
return index;

}