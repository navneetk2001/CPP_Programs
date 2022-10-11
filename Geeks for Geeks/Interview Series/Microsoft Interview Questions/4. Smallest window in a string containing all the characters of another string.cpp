// Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

// Example 1:
// Input:
// S = "timetopractice"
// P = "toc"
// Output: 
// toprac
// Explanation: "toprac" is the smallest substring in which "toc" can be found.

// Example 2:
// Input:
// S = "zoomlazapzo"
// P = "oza"
// Output: apzo
// Explanation: "apzo" is the smallest substring in which "oza" can be found.




//Solution Approach :- Hashing + Sliding Window Approach 
class Solution{
public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int count=0;
        int mp[256]={0};
        for(int i=0;i<p.size();i++){
        	if(mp[p[i]]==0){
        		count++;
        	}
        	mp[p[i]]++;
        }
        
        int res=INT_MAX;
        int start=0;
        int i=0,j=0;
        while(j<s.size()){
        	mp[s[j]]--;
        	if(mp[s[j]]==0){
        		count--;
        	}
        
        	if(count==0){
        		while(count==0){
        			if(j-i+1<res){
        				res=j-i+1;
        				start=i;
        			}
        			mp[s[i]]++;
        			if(mp[s[i]]==1){
        				count++;
        			}
        			i++;
        		}
        	}
        	j++;
        }
        
        if(res!=INT_MAX){
        	return s.substr(start,res);
        }
        else{
        	return "-1";
        }
    }
};



//Second Solution :-
string smallestWindow (string s, string p){
    unordered_map<char,int> mp;
    for(auto it: p){
        mp[it]++;
    }

    int count=mp.size();   //no.of distinct element in string p

    int i=0,j=0,len=INT_MAX;
    pair<int,int> ans;
    string str="";

    while(j<s.length()){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
               count--;
        }
        if(count==0){
            while(count==0){
                // find the start & end point of a string.
                if(j-i+1 < len)
                {
                    len=j-i+1;
                    ans={i,len};
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                       count++;
                }
                 i++;
            }
        }
        j++;
    }
    return len==INT_MAX?"-1":s.substr(ans.first, ans.second);
}
