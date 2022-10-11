// You are given a 0-indexed integer array nums and an integer k.
// You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.
// You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.
// Return the maximum score you can get.

// Example 1:
// Input: nums = [1,-1,-2,4,-7,3], k = 2
// Output: 7
// Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.

// Example 2:
// Input: nums = [10,-5,-2,4,0,3], k = 3
// Output: 17
// Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

// Example 3:
// Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
// Output: 0




//Solution Approach :-
// Observation :- 
// Let's try to solve this from the end for better visualization (It can be solved both ways).
// At every index i we want to pick the maximum result from i+1 to i+k and add nums[i] to it
// A maximum from i+1 to i+k can be found in O(1) time using a monoqueue. If monoqueue seems a little advanced you can even use a multiset to do the same thing sacrificing a little for time complexity O(logk) .

// Now all we need to do is use this monoqueue or multiset to get the maximum result of the next k indices and store it somewhere, we can use the input array itself as an auxillary array.
// Let's store only the indices in the monoqueue so that we can limit the monoqueue to have results only for the next k indices at max. With a multiset you'd store the actual values and delete the value for answer [i+k].

// Best problem to solve to understand the workings of a monoqueue:->  239. Sliding Window Maximum

class Solution {
public:
    int maxResult(vector<int>& nums, int k){
        long curr=0;
        deque<int> dq;     		// Monoqueue
		
		// Start answering the best possible results for index `i` from the back
        for(int i=nums.size()-1;i>=0;i--){
            curr = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);       // Get current best, the maximum result will be the first element in the monoqueue.
			
			// We remove all the smaller results greedily as they wont get used anyways (This helps the monoqueue to remain sorted)
            while(!dq.empty()&&curr>nums[dq.back()]){
                dq.pop_back();	
            }
            dq.push_back(i);              // Insert current index into the monoqueue
			
			// Erase all the indices in deque that are greater than or equal to i+k.
            if(dq.front()>=i+k){
                dq.pop_front();
            }
            nums[i]=curr;                      // Use input array as auxillary array to store the best results.
        }
        return curr;                           // `curr` would have the best or the maxium result to reach end from index 0.
    }
};

// Time: O(n).
// Space O(n). Since the algorithm uses auxillary array, even though it's the input itself. This can be reduced to O(k) if we simply store the index and value in the deque itself.



//Second Solution :- DP + Monodeq
// For each step, the best value is the number at that step, plus the max value among the previous k steps.
// We can use a sliding window technique along with monotonically decreasing deque. That way, the max value will be the first element in the deque.
// It's easy to see that this solution has O(n) complexity, but somehow its runtime is slower than for the pruning solution above. Perhaps there is no a test case with all negative numbers (update: now there is).

int maxResult(vector<int>& nums, int k) {
    deque<int> d{0};
    for (int i = 1; i < nums.size(); ++i) {
        if (d.front() + k < i){
            d.pop_front();        
        }
        nums[i] += nums[d.front()];
        while (!d.empty() && nums[d.back()] <= nums[i]){
            d.pop_back();
        }
        d.push_back(i);
    }
    return nums.back();
}



//Third Solution :- DP + Pruning
// Not the most efficient solution - I somehow fixed my mind on O(n * n) DP during the contest. Until I got TLE :)
// Then I got a hunch that there must be some O(n) solution, but instead I just modified DP to stop the inner loop when we find a positive number. We would definitelly take that spot before jumping any further.
// Note: this solution is not accepted anymore, as all-negative test case was added after the contest.

int maxResult(vector<int>& nums, int k) {
    vector<int> dp(nums.size(), INT_MIN);
    dp[0] = nums[0];
    for (auto i = 0; i < nums.size(); ++i){
        for (auto j = 1; j <= k && i + j < nums.size(); ++j) {
            dp[i + j] = max(dp[i + j], dp[i] + nums[i + j]);
            if (nums[i + j] >= 0){
                break;
            }
        }
    }
    return dp.back();
}



//Fourth Solution :- Dp Solution <-- Give You TLE
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            int l = k;
            while(l){
                if(i-l>=0){
                    dp[i] = max(dp[i-l]+nums[i], dp[i]);     
                }
                l--;
            }
        }
        return dp[nums.size()-1];
    }
};

// Why it give Us Tle In Dp?? Let's Find it and try To Optimize it
// As Our Dp solution take O(N * K) Time compexity where N and K both can be as learge as 10^5 so no where it can be accepted by that approch

// Now while Applying Dp what we did is like
// Dp[i] = max(dp[i-k]+nums[i],dp[i]) where k-- 
// By doing this we only found max value from previous find DP values in between i to i-k!!! in 
// O( K ) Time right??
// So total time taken is O(N*K)

// Optimize it
// now  here is the trick we don't need to loop each K time insted of what we can do we can use set/priority_queue to find max DP valu from previous K element by O(log K) time 
// now find It and add to the DP table . That's it!!!!!!
// Here Is the O ( N Log K) slution

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size()==1){
        	return nums[0];
        }
        vector<int> dp(nums.size(),INT_MIN);
        multiset<int>Q;
        dp[0] = nums[0];
        Q.insert(dp[0]);
        for(int i = 1;i<nums.size();i++){
            if(Q.size()>k){
                auto it = Q.find(dp[i-k-1]);
                Q.erase(it);
            }
            dp[i] = max(*Q.rbegin()+nums[i],dp[i]);
            Q.insert(dp[i]);
        }
        return dp[nums.size()-1];
    }
};



//Fifth Solution :-
// score[i] will store the score if I start jumping from index i and priority queue will store all the scores of the window [i+1, min(n-1, i+k)].
// To get the maximum score from index i, I should jump to next index with the maximum value in the window.

#define pii pair<int, int>
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n=nums.size();
        int score[n];
        priority_queue<pii> pq;
        
        for(int i=n-1 ; i>=0 ; i--){
            while(pq.size() && pq.top().second > i+k){
                pq.pop();
            }
            
            score[i] = nums[i];
            score[i] += (pq.size() ? pq.top().first : 0);
            pq.push({score[i], i});
        }
        
        return score[0];
    }
};




//Solution :- Recursion [TLE]
class Solution {
public:
    int maxx;
    void recur(vector<int>& nums, int k, int index, int sum) {
        if(nums.size()-1 == index){            // Reached last index
            maxx = max(maxx, sum);
            return;
        }
        
		// Check all the possibilities
        for(int i=1; (i<=k && (i+index)<nums.size()); ++i) {
            recur(nums, k, i+index, sum+nums[i+index]);
        }
    }
    
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), -1);
        recur(nums, k, 0, nums[0]);
        return maxx;
    }
};


//Memoization [TLE]

class Solution {
public:
    int recur(vector<int>& nums, int k, int index, vector<int>& dp) {
        if(dp[index] != -1)
            return dp[index];
        
        if(index == nums.size()-1) {
            dp[index] = nums[index];
            return dp[index];
        }
        
        int max_so_far = INT_MIN;
        
        for(int i=1; (i<=k && (i+index)<nums.size()); ++i) {
            max_so_far = max(max_so_far, recur(nums, k, i+index, dp));
        }
        
        dp[index] = max_so_far + nums[index];
        
        return dp[index];
    }
    
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), -1);
        return recur(nums, k, 0, dp);
    }
};