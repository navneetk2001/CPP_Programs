// Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
// Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

// Example 1:
// Input : str = "geeksforgeeks"
// Output: 1
// Explanation: All the repeated characters of the given string can be rearranged so that no adjacent characters in the string is equal.Any correct rearrangement will show a output of 1.

// Example 2:
// Input : str = "bbbbb"
// Output: 0
// Explanation: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated character.




//Solution Approach :- 
class Solution{
public:
    string rearrangeString(string str){
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> max_heap;        // max-heap
        for(auto x: str){    //insert char into map to store frequency
            freq[x]++;
        }
        
        for(auto it: freq){    //push into priority queue
            max_heap.push({it.second, it.first});
        }
        
        str = "";
        while(max_heap.size() > 1){
            auto top1 = max_heap.top();   //store first top element 
            max_heap.pop();

            auto top2 = max_heap.top();  //store second top element
            max_heap.pop();
            
            str += top1.second;  //now adding the stored char in answer string
            str += top2.second;
            
            if(--top1.first > 0){   //reducing freq. of char by 1 and checking if its greater than 1
                max_heap.push(top1);
            }
            if(--top2.first > 0){   //reducing freq. of char by 1 and checking if its greater than 1
                max_heap.push(top2);
            }
        }
        
        if(max_heap.size()){
            if(max_heap.top().first == 1){
                str += max_heap.top().second;
            }
            else{
                return "-1";
            }
        }
        return str;
    }
};



//Second Solution :-
string rearrangeString(string s){
    int n=s.length();
    sort(s.begin(),s.end());
    
    string ans=s;
    int c=0;
    for(int i=0;i<n;i+=2){
        ans[i]=s[c++];
    }
    
    for(int i=1;i<n;i+=2){
        ans[i]=s[c++];
    }
    
    for(int i=1;i<n;i++){
        if(ans[i]==ans[i-1]){
            return "-1";
        }
    }
    return ans;
}
