https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1




//Solution Approach :-
class Solution{
public:
    int findSubString(string str){
        int n =str.length();
        
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[str[i]]++;
        }
    
        int count = mp.size();
        mp.clear();
        int i=0,j=0,ans=INT_MAX;
        
        while(j<n){
            mp[str[j]]++;
            if(mp.size()<count){
                j++;
            }
            else if(mp.size()==count){
                while(mp.size()==count){
                    ans=min(ans,j-i+1);
                    mp[str[i]]--;
                    if(mp[str[i]]==0){
                        mp.erase(str[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};



//Second Solution :-
int findSubString(string str)
{
    unordered_map<char,int>m;
    for(int i=0;i<str.length();i++){
        m[str[i]]=0;
    }
    
	int i=0,j=0,count=0,ans=INT_MAX,n=str.length();
    string res;
    while(j<n)
    {
        if(m[str[j]]==0){
        	count++;
        }
        
        m[str[j]]++;
        
        if(count==m.size()){
            while(i<n and m[str[i]]>1){
                m[str[i]]--;
                i++;
            }
            
            if(ans>j-i+1){
                ans=j-i+1;
                res=str.substr(i,j-i+1);
            }
        }
        j++;
    }
    return res.size();
}




//Third Solution :-
int findSubString(string str)
{
    unordered_map<char,int> freq;
    unordered_set<char> present;
    int n = str.length();
    for(int i=0; i<n; i++){
        present.insert(str[i]);
    }
    int totalLetters = present.size();
    if(totalLetters==n) return n;
    int allpresent=0, ans = n, windowStart=0;
    for(int i=0; i<n; i++){
        freq[str[i]]++;
        if(freq[str[i]]==1){
            allpresent++;
        }
        if(allpresent==totalLetters){
            int j=windowStart;
            while(j<i && freq[str[j]]>1){
                freq[str[j]]--;
                j++;
            }
            windowStart = j;
            ans = min(ans, i-windowStart+1);
        }
    }
    return ans;
}