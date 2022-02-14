Given an array of strings arr[] of size N, find if there exists 2 strings arr[i] and arr[j] such that arr[i]+arr[j] is a palindrome i.e the concatenation of string arr[i] and arr[j] results into a palindrome.
Example 1:
Input:
N = 6
arr[] = {"geekf", "geeks", "or","keeg", "abc", 
          "bc"}
Output: 1 
Explanation: There is a pair "geekf"
and "keeg".

Example 2:
Input:
N = 5
arr[] = {"abc", "xyxcba", "geekst", "or", "bc"}
Output: 1
Explanation: There is a pair "abc"
and "xyxcba".


//Time Complexity :-O(n*l^2)
//Space C0mplexity :-O(n)
class Solution{   
  public:
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        unordered_map<string, int>dict;
    	//bulid dicitonary
    	for(int i=0;i<N;i++){
    		string key=arr[i];
    		dict[key]=i;
    	}
    
    	//edge case if empty string exists, find all palindrome to become pairs ("", self)
    	if(dict.find("")!=dict.end()){
    		for(int i=0;i<N;i++){
    			if(i==dict[""]) continue;
    			if(isPalindrome(arr[i])) return 1;   //1) if self is palindrome, so here ans overs concatenate("",self)
    		}
    	}
    
    	for(int i=0;i<N;i++){
    		int l=arr[i].size();
    		for(int j=0;j<l;j++){
    			string left = arr[i].substr(0,j);
    			string lr=left;
    			reverse(lr.begin(), lr.end()); //left reverse
    			
    			string right = arr[i].substr(j);
    			string rr=right;
    			reverse(rr.begin(), rr.end()); //right reverse
    
    			if(dict.find(lr)!=dict.end() && isPalindrome(right) && dict[lr]!=i){
    				return 1;  //2) when j=0, left="", right=self, so here covers concatenate(self,"")
    			}
                
                if(dict.find(rr)!=dict.end() && isPalindrome(left) && dict[rr]!=i){
    				return 1;  //2) when j=0, left="", right=self, so here covers concatenate(self,"")
    			}
    
    		}
    	}
    	return 0;
    }

};





//Another Method :-
class Solution{   
 public:
   // Function to check if a palindrome pair exists
   bool ispa(string s)
   {
       int l=0;
       int h=s.size()-1;
       while(h>l)
       {
           if(s[l++]!=s[h--])
             return false;
       }
       return true;
   }
   bool palindromepair(int N, string arr[]) {
       for(int i=0;i<N;i++)
       {
           for(int j=0;j<N;j++)
           {
               if(i!=j&&arr[i][0]==arr[j][arr[j].size()-1]&&(ispa(arr[i]+arr[j])))
                 return true;
           }
       }
       return false;
   }

 

};