// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// Example 1:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true

// Example 2:
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false

// Example 3:
// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false



//Solution Approach :-
class Solution {
public:
	bool wordPattern(string pattern, string s) {
		vector<string> v;
		int i = 0;
		string temp = "";
		while(i < s.size()){
			if(s[i] == ' '){
				v.push_back(temp);
				temp = "";
			}
			else
			{
				temp += s[i];
			}
			i++;
		}
		v.push_back(temp);

		if(v.size() != pattern.size())
		{
			return false;
		}
		
		unordered_map<char, string> m;
		set<string> st;
		for(int i = 0; i < pattern.size(); i++)
		{
			if(m.find(pattern[i]) != m.end())
			{
				if(m[pattern[i]] != v[i]) 
				{
					return false;
				}
			}
			else
			{
				if(st.count(v[i]) > 0)
				{
					return false;
				}
				else
				{
					m[pattern[i]] = v[i];
					st.insert(v[i]);
				}
			}
		}
		return true;
	}
};



//Second Solution :-
bool wordPattern(string pattern, string str) {
    map<char, string> m;
    set<string> set_string;
    istringstream input(str);
    string s;

    for(int i = 0; i < pattern.size(); i++){
        if(input>>s){
        if(m.find(pattern[i]) != m.end()){
            if(m[pattern[i]] != s)return false; //pattern already mapped with some other string
        }
        else {
            if(set_string.count(s)){
                return false;//string already exist for some pattern char 
            }
            else{
                m[pattern[i]] = s;
                set_string.insert(s);
            }
        }
        }
        else return false ;
    }
    if(input>>s)return false ;//more string compared to pattern
    return true;
}



//Third Solution :-
//APPROACH :
	//Use two maps, one maps the letters of pattern to index+1 & the other maps the words in s to index+1.
	//Use istringstream to extract words from s & i to traverse pattern.
	//Return true if the values of both the keys ( m1[pattern[i]] & m2[word] ) are equal && i reaches pattern.size() & stops. (ie; No. of words in s = pattern.size() ), otherwise false.

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        
        istringstream in(s); string word;
        int i = 0, n = pattern.size();
        
        for(word; in>>word; i++){
            if(i==n || p2i[pattern[i]] != w2i[word]) return false; //If it reaches end before all the words in string 's' are traversed || if values of keys : pattern[i] & word don't match return false
            
            p2i[pattern[i]] = w2i[word] = i+1; //Otherwise map to both to a value i+1
        }
        return i==n; //both the lengths should be equal
    }
};






