Given a string and number of rows ‘n’. Print the string formed by concatenating n rows when the input string is written in row-wise Zig-Zag fashion.

Example 1:
Input: 
str = "ABCDEFGH"
n = 2
Output: "ACEGBDFH"
Explanation: 
Let us write input string in 
Zig-Zag fashion in 2 rows.
A   C   E   G  
  B   D   F   H
Now concatenate the two rows and ignore 
spaces in every row. We get "ACEGBDFH"

Example 2:
Input: 
str = "GEEKSFORGEEKS"
n = 3
Output: GSGSEKFREKEOE
Explanation: 
Let us write input string in 
Zig-Zag fashion in 3 rows.
G       S       G       S
  E   K   F   R   E   K
    E       O       E
Now concatenate the two rows and ignore spaces
in every row. We get "GSGSEKFREKEOE"

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).


//Approach :-
str = "GEEKSFORGEEKS"
n = 3
Output: GSGSEKFREKEOE

// G E E K S F O R G E E K S
// 0 1 2 1 0 1 2 1 0 1 2 1 0

// in first it will include in row 0 :-> G
//                          in row 1 :-> E K
//                          in row 2 :-> E


class Solution{
    public:
    string convert(string s, int n) {
        if(n==1)
        	return s;

        string ans[n];
        int curRow=0, mod=1;
        for(auto e:s){
        	ans[curRow].push_back(e);
        	if(curRow==0){
        		mod=1;
        	}
        	if(curRow==n-1){
        		mod=-1;
        	}
        	curRow+=mod;
        }
        s.clear();
        for(auto e:ans){
        	s.append(e);
        }
        return s;
    }
};



//Second Solution :-
class Solution{
    public:
    string convert(string s, int numRows) {
        vector<string>v(numRows,"");
        int i=0, n=s.length();
        while(i<n){
        	for(int j=0;j<numRows && i<n;j++){
        		v[j].push_back(s[i++]);
        	}
        	for(int j=numRows-2;j>=1 && i<n;j--){
        		v[j].push_back(s[i++]);
        	}
        }
        
        string res="";
        for(auto i:v){
        	res+=i;
        }
        
        return res;
    }
};