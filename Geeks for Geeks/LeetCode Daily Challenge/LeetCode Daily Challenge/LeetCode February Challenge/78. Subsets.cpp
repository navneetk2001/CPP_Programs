// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]



// Solution Approach :- 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }

private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};


//Another Solution :-
class Solution {
public:
    void hepler(vector<int>& m,int i,vector<vector<int>>& v,vector<int>& v1)
    {
        if(i==m.size())
        {
            v.push_back(v1);
            return;
        }
        v1.push_back(m[i]);
        hepler(m,i+1,v,v1);
        v1.pop_back();
        hepler(m,i+1,v,v1);
     
        
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> v;
        vector<int> v1;
        hepler(nums,0,v,v1);
        return v;
    }
};



//Another Solution :- Using Bit Manipulation :-

// The total number of possible subsets of any array of size n is 2^n. Because for each index there are two options either take it or leave it. So, for n indexes 2*2..n times options. (Using Permutation and Combination).
// Suppose for array size = 3
// 000. - Choose no item
// 001 - Choose only last item
// 010 - Choose only second last item
// 011 - Choose last and second last item
// 100 - Choose only first item
// 101 - Choose first and last item
// 110 - Choose first and second last
// 111 - Choose all

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int> > ans;
        vector<int> tmp;
        
        int l = nums.size();
        int total = (1<<l);   //total number of possible subsets. 
        
        for(int i = 0;i<total;i++)
        {
            tmp.clear();
            for(int j = 0;j<nums.size();j++)
            {
                if(1<<j & i) //check if that bit is set or not.
                {
                    tmp.push_back(nums[j]);
                }
            }
            
            ans.push_back(tmp);
        }
        
        return(ans);
    }
};