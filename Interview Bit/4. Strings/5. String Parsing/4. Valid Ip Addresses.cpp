// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

// Example:
// Given “25525511135”,
// return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order.

//Hint :-
//You need to place only 3 dots and every segment should be a valid one.

//Solution Approach :-
// Brute force works here.
// Essentially you have to place 3 dots in the given string.
// Try out all the possible combinations for the 3 dots.
// Corner case:
// 25011255255
// 25.011.255.255 is not valid as 011 is not valid.
// 25.11.255.255 is not valid either as you are not allowed to change the string.
// 250.11.255.255 is valid.


// First Method :- Giving some wrong answer (Backtracking)
bool isValid(string a) {
    if(a.size()>3 || a.size()<1) {
        return false;
    }
    if(a.size()==2 || a.size()==3) {
        if(a[0]=='0') {
            return false;
        }
        int p = stoi(a);
        if(p>255 || p<0) {
            return false;
        }
    }
    return true;
}

void helper(string s, int i, int par, string ans, vector<string>&res){
	if(i==s.length() || par==4){
		if(s.length()==i && par==4){
			res.push_back(ans.substr(0,ans.length()-1));
		}
		return;
	}
	helper(s,i+1,par+1, ans+s[i]+'.',res);

	if(i+2<=s.length() && isValid(s.substr(i,i+2))){
		helper(s,i+2,par+1, ans+s.substr(i,i+2)+'.', res);
    }

	if(i+3<=s.length() && isValid(s.substr(i,i+3))){
		helper(s,i+3,par+1, ans+s.substr(i,i+3)+'.', res);
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
	vector<string>res;
    helper(A,0,0,"",res);
    return res;
}


//Second Method :-
bool isValid(string a) {
    if(a.size()>3 || a.size()<1) {
        return false;
    }
    if(a.size()==2 || a.size()==3) {
        if(a[0]=='0') {
            return false;
        }
        int p = stoi(a);
        if(p>255 || p<0) {
            return false;
        }
    }
    return true;
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    if(A.size()>12 || A.size()<4) {
        return ans;
    }
    for(int i=1; i<A.size()-2; i++) {
        for(int j=i+1;j<A.size()-1;j++) {
            for(int k=j+1;k<A.size();k++) {
                string a = A.substr(0,i-0);
                string b = A.substr(i,j-i);
                string c = A.substr(j,k-j);
                string d = A.substr(k,A.size()-k);
                if(isValid(a)&&isValid(b)&&isValid(c)&&isValid(d)) {
                    string temp = a + "." + b + "." + c + "." + d;
                    ans.push_back( temp);
                }
            }
        }
    }
    return ans;
}


//Third Method :-
class Solution {
public:
    vector<string> restoreIpAddresses(string s)  {
        vector<string> ans;
        if (s.size() > 12 || s.size() < 4)
            return ans;

        for (int i = 1; i < 4; i++) {
            string first  =  s.substr(0, i);
            if (!isValid(first))
                continue;
            for (int j = 1; i + j < s.size() && j < 4; j++) {
                string second  =  s.substr(i, j);
                if (!isValid(second))
                    continue;
                for (int k = 1; i + j + k < s.size() && k < 4; k++) {
                    string third = s.substr(i + j, k);
                    string fourth = s.substr(i + j + k);
                    if (isValid(third) && isValid(fourth)) {
                        string current  =  first + "." + second + "." + third + "." + fourth;
                        ans.push_back(current);
                    }
                }
            }
        }

        return ans;
    }

    bool isValid(string s) {
        if (s.size() > 1 && s[0]  ==  '0')
            return false;
        if (stoi(s) <= 255 && stoi(s) >= 0)
            return true;
        else
            return false;
    }
};
