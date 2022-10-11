// Given a string s, remove all its adjacent duplicate characters recursively. 

// Example 1:
// Input:
// S = "geeksforgeek"
// Output: "gksforgk"
// Explanation: g(ee)ksforg(ee)k -> gksforgk

// Example 2:
// Input: 
// S = "abccbccba"
// Output: ""
// Explanation: ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)



//Solution Approach :-
class Solution{
public:
    string rem(string &s){
        string res = "";
        int i=0,j=0;

        while(i<s.size()){
            j=i+1;
            while(j<s.size() && s[i]==s[j]){
            	j++;
            }

            if(i+1==j){
                res.push_back(s[i]);
                i++;
            }
            else{ 
            	i=j;
            }
        }
        if(s!=res){
        	return rem(res);
        }
        return res;
    }
    
    string remove(string &s){
        return rem(s);
    }
};

//Second Solution :-
