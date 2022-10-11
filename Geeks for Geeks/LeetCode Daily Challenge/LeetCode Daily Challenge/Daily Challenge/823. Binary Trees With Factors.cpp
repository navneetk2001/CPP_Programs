https://leetcode.com/problems/binary-trees-with-factors/






//Solution :- 
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr){
        map<int,long long int> m;     //initializing a map with each element count as 1 b/c each element can form a binary tree with itself
        sort(arr.begin(),arr.end());
        
        for(int x=0;x<arr.size();x++){       //inserting in the map each element with count 1 b/c each element can form a binary tree with itself
            m.insert({arr[x],1});
        }
        
        for(int i=1;i<arr.size();i++)
        {   
            auto it3 = m.find(arr[i]);     //current element 
            long long int count =0;        //finding in how many ways we can form a tree with root as current element
            
            for(int j=0; j<i; j++){       //traverse from start till current element b/c these numbers can be its possible factors as array is sorted
                if(arr[i] % arr[j]==0)    //if arr[j] divides arr[i], then it can be a possible solution
                { 
                    auto it = m.find(arr[j]);                 //This is the first factor of possible binary tree           
                    auto it2 = m.find(arr[i]/arr[j]);        //Now we will find the second factor

                    if(it2!=m.end())        //if second factor is present then only we can increase the count
                    {
                        count+=(it->second)*(it2->second);     //count updated as how many ways we can form B.T
                    }
                }
            }
            it3->second += count;      //increment the count of current element in the map
        }

        long long int sum =0;
        for(auto it4 = m.begin(); it4 != m.end(); it4++){
            sum += it4->second;
        }
       
        return sum%(1000000007);
    }
};  
        



//Solution Approach :- Recursion
long rec(vector<int>& arr, int i, unordered_map<int, int>& mp) {
	long ans = 1;
	for (int j = 0; j < i; j++) {
		if (arr[i] % arr[j] == 0 && mp.find(arr[i] / arr[j]) != mp.end()) {
			long left = rec(arr, j, mp);
			long right = rec(arr, mp[arr[i] / arr[j]], mp);
			ans = (ans + (left * right)) % MOD;
		}
	}
	return ans;
}



//Memoization :- 
long memo(vector<int>& arr, int i, unordered_map<int, int>& mp, vector<int>& dp) {
	if(dp[i] != -1){   // Add on
		return dp[i]; 
	}

	long ans = 1; 
	for (int j = 0; j < i; j++) {
		if (arr[i] % arr[j] == 0 && mp.find(arr[i] / arr[j]) != mp.end()) {
			long left = memo(arr, j, mp, dp);
			long right = memo(arr, mp[arr[i] / arr[j]], mp, dp);
			
			ans = (ans + (left * right)) % MOD;
		}
	}
	return dp[i] = ans; // Add on
}



//Second Solution :-
class Solution{
public:
    int mod = 1000000007;
    long long helper(vector<int> & arr,unordered_map<int,long long> &m,unordered_set<int> &st, int i){
        if(m.find(i) != m.end()){
            return m[i];
        }
        long long cnt =1;
        
        for(auto it:  arr){
            if(it>i){
                break;
            }
            if(i%it==0 && st.find(i/it)!=st.end()){
                cnt = cnt%mod + (helper(arr,m,st,i/it)%mod) * (helper(arr,m,st,it)%mod);
            }
        }
        return m[i] = cnt % mod;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long> m;
        unordered_set<int> st;
        sort(arr.begin(),arr.end());
        
        for(auto it: arr){
            st.insert(it);
        }
        int ans=0;
        for(auto it : arr){
            ans = ans%mod + helper(arr,m,st,it)%mod;
        }
        return ans%mod;
    }
};





//Third Solution :-
// sort the array and use HashMap to record each Integer, and the number of trees with that Integer as root
// (1) each integer A[i] will always have one tree with only itself
// (2) if A[i] has divisor (a) in the map, and if A[i]/a also in the map then a can be the root of its left subtree, and A[i]/a can be the root of its right subtree;
// the number of such tree is map.get(a) * map.get(A[i]/a)
// (3) sum over the map

class Solution {
public:
    int mod = pow(10,9) + 7;
    int numFactoredBinaryTrees(vector<int>& arr){
        sort(arr.begin(), arr.end());

        unordered_map <int, long> rootWithCount;
        rootWithCount[arr[0]] = 1;

        for(int i = 1; i < arr.size(); i++){
            long count = 1;
            for(auto j : rootWithCount){
                int rootEle = j.first;
                if(arr[i] % rootEle == 0 && rootWithCount.find(arr[i] / rootEle) != rootWithCount.end()){
                    count += rootWithCount[rootEle] * rootWithCount[arr[i] / rootEle];
                }
            }
            rootWithCount[arr[i]] = count;
        }

        int noOfTrees = 0;
        for(auto i : rootWithCount){
            noOfTrees = (noOfTrees + i.second) % mod;
        }
        return noOfTrees;
    }
};

// TC: O(N^2)
// SC: O(N)
