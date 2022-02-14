// Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
// For N =1 we have column A, for 27 we have AA and so on.
// Note: The alphabets are all in uppercase.

// Example 1:
// Input:
// N = 51
// Output: AY



class Solution{
    public:
    string ExcelColumn(int N)
    {
        int rem;
    	string res="";
        while(N>0){
        	rem = N%26;
        	if(rem==0){
        		res+='Z';
        		N=(N/26)-1;
        	}
        	else{
        		res+=(char)((N-1)%26+'A');     //add char corresponding to remainder
        		N=N/26;
        	}
        }
        reverse(res.begin(),res.end());
        return res;  //return the reverse of res
    }
};




//Solution :-2
public:
    string ExcelColumn(int N)
    {
        vector<char> v;
        
        while (N) {
            if (N%26!=0) {
                v.push_back((N%26)+64);
                N = N/26;
            }
            else {
                v.push_back((N%26)+90);
                N = N/26;
                N--;
            }
            
        }
        
        reverse(v.begin(), v.end());
        string res = "";
        
        for (auto i:v) {
            res += i;
        }
        return res;
    }



//Solution :-3
class Solution{
   public:
   string ExcelColumn(int N)
   {
       std::string s(1, 'A'+(N-1)%26);
       if (N<27) return s;
       return  ExcelColumn((N-1)/26) + s;
   }
};



//Solution :-4
string ExcelColumn(int n)
   {
       string ans="";
       while(n)
       {
           n--;
           ans=(char)(n%26+'A')+ans;
           n=n/26;
           
       }
       return ans;
   }



//Solution :-5
string ExcelColumn(int N)
    {
        // Your code goes here
        string ans = "";
        while(N > 0){
            ans.push_back('A' + (N-1)%26);
            N = (N - 1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
