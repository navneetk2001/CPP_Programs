https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1




//Solution Approach :-
class Solution{
public:
    int search(string pat, string txt) {
        unordered_map<char,int> m;
        for(auto it : pat){
            m[it]++;
        }
      
        int k = pat.size();                     //size of pattern/window
        int count = m.size();                   //size of map
        int ans = 0;
        int i = 0, j = 0;
        
        while(j < txt.size()){
            if(m.find(txt[j]) != m.end()) {     //if jth char is found in the map then decrease the count of that char in map
                m[txt[j]]--;
                
                if(m[txt[j]] == 0){             //whenever the count of any char becomes o then reduce the size of map
                    count--;
                }
            }
            if(j - i + 1 < k){                  //if window size(j-i+1) is less than k then increment j
                j++;
            }
            else if(j - i + 1 == k) {          //if window size(j-i+1) is equal to k
                if(count == 0){                //if at any time size of map becomes 0 then increment ans 
                    ans++;
                }

                if(m.find(txt[i]) != m.end()) {   //starts shrinking the window from left
                    m[txt[i]]++;

                    if(m[txt[i]] == 1){           //whenever new element is added in the map then increment the size of map
                        count++;
                    }
                }
                i++; 
                j++;
            }
        }
        return ans;
    }
};




//Second Solution :-
int search(string pat, string txt) {
    vector<int> arr1(26,0),arr2(26,0);
    int d=0,x=0,ans=0;
    
    for(int i=0;i<pat.length();i++){
        if(arr1[pat[i]-'a']==0){
            d++;
        }
        arr1[pat[i]-'a']++;
    }

    for(int i=0;i<txt.length();i++){
        arr2[txt[i]-'a']++;
        if(arr1[txt[i]-'a']){
            if(arr2[txt[i]-'a']==arr1[txt[i]-'a']){
                x++;
            }
        }
        if(i>=pat.size()){
            arr2[txt[i-pat.size()]-'a']--;
            if(arr2[txt[i-pat.size()]-'a']+1==arr1[txt[i-pat.size()]-'a'])x--;
        }
        if(x==d){
            ans++;
        }
    }
    return ans;
}




//Third Solution :-
bool areSame(vector<int>&pmap,vector<int>&tmap){
   for(int i=0;i<26;i++){
       if(pmap[i]!=tmap[i]){
           return false;
       }
   }
   return true;
}

int search(string pat, string txt) {
    int n1=pat.length(),n2=txt.length();
    vector<int> pmap(26,0),tmap(26,0);
    int count=0;
    for(int i=0;i<n1;i++){
        pmap[pat[i]-'a']++;
        tmap[txt[i]-'a']++;
    }

    int i=n1,j=0;
    while(i<n2){
        if(areSame(pmap,tmap)){
            count++;
        }
        tmap[txt[i]-'a']++;
   
        if(tmap[txt[j]-'a']==1){
            tmap[txt[j]-'a']=0;
        }
        else{
            tmap[txt[j]-'a']--;
        }
        i++;
        j++;
    }
    if(areSame(pmap,tmap)){
        count++;
    }
    return count;
}



//Fourth Solution :-
class Solution{
public:
    int search(string pat, string txt) {
        int n=txt.length();
        int k=pat.length();
        int i=0,ans=0;
        int j=0;
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;
        for(int i=0;i<k;i++){
            mp[pat[i]]++;
        }
        for(int i=0;i<k;i++){
            mp1[txt[i]]++;
        }
        i=0;
        j=k-1;
        int count=0;
        while(j<n){
            int count1=0;
            for(auto i:mp){
                if(mp1[i.first]!=i.second) break;
                count1++;
            }
            if(count1==mp.size()) count++;
            mp1[txt[i]]--;
            i++;
            j++;
            mp1[txt[j]]++;
        }
        return count;
    }
};