// Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 
// Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

// Example 1:
// Input: 
// arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
// Output:
// 15 7 5 3 9 6 2 4 32
// Explanation:
// The integers in their binary
// representation are:
// 15 - 1111
// 7  - 0111
// 5  - 0101
// 3  - 0011
// 9  - 1001
// 6  - 0110
// 2  - 0010
// 4  - 0100
// 32 - 10000
// hence the non-increasing sorted order is:
// {15}, {7}, {5, 3, 9, 6}, {2, 4, 32}
 
// Example 2:
// Input: 
// arr[] = {1, 2, 3, 4, 5, 6};
// Output: 
// 3 5 6 1 2 4
// Explanation:
// 3  - 0011
// 5  - 0101
// 6  - 0110
// 1  - 0001
// 2  - 0010
// 4  - 0100
// hence the non-increasing sorted order is
// {3, 5, 6}, {1, 2, 4}



// Solution Approach :-
// for every number store the number of set bits 
int setBitCount(int n){
	int cnt=0;
	while(n){
		if(n%2==1){
			cnt++;
		}
		n=n/2;
	}
	return cnt;
}

class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        unordered_map<int, vector<int>> mp;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
        	int val=setBitCount(arr[i]);    //giving count of set bits
        	mp[val].push_back(arr[i]);      // insert number in num_of_set_bits
        	mx=max(mx,val);                 //keeping track of maximum set bits
        	mn=min(mn,val);                 //keeping track of minimum set bits
        }

        int idx=0;
        for(int i=mx;i>=mn;i--){
        	if(mp.count(i)){     //if it is having any elements
        		for(auto &e : mp[i]){   //print all the elemnts in that i
        			arr[idx]=e;
        			idx++;
        		}
        	}
        }
        return; 
    }
};


//Second Approach :-
class Solution{
    public:
    int CountSetBits(int n)
    {
        int cnt = 0;
        while(n)
        {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
       return a.second > b.second;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,int>>ans;
        for(int i = 0;i<n;i++)
        {
            int x = CountSetBits(arr[i]);
            ans.push_back({arr[i],x});
        }
        stable_sort(ans.begin(),ans.end(),cmp);
        for(int i = 0;i<n;i++)
        {
            arr[i] = ans[i].first;
        }
    }
};