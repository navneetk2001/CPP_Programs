// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

// Example 1:
// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"

// Example 2:
// Input : "aaab"
// Output : 2
// Explanation : Sub-string -> "ab"
 
// Example 3:
// Input : "GEEKSGEEKSFOR"
// Output : 8
// Explanation : Sub-string -> "GEEKSFOR"




//Solution Approach :-
class Solution{
public:
    int findSubString(string str)
    {
       	unordered_map<char,int>m;
       	for(int i=0;i<str.size();i++){      //store all the characters of the string in map
           	m[str[i]]++;
       	}
      	int k=m.size();            //It will give us no of ditinct elements in the string

       	unordered_map<char,int>mp;
       	int mx=INT_MAX;                   //store the smallest window size
       
       	int i=0, j=0;
       	while(j<str.size()){
        	mp[str[j]]++;
           	if(mp.size()<k){
            	j++;
           	}
            else if(mp.size()==k){
                mx=min(mx,j-i+1);
                while(mp.size()==k){
                    mx=min(mx,j-i+1);
                    mp[str[i]]--;
                    if(mp[str[i]]==0){
                    	mp.erase(str[i]);
                    }
                    i++;
                }
                j++;
            }
             
        }
        return mx;
    }
};



//Second Solution :-
bool check(int *a, int *b) {
    for(int i = 0; i < 60; i++) {
        if(a[i] > 0 && b[i] <= 0) {
            return false;
        }
    }
    return true;
}

int findSubString(string s){
    int n = s.length();
    int freq_1[60] ={0};
    int freq_2[60] = {0};
    
    for(char c : s)
        freq_1[c - 'A']++;
        
    int i = 0;
    int ans = INT_MAX;
    int cur = 0;
    
    for(int j = 0; j < n; j++) {
        freq_2[s[j]-'A']++;
        
        while(check(freq_1,freq_2)){
            cur = j - i + 1;
            ans = min(ans,cur);
            freq_2[s[i] - 'A']--;
            i++;
        }
    } 
    return ans;
}




//Third Solution :-
int findSubString(string str){
    int n=str.size();
    set<char>s;
    unordered_map<char,int>freq;
    
    for(int i=0;i<n;i++){
        s.insert(str[i]);
    }

    int total=s.size();
    int c=0,left=0;
    int mn=n;  //we know that in worst case the minimum length would be n.
    
    for(int right=0;right<n;right++){
        freq[str[right]]++;
        if(freq[str[right]]==1){      //a new char found
            c++;
        }

        while(freq[str[left]]>1){    //left most char is present atleast two times; Is n't the left most char is redundant? Yes, it is. Let't remove the left most ele
            freq[str[left]]--;
            left++;
        }
        if(c==total){  //Number of distinct chars in the current window==total
            mn=min(mn,right-left+1);
        }
    }
    return mn;
}