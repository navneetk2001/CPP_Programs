// You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:
// Sort the values at odd indices of nums in non-increasing order.
// For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
// Sort the values at even indices of nums in non-decreasing order.
// For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
// Return the array formed after rearranging the values of nums.

// Example 1:
// Input: nums = [4,1,2,3]
// Output: [2,3,4,1]
// Explanation: 
// First, we sort the values present at odd indices (1 and 3) in non-increasing order.
// So, nums changes from [4,1,2,3] to [4,3,2,1].
// Next, we sort the values present at even indices (0 and 2) in non-decreasing order.
// So, nums changes from [4,1,2,3] to [2,3,4,1].
// Thus, the array formed after rearranging the values is [2,3,4,1].

// Example 2:
// Input: nums = [2,1]
// Output: [2,1]
// Explanation: 
// Since there is exactly one odd index and one even index, no rearrangement of values takes place.
// The resultant array formed is [2,1], which is the same as the initial array. 


//First Approach :-
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for(int i=0;i<nums.size();i++){
        	if(i%2){
        		odd.push_back(nums[i]);
        	}
        	else{
        		even.push_back(nums[i]);
        	}
        }

        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());

        sort(even.begin(), even.end());
        int o=0, e=0;
        for(int i=0;i<nums.size();i++){
        	if(i%2){
        		nums[i]=odd[o++];
        	}
        	else{
        		nums[i]=even[e++];
        	}
        }
        return nums;
    }
};


//Second Approach :-  using priority queue
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();        
        vector<int>res;        
        priority_queue<int>odd; 
        priority_queue<int,vector<int>,greater<int>> even;

        for(int i=0;i<n;i++){            
            if(i%2){
                odd.push(nums[i]);
            }
            else{
                even.push(nums[i]);
            }            
        }              
        for(int i=0;i<n;i++){            
            if(i%2){
                int x = odd.top();
                odd.pop();
                res.push_back(x);
            }
            else{
                int y = even.top();
                even.pop();
                res.push_back(y);
            }            
        }        
        return res;
    }
};


//Third Approach :-
package array;

public class ArrayApp {

  public static void seperateEvenOddNumbers(int[] arr) {
    if(arr.length <= 1) {
      return;
    }
    
    int left, right;
    left = 0;
    right = arr.length - 1;
    
    while(left < right) {
      while(arr[left] % 2 == 0 && left < right) {
        left++;
      }
      
      while(arr[right] % 2 != 0 && left < right) {
        right--;
      }
      
      if(left < right) {
        int x = arr[left];
        arr[left] = arr[right];
        arr[right] = x;
        
        left++;
        right--;
      }
    }
  }
  
  public static void main(String[] args) {
    int[] arr = {1, 2, 4, 3, 5, 7, 8, 6};

    ArrayApp.seperateEvenOddNumbers(arr);
    
    for(int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
  }

}
