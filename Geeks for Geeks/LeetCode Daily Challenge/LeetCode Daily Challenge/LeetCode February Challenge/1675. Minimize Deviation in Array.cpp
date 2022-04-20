// You are given an array nums of n positive integers.
// You can perform two types of operations on any element of the array any number of times:
// If the element is even, divide it by 2.
// For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
// If the element is odd, multiply it by 2.
// For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
// The deviation of the array is the maximum difference between any two elements in the array.
// Return the minimum deviation the array can have after performing some number of operations.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: 1
// Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.

// Example 2:
// Input: nums = [4,1,5,20,3]
// Output: 3
// Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.

// Example 3:
// Input: nums = [2,10,8]
// Output: 3



//Solution  :- Using Priority Queue
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
         priority_queue<int>pq;
         int n=nums.size();
         int mi=INT_MAX,mx=INT_MAX;
         for(int i=0;i<n;i++)
         {
             if(nums[i]%2==0)
             {
                 pq.push(nums[i]);
             }
             else
             {
                 nums[i]*=2;
                 pq.push(nums[i]);
             }
             mi=min(mi,nums[i]);
             mx=max(mx,nums[i]);
         }
         int res=mx-mi;
         while(pq.top()%2==0)
         {
               int curr=pq.top();
               pq.pop();
               res=min(res,curr-mi);
               curr/=2;
                pq.push(curr);
                mi=min(mi,curr);
         }
        res=min(res,pq.top()-mi);
         return res;
    }
};



//Solution  :- Using set
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set <int>  s;
        for(int i = 0; i<nums.size() ; ++i)
        {
            if(nums[i] % 2 == 0)
                s.insert(nums[i]);
                
            else
                s.insert(nums[i] * 2);
        }
        
        int diff = *s.rbegin() - *s.begin();
        
        while(*s.rbegin() % 2 == 0)
        {
            int x = *s.rbegin();
            s.erase(x);
            
            s.insert(x/2);
            
            diff = min(diff, *s.rbegin() - *s.begin());
        }
        
        return diff;
    }
};


//BruteForce Approach :- 
// Write a o(N^2) implementation to understand the problem
// Facts:
// If a num is odd we can multiply only one time as it will become even (ie 5 * 2 = 10) and then as it has become even if we divide we can
// back to the first number (10 / 2 = 5)
//
// If a number is even we can divide it until it will become ODD es 14 -> 7 and then stop as 7 can only be multiplied by 2 getting back 14
//
// deviation is nothing more than MAX_ELEMENT - MIN_ELEMENT aa it is the maximum difference between two any elemenets of the array.
//
// In order to minimize deviation we have to make MAX_ELEMENT the smallest possible and MIN_ELEMENT the biggest possible.
// Decreasing means DIVIDE (possible only for EVEN ELEMENT) and INCREASE means multiply (possible only for ODD ELEMENTS)
//

// Time Complexity O(N^2), Space Complexity O(1) 
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // the result
        int deviation = numeric_limits<int>::max();
        
        // let's first multiply all ODD numbers by 2 and put into the array 
        // (doing this we will reach a status of element that can't be increased anymore)
        // and keep track of minimum value and maximum value of the array
        
        int minval = numeric_limits<int>::max();
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & 1) // multiply by two ODD values
                nums[i] <<= 1;
            if(nums[i] < minval)
                minval = nums[i];
        }

        // try to minimize the deviation now...
        // As all numbers are even so we can divide by 2 the maximum value inside the array when calculating the deviation
        // and then we have to check if there is a NEW max in the array...and continue until we can't reduce any longer...when does it happens?
        // When the maximum is an ODD number as we can't devide any longer...and if we multiply we will increase it.
        // Now proceed in a naive way and do a quadratic check....without any other optimization.
        for(int i = 0; i < nums.size(); i++) {
            int maxval = numeric_limits<int>::min();
            int max_idx = -1;
            for(int j = 0; j < nums.size(); j++) {
                // find new max;
                if(nums[j] > maxval) {
                    maxval = nums[j];
                    max_idx = j;
                }
            }
            deviation = min(deviation, maxval - minval);
            // If maxvalue is even just divide by 2 and re push into vector
            if(!(nums[max_idx] & 1)) {
                // As we are DECREASING a number here we have to check agains our current minimum..and eventually update it
                nums[max_idx] >>= 1;
                if(nums[max_idx] < minval)
                    minval = nums[max_idx];
            }
        }
        return deviation;
    }
};