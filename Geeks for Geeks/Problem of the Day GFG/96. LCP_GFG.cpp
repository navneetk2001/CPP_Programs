Geek is at the geek summer carnival. He is given an array of N strings. To unlock exclusive course discounts he needs to find the longest common prefix among all strings present in the array. Can you help him ?

Example 1:
Input:
N = 4
ar[] = {geeksforgeeks, geeks, geek, geezer}

Output: gee
Explanation: Longest common prefix in all the given string is gee. 
 

Example 2:
Input:
N = 3
ar[] = {apple, ape, april}
Output: ap


//Solution Approach :-
class Solution{
public:
    string LCP(string a[], int n)
    {
        if(n==0)
        	return "-1";
        if(n==1)
        	return a[0];

        sort(a,a+n);
        int l=min(a[0].size(),a[n-1].size());
        int c=0,i=0;
        while(i<l && a[0][i]==a[n-1][i]){
        	c++;
        	i++;
        }
        if(c==0){
        	return "-1";
        }
        return a[0].substr(0,c);
    }
};



//Second Solution :- Without sorting 
class Solution{
public:
   string LCP(string ar[], int n)
   {
       string lcp=ar[0];
       for(int i=1;i<n;i++)
       {
           int len=min(lcp.length(),ar[i].length());
           while(ar[i].substr(0,len)!=lcp.substr(0,len))
               len--;
           lcp=lcp.substr(0,len);  
       }
       return (lcp.length() == 0)?"-1":lcp;
   }
};


//Third Solution :-
class Solution{
public:
    string LCP(string ar[], int n)
    {
        int start=0,end=INT_MAX;
        for(int i=0;i<n;i++){
            int t=ar[i].length();
            end=min(end,t);
        }

        int rightMax=-1;
        while(start<end){
            bool check=true;
            int mid=start+(end-start)/2;
            for(int i=0;i<n-1;i++){
                if(ar[i][mid]!=ar[i+1][mid])
                    check=false;
            }
            if(check){
                rightMax=max(mid,rightMax);
                start=mid+1;
            }
            else end=mid-1;
        }
        if(rightMax==-1) return "-1";
        string ans;
        for(int i=0;i<=rightMax;i++)
            ans+=ar[0][i];
        return ans;
    }
};


//Fourth Solutionn :- Using tries
class Solution{
public:
   class TrieNode {
       public:
       char val;
       unordered_map<char,TrieNode*> children;
       bool isTerm ;
       
       TrieNode(char c){
           val = c ;
           children = unordered_map<char,TrieNode*>() ;
           isTerm=false ;
       }
   };
   class Trie{
       public: 
       TrieNode* root ;
       
       Trie(){
           root = new TrieNode('\0') ;
       }
       
       void insert(string s){
           TrieNode *curr = root ;
           for(int i=0 ; i<s.size() ; i++){
               if(curr->children.count(s[i]) == 0)
                   curr->children[s[i]] = new TrieNode(s[i]) ;
                   
               curr = curr->children[s[i]] ;
           }
           curr->isTerm = true ;
       }
   };
   
   string LCP(string s[], int n)
   {
       Trie t ;
       for(int i=0 ; i<n ; i++)
           t.insert(s[i]) ;
           
       TrieNode *curr = t.root ;
       
       if(curr->children.size() > 1)
           return "-1" ;
           
       for(auto &p: curr->children)
               curr = p.second ;
       string ans ;
       while(curr->children.size() == 1 && !(curr->isTerm)){
           ans += curr->val ;
           for(auto &p: curr->children)
               curr = p.second ;
           
       }
       ans += curr->val ;
       
       return ans ;
       
   }
};
