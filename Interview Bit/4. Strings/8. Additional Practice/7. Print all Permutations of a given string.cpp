Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.

Example 1:
Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .

Example 2:
Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.



void helper(string str, int st, vector<string> &ans){
        if(st == str.size()){
            ans.push_back(str);
            return;
        }
        
        for(int i=st; i<str.size(); i++){
            swap(str[st],str[i]);
            helper(str,st+1,ans);
            swap(str[st],str[i]);
        }
}

class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
	         vector<string> ans;
             helper(S,0,ans);
             sort(ans.begin(),ans.end());
             return (ans);
		}
};