// Given an integer n, return the number of trailing zeroes in n!.
// Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

// Example 1:
// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.

// Example 2:
// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.

// Example 3:
// Input: n = 0
// Output: 0




//Solution Approach :-
// Well, to compute the number of trailing zeros, we need to first think clear about what will generate a trailing 0? Obviously, a number multiplied by 10 will have a trailing 0 added to it. So we only need to find out how many 10's will appear in the expression of the factorial. Since 10 = 2 * 5 and there are a bunch more 2's (each even number will contribute at least one 2), we only need to count the number of 5's.
// Now let's see what numbers will contribute a 5. Well, simply the multiples of 5, like 5, 10, 15, 20, 25, 35, .... So is the result simply n / 5? Well, not that easy. Notice that some numbers may contribute more than one 5, like 25 = 5 * 5. Well, what numbers will contribute more than one 5? Ok, you may notice that only multiples of the power of 5 will contribute more than one 5. For example, multiples of 25 will contribute at least two 5's.
// Well, how to count them all? If you try some examples, you may finally get the result, which is n / 5 + n / 25 + n / 125 + .... The idea behind this expression is: all the multiples of 5 will contribute one 5, the multiples of 25 will contribute one more 5 and the multiples of 125 will contribute another one more 5... and so on. Now, we can write down the following code, which is pretty short.

class Solution {
public:
    int trailingZeroes(int n) { 
        int count = 0;
        for (long long i = 5; n / i; i *= 5){
            count += n / i;                      //calculate total no of 5's in the n factorial
        }
        return count;
    }
};



//Second Solution :- recursive
// The idea is:
// The ZERO comes from 10.
// The 10 comes from 2 x 5
// And we need to account for all the products of 5 and 2. likes 4×5 = 20 ...
// So, if we take all the numbers with 5 as a factor, we'll have way more than enough even numbers to pair with them to get factors of 10

class Solution {
public:
    int trailingZeroes(int n) { 
		return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};



//Third Solution :-
// Because from 1 to n, the number of 2 factors is always bigger than the number of 5 factors. So we only need to find the number of 5 factors among 1...n.
// 1st loop: 5, 10, 15, 20, 25, 30, ....
// 2nd loop: 25 50 ......

class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        while(n){
            n/=5;
            res+=n;
        }
        return res;
    }
};