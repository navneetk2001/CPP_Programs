

//Hint :-
Let us look at every bit position.
Every number that occurs thrice will either contribute 3 ‘1’s or 3 ‘0’s to the position.
The number that occurs once X will contribute exactly one 0 or 1 to the position depending on whether it has 0 or 1 in that position.
So:
If X has 1 in that position, we will have (3x+1) number of 1s in that position.
If X has 0 in that position, we will have (3x+1) number of 0s in that position.
Can you think of a solution using the above observation?

//Solution Approach :- 
Having noticed that if X has 1 in that position, we will have 3x+1 number of 1s in that position. If X has 0 in that position, we will have 3x+1 number of 0 in that position.
A straightforward implementation is to use an array of size 32 to keep track of the total count of ith bit.
We can improve this based on the previous solution using three bitmask variables:
ones as a bitmask to represent the ith bit had appeared once.
twos as a bitmask to represent the ith bit had appeared twice.
threes as a bitmask to represent the ith bit had appeared three times.
When the ith bit had appeared for the third time, clear the ith bit of both ones and twos to 0. The final answer will be the value of ones.


//First Solution :-
int Solution::singleNumber(const vector<int> &arr) {
    int n=arr.size();
	vector<int>f(32,0);

	for(int e: arr){
		for(int i=0;i<32;i++){
			if(e & (1<<i)){
				f[i]++;
			}
		}
	}
    
	int res=0;
	for(int i=0;i<32;i++){
		if(f[i]%3==1){
			res+=(1<<i);
		}
	}
	return res;
}

//Second Solution :-
class Solution {
public:
    int singleNumber(const vector<int> &A) {
            int n = A.size();
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }
};


//Approach 2:
int singleNumber(const vector<int> &A) {
    int n = A.size();
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones & A[i];
        ones ^= A[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}


//Third Solution :- 
int Solution::singleNumber(const vector<int> &A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.size(); i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;

}


//4 methods :-
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //Using XOR + AND combination
        int ones = 0;
        int twos = 0;
        for(auto ele: nums)
        {
            ones = (ones^ele) & (~twos);
            twos = (twos^ele) & (~ones);
        }
        return ones;
        
        //Counting SET-BIT
        int n=nums.size();
        unsigned int ans=0,shift=1;
        for(int i=0;i<32;++i)
        {
            int count=0;
            for(auto ele: nums)
            {
                if(ele & shift)
                    count+=1;
            }
            if(count%3 != 0)
                ans += shift;
            shift*=2;
            
        }
        return ans;
        
        
        //SORTING
        int n=nums.size();
        if(n<3)
            return nums[0];
        
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1])
            return nums[0];
        int i=1;
        while(i<n)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
            i+=3;
        }
        return nums[n-1];
        
    }
}
