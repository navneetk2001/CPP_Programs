// Given an array A[] and positive integer K, the task is to count total number of pairs in the array whose sum is divisible by K.

// Example 1:
// Input : 
// A[] = {2, 2, 1, 7, 5, 3}, K = 4
// Output : 5
// Explanation : There are five pairs possible whose sum is divisible by '4' i.e., (2, 2), (1, 7), (7, 5), (1, 3) and (5, 3)

// Example 2:
// Input : 
// A[] = {5, 9, 36, 74, 52, 31, 42}, K = 3
// Output : 7 
// Explanation : There are seven pairs whose sum is divisible by 3, i.e, (9, 36), (9,42), (74, 52), (36, 42), (74, 31), (31, 5) and (5, 52).




//Solution :-
long long countKdivPairs(int A[], int n, int K){
	unordered_map<int,int>m;
	long ans = 0;
	for(int i=0;i<n;i++)
	{ 
	    int rem1 = A[i]%K;
	    if(rem1!=0){
	    	ans+=m[K-A[i]%K];
	    }
	    else{
	    	ans+=m[0];
	    }
	    m[rem1]++;
	}
	return ans;    
}



//First Solution :-
class Solution{
public:
    long long countKdivPairs(int A[], int n, int K){
        long long ans = 0;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            int j = A[i] % K;
            if (j == 0 && mp.find(0) != mp.end()) {
                ans += mp[0];
            }
            else if (mp.find(K - j) != mp.end()) {
                ans += mp[K - j];
            }
            mp[j]++;
        }
        return ans;
    }
};


//Second Solution :-
//Simple Concept is the remainder property : (a+b)%m = a%m + b%m ;
#define ll long long
class Solution{
public:
    long long countKdivPairs(int A[], int n, int K){
        unordered_map<int,int>umap;
        
        for(int i=0;i<n;i++){
            umap[A[i]%K]++;
        }

        ll temp = 0,cnt=0;
        for(int i=0;i<n;i++){
            umap[A[i]%K]--;
            
            temp = (K - (A[i]%K))%K;
            
            if(umap.find(temp) != umap.end()){
            	cnt += umap[temp];
            }
        }
        return cnt;
    }
};



//Third Solution :-
#define ll long long
class Solution{
public:
    long long countKdivPairs(int a[], int n, int k){
        vector<ll> cnt(k,0);
        for(int i=0;i<n;i++) {
            cnt[a[i]%k]++;
        }

        ll ans=(cnt[0]*(cnt[0]-1))/2;
        for(int i=1;i<=k/2 and 2*i!=k;i++) {
            ans+=(cnt[i]*cnt[k-i]);
        }
        if(k%2==0){
            ans+=(cnt[k/2]*(cnt[k/2]-1))/2;
        }
        return ans;
    }
};
