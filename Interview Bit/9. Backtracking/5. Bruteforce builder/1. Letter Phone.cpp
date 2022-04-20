// Given a digit string, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below.
// The digit 0 maps to 0 itself.
// The digit 1 maps to 1 itself.
// Input: Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Make sure the returned strings are lexicographically sorted.

//Solution Approach :- 
For every integer, you have 1/3/4 options. Try appending every letter in the option to the string and move forward.

//First Solution :-
void findall(string word, int i, vector<string>&keypad, vector<string>&ans, string digits, int n){
    if(i == n){   
        ans.push_back(word);
        return;
    }
    string digit=keypad[digits[i]-'0'];
    for(int j=0;j<digit.length();j++)
    {
        findall(word + digit[j],i+1,keypad,ans,digits,n);
    }
}

vector<string> Solution::letterCombinations(string A) {
    int n=A.size();
    if(A.empty()) return {};
    vector<string>k(10);
    k[0]="0";
    k[1]="1";
    k[2]="abc";
    k[3]="def";
    k[4]="ghi";
    k[5]="jkl";
    k[6]="mno";
    k[7]="pqrs";
    k[8]="tuv";
    k[9]="wxyz";
    vector<string>ans;
    findall("",0,k,ans,A,n);
    return ans;
}


//Second Solution :- 
class Solution {
public:
    const vector<string> pad = {
        "0", "1", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
		vector<string> result;
        result.push_back("");
        
        for(auto digit: digits) {
            vector<string> tmp;
            for(auto candidate: pad[digit - '0']) {
                for(auto s: result) {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};


//Third Solution :- 
// first we will make a vector of strings to store all the possible characters which can be generated when a particular number key is pressed(number >= 2 and number <= 9, according to constraints) , like shown below -
// vector<string> keys = {"0 will not be pressed" , "1 will not be pressed", "abc" , "def" , "ghi" , "jkl", "mno" , "pqrs", "tuv" , "wxyz"};
// now we can assume this as a graph where a particular key has several children like key 2 has childs -> 'a' , 'b' , 'c'.
// if a key is pressed then our answer should have all the possible charactes from that key for that given position.
// and we will include all posible characters until size of the combinationString(a string which includes all possible combinations from given digits) is not equal to size of digits string.
// Once length of digits (string) == length of combination string will get satisfied, we will include that string in our ans.

vector<string> letterCombinations(string digits) {
      vector<string> v = {"0" , "1" , "abc" , "def" , "ghi" , "jkl", "mno" , "pqrs", "tuv" , "wxyz"};
  	 // to store all possible letter combianations
      vector<string> ans;
      string temp="";
  	 // bfs implementation
      queue<string> q;
      q.push(temp);
  	 // if no digit is pressed, no letter combinations will be there
      if(!digits.size() ) return ans;
      while(!q.empty())
      {
  		 // get the top most element from the queue and pop it from queue
          string top = q.front();
          q.pop();
  	   	// if no. of digits pressed(given) == characters obtained by pressing digits
          if(top.size() == digits.size()) 
  			ans.push_back(top);
          else
          {
  		 	// include all possible characteres which can be obtained, when a next digit will be pressed
              temp = v[digits[top.length()] - '0'];
              for(auto ch: temp) q.push(top + ch);
          }
      }
      return ans;
  }



//Fourth Solution :-
class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[])
    {
        if(index >= digit.length())
        {
            ans.push_back(output);
            return;
        }
        
        int num = digit[index] - '0';
        string value = mapping[num];
        
        for(int i=0; i<value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        if(digits.length() == 0)    return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};