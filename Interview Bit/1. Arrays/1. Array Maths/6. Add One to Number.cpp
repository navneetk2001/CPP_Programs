// Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

// The digits are stored such that the most significant digit is at the head of the list.

// NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: 
// for this problem, following are some good questions to ask :

// Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
// A : For the purpose of this question, YES
// Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
// A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.


//Hint 1
First convince yourself that constructing numbers and then adding 1 will not work.
The number of digits can be really high ( Imagine 1000 - 10000 digits ).

Now, lets look at how we will add 1.
Try to think of how you would add 1 on paper. Start from the last digit, and maintain carry.


//Hint 2
There are 2 cases with adding one.

Case 1:

The number of digits after adding 1 remains the same.

This is the easy case. Simulate the mathematical process of adding one maintaining carry from the digit.

Case 2:

The number of digits increases by 1 when adding.

This causes some complication as you would have to shift all digits by 1 to make space for the new digit in the most significant position.

Tip :Try reversing the digits for the addition. Reverse them back after getting the result.




//Solution Approach
Reverse the digits of the number to make your life easier.

Maintain a carry which is initialized to 1 ( Denoting that we need to add one to the number ).
Run a loop on the digit array ( which is now reversed ), and add carry to the current digit. If the digit D exceeds 10 on doing so, store the last digit in current position ( D % 10 ), and make carry = rest of the digits ( D / 10 ). Continue the process till you have covered all the digits.
Now if at the end, carry = 0, we are done, and we can return the array.

If not, we need to add one more digit, with carry in it.









// First Method :- 
vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size(),carry=0;
    vector<int>res;

    res.push_back((1+A[n-1])%10);
    carry=(1+A[n-1])/10;

    for(int i=n-2;i>=0;i--){
        res.push_back((carry+A[i])%10);
        carry=(carry+A[i])/10;
    }
    if(carry)
     res.push_back(carry);
    int x=res.size();
    for(int i=0;i<x/2;i++){
       swap(res[i],res[x-i-1]);
    }

    while(res[0]==0){
       res.erase(res.begin());
    }
    return res;
}




//Second Method :- 
class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            reverse(digits.begin(), digits.end());
            vector<int> ans;
            int carry = 1;
            for (int i = 0; i < digits.size(); i++) {
                int sum = digits[i] + carry;
                ans.push_back(sum%10);
                carry = sum / 10;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry /= 10;
            }
            while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
                ans.pop_back();
            }
            reverse(ans.begin(), ans.end());
            reverse(digits.begin(), digits.end());
            return ans;
        }
};


//Third Method :-
