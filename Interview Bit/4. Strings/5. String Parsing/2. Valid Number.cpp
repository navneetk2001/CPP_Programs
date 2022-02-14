// Note: It is intended for some problems to be ambiguous. You should gather all requirements up front before implementing one.
// Please think of all the corner cases and clarifications yourself.

// Validate if a given string is numeric.
// Examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

// Clarify the question using “See Expected Output”
// Is 1u ( which may be a representation for unsigned integers valid?
// For this problem, no.

// Is 0.1e10 valid?
// Yes

// -01.1e-10?
// Yes

// Hexadecimal numbers like 0xFF?
// Not for the purpose of this problem

// 3. (. not followed by a digit)?
// No

// Can exponent have decimal numbers? 3e0.1?
// Not for this problem.

// Is 1f ( floating point number with f as prefix ) valid?
// Not for this problem.

// How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
// Not for this problem.

// How about integers preceded by 00 or 0? like 008?
// Yes for this problem


LeetCode explanation :-
// A valid number can be split up into these components (in order):
// A decimal number or an integer.
// (Optional) An 'e' or 'E', followed by an integer.
// A decimal number can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// One of the following formats:
// One or more digits, followed by a dot '.'.
// One or more digits, followed by a dot '.', followed by one or more digits.
// A dot '.', followed by one or more digits.
// An integer can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// One or more digits.
// For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

// Given a string s, return true if s is a valid number.


//Hint :-
This is a brute force problem with lot of corner cases. You need to properly figure them out before coding.
Some of them includes dealing with numbers having different signs.

//Solution Approach :-
Most of the corner cases have already been mentioned in the question itself.
To start with, make sure you skip the whitespaces.
Then ignore the ‘+’ or ‘-‘ sign.
Scan the following string till you find numbers and ‘.’ and confirm at least one digit, less than one ‘.’ and the string not ending with ‘.’.
Now the remaining string could have ‘e’ followed by a number.
Confirm if the next character is ‘e’, then again repeat the process of skipping the sign and looking for digits.


// First Method :-
int Solution::isNumber(const string A) {
   int st=0,en=A.length()-1;
   while(A[st]==' ')st++;
   while(A[en]==' ')en--;
   if(A[st]=='-')st++;

    int deci=0;
    int e=0;
    
    if(st==A.length())return 0;

    for(int i=st;i<=en;i++)
    {
        if(A[i]>='0' && A[i]<='9')continue;
        else if(A[i]=='.' && deci==0 && e==0)
        {
            deci++;
            if(i+1>=A.length())
            return 0;
            
        }
        else if(A[i]=='e' && e==0)
        {
            if(A[i-1]=='.')return 0;
            e++;
           if(A[i+1]=='-')i++;
        }
        else 
        	return 0;
    }
    return 1;
}



//Second Method :-
class Solution {
public:
    bool isNumber(string s) {
        int signcount=0, ecount=0, dotcount=0; 
        bool dotnot=false, enot=true, intcount=false, intpresent=false;
        if(s.size()==1)
        {
            if(s[0]>='0' && s[0]<='9')
                return true;
            else
                return false;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i] >= '0' && s[i]<='9')
            {
                intpresent=true;
                enot =false;
                if(ecount>0)
                {
                    intcount=true;
                }
                continue;
            }
            else if(s[i] =='-' || s[i]=='+')
            {
                signcount++;
                if(i-1 >=0 && (s[i-1]!='e' && s[i-1]!='E'))
                   return false;
                if(signcount>2)
                    return false;
            }
            else if(s[i]=='e' || s[i] == 'E')
            {
                ecount++;
                dotnot = true;
                if(enot)
                    return false;
                if(i+1>=s.size())
                    return false;
                if(ecount>1)
                    return false;
            }
            else if(s[i] == '.')
            {
                dotcount++;
                if(dotnot)
                    return false;
                if(dotcount>1)
                    return false;
            }
            else
            {
                return false;           
            }
        }
        if(ecount>0 && intcount==false)
            return false;
        if(!intpresent)
            return false;
        return true;
    }
};




//Third Method :-
class Solution {
    public:
        bool isNumber(const string &S) 
        {
            const char *s = S.c_str();
            int i = 0;

            // skip the whilespaces
            while (s[i] == ' ') { 
                i++;
            }
            if (s[i] == '\0') return false;

            // check the significand
            if (s[i] == '+' || s[i] == '-') i++; // skip the sign if exist
            int num_digits, num_points;
            for (num_digits=0, num_points=0; (s[i] <= '9' && s[i] >= '0') || s[i]=='.'; i++) {
                if (s[i] == '.') {
                    num_points++;
                } else {
                    num_digits++;
                }
            }

            // no more than one point, at least one digit. Should not end with .
            if (num_points > 1 || num_digits < 1 || s[i - 1] == '.') 
                return false;

            // check the exponent if exist
            if(s[i] == 'e') {
                i++;
                if (s[i] == '+' || s[i] == '-') i++; // skip the sign

                num_digits = 0;
                while (s[i] >= '0' && s[i] <= '9') { 
                    i++; 
                    num_digits++;
                }

                if (num_digits < 1)
                    return false;
            }

            // skip the trailing whitespaces
            while (s[i] == ' ') {
                i++;
            }

            return s[i] == '\0';  // must reach the ending \0 of the string
        }
};



//Fourth Solution :-
int Solution::isNumber(const string A) {
    int n=A.size(), i=0, sign=1, base=0, num_digits=0, num_decimal=0;
    
    while(A[i]==' ')
        i++;
    
    if (A[i] == '-' || A[i] == '+') 
        i++;
        
    while((A[i] >= '0' && A[i] <= '9') || A[i]=='.'){
        if(A[i]=='.')
            num_decimal++;
        else
            num_digits++;
        i++;
    }
    
    if(num_digits<1 || num_decimal>1 || A[i-1]=='.')
        return 0;
    
    if(A[i]=='e'){
        i++;
        
        if (A[i] == '-' || A[i] == '+')
            i++;
        
        while(A[i] >= '0' && A[i] <= '9'){
            num_digits++;
            i++;
        }
    
        if(num_digits<1)
            return 0;
    }
    
    while(A[i]==' ')
        i++;
    
    if(i==n)
        return 1;
    
    return 0;
}




//Giving Wrong answer
bool isDigit(char c){
    return (c >= '0'  && c<='9');
}

int Solution::isNumber(const string s) {
//    string s=trim(A);
    if (s.length() == 0) return false;
    
    bool numberSeen = false;
    bool eSeen = false;
    bool decimalSeen = false;
    
    int st=0,en=s.length()-1;
    while(s[st]==' ')st++;
    while(s[en]==' ')en--;
    if(s[st]=='-')st++;

    int i=st;
    for (;i < en; ++i) {
        char c = s[i];
        switch(c) {
            case '.':
                if (decimalSeen || eSeen) return false;
                decimalSeen = true;
                break;
            case 'E':
            case 'e':
                if (eSeen || !numberSeen) return false;
                eSeen = true;
                numberSeen = false;
                break;
            case '+':
            case '-':
                if (i != 0 && ((s[i-1]) != 'e' || (s[i-1]) != 'E')) return false;
                numberSeen = false;
                break;
            default:
                if (!isDigit(c)) return false;
                numberSeen = true;
        }

    }

    return numberSeen;
}


