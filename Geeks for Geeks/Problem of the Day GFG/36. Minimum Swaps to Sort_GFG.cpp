// Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

// Example 1:
// Input:
// nums = {2, 8, 5, 4}
// Output: 1
// Explaination: swap 8 with 4.

// Example 2:
// Input:
// nums = {10, 19, 6, 3, 5}
// Output: 2
// Explaination: swap 10 with 3 and swap 19 with 5.


//Solution :-
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=a.size();
	    vector<pair<int,int>>v;
	    for(int i=0;i<n;i++){
	    	v.push_back({a[i],i});
	    }
	    sort(v.begin(), v.end());
	    int swap_count=0;
	    for(int i=0;i<n;i++){
	    	if(v[i].second!=i){
	    		swap_count++;
	    		swap(v[i],v[v[i].second]);
	    		i--;
	    	}
	    }
	    return swap_count;
	}
};


//Another Solution :-

singhashwani2002
21 hours ago

int minSwaps(vector<int>&nums)
{
    int n=nums.size();
    int ans=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m.insert({nums[i],i});
    }
    vector<int> temp=nums;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++)
    {
       if(nums[i]!=temp[i])
       {
           ans++;
           int var=nums[i];
           nums[i]=temp[i];
           nums[m[temp[i]]]=var;
           m[var]=m[temp[i]];
       }
    }
    return ans;
}


//Third Solution :- 
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]=i;
        int i=0,c=0;;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(nums[i]!=it->first)
            {
                swap(nums[i],nums[it->second]);
                mp[nums[it->second]]=it->second;
                c++;
            }
            i++;
        }
        return c;
	}
};