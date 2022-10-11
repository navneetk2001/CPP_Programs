// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:
// Input: nums = [1]
// Output: [[1]]




//Solution Approach :- Backtracking
class Solution {
public:
	void permute(vector<int> nums, int i, vector<vector<int>>& perms) {
        if(i == nums.size()){
            perms.push_back(nums);
        } 
        else{
            for(int j = i; j < nums.size(); j++){
                swap(nums[i], nums[j]);
                permute(nums, i + 1, perms);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        permute(nums, 0, perms);
        return perms;
    }
};




//Second Solution :- Next Permutation
//Besides backtracking, you may also solve this problem using Next Permutation: computing the next permutation and add it to the result until the permutation becomes the original array (n! times since all digits are distinct).
class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> perms;
        for(int i = 0, n = factorial(nums.size()); i < n; i++){
            perms.push_back(nums);
            nextPermutation(nums);
        }
        return perms;
    }

private:
    int factorial(int n){
        int f = 1;
        while(n > 1){
            f *= n--;
        }
        return f;
    }
    
    void nextPermutation(vector<int>& nums){
        int n = nums.size(), i, j;
        for(i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                break;
            }
        }

        if(i < 0){
            reverse(nums.begin(), nums.end());
        } 
        else{
            for(j = n - 1; j > i; j--){
                if(nums[j] > nums[i]){
                    break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};



//Third Solution :- Backtracking
class Solution {
public:
    vector<vector<int>> result;
 
    void permutation(vector<int> &nums,int i,int n){
        if(i==n){
            result.push_back(nums);
            return ;
        }

        for(int j=i;j<=n;j++){
            swap(nums[i],nums[j]);
            permutation(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums){
        permutation(nums,0,nums.size()-1);
        return result;
    }
};