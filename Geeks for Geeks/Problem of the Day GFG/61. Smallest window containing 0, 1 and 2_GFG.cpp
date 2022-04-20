// Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

// Example 1:

// Input:
// S = "01212"
// Output:
// 3
// Explanation:
// The substring 012 is the smallest substring that contains the characters 0, 1 and 2.

// Example 2:
// Input: 
// S = "12121"
// Output:
// -1
// Explanation: 
// As the character 0 is not present in the string S, therefor no substring containing
// all the three characters 0, 1 and 2 exists. Hence, the answer is -1 in this case.




//First Solution :-
int smallestSubstring(string S) {
    bool answerExist = false;
    int lastZero =-1, lastOne = -1, lastTwo = -1;
    int ans = S.size();
    for(int i=0;i<S.size();i++){
    	if(S[i]=='0'){
    		lastZero=i;
    	}
    	else if(S[i]=='1'){
    		lastOne=i;
    	}
    	else{
    		lastTwo=i;
    	}

    	if(lastZero!=-1 && lastOne!=-1 && lastTwo!=-1){
    		answerExist=true;
    		ans=min(ans, 1+i-min(lastZero, min(lastOne,lastTwo)));
    	}
    }
    if(answerExist){
    	return ans;
    }
    return -1;
}


//Solution Approach :- sliding window with 2 pointers
int smallestSubstring(string S) {
    int arr[3] = {0};
    int ans = INT_MAX;
    int j = 0; // left ptr
    for(int i = 0; i < S.length(); i++){
        arr[S[i] - '0']++;
        if(arr[0]*arr[1]*arr[2] > 0){
            ans = min(ans, i - j + 1);
            arr[S[j] - '0']--;
            j++;
            while(j < i && arr[0]*arr[1]*arr[2] > 0){
                ans = min(ans, i - j + 1);
                arr[S[j] - '0']--;
                j++;
            }
        }
    }
    return ans != INT_MAX ? ans : -1;
}


//Second Solution :-
class Solution 
{
  public:
  	bool check(string s)
  	{
  		if(s.find('0') == string::npos)
  			return false;

  		if(s.find('1') == string::npos)
  			return false;

  		if(s.find('2') == string::npos)
  			return false;

  		return true;
  	}

    int smallestSubstring(string s) 
    {
        if(!check(s))
        	return -1;

        int zero = -1;
        int one = -1;
        int two = -1;
        
        int mini = INT_MAX;
        for(int i = 0;i < s.size();i++)
        {
        	if(s[i] == '0')
        		zero = i;
        	if(s[i] == '1')
        		one = i;
        	if(s[i] == '2')
        		two = i;

        	if(zero != -1 and one != -1 and two != -1)
        	{
        		int min_ele = min({zero,one,two});
        		int max_ele = max({zero,one,two});
        		mini = min(mini,max_ele - min_ele + 1);
        	}
        }
        return mini;
    }
};


//Third Solution :-
int smallestSubstring(string S) {
    int n = S.length();
    vector<int> mp(3, 0);
    int ans = n+1, j = 0;
    
    for(int i=0; i<n; i++)
    {
        mp[S[i]-'0']++;
        
        while(mp[0] and mp[1] and mp[2])
        {
            ans = min(ans, i-j+1);
            mp[S[j]-'0']--;
            j++;
        }
    }
    
    if(ans > n)
    return -1;
    
    return ans;
}


//Fourth Solution :- 

shivamrai714
2 days ago

//sliding window :using map c++ sol

 

class Solution {
 public:
   int smallestSubstring(string s){
     int ans=INT_MAX;
     unordered_map<char,int>m;
     int n=s.size();
     int i=0,j=0;
     
     while(j<s.size())
     {
         m[s[j]]++;
         
         if(m.size()==3)     //all char found so cal. size of window (j-i+1)
         {
             ans=min(ans,j-i+1);
        

   //now remove ele from front to search more possible ans.
       

   while(m.size()==3)
   {  
        m[s[i]]--;                                //remove cal. of i   
        if(m[s[i]]==0)

        m.erase(s[i]);

       
  //front ele removed ,so erase from map , and                     seach for same using j pointer in forward direction.

          
             i++;
    }
         i--;          //done this , to cal window size, that we have removed front ele .(j-i+1); and then adjst it using i++;
    

      ans=min(ans,j-i+1);
         
             i++;
         }      
         
         j++;
     }
     if (ans==INT_MAX) return -1;
    return ans; 
   }
};