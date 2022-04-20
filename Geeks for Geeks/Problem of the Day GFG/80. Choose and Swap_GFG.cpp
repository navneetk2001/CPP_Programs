You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:
Input:
A = "ccad"
Output: "aacd"
Explanation: In ccad, we choose a and c and after doing the replacement operation once we get, 
aacd and this is the lexicographically smallest string possible. 
 
Example 2:
Input: A = "abba"
Output: "abba"
Explanation: In abba, we can get baab after doing the replacement operation once for a and b 
but that is not lexicographically smaller than abba. So, the answer is abba. 



//Solution :-
// Approach  :-  Replace the leftmost character with the smallest possible character that is only present on the right side.
string chooseandswap(string a){
    int charr[26];
    int n=a.size();
    memset(charr,-1,sizeof(charr));
    for(int i=0;i<n;i++){
        if(charr[a[i]-'a']==-1){
      	   charr[a[i]-'a']=i;
      	}
    }

   int i=0,j=0;
   for(i=0;i<n;i++){
       bool flag=false;
       for(j=0;j<a[i]-'a';j++){
           if(charr[j] > charr[a[i]-'a']){
               flag=true;
               break;
           }
       }
       if(flag)
       break;
   }

   if(i<n){
	    char ch1=a[i];
	    char ch2=char(j+'a');
	    for( i=0;i<n;i++){
	        if(a[i]==ch1){
	      	    a[i]=ch2;
	        }
	        else if(a[i]==ch2){
	            a[i]=ch1;
	        }
	    } 
    }

    return a;
}


//Sexond Solution :-

//Time Complexity     : O(N)
//Space Complexity    : O(1)

string chooseandswap(string a){
    int found[26] = {0};
    char max_so_far = CHAR_MIN ;
    char smallest   = CHAR_MAX ;

    for(int i = 0  ; i < a.size() ; ++i){
        if(found[a[i] - 'a'] == 0 && a[i] < max_so_far){
            for(int j = i ; j < a.size() ; ++j){
                if(found[a[j] - 'a'] == 0){
                    smallest = min(smallest , a[j]) ;
                }
                found[a[j] - 'a'] = 1 ;
            }
            for(int j = i - 1 ; j >= 0 ; --j){
                if(a[j] > smallest){
                    max_so_far = a[j] ;
                }
            }
            break;
        }
        max_so_far = max(max_so_far , a[i]);
        found[a[i] - 'a'] = 1 ;
    }
    if(max_so_far != CHAR_MIN && smallest != CHAR_MAX){
        for(int i = 0 ; i < a.size() ; ++i){
            if(a[i] == max_so_far){
                a[i] = smallest ;
            }
            else if(a[i] == smallest){
                a[i] = max_so_far ;
            }
        }
    }
    return a;
}


//Third Solution :- Using Set
string chooseandswap(string a){
    unordered_set<char> st;
    int n = a.length();
    for(int i = 0; i < n; i++)
    {
        char smallest = a[i];
        for(int j = i + 1; j < n; j++)
        {
            if(st.find(a[j]) == st.end() && smallest > a[j])
            {
                smallest = a[j];
            }
        }

        if(smallest != a[i])
        {
            char toChange = a[i];
            for(int j = 0; j < a.length(); j++)
            {
                if(a[j] == smallest)
                {
                    a[j] = toChange;
                }
                else if(a[j] == toChange)
                {
                    a[j] = smallest;
                }
            }
            return a;
        }
        st.insert(a[i]);
    }

    return a;
}



//Fourth Solution :-
#define MAX 26

string smallestStr(string str, int n)
{
    int i, j;
    // To store the first index of
    // every character of str
    int chk[MAX];
    for (i = 0; i < MAX; i++)
        chk[i] = -1;

    // Store the first occurring
    // index every character
    for (i = 0; i < n; i++) {

        // If current character is appearing
        // for the first time in str
        if (chk[str[i] - 'a'] == -1)
            chk[str[i] - 'a'] = i;
    }

    // Starting from the leftmost character
    for (i = 0; i < n; i++) {

        bool flag = false;

        // For every character smaller than str[i]
        for (j = 0; j < str[i] - 'a'; j++) {

            // If there is a character in str which is
            // smaller than str[i] and appears after it
            if (chk[j] > chk[str[i] - 'a']) {
                flag = true;
                break;
            }
        }

        // If the required character pair is found
        if (flag)
            break;
    }

    // If swapping is possible
    if (i < n) {

        // Characters to be swapped
        char ch1 = str[i];
        char ch2 = char(j + 'a');

        // For every character
        for (i = 0; i < n; i++) {

            // Replace every ch1 with ch2
            // and every ch2 with ch1
            if (str[i] == ch1)
                str[i] = ch2;

            else if (str[i] == ch2)
                str[i] = ch1;
        }
    }

    return str;
}