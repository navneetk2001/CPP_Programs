// You are given a 0-indexed array nums that consists of n distinct positive integers. Apply m operations to this array, where in the ith operation you replace the number operations[i][0] with operations[i][1].

// It is guaranteed that in the ith operation:
// operations[i][0] exists in nums.
// operations[i][1] does not exist in nums.
// Return the array obtained after applying all the operations.

// Example 1:
// Input: nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
// Output: [3,2,7,1]
// Explanation: We perform the following operations on nums:
// - Replace the number 1 with 3. nums becomes [3,2,4,6].
// - Replace the number 4 with 7. nums becomes [3,2,7,6].
// - Replace the number 6 with 1. nums becomes [3,2,7,1].
// We return the final array [3,2,7,1].

// Example 2:
// Input: nums = [1,2], operations = [[1,3],[2,1],[3,2]]
// Output: [2,1]
// Explanation: We perform the following operations to nums:
// - Replace the number 1 with 3. nums becomes [3,2].
// - Replace the number 2 with 1. nums becomes [3,1].
// - Replace the number 3 with 2. nums becomes [2,1].
// We return the array [2,1].




//First SOlution :-
// Intuition
// We need record the index w.r.t to every original value , for updating the new values values later in operations at its index stored.
// Why?? We can only change the array if we have access to its index. For getting the access so that we can change its place with new value, we need to store index.
// How?? We will use a data structure which stores key-value pair i.e MAP.

// Algorithm:
// We will simply create a array where we will store the index corresponding to its index.
// While doing operations , we will just have to access the index of original we stored and replace the new value to its index and update that index correspoding to that new value.

vector<int> arrayChange(vector<int>& A, vector<vector<int>>& op) {
    unordered_map<int,int> store;
    for(int i=0;i<A.size();i++){
    	store[A[i]]=i;
    }

    for(auto i:op){
        A[store[i[0]]]= i[1];           //replace value to its index
        store[i[1]]= store[i[0]];       //update new value with its index
    }
    return A;
} 


//Second Solution :-
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }

        for(int i=0;i<operations.size();i++){
            int ind=m[operations[i][0]];
            m.erase(operations[i][0]);
            
            nums[ind]=operations[i][1];
            m[operations[i][1]]=ind;
        }
        return nums;
    }
};

