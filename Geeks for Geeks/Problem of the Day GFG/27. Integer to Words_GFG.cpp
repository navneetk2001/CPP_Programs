Write a function to convert a given number into words.

Example 1:
Input:
N = 438237764
Output: forty three crore eighty two lakh 
thirty seven thousand seven hundred and sixty four
 
Example 2:
Input:
N = 1000
Output: one thousand


// Complexity Analysis: 

// Time complexity: O(1). 
// The loop runs for a constant amount of time.
// Auxiliary space: O(1). 
// As no extra space is required.

vector<string>ones{"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
vector<string>tens{"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety " };

string numToWord(int n, string s){
	string str="";
	if(n>19){
		str+=tens[n/10]+ones[n%10]; //43 = forty + three
	}
	else{
		str+=ones[n];
	}

	if(n){
		str+=s;   //crore
	}

	return str; // forty three crore
}


class Solution{   
public:
    string convertToWords(long n) {
        string res;
    	res+=numToWord((n/10000000), "crore ");  //43, crore=forty three crore
    	res+=numToWord((n/100000)%100, "lakh ");  //82, lakh=eighty two lakh
    	res+=numToWord((n/1000)%100, "thousand ");  //37, thousand=thirty seven thousand
    	res+=numToWord((n/100)%10, "hundred ");  //7, hundred=seven hundred
    
    	if(n>100 && n%100){
    		res+="and "; //it will add "and" if there is a number
    	}
    	res+=numToWord((n%100),""); //64, = sixty four
        if(res=="")
            res = "zero";
    	return res;
    }
};




