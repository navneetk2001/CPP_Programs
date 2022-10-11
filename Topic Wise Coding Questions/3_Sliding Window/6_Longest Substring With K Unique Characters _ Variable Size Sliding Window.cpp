https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1



//Solution Approach :-
class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        int res = -1;
        unordered_map<char,int> map;
        int j = 0;
        for(int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
            if(map.size() == k)
            {
                res = max(res,(i-j)+1);
            }
            if(map.size() > k)
            {
                while(map.size() != k)
                {
                    map[s[j]]--;
                    if(map[s[j]] == 0){
                        map.erase(s[j]);
                    }
                    j++;
                }
            }
        }
        return res;
    }
};




//Second Solution :- 
int longestKSubstr(string s, int k) {
	unordered_map<char,int> mp;
	int i = 0;
	int j = 0;
	int ans = -1;

	while(j < s.length()){
       	mp[s[j]]++;
       
       	while(mp.size() > k){
           	mp[s[i]]--;
           	if(mp[s[i]] == 0){
           		mp.erase(s[i]);
           	}
           	++i;
       	}
       
       	if(mp.size() == k){
           	ans = max(ans, (j-i) + 1); 
       	}
       	j++;
   	}
   	return ans;
}



//Third Solution :-
int longestKSubstr(string s, int k) {
    if(k == 0){
        return -1;
    }
    int hash[128] = {0};
    int count = 0;
    int maxi = -1;
    int j = 0;

    for(int i = 0; i < s.length(); i++){
        while(j < s.length() && (count < k || hash[(int)s[j]] != 0)){
            if(hash[(int)s[j]] == 0){
                count++;
            }
            hash[(int)s[j]]++;
            j++;
        }
        if(count == k){
            maxi = max(maxi, j - i);
        }
        if(hash[(int)s[i]] == 1){
            count--;
        }
        hash[(int)s[i]]--;
    }
    return maxi;
}



