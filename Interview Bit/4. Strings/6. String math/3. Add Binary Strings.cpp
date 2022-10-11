// Given two binary strings, return their sum (also a binary string).

// Example:
// a = "100"
// b = "11"
// Return a + b = "111".


//Hint :-
// This is exactly like adding 2 numbers.
// Note 1: It might be easier if you construct the reverse of the answer, reversing the strings that we have to add.
// Note 2: Make sure you don’t stop before carry is 0. (Cases like 11 + 1.)


//Solution Approach :-
// Since sizes of two strings may be different, we first make the size of smaller string equal to that of bigger string by adding leading 0s for simplicity
// Note that you can handle the addition without adding zeroes as well by adding a few if statements.
// After making sizes same, one by one, we add bits from rightmost bit to leftmost bit.
// In every iteration, we need to sum 3 bits: 2 bits of 2 given strings and carry.
// The sum bit will be 1 if, either all of the 3 bits are set or one of them is set.So we can add all the bits and then take remainder with 2 to get the current bit in the answer.

// How to find carry?
// Carry will be 1 if any of the two bits is set. So we can find carry by adding the bits and dividing the result by 2.
// Following is a step by step algorithm:
// Make them equal sized by adding 0s at the begining of smaller string.
// Perform bit addition
// Boolean expression for adding 3 bits a, b, c
// Sum = (a + b + c) % 2
// Carry = (a + b + c ) / 2


// First Method :-
string Solution::addBinary(string A, string B) {
    string res;
    int j=A.size()-1, k=B.size()-1;
    int carry=0;
    while(j>=0 || k>=0){
        int sum=carry;
        if(j>=0){
            sum+= A[j--]-'0';
        }
        if(k>=0){
            sum+= B[k--]-'0';
        }
        carry=(sum>1)?1:0;
        res+=to_string(sum%2);
    }
    if(carry) res+='1';
    reverse(res.begin(), res.end());
    return res;
}


//Second Method :-
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
	    int ansLen = 0, carry = 0, sum;
	    int i = (int)a.length() - 1, j = (int)b.length() - 1;
	    while (i >= 0 || j >= 0 || carry) {
	        sum = carry;
	        if (i >= 0) sum += (a[i] - '0');
	        if (j >= 0) sum += (b[j] - '0');
	        ans.push_back((char)('0' + sum % 2));
	        carry = sum / 2;
	        i--; 
	        j--;
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
    }
};


//Third Method :-
string Solution::addBinary(string A, string B) {
    string C;
    vector<int> ans;
    if(B.length()>A.length()){
        swap(A,B);
    }
        
    int i = A.length()-1 , j = B.length()-1;
    int carry=0;
    while(i>=0 && j>=0)
    {
        if(A[i]-'0' + B[j]-'0' + carry == 2){
            A[i]='0';
            carry=1;
        }
        else if(A[i]-'0' + B[j]-'0' + carry == 3){
            A[i]='1';
            carry=1;
        }
        else if(A[i]-'0' + B[j]-'0' + carry == 1)
        {
            A[i]='1';
            carry=0;
        }
        else if(A[i]-'0' + B[j]-'0' + carry == 0){
            A[i]='0';
            carry = 0;
        }
        i--;
        j--;
    }
    
    while(i>=0){
        if(A[i]-'0' + carry==2){
            A[i]='0';
            carry=1;
        }
        else if(carry +A[i]-'0' ==1){
            A[i]='1';
            carry=0;
        }
        else{
            A[i]='0';
            carry=0;
        }
        i--;
    }
    
   
    string D;
    if(carry==1){
    	D="1";
    	A.insert(0,D);
    }
    return A;
}


//Fourth Solution :-
string Solution::addBinary(string a, string b) {

	int n=a.size();
	int m=b.size(); 
	int i=n-1,j=m-1;

	int carry=0;
	string ans;

	while(i>=0 && j>=0){
	    int k=(a[i]-'0')+(b[j]-'0')+carry;
	    if(k>1){
	        ans+=to_string(k%2);
	        carry=k/2;
	    }
	    else{
	       ans+=to_string(k%2);
	        carry=k/2;
	    }
	    i--;
	    j--;
	}

	while(i>=0){
	     int k=(a[i]-'0')+carry;
	    if(k>1){
	        ans+=to_string(k%2);
	        carry=k/2;
	    }
	    else{
	        ans+=to_string(k%2);
	        carry=k/2;
	    }
	    i--;
	}

	while(j>=0){
	    int k=(b[j]-'0')+carry;
	    if(k>1){
	       ans+=to_string(k%2);
	        carry=k/2;
	    }
	    else{
	        ans+=to_string(k%2);
	        carry=k/2;
	    }
	    j--;
	}
	if(carry) ans+=to_string(1);
	reverse(ans.begin(),ans.end());
	return ans;
}