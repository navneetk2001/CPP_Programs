// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// P.......A........H.......N
// ..A..P....L....S....I...I....G
// ....Y.........I........R
// And then read line by line: PAHNAPLSIIGYIR

// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

// **Example 2 : **
// ABCD, 2 can be written as
// A....C
// ...B....D
// and hence the answer would be ACBD.


//Solution Approach :-
// Just look at simply simulating what is being told in the problem.
// Follow the simple steps:

// You need to maintain numRows number of strings S[numRows].
// And then populating string S in each row in zigzag fashion.
// Finally concatenate S[0]....S[numRows-1] to get the answer.


//First Solution :-

//Approach :-
// str = "GEEKSFORGEEKS"
// n = 3
// Output: GSGSEKFREKEOE

// G E E K S F O R G E E K S
// 0 1 2 1 0 1 2 1 0 1 2 1 0

// in first it will include in row 0 :-> G
//                          in row 1 :-> E K
//                          in row 2 :-> E

class Solution{
    public:
    string convert(string s, int n) {
        if(n==1){
        	return s;
        }

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


//Third Solution :-
string convert(string s, int k) {
    if(k == 1){
        return s;
    }
    int n = s.size(), j = 0;
    vector<vector<char>> v(k);
    bool flg = true;
    
    for(int i=0; i<n; i++){
        v[j].push_back(s[i]);
        j += (flg == true) ? 1 : -1;
        if(j == 0 || j == k-1){
            flg = !flg;
        }
    }
    string str = "";
    for(auto i:v){
        for(auto j:i)
            str += j;
    }
    return str;
}


//Fourth Solution :-
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n){
                    ret += s[j + cycleLen - i];
                }
            }
        }
        return ret;
    }
};
