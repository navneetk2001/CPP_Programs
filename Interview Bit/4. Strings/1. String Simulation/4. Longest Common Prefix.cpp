// Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array.
// Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.
// For Example: longest common prefix of "abcdefgh" and "abcefgh" is "abc".


//Solution Approach
Note: the prefix has to be the prefix of ALL the strings.
So, you can pick any random string from the array and start checking its characters from the beginning in order to see if they can be a part of the common substring.


// First Method :-
string Solution::longestCommonPrefix(vector<string> &A) {
    int mn=INT_MAX;
    if(A.size()==0) {
        return "";
    }

    string c = A[0];   //Assume this as longest Common prefix
    for(int i=1;i<A.size();i++){
        int j=0, k=0;
        int len=0;

        while(j<c.size() and k<A[i].size()){  //check one by one for each string
            if(c[j] == A[i][k]){
                len++;
            }
            else{
                break;
            }
            j++;
            k++;
        }
        mn=min(mn,len);
    }
    return c.substr(0,mn);
}


//Second Method :-
string Solution::longestCommonPrefix(vector<string> &A) 
{
    string s;         
    sort(A.begin(),A.end());    //sorting the strings lexicographically 
    int m,n;
    m=A.size()-1;
    n=min(A[0].length(),A[m].length());
    int i=0;
    //first and last string will be most dissimilar thus finding common charcters in these
    while(i<n && A[0][i]==A[m][i])
    {
        s+=A[0][i];
        i++;
    }
    return s;
}

//Third Method :-
int findMinLength(string arr[], int n)
{
    int min = arr[0].length();
 
    for (int i=1; i<n; i++)
        if (arr[i].length() < min)
            min = arr[i].length();
 
    return(min);
}
 

string commonPrefix(string arr[], int n)
{
    int minlen = findMinLength(arr, n);
 
    string result; // Our resultant string
    char current;  // The current character
 
    for (int i=0; i<minlen; i++)
    {
        // Current character (must be same
        // in all strings to be a part of
        // result)
        current = arr[0][i];
 
        for (int j=1 ; j<n; j++)
            if (arr[j][i] != current)
                return result;
 
        // Append to result
        result.push_back(current);
    }
 
    return (result);
}


