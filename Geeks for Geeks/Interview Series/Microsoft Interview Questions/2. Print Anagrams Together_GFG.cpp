Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.
Example 1:
Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
act cat tac 
god dog
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.



vector<vector<string>> Anagrams(vector<string>& string_list){
	vector<vector<string>> result;

	//hash map to maintain groups of anagrams
	unordered_map<string,vector<string>> umap;
	for(int i=0;i<string_list.size();i++){
		string s=string_list[i];

		//sort each string
		sort(s.begin(),s.end());
		umap[s].push_back(string_list[i]);
	}

	for(auto itr=umap.begin();itr!=umap.end();itr++){
		result.push_back(itr->second);
	}

	return result;
}