Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:
Input: a = 2, b = [3]
Output: 8

Example 2:
Input: a = 2, b = [1,0]
Output: 1024

Example 3:
Input: a = 1, b = [4,3,3,8,5,2]
Output: 1





//First Solution :- Go SEE LUV CP Videos on this topic
class Solution {
public:
	int binExp(int a, int b, int m){
		a%=m;
		int ans = 1;
		while(b>0){
			if(b&1){
				ans = (ans * 1ll * a) % m;
			}
			a = (a*1ll*a) % m;
			b>>=1;
		}
		return ans;
	}
	
    int superPow(int a, vector<int>& b) {
        int bmod = 0;
        for(int val:b){
        	bmod = (bmod * 10 + val) % 1140;  //1140 is phi(1337) using ETF
        }

        return binExp(a, bmod, 1337);
    }
};



//Second Solution :- Easy but not the fastest
// One knowledge: ab % k = (a%k)(b%k)%k
// Since the power here is an array, we'd better handle it digit by digit.
// One observation:
// a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
// Looks complicated? Let me put it other way:
// Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
// f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;

//Implementation of this idea:
class Solution {
    const int base = 1337;
    int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
    {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};

// Note: This approach is definitely not the fastest, but it is something one can quickly understand and write out when asked in an interview.
// And this approach is not using any built-in "pow" functions, I think this is also what the interviewer would expect you to do.
// Hope it helps!



//Third Solution :-
// 1337 only has two divisors 7 and 191 exclusive 1 and itself, so judge if a has a divisor of 7 or 191, and note that 7 and 191 are prime numbers, phi of them is itself - 1, then we can use the Euler's theorem, see it on wiki https://en.wikipedia.org/wiki/Euler's_theorem, it's just Fermat's little theorem if the mod n is prime.
// see how 1140 is calculated out:
// phi(1337) = phi(7) * phi(191) = 6 * 190 = 1140

// (1) Firstly, if a has both divisor 7 and 191, that's a % 1337 == 0, answer is 0.
// (2) Then if a has neither divisor 7 nor 191, that's a and 1337 are coprime, so ab % 1337 = ab % phi(1337) % 1337 = ab % 1140 % 1337.
// (3) Finally, a could has either divisor 7 or 191, that's similar.
// Let it be 7 for example.
// Let a = 7nx
// and let b = 1140p + q, where 0 < q <= 1140
// then: ab % 1337
// = ((7nx)b) % 1337
// = (7nbxb) % 1337
// = ( (7nb % 1337) * (xb % 1337) ) % 1337
// = ( (71140np + nq % 1337) * (x1140p + q % 1337) ) % 1337

// now note x and 1337 are coprime, so
// = ( (71140np + nq % 1337) * (xq % 1337) ) % 1337
// = ( 7 * (71140np + nq - 1 % 191) * (xq % 1337) ) % 1337

// note 7 and 191 are coprime too, and 1140 is a multiple of 190, where 190 = phi(191). What's more we should assure that q != 0, if b % 1140== 0, then let b = 1140. so
// = ( 7 * (7nq - 1 % 191) * (xq % 1337) ) % 1337
// = ( (7nq % 1337) * (xq % 1337) ) % 1337
// = (7nqxq) % 1337
// = ((7nx)q) % 1337
// = (aq) % 1337
// now you see condition (2) and (3) can be merged as one solution, if you take care of when b % 1440 == 0, and let b += 1140. Actually (1) can be merged too, but not efficient.

int superPow(int a, vector<int>& b) {
    if (a % 1337 == 0) return 0; // this line could also be removed
    int p = 0;
    for (int i : b) p = (p * 10 + i) % 1140;
    if (p == 0) p += 1140;
    return power(a, p, 1337);
}


int power(int x, int n, int mod) {
    int ret = 1;
    for (x %= mod; n; x = x * x % mod, n >>= 1) if (n & 1) ret = ret * x % mod;
    return ret;
}


//Fourth Solution :- Fermat and Chinese Remainder
The helper computes a^b modulo the given prime.

int superPow(int a, vector<int>& b) {
    return (764 * superPow(a, b, 7) + 574 * superPow(a, b, 191)) % 1337;
}

int superPow(int a, vector<int>& b, int prime) {
    if (!(a %= prime)) return 0;
    int e = 0, mod = prime - 1;
    for (int digit : b)
        e = (e * 10 + digit) % mod;
    int pow = 1;
    while (e) {
        if (e & 1)
            pow = pow * a % prime;
        a = a * a % prime;
        e >>= 1;
    }
    return pow;
}

// Using the Chinese Remainder Theorem
// Let's call x = ab. We want to know x % 1337. The helper function using Fermat already gave us u and w so that x % 7 = u and x % 191 = w. Or put differently, x ≡ u (mod 7) and x = w + 191t for some integer t. Combine these to get w + 191t ≡ u (mod 7). Subtracting w and multiplying with [191-1]7 (the multiplicative inverse of 191 modulo 7) we get t ≡ (u-w)·[191-1]7 (mod 7).

// We have [191-1]7 = [(191%7)-1]7 = [2-1]7 and one can easily see that the latter is 4, as (2*4)%7=1.
// Using that, we have t ≡ 4(u-w) (mod 7) or in other words t = 4(u-w) + 7s for some integer s. Which means:
// x = w + 191t
// = w + 191(4(u-w) + 7s)
// = 764u - 763w + 1337s
// = 764u + (1337-763)w + 1337(s-w)
// = 764u + 574w + 1337(s-w)

// So we can compute x from u and v as x = (764u + 574w) % 1337, like I have done in my solutions.