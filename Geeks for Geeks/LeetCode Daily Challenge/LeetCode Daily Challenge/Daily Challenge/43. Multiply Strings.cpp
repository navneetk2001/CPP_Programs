// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly. 

// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"




//Solution Approach :-
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
        	return "0";
        }
        
        vector<int> res(num1.size()+num2.size(), 0);
        
        for(int i = num1.size()-1; i >= 0; i--){
            for(int j = num2.size()-1; j >= 0; j--){
                res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }
        
        int i = 0;
        string ans = "";
        while(res[i] == 0){
        	i++;
        }
        while(i < res.size()){
        	ans += to_string(res[i++]);
        }
        
        return ans;
    }
};





//Second Solution :-
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}




//✔️ Solution - I (Simple School Multiplication)
// We can perform multiplication of two strings in the same way as we would manually in real life - simple elementary school multiplication.
// Take one of the number n1 and multiply each of its digit with the other number n2 to get an intermediate result.
// The intermediate results are padded with 0 at the end. For eg. -
// The intermediate result of last digit of n1 multiplied with n2 is padded with zero 0.
// the 2nd last digit of n1 multiplied with n2 is padded with one 0 at the end and so on...
// Finally, all the intermediate results are added together to get the final output.
// In the below solution, instead of storing all the intermediate results as we would on paper and then adding them all at last, we instead add intermediate result at each step. This saves us some space and is a bit concise.		
// The below code might look long but is really easy to understand and just simple school multiplication and addition written out into code.

class Solution {
public:
    string multiply(string& A, string& B) {
        if(A == "0" || B == "0") return "0";                  // if either is 0, final result will be 0
		if(size(A) < size(B)) return multiply (B, A);
        string ans = "";
        for(int j = size(B)-1, pad = 0; j >= 0; j--) {
            auto res = multiplyDigit(A, B[j], pad++);         // multiply each digit of B with A considering proper padding of 0 at end
            ans = addStrings(ans, res);                       // keep adding intermediate result to final result
        }
        return ans;
    }
	
	// multiply a string number with a char digit
    string multiplyDigit(string& s, char c, int pad) {
        int i = size(s)-1, carry = 0, digit1 = c-'0', digit2, res;
		// the string is formed in reverse manner & then reversed at end
		// This is because it's O(1) to push at the end instead of at the start
        string ans = string(pad, '0');
        while(i >= 0) {
            digit2 = s[i--]-'0';                    // get digit of num1 to be multiplied with digit1
            res = digit1 * digit2 + carry;          // multiplication of digits + carry from previous
            carry = res / 10;                       // update carry
            ans += res%10+'0';                      // only consider last digit & add it to result
        }
        if(carry) ans += carry+'0';                 // if there's leftover carry at end after multiplying all digits
        reverse(begin(ans), end(ans));              // reverse back to get correct result
        return ans;
    }
	
	// adds two string numbers - https://leetcode.com/problems/add-strings/
    string addStrings(string& A, string& B) {
        if(size(A) < size(B)) return addStrings(B, A);   // we assume A is the bigger string
        int i = size(A)-1, j = size(B)-1, carry = 0, digit1, digit2, res;
        string ans = "";
        while(i >= 0) {
            digit1 = A[i--]-'0', digit2 = j >= 0 ? (B[j--]-'0') : 0;  // get digits from both numbers
            res = digit1 + digit2 + carry;               // add both digit and carry from previous
            carry = res / 10;                            // update carry
            ans += res%10+'0';                           // only consider last digit & add it to result
        }
        if(carry) ans += carry+'0';                      // if there's leftover carry at end after multiplying all digits
        reverse(begin(ans), end(ans));                   // We formed in reverse order. Reverse it back to get correct result
        return ans;
    }
};