// 2 players A and B take turns alternatively to play a game in which they have N numbers on a paper. In one turn, a player can replace one of the numbers by any of its factor (except for 1 & the number itself). The player who is unable to make a move looses the game. Find the winner of the game if A starts the game and both play optimally.
 
// Example 1:
// Input: nums = [5, 7, 3]
// Output: B
// Explanation: Since all the numbers are prime, so A will not be able to make the first move. 

// Example 2:
// Input: nums = [2, 4, 7, 11]
// Outptut: A
// Explanation: In the first move A will replace 4 by 2, so the numbers will become [2, 2, 7, 11] now B will not be able to make a move since all the remaining numbers can only be divided by 1 or the number itself.




//Solution Approach :-
// The idea is:
// On A's turn, if current number is non-prime and excluding that number, if count of other non-prime numbers is odd, then A's replace this current number with non-prime factor, else with prime-factor.
// Vice versa for B's turn.

bool brainGame(vector<int>nums) {
	vector<int>a(1005);
	for(int i = 2; i<= 1000; i++){
		for(int j = 2*i; j <= 1000; j+=i){
			a[j] = max(a[j], 1 + a[i]);
		}
	}
	int x = 0;
	for(int i = 0; i < nums.size(); i++){
		x = x ^ a[nums[i]];
	}
	if(x == 0){
		return false;
	}
	return true;
}



//Second Solution :-
class Solution{
    bool isPrime(int n){
        if(n <= 1){
            return false;
        }
            
        if(n <= 3){
            return true;
        }
            
        if(n%2 == 0 || n%3 == 0){
            return false;
        }
            
        for(int i = 5; i <= n; i += 6){
            if(n%i == 0 || n%(i+2) == 0){
                return false;
            }
        }
        
        return true;
    }
    
    int primeFactors(int n){
        int ans = 0;
        while(n%2 == 0){
            ans++;
            n /= 2;
        }
        
        while(n%3 == 0){
            ans++;
            n /= 3;
        }
        
        for(int i=5; i<=sqrt(n); i += 6){
            while(n%i == 0){
                ans++;
                n /= i;
            }
            while(n%(i+2) == 0){
                ans++;
                n /= (i+2);
            }
        }
        
        if(n > 3){
            ans++;
        }
            
        return ans;
    }

	public:
    bool brainGame(vector<int>nums) {
        vector<int> v(1001, 0);
        for(int i=2; i<1001; i++){
            if(!isPrime(i)){
                v[i] = primeFactors(i) - 1;
            }
        }
        
        int x = 0;
    	for(int i = 0; i < nums.size(); i++){
    		x = x ^ v[nums[i]];
    	}
    	
    	if(x == 0){
    		return false;
    	}
    	return true;
    }
};



