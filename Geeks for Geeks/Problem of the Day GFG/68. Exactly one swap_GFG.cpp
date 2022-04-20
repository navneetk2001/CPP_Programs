// Given a string S containing lowercase english alphabet characters. The task is to calculate the number of distinct strings that can be obtained after performing exactly one swap.
// In one swap,Geek can pick two distinct index i and j (i.e 1 < i < j < |S| ) of the string, then swap the characters at the position i and j.

// Example 1:
// Input:
// S = "geek"
// Output: 6
// Explanation: 
// After one swap, There are only 6 distinct strings 
// possible.(i.e "egek","eegk","geek","geke","gkee" and "keeg")
 

// Example 2:
// Input:
// S = "ab"
// Output: 1
// Explanation:
// Only one string is possible after one swap(i.e "ba")



//Solution Approach :-
class Solution
{
public:
    long long countStrings(string S)
    {
        //Formula for n distinct character ( n * (n-1) )/ 2
        long long res = (S.size() * (S.size() - 1))/2;
        long long arr[26] = {0};
        
        for(char ch : S)
            arr[ch - 'a']++;
            
        int j = 0;
        for(int i = 0; i< 26; i++)
        {
            if(arr[i] > 1)
            {   
                //Remove the count of repeating strings 
                res = res - (arr[i] * (arr[i] - 1))/2;
                j++;
            }
        }
        // +1 for the repeated strings 
        return j == 0 ? res : res+1;
    }
};



//Second Solution :-
long long countStrings(string S)
{
    //Formula for n distinct character(n*(n-1))/2
    long long ans = S.size() * (S.size() - 1LL) >> 1;
    int cnt[26] = {0};
    bool original = false;
    for(int i = 0  ;i <  S.size() ; ++i){
        ans -= cnt[S[i] - 'a']  ;
        if(++cnt[S[i] - 'a'] == 2) 
            original = true ;
    }
    return ans + original; 
}