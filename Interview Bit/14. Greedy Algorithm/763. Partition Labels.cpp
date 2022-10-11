https://leetcode.com/problems/partition-labels/




//Solution Approach :- 
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i = 0; i < s.size(); i++){        // filling last occurence of each char in the map
            char ch = s[i];
            mp[ch] = i;
        }

        vector<int> ans;
        int prev = -1;               //to store the starting index of each partition 
        int maxi = 0;                //to store the maximum value of each partition
        
        for(int i = 0; i < s.size(); i++){
            maxi = max(maxi, mp[s[i]]);
            if(maxi == i){                     // partition time
                ans.push_back(maxi - prev);    // push partition length
                prev = maxi;                   // update prev
            }
        }
        return ans;
    }
};




//Second Solution :- 
// ALGORITHM :-> 
// Fundamental idea is that if two instances of characters should be in the same partition.
// So, we start with the first character and see at what point we can finish the partition.
// The earliest we can do is at the last instance of this character.
// What if we find a character between the first character and the last instance of it?
// In this case, we increase the length of the partition. Why?
// If we do not increase the partition, the new character ends up into two partitions, which violates the constraint of the problem.
// If we have gone through all the characters between the start of partition and maximum of the last instance of characters, we can close the partition and start a new one.
// Runtime: O(n). We analyze each character twice.
// Memory: O(1). We use 26 elements for the algorithm. Additional memory is used to store the result; the algorithm does not need it.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> end_idx(26,0);		// vector for keeping the track of  last occurence of every character
        
        for(int i = 0; i < s.length(); ++i){
            end_idx[s[i] - 'a']  = i;
        }
        
        vector<int> res;
        int start = 0, end = 0;

        for(int i = 0; i < s.length(); ++i){    		// scanning string character by character
            end = max(end, end_idx[s[i] - 'a']);    	// whenever we get an character we check, last index of that character
            if(i == end){ 			                    // when current i.e i == end, add it to result
                res.push_back(i - start + 1);           // all the characters of current partition included
                start = i + 1;			             	// update the start pointer for fresh start
            }
        }
        return res;
    }
};