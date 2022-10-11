// A string s is called good if there are no two different characters in s that have the same frequency.
// Given a string s, return the minimum number of characters you need to delete to make s good.
// The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

// Example 1:
// Input: s = "aab"
// Output: 0
// Explanation: s is already good.

// Example 2:
// Input: s = "aaabbbcc"
// Output: 2
// Explanation: You can delete two 'b's resulting in the good string "aaabcc".
// Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

// Example 3:
// Input: s = "ceabaacb"
// Output: 2
// Explanation: You can delete both 'c's resulting in the good string "eabaab".
// Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).





//Solution Approach :-
// 1. the question not about minimum deletions to make frequencies of characters as unique , instead its about minimum number of deletion required to make an array unique.
// 2. the only reason it is put in medium(which is ig not required) is to identify that array .. yeah ig if you have read till here you should have already figured that out by now . so basically the array is made up of frequencies of these elements.

// Algorithm:
// 1. make a freq array which stores frequency of elements of size 26 as given in question input string contains only lowercase english letters.
// 2. Now you can either sort the array or use a set to make count of unique elements.

int minDeletions(string str) {
    int freq[26]={0};
    for(auto i:str){
        freq[i-'a']++;
    }

    unordered_set<int> s;
    int ans=0;
    for(auto i:freq){
        if(i!=0){
            if(s.find(i)==s.end()){  //if the frequency is not already seen then directly push it in set
                s.insert(i);
            }
            else{                //if it has already been seen
                int cnt=i;       //store the frequency as count
                while(s.find(i)!=s.end() and i>0){   //iterate till it's not been seen in set
                    i--;
                }
                if(i!=0){           //if it's count is not zero then push it in set
                    s.insert(i);     
                }
                ans+=cnt-i;       //update ans 
            }
        }
    }
    return ans;
}



//Second Solution :-
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq (26, 0);      //Array to store the count of each character.
        for (auto c : s){              //Calculatimg frequency of all characters.
            freq[c - 'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<int>());         //sorting the frequency in descending order
        int ans = 0;                            //to store the deletions.
        int maxAllowedFreq = freq[0];           //greatest frequency

        for(auto currFreq : freq){
        	if(currFreq > maxAllowedFreq){
        		if(maxAllowedFreq > 0){
        			ans += (currFreq - maxAllowedFreq);
        		}
        		else{
        			ans += currFreq;
        		}
        	}
        	maxAllowedFreq = min(currFreq-1, maxAllowedFreq-1);
        }
        return ans;
    }
};




//Third Solution :-
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq (26, 0);      //Array to store the count of each character.
        for (char c : s){              //Calculatimg frequency of all characters.
            freq[c - 'a']++;
        }
        
        sort(freq.begin(), freq.end());         //sorting the frequencies. So the greatest frequencies are in right side.
        int del = 0;                            //to store the deletions.
        
        for (int i = 24; i >= 0; i--) {          //Checking if 2 frequencies are same, if same then decrease the frequency so that it becomes less than the next greater one.So Start from the 2nd greatest frequency that is at freq[24].
            if(freq[i] == 0) break;              // if frequency is 0 that means no more character is left.
            
            if(freq[i] >= freq[i+1]){
                int prev = freq[i];                   //To store the frequency before deletion.
                freq[i] = max(0, freq[i+1] -1);       //New frequency should be 1 less than the previous frequency in the array.
                del += prev - freq[i];                //Calculating deleted characters 
            }
        }
        return del;
    }
};



//Fourth Solution :- The intution is simple:
int minDeletions(string s) {
    int ans = 0;

    unordered_map<char, int> char_counts;      // count each char
    for(const char& c : s) char_counts[c]++;

    unordered_set<int> seen;                   // make a set to hold which counts we've seen

    for(auto[k, v] : char_counts){                // for each count
        while(seen.find(v) != seen.end()) {       // if we've seen it, decrement it until we haven't
            v--;
            ans++;
        }
        if(v > 0){             // add it
            seen.insert(v);
        }
    }
    return ans;
}