Given a array of N strings, find the longest common prefix among all strings present in the array.

Example 1:
Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common prefix in all the given strings.

Example 2:
Input: 
N = 2
arr[] = {hello, world}
Output: -1
Explanation: There is no common prefix in the given strings.


string longestCommonPrefix(string arr[], int N){
	string ans;
	int j=0;
	bool check=true;

	while(check){
		for(int i=0;i<N;i++){
			if((j>=(int)arr[i].size()) || (arr[i][j] != arr[0][j])){
				check=false;
				break;
			}
		}
		if(check){
			ans+=arr[0][j];
		}
		j++;
	}

	return ans.length()?ans:"-1";
}



//Another Method :-
// A Utility Function to find the common prefix between
// strings- str1 and str2
string commonPrefixUtil(string str1, string str2)
{
    string result;
    int n1 = str1.length(), n2 = str2.length();

    // Compare str1 and str2
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++)
    {
        if (str1[i] != str2[j])
            break;
        result.push_back(str1[i]);
    }

    return (result);
}

// A Function that returns the longest common prefix
// from the array of strings
string commonPrefix (string arr[], int n)
{
    string prefix =  arr[0];

    for (int i=1; i<=n-1; i++)
        prefix = commonPrefixUtil(prefix, arr[i]);

    return (prefix);
}