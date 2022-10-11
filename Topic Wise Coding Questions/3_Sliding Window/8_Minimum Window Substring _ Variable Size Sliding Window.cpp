https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1



//Solution Approach :- 
string smallestWindow (string s, string p)
{
	int n = p.length();
	unordered_map<char, int> map;

	for(int i=0; i<n; i++){
	   	map[p[i]]++;
	}

	int count = map.size();
	int i = 0; 
	int j = 0;
	string ans = "";
	int a = -1;
	int b = -1;
	
	while(j < s.length()){
       	if(map.find(s[j]) != map.end()){
           	map[s[j]]--;
           	if(map[s[j]] == 0){
               	count--;
           	}
           	if(count == 0){
               	if(a == -1 && b == -1){
                   	a = i;
                   	b = j;
               	}
               	else if(j-i+1 < b-a+1){
                   	a = i;
                   	b = j;
               	}
               
               	while(count == 0){
                   	if(map.find(s[i]) != map.end()){
                       	map[s[i]]++;
                       	if(map[s[i]] > 0){
                           	count ++;
                       	}
                   	}
                   	if(j-i+1 < b-a+1){
                       a = i;
                       b = j;
                   	}
                   	i++;
               	}
           	}
       	}
       	j++;
   	}
   	if(a == -1 && b == -1){
       	ans += to_string(-1);
       	return ans;
   	}
	for(int i=a; i<=b; i++){
	   	ans += s[i];
	}
	return ans;
}




//Second Solution :-
string smallestWindow (string s, string p){
    vector<int> pat(256,0);
    vector<int> str(256,0);
    int n = s.length();
    int m = p.length();
    for(int i=0; i<m; i++){
        pat[p[i]]++;
    }
    int start = 0, front = -1, mini = INT_MAX, len = 0, count = 0;
    for(int i=0; i<n; i++){
        str[s[i]]++;
        if(str[s[i]] <= pat[s[i]]) count++;
        if(count == m){
            while(str[s[start]] > pat[s[start]]){ // (here // editor code uses unnecessarily 2 conditions . If a char is // part of string and not part of pattern then count of pat  // array will be 0 and count of str array will be > 0 so that // condition also gets covered no need to write 2 conditions)
             
                str[s[start]]--;
                start++;
            }
            len = i-start+1;
            if(mini > len){
                mini = len;
                front = start;
            }
        }
    }
    return (front == -1) ? "-1" : s.substr(front, mini);
} 



//Third Solution :-
string smallestWindow (string s, string p)
{
    int n = s.length();
    int start=0,end=INT_MAX;

    unordered_map<char,int> mp;
    for(auto &ele:p){
        mp[ele]++;
    }
    int count = mp.size();
    int i=0,j=0;
    
    while(j<n){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
        }
        if(count==0){
            while(count==0){
                if(end-start>j-i){
                    start=i;
                    end=j;
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count++;
                    }
                }
                i++;
            }
        }
        j++;
    }
    return end== INT_MAX? "-1":s.substr(start,end-start+1);
}