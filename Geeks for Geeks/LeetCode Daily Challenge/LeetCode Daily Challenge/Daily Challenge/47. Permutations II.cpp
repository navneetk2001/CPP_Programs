// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Example 1:
// Input: nums = [1,1,2]
// Output: [[1,1,2], [1,2,1], [2,1,1]]

// Example 2:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]



//Solution Approach :-
class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for(int k = i; k < j; k++) {
            if(i != k && num[i] == num[k]){
                continue;
            }
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};



//Second Solution :-
//Starting with the simplest solution using std::next_permutation. This may not be acceptable in a 1:1 interview, but it's a good start. If you are doing a technical evaluation, this may be acceptable. Note that I'm sorting the elements as std::next_permutation returns false once it reaches the last lexicographically sorted permutation.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        vector<vector<int>> output;
        output.emplace_back(nums);

        while (next_permutation(begin(nums), end(nums))) {
            output.emplace_back(nums);
        }
        return output;
    }
};



//Third Solution :-
//Backtracking using a hash table. This is the same solution you'd find in the Solution tab. The key insight here is that by iterating through unique numbers, we can avoid duplication. If you practice the Permutations problem first, identifying this solution might be challenging, but it's easy enough to understand when you consider it on its own.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> curr;
        unordered_map<int, int> counter;
        for (auto x : nums) ++counter[x];
        generatePermutations(counter, curr, output, size(nums));
        return output;
    }
private:
    void generatePermutations(unordered_map<int, int>& counter, vector<int>& curr, vector<vector<int>>& output, int n) {
        if (size(curr) == n) {
            output.emplace_back(curr);
            return;
        }
        for (auto [key, value] : counter) {
            if (value == 0) continue;
            curr.emplace_back(key); --counter[key];
            generatePermutations(counter, curr, output, n);
            curr.pop_back(); ++counter[key];
        }
    }
};