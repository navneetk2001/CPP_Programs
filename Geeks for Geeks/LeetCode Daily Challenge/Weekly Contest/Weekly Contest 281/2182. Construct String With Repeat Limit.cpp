// You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
// Return the lexicographically largest repeatLimitedString possible.
// A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.


// Example 1:
// Input: s = "cczazcc", repeatLimit = 3
// Output: "zzcccac"
// Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
// The letter 'a' appears at most 1 time in a row.
// The letter 'c' appears at most 3 times in a row.
// The letter 'z' appears at most 2 times in a row.
// Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
// The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
// Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.

// Example 2:
// Input: s = "aababab", repeatLimit = 2
// Output: "bbabaa"
// Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
// The letter 'a' appears at most 2 times in a row.
// The letter 'b' appears at most 2 times in a row.
// Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
// The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
// Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.




//Solution Approach :- 
class Solution {
public:
string repeatLimitedString(string s, int k) {
    int arr[26]={0};
    string str;
    for(int i=0;i<s.length();i++)
    {
        arr[s[i]-'a']++;
    }
    for(int i=25;i>=0;)
    {
        if(arr[i]<=k&&arr[i]>=0)
        {
            for(int j=0;j<arr[i];j++)
            {
                str.push_back(i+'a');
            }
            i--;
        }
        while( i>=0 && arr[i]>k  )
        {
             for(int j=0;j<k;j++)
            {
                str.push_back(i+'a');
            }
            if(i==0)
                return str;
            int j;
            for(j=i-1;j>=-1;j--)
            {
                if(j==-1)
                    return str;
                if(arr[j]>0)
                {
                   str.push_back(j+'a');
                   arr[j]--;
                    break;
                }
            }
          
            arr[i]=arr[i]-k;
        }
       
    }
    return str;
} 
};



//Solution Approach :- Greedy Stack Based Solution
class Solution {
public:
    string repeatLimitedString(string s, int k) {
        string ans="";
        
        int arr[26]={0};
        for(auto x:s)
            arr[x-'a']++;
        
        stack<pair<int,int>>q;
        
        for(int i=0;i<26;i++)
            if(arr[i]>0)
                q.push({i,arr[i]});
        
        while(q.size())
        {
            int ch=q.top().first;
            int freq=q.top().second;
            q.pop();
            
            int t=min(k,freq);
            while(t--)
                ans+=('a'+ch);
            if(freq-k>0)
            {
                if(!q.size())
                    break;
                else
                {
                    pair<int,int>p=q.top();
                    q.pop();
                    if(p.second-1>0)
                        q.push({p.first,p.second-1});
                    q.push({ch,freq-k});
                    q.push({p.first,1});
                }
            }
        }
        
        return ans;
    }
};



//Solution :- Sliding Window || Binary Search|| c++
// Algorithm:
// First sort the string in descending order.
// Perform sliding window by keeping the window size=limit
// If within the window a character not equal to the character at the begining of the window is found, then start the window from that character.
// Else if we come out of the window, check if that character is equal to the character in previous window, then swap it with another character from the string which is not equal to that chracter, if not found then the string computed till now is the answer.
// We store the computed string yet in another string to avoid creating a substring while returning the answer.

class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        if(s.length()==1)
            return s;
        sort(s.begin(),s.end(),greater<char>());
        string ans;
        for(int i=0;i<s.length();)
        {
            int j;
            for(j=i;j<i+limit&&j<s.length();j++)
            {
                if(s[j]!=s[i])  //beginnig of a new window
                 {
                    i=j;
                 }
                ans+=s[j];     //computed string till now.
               
                
            }
            if(j==s.length())
                return ans;
            if(s[j]==s[i])  
            {
                
            auto it=upper_bound(s.begin()+j,s.end(),s[j],greater<int>()); //binary search for the next character
                
                    if(it!=s.end())
                    {
                        swap(s[distance(s.begin(),it)],s[j]);
                        i=j;
                        
                    }
                
                if(i!=j)
                   return ans;
                    
                
            }
            else
              i=j;
            
           }
        
        return ans;
        
        
    }
};




//Solution :- Priority Queue || Max Heap || Map || C++
class Solution {
public:
    string repeatLimitedString(string s, int r) {
        unordered_map<char,int>mp;
        for(auto c:s)
        {
            mp[c]++;
        }
        // Keep the characters and it's count in max heap, Charater as first element
        priority_queue<pair<char,int>>pq;
        for(auto p:mp)
        {
            pq.push(p);
        }
        string ans;
        // For each top element, if it has occurance greater or equal to repeatLimit than take this character repeatLimit times 
        while(!pq.empty())
        {
            auto [c,f]=pq.top();
            pq.pop();
            for(int i=0;i<r and f>0;i++)
            {
                ans+=c;
                f--;
            }
            // if frecuency of current charater>repeatLimit
            if(f)
            {
                // than check if there is any element in heap so that we can take that 
                if(!pq.empty())
                {
                    auto p=pq.top();
                    pq.pop();
                    ans+=p.first;
                   if(p.second-- >1)
                   {
                       pq.push(p);
                   }
                pq.push({c,f}); 
                }
				// otherwise if this was the last element that return from here
                else
                {
                    return ans;
                }
            }
            
        }
        return ans;
    }
};