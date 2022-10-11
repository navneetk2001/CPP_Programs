// Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

// Example 1:
// Input:
// K = 4
// str = "1234567"
// Output: 7654321
// Explanation: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5

// Example 2:
// Input:
// K = 3
// str = "3435335"
// Output: 5543333
// Explanation: Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4 



//First Solution :-
class Solution{
public:
    void rec(string str, int k, int a, string &ans){
        ans=max(ans,str);
        if(k==0) {
            return;
        }
        
        for(int i=a;i<str.length()-1;i++){
            for(int j=i+1;j<str.length();j++){
                if(str[j]>str[i]){
                    swap(str[i],str[j]);
                    rec(str,k-1,i+1,ans);
                    swap(str[i],str[j]);
                }
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
       rec(str,k,0,ans);
       return ans;
    }
};



//Second Solution :-
class Solution
{
   public:
   string s;
   void answer(string curr,int k,int i){
       if(k==0 || i==s.size()){
           if(s<curr){
               s=curr;
           }
           return;
       }
       
       for(int j=i;j<curr.size();++j){
           if(curr[j]<=curr[i] && i!=j){
               continue;
           }
           
           swap(curr[j],curr[i]);
           // saving the swap when i=j;
           if(i==j){
               answer(curr,k,i+1);
           }
           answer(curr,k-1,i+1);
           swap(curr[j],curr[i]);
       }
       return ;
       
   }
   //Function to find the largest number after k swaps.
   string findMaximumNum(string str, int k)
   {
      s=str;
      answer(str,k,0);
      return s;
   }
};


//Third Solution :-
class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void findMaxUtil(string str, string &max, int k, int pos)
    {
        if(k == 0)
            return;
            
        char maxm = str[pos];
        for(int i = pos+1; i < str.length() ;i++)
        {
            if(maxm < str[i])
                maxm = str[i];
        }
        
        if(maxm != str[pos])
            k--;
            
        for(int i=str.length()-1; i>=pos ;i--)
        {
            if(str[i] == maxm)
            {
                swap(str[i], str[pos]);
                if(str.compare(max) > 0)
                    max = str;
                    
                findMaxUtil(str, max, k, pos+1);
                
                swap(str[i], str[pos]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string max = str;
       findMaxUtil(str, max, k, 0);
       return max;
    }
};