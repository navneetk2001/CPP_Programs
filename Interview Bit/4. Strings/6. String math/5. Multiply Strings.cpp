// Given two numbers represented as strings, return multiplication of the numbers as a string.
// Note: The numbers can be arbitrarily large and are non-negative.
// Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer.
// For example, 
// given strings "12", "10", your answer should be “120”.
// NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 
// We will retroactively disqualify such submissions and the submissions will incur penalties.


//Hint :-
// If length of input strings are N and M, then the expected comlexity is O(N*M) here.
// You need to code the same process of multiplication which you follow on pen-paper.

//Solution Approach :-
// Would it be easier if you reversed the number for multiplication to calculate the reverse of the answer and then reverse it back to get the actual answer?
// It is mostly simulation of the multiplication process where we take one number digit by digit and keep multiplying the digit with the other number and maintaining the sum in another array.

//First Solution :-
string Solution::multiply(string A, string B) {
    int n = A.size();
    int m = B.size();
    string ans(n + m, '0');

    for(int i = n - 1; i>=0; i--){
        for(int j = m - 1; j >= 0; j--){
            int p = (A[i] - '0') * (B[j] - '0') + (ans[i + j + 1] - '0');
            ans[i+j+1] = p % 10 + '0';
            ans[i+j] += p / 10 ;
        }
    }

    for(int i = 0; i < m + n; i++){
        if(ans[i] !='0'){
            return ans.substr(i);
        }
    }
    return "0";
}


//Second Solution :-
string Solution::multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0"){         // handle edge-case where the product is 0       
        return "0";     
    }
    
    vector<int> num(num1.size() + num2.size(), 0);       // num1.size() + num2.size() == max no. of digits
    
    // build the number by multiplying one digit at the time
    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            num[i + j] += num[i + j + 1] / 10;
            num[i + j + 1] %= 10;
        }
    }
    
    // skip leading 0's
    int i = 0;
    while (i < num.size() && num[i] == 0) ++i;
    
    // transofrm the vector to a string
    string res = "";
    while (i < num.size()) res.push_back(num[i++] + '0');
    
    return res;
}

//Third Solution :-
string Solution::multiply(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    string res;
    res.resize(A.size() + B.size(), '0');

    for (int i = 0; i < A.size(); ++i) {
        int p = 0;
        for (int j = 0; j < B.size() || p; ++j) {
            int val = res[i+j]-'0';
            int mul = 0;
            if (j < B.size()) {
                mul = (B[j] - '0');
            }

            val+=(A[i]-'0')*mul+p;
            p=val/10;
            val%=10;
            res[i+j]=(val+'0');
        }
    }

    while ((res.size() > 1) && (res[res.size() - 1] == '0'))
        res.pop_back();
    
    reverse(res.begin(), res.end());
    return res;
}
