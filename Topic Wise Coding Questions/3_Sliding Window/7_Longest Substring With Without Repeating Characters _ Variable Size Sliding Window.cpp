https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1




//Solution Approach :-
class Solution {
public:
    int longestUniqueSubsttr(string s) {
        if (s.size()==0){
            return 0;
        }

        unordered_map<char, int> mp;
        int i=0;
        int j=0;
        int mx=INT_MIN;
        
        while(j<s.size()){
            mp[s[j]]++;
            if (mp.size() == j-i+1){
                mx=max(mx, j-i+1);
            }
            else if (mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if (mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return mx;
    }
};



//Second Solution :-
int longestUniqueSubsttr(string S){
    int x[26]={0};
    int i=0;
    int j=0;
    int maxlen = INT_MIN;
    while(j<S.length())
    {
        x[S[j]-'a']++;
        if(x[S[j]-'a']>1)
        {
            maxlen = max(maxlen,j-i);
            while(x[S[j]-'a']!=1)
            {
                x[S[i]-'a']--;
                i++;
            }
            
        }
       j++; 
    }
    maxlen = max(maxlen,j-i);
    return maxlen;
}




//Third Solution :-
int longestUniqueSubsttr(string S){
    int n=S.length();
    int i=-1,j=-1;
    int maxi=0;
    vector<int>map1(26,0);
    while(true){
       bool flag1=false,flag2=false;
       while(i<n-1){
           i++;
           flag1=true;
           map1[S[i]-'a']++;
           if(map1[S[i]-'a']==2){
               break;
           }
           else{
               int len=i-j;
               if(len>maxi){
                   maxi=len;
               }
           }
       }
       while(j<i){
           j++;
            map1[S[j]-'a']--;
            flag2=true;
           if(map1[S[j]-'a']==1){
               break;
           }
       }
       if(flag1==false and flag2==false)break;
   }
   return maxi;
   
}



//Fourth Solution :-
int longestUniqueSubsttr(string S){
   int len=S.size();
   int i=0, j;
   vector<int>v(26, -1);  // array of 26 character
   int mx=-1;
   for(j=0; j<len; j++)
   {
       if(v[S[j]-'a']==-1) 
          v[S[j]-'a']=j;
       else if(i<=v[S[j]-'a'])
       {
           mx=max(mx, j-i);          //find the length
           i=max(i, v[S[j]-'a']+1);  //update the ith position
           v[S[j]-'a']=j;            //update the new position 
       }
       else
          v[S[j]-'a']=j; 
   }
   mx=max(mx, j-i);  // if all unique character 
   return mx;
}