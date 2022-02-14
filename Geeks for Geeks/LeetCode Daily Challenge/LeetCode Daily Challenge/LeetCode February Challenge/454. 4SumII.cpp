// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 
// Example 1:
// Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// Output: 2
// Explanation:
// The two tuples are:
// 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

// Example 2:
// Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
// Output: 1


//Brute Force Approach :- Use 4 loops   :-> Time Complexity :- O(N^4)

//Another Approach :- Use one map and 3 loops :-> Time Complexity :- O(N^3)
    //a+b+c+d = 0  => d = -(a+b+c)   // So, we will store d in map and find -(a+b+c) in map


//Better Approach :- 
//a+b+c+d = 0  => (d+c) = -(a+b)   //So, we will store sum of each c & d in map and find -(a+b) in map
//Time Complexity :- O(N^2)
class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) 
    {
        int n = a.size();
        unordered_map<int, int> mp;
        
        int ans = 0;
        
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                mp[c[i]+ d[j]]++;  //store the sum of every element of C with every element of D in map
            }
        }
        
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                ans = ans + mp[-(a[i] + b[j])];   //if for every sum of A and B, negetive sum is found in map, update count
            }
        }
        
        return ans;
    }
};


//Another Solution :-
class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int count=0;
        unordered_map<int,int> mp;
        
        /* Philosophy
        
        1. I know that Addtion have two parts in it  EG (a +b , Part 1 - a, Part 2- b.
        2.So, Lets make and find this dependency factors. How can I do it?
        3. If there are 4 Sum. it means 2 sums is going to Part 1 and another 2 gonna be Part 2 which are dependent on Part 1 for 0 resultant.
        4. I gonna store summation 2 nums1 in a FREQUENCY Hashmap.
        5. Then I traverse 2nd part of the summation (rest to nums) and keep checking that do (0-it1-it2) is exist in map . 
        6. If yes, the add the frequency of Part1 int COUNT var.
        7. return count;
        */
        
        //Traversing Part 1
        for (auto &it1: nums1)
            for (auto &it2:nums2)
                mp[it1+it2]++; 
        
        // Traversing Part 2
        for(auto &it3: nums3)
            for(auto &it4:nums4)
               if(mp.count(0-it3-it4)) count+=mp[0-it3-it4];
        
        return count;
    }
};