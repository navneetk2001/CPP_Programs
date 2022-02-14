Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221

Example 1:
Input:
n = 5
Output: 111221
Explanation: The 5th row of the given pattern
will be 111221.

Example 2:
Input:
n = 3
Output: 21
Explanation: The 3rd row of the given pattern
will be 21.



//Recursive Solution :-
class Solution
{
  public:
    string lookandsay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";

        string result=lookandsay(n-1);
        string newresult="";
        int count=1;

        for(int i=1;i<result.size();i++){
        	if(result[i]!=result[i-1]){
        		newresult.push_back('0'+count);//'0'+count is converting int to char
        		newresult.push_back(result[i-1]);
        		count=1;
        	}
        	else{
        		count++;
        	}
        	if(i==result.size()-1){
        		newresult.push_back('0'+count);
        		newresult.push_back(result[i]);
        	}
        }
        return newresult;
    }   
};




//Second Solution :-
string Solution::countAndSay(int A) {
    if(A==1) return "1";
    if(A==2) return "11";

    string ans="11";
    for(int i=3;i<=A;i++){
        string temp_str="";
        ans=ans+'&';
        int count=1;
        for(int j=1;j<ans.length();j++){
            if(ans[j]!=ans[j-1]){
                temp_str=temp_str+to_string(count);
                temp_str=temp_str+ans[j-1];
                count=1;
            }
            else{
                count++;
            }
        }
        ans=temp_str;
    }
    return ans;
}