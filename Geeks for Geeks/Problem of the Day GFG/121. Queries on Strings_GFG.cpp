// Given a string str you have to answer several queries on that string. In each query you will be provided two values L and R and you have to find the number of distinct characters in the sub string from index L to index R (inclusive) of the original string.
 
// Example 1:
// Input: str = "abcbaed",
// Query = {{1,4},{2,4},{1,7}}
// Output: {3,2,5}
// Explanation: For the first query distinct characters from [1, 4] are a, b and c.
// For the second query distinct characters from [2, 4] are b and c.
// For the third query distinct characters from [1, 7] are a, b, c, d and e.




//Solution Approach :-
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    vector<int>v;
	    for(int i=0;i<Query.size();i++){
	        set<char>s;
	        int a=Query[i][0];
	        int b=Query[i][1];
	        for(int j=a;j<=b;j++){
	            s.insert(str[j-1]);
	        }
	        v.push_back(s.size());
	    }
	    return v;
	}
};



//Second Solution :-  DP
class Solution{
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    int n=str.length();
    	int arr[n+1][26];
    	
    	for(int i=0;i<n+1;i++){
    	    for(int j=0;j<26;j++){
    	    	arr[i][j]=0;
    	    }
    	}
    	
    	for(int i=0;i<n;i++){
    	    for(int j=0;j<26;j++){
    	    	arr[i+1][j]=arr[i][j];
    	    	if((str[i]-'a')==j){
    		    	arr[i+1][j]++;
    	    	}
    	    }
    	}
    
    	vector<int>ans;
    	for(int i=0;i<Query.size();i++){
    	    int l=Query[i][0];
    	    int r=Query[i][1];
    	    int count=0;
    	    for(int j=0;j<26;j++){
    	        if((arr[r][j]-arr[l-1][j])>0){
    	            count++;
    	        }
            }
    	    ans.push_back(count);
    	}
    	return ans;
	}
};




//Third Solution :- 
vector<int>SolveQueris(string str, vector<vector<int>>Query){
	int n=str.size();
	vector<int> ans;
	vector<vector<int>> mp;
    vector<int> temp(26,0);
    mp.push_back(temp);
	for(int i=0;i<str.size();i++){
	    temp[str[i]-'a']++;
	    mp.push_back(temp);
	}
	
	for(int i=0;i<Query.size();i++){
	    int l=Query[i][0]-1;
	    int r=Query[i][1];
	    int count=0;
	    for(int i=0;i<26;i++){
	        if(mp[r][i]-mp[l][i] > 0){
	            count++;
	        }
        }
	    ans.push_back(count);
    }
    return ans;
}