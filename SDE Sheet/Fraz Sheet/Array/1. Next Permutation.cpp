https://leetcode.com/problems/next-permutation/




//Solution Approach :-
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1){
            return;
        }

        int idx1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx1=i;
                break;
            }
        }
        
        if(idx1<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            int idx2=0;
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]>nums[idx1]){
                    idx2=i;
                    break;
                }
            }
            swap(nums[idx1],nums[idx2]);
            sort(nums.begin()+idx1+1,nums.end());
        }
    }
};





//Second Solution :- 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
    	
    	int infpt = 0;
    	for(int i=n;i>0;i--){
    		if(nums[i] > nums[i-1]){
    			infpt = i;
    			break;
    		}
    	}

    	if(infpt == 0){
    		sort(nums.begin(), nums.end());
    	}
    	else{
    		int toSwap = nums[infpt - 1];
    		int min = INT_MAX;
    		for(int j=infpt;j<=n;j++){
    			if(nums[j] - toSwap > 0 && nums[j] - toSwap < min){
    				int temp = nums[j];
    				nums[j] = nums[infpt - 1];
    				nums[infpt-1] = temp;
    			}
    		}
    	}
    	sort(nums.begin()+infpt, nums.end());
    }
};




//Third Solution :-
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
        if(n==1)
            return;
        
        int i=1;
        int lastInc = -1;
        while(i<n) {    //Find the peak of last ASC order
            if(nums[i]>nums[i-1])
                lastInc = i;
            i+=1;
        }
        
        if(lastInc==-1) {   //Check if array is DSC
            for(i=0;i<n/2;++i)
                swap(nums[i],nums[n-i-1]);
            return;
        }
        //Find element in the range (nums[lastInc-1] to nums[lastInc]) to the right
        int mn = nums[lastInc];
        int index = lastInc;
        for(i=lastInc;i<n;++i) {
            if(nums[i]>nums[lastInc-1] and nums[i]<nums[index]) {
                index = i;
            }
        }
        swap(nums[lastInc-1],nums[index]);
        sort(nums.begin()+lastInc,nums.end());
    }
};





