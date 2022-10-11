// You are given two string arrays words1 and words2.
// A string b is a subset of string a if every letter in b occurs in a including multiplicity.

// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.
// Return an array of all the universal strings in words1. You may return the answer in any order.

// Example 1:
// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]

// Example 2:
// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
// Output: ["apple","google","leetcode"]





//Solution Approach :-
//We can count frequency or character in each word from B. We will maintain a vector Maxfreq, which will store the minimum frequency of each character required for a word from A to be universal word.
//We can finally iterate over each word from A, and check if each characters frequency is greater than or equal to the minimum required frequency (checked from Maxfreq).

// count frequency of each character in a word
vector<int> countFreq(string& word){
	vector<int> freq(26);
	for(auto& c : word){
		freq[c - 'a']++;
	}
	return freq;
}

vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
	vector<string> ans;

	vector<int> Maxfreq(26); // maintains minimum freq of each char required for a word to be universal word
	for(auto& word : B){
		vector<int> freq = countFreq(word);            
		for(int i = 0; i < 26; i++){
			Maxfreq[i] = max(Maxfreq[i], freq[i]);    //stores maxFreq for a universal word
		}
	}        

	for(auto& word : A){
		vector<int> freq = countFreq(word);    //stores the frequency of each char in word A
		int i = 0;
		for(;i < 26; i++){           
			if(freq[i] < Maxfreq[i]){    //if any freq in words of A is less than maxFreq[i], then that word won't be the part of subset
				break;
			}
		}
		if(i == 26) ans.push_back(word);
	}
	return ans;
}

//Time Complexity : O(N1 + N2), where N1 is the sum of length of all words from A and b is the sum of length of all words from N2
//Space Complexity : : O(U), where U, is the sum of length of all universal words.



//Second Solution :-
Approch :
//we know that order doesn't matter and all word of B are subset of word in A then only that word is considered. Having this in mind lets make a common word through B and just check that word as a subset in A.
//we can make a frequency map. instead of using Hashmap we can use array of 26(as all are lowercase) to store frequency.
// Time Compexity : O(A + B)
// Space Compexity : O(1) -> constant

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> freq(26,0);           //create the frequency count of elements of B.
        for(auto x:B){
            vector<int> temp(26,0);
            for(auto y:x){
                temp[y-'a']++;
                freq[y-'a'] = max(freq[y-'a'],temp[y-'a']); 
            }
        }
        vector<string>res;
        for(auto x:A){
            vector<int> temp(26,0);
            for(auto y:x) temp[y-'a']++;    //create the frequency count for all the elements in A
            bool flag=true;
            for(int i=0 ; i<26 ; i++)
                if(freq[i]>temp[i]) {flag=false;break;}         //check if the frequency count of B is subset of all A elements
            if(flag) res.push_back(x);
        }
        return res;
    }
};