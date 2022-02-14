vector<vector<string>> groupAnagrams(vector<string>& strs){
	unordered_map<string,vector<string>>mymap;
	int n=strs.size();
	string temp;

	for(int i=0;i<n;i++){
		temp=strs[i];
		sort(strs[i].begin(),strs[i].end());
		mymap[strs[i]].push_back(temp);
	}

	vector<vector<string>> result;

	for(auto itr=mymap.begin();itr!=mymap.end();itr++){
		result.push_back(itr->second);
	}
	return result;
}



//1 . C++ Solution With Sort in O(N*KlogK) Time

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        
        for(string str : strs)
        {
            string copy = str;
            sort(copy.begin(),copy.end());
            mpp[copy].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto x : mpp)
        {     
            ans.push_back(x.second);
        }
        return ans;
    }
};




//2 . C++ Solution Without Sort in O(N*K) Time

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>>mpp;  
        for(string s : strs)
        {
            map<char,int>mpp2;
            for(char ch : s)
                mpp2[ch]++;
            mpp[mpp2].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto x : mpp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};