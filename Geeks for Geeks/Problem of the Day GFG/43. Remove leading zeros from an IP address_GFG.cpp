// Given an IP address, remove leading zeros from the IP address. Note that our IP address here can be a little different. It can have numbers greater than 255. Also, it does not necessarily have 4 numbers. The count can be lesser/more.

// Example 1:
// Input:
// S = "100.020.003.400"
// Output: 100.20.3.400
// Explanation: The leading zeros are removed
// from 20 and 3.

// Example 2:
// Input: 
// S = "100.000.010.0999"
// Output: 100.0.10.999
// Explanation: The leading zeros are removed
// from 0, 10 and 999.



//Solution Approach :- 

class Solution
{
  public:
    string newIPAdd (string s)
    {
        int n=s.length();
        string ans="";

        for(int i=0;i<n;i++){
        	string temp="";
        	while(i<n and s[i]=='0'){   
        		i++;
        	}

        	while(i<n and s[i]!='.'){
        		temp+=s[i++];
        	}

        	if(temp.size()==0){    // in case of 100.400.000.0999
        		temp='0';
        	}

        	if(i<n){
        		ans=ans+temp+'.';
        	}
        	else{           //if you reach at end then don't add '.' at end 
        		ans+=temp;
        	}
        }
        return ans;
    }
};


//Second Solution :-
// Time: O(N)
class Solution
{
  public:
    string newIPAdd (string s)
    {
        int i=0;
        int n = s.length();
        string ans = "";
        while(i < n) {
            int j = i;
            bool flag = false;
            
            while(j < n && s[j] != '.') {
                if(s[j] != '0') {
                    flag = true;
                }
                
                if(flag) ans += s[j];
                j += 1;
            }
            
            if(!flag) ans += '0';
            
            if(j < n) ans += '.';
            i = j+1;
            
        }
        
        return ans;
    }
};


//Third Solution :-

khansuddhasattwa
4 days ago

class Solution
{
 public:
void solve(string &temp)
{
	while(temp.size()!=1){
		if(temp[0]=='0')
		 	temp.erase(temp.begin());
		else
		 	break;
	}
}

string newIPAdd (string s)
{
   int left=0;
   int right=0;
   string ans="";
   while(right<s.size())
   {
       if(s[right]!='.')
       right++;
       else
       {
           string temp= s.substr(left,right-left);
           solve(temp);
           ans+=temp;
           ans+=".";
           left=right+1;
           right++;
       }
   }
   string temp= s.substr(left,right-left);
   solve(temp);
   ans+=temp;
   return ans;
}
};

