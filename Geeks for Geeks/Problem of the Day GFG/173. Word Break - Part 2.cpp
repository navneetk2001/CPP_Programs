// Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.
// Follow examples for better understanding.

// Example 1:
// Input: s = "catsanddog", n = 5 
// dict = {"cats", "cat", "and", "sand", "dog"}
// Output: (cats and dog)(cat sand dog)
// Explanation: All the words in the given sentences are present in the dictionary.

// Example 2:
// Input: s = "catsandog", n = 5
// dict = {"cats", "cat", "and", "sand", "dog"}
// Output: Empty
// Explanation: There is no possible breaking of the string s where all the words are present in dict.




//Solution Approach :-
void dfs(string &s,unordered_set <string> &st,string ans,vector<string> &res){
    if(s.length()==0){
        ans.pop_back();         // to pop the extra space
        res.push_back(ans);
        return;
    }

    for(int i=0;i<s.length();i++){
        string left = s.substr(0,i+1);
        if(st.find(left)!=st.end()){
            string right = s.substr(i+1);
            dfs(right,st,ans+left+" ",res);
        }
    }
}

vector<string> wordBreak(int n, vector<string>& dict, string s){
    vector<string> res;
    unordered_set<string> st(dict.begin(), dict.end());
    dfs(s,st,"",res);
    return res;
}



//Second Solution :- Backtracking
class Solution{
public:
    vector<string> ans;
    void solve(int last, int index, string &s, vector<string> make, unordered_map<string, int> &mp){
        if(index == s.size()){
            string curr;
            for(int i = 0; i < make.size(); i++){
                if(i == make.size() - 1){
                    curr += make[i];
                }
                else{
                    curr += make[i] + ' ';
                }
            }
            ans.push_back(curr);
            return;
        }

        for(int i = index; i < s.size(); i++){
            string temp = s.substr(last, i - last + 1);
            if(mp[temp]){
                make.push_back(temp);
                solve(i + 1, i + 1, s, make, mp);
                make.pop_back();
            }
        }
    }

    vector<string> wordBreak(int n, vector<string> &dict, string s){
        unordered_map<string, int> mp;
        for (auto i : dict){
            mp[i] = 1;
        }

        vector<string> make;
        solve(0, 0, s, make, mp);
        return ans;
    }
};




//Third Solution :-
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> dfs(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,dfs(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDic) {
        unordered_set<string> wordDict(wordDic.begin(),wordDic.end());
        return dfs(s,wordDict);
    }
};



//Third Solution :-
void dfs(unordered_set <string> &st, string s, int idx, string str, vector <string> &v){
    if(s[idx] == '\0'){
        str.pop_back();
        v.push_back(str);
        return;
    }
    string x = "";
    for(int i = idx; s[i] != '\0'; i++){
        x += s[i];
        if(st.find(x) != st.end()){
            str += x;
            str += ' ';
            dfs(st, s, i+1, str, v);
            for(int j=0; j<=x.size(); j++)
                str.pop_back();
        }
    }
}
vector<string> wordBreak(int n, vector<string>& dict, string s){
    vector <string> v;
    unordered_set <string> st(dict.begin(), dict.end());
    dfs(st, s, 0, "", v);
    return v;
}

