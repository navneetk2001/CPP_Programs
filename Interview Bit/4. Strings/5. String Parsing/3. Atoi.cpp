// There are certain questions where the interviewer would intentionally frame the question vague.
// The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.
// Implement atoi to convert a string to an integer.

// Example :
// Input : "9 2704"
// Output : 9
// Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

// Questions:
// Q1. Does string contain whitespace characters before the number?
// A. Yes

// Q2. Can the string have garbage characters after the number?
// A. Yes. Ignore it.

// Q3. If no numeric character is found before encountering garbage characters, what should I do?
// A. Return 0.

// Q4. What if the integer overflows?
// A. Return INT_MAX if the number is positive, INT_MIN otherwise.
// Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
// If you do, we will disqualify your submission retroactively and give you penalty points.

//Hint :-
// Think of all possible cases to handle as tricky cases.
// You also need to take special care for numbers which overflows. How?

//Solution Approach :-
// We only need to handle four cases:
// Discards all leading whitespaces
// Sign of the number
// Overflow
// Invalid input
// Detecting overflow gets tricky. You need to detect overflow before the number is about to overflow.
// So:
// If the number is positive and the current number is greater than MAX_INT/10, and you are about to append a digit, then certainly your number will overflow.
// If the current number = MAX_INT / 10, then based on the last digit, we can detect if the number will overflow.


// First Method :-
int Solution::atoi(const string A) {
    int sign = 1; 
    int result = 0; 
    int index = 0;
    int n = A.size();
    
    while(index < n && A[index] == ' '){      // Discard all spaces from the beginning of the input string.
        index++; 
    }
    
    if(index < n && A[index] == '+'){            // sign = +1, if it's positive number, otherwise sign = -1. 
        sign = 1;
        index++;
    } 
    else if(index < n && A[index] == '-'){
        sign = -1;
        index++;
    }
    
    // Traverse next digits of input and stop if it is not a digit. End of string is also non-digit character.
    while(index < n && isdigit(A[index])) {
        int digit = A[index] - '0';

        // Check overflow and underflow conditions. 
        if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
            return sign == 1 ? INT_MAX : INT_MIN;    // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31. 
        }
        
        result = 10 * result + digit;              // Append current digit to the result.
        index++;
    }
    
    // We have formed a valid number without any overflow/underflow. Return it after multiplying it with its sign.
    return sign * result;
}


//Second Method :-
int Solution::atoi(const string A) {
    long long i=0,n=A.size(),ans=0,t=2147483647;
    char sign='+';

    while(A[i]==' ')i++;  //check for blank space before the number
    if(A[i]=='-' || A[i]=='+'){   //Assigning sign 
        sign=A[i];
        i++;
    }
    while(i<n && A[i]<='9' && A[i]>='0'){
        if(ans*10+A[i]-'0'>t){   //check for overflow
            if(sign=='-'){
                return -t-1;
            }
            return t;
        }
        ans=ans*10 + A[i]-'0';   //creating the number
        i++;
    }
    if(sign=='-')return -ans;  //checking for positive and negative number
    return ans;
}


//Third Method :-
int Solution::atoi(const string A) {
	stringstream res(A);
	int x = 0;
	res >> x;
	return x;
}

int Solution::atoi(const string A) {
	stringstream ss;
	ss<<A;

	long long i;
	ss>>i;
	if(i<INT_MIN){
		i=INT_MIN;
    }
	if(i>INT_MAX){
		i=INT_MAX;
    }

	return i;
}