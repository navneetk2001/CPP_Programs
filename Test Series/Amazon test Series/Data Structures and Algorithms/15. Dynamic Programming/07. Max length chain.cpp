https://practice.geeksforgeeks.org/problems/max-length-chain/1



//Solution Approach :- we can do it in O(nlogn) time and with O(1) space, try below solution, first sort based on first values 
static bool comparison(val a, val b){
   	return a.first < b.first;
}

int maxChainLen(struct val p[],int n){
	sort(p, p+n, comparison);
  	val cur = p[0];
   	int count = 1;
   	
   	for(int i=1; i<n; i++){
       	if(cur.second < p[i].first){
           	count++;
           	cur = p[i];
       	}
       	else{
           	if(cur.second > p[i].second){
               	cur = p[i];
           	}
       	}
   	}
   	return count;
}




//Second Solution :- 
//Sort the vals based on their second value. Now iterate through the array taking each of the indices as the starting val. If we know the starting val and rest of the array is sorted according to the above condition, we can easily find the optimal number of elements in the chain as we need to compare the second of the current element to the first of the potential next element. Keep on incrementing the length counter everytime a valid next element is found. Update the current element. Stop when we reach the end of the array. Finally, take the maximum of all lengths found. 
bool comparison(val a, val b){
    return a.second<b.second;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n){
    sort(p, p+n, comparison);
    int ans = 0;
    for(int i=0; i<n; i++){
        int curr = p[i].second;
        int l = 1;
        int j = i+1;
        while(j<n){
            while(j<n && p[j].first<=curr){
                j++;
            }
            if(j==n){
                break;
            }
            l++;
            curr = p[j].second;
            j++;
        }
        ans = max(ans, l);
    }
    return ans;
}



//Third Solution :- Using longest increasing subsequence
int maxChainLen(struct val p[],int n){
	vector<int> dp(n,1);

	vector<pair<int,int>> pt;
	int ans=1;
	for(int i=0;i<n;i++){
	  	pt.push_back(make_pair(p[i].first, p[i].second));
	}
	
	sort(pt.begin(),pt.end());
	for(int i=1;i<n;i++){
	   	for(int j=i-1;j>=0;j--){
	       	if(pt[i].first > pt[j].second){
	       		dp[i]=max(dp[i], dp[j]+1);
	       	}
	   	}
	   	ans = max(ans,dp[i]);
	}
	return ans;
}



//Fourth Solution :-
static bool  com(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}

int maxChainLen(struct val p[],int n)
{
 
	vector<vector<int>> v;
	for(int i=0;i<n;i++){
	 	v.push_back({p[i].first,p[i].second});
	}

	sort(v.begin(),v.end(),com);

	vector<int> lis(n,1);
	for(int i =1;i<n;i++){
	 	for(int j=0;j<i;j++){
	      	if(v[j][1] < v[i][0] && lis[i] < lis[j]+1){
	          	lis[i]= lis[j] + 1;
	     	}
	 	}
	}
	 
	int maxi = INT_MIN;
	for(int i =0;i<n;i++){
	 	maxi = max(lis[i],maxi);
	}
	return maxi;
}



//Fifth Solution :- Recursion + Memoization
int solve(int indx, int prev, vector<pair<int,int>> &v, int n, vector<vector<int>> &dp){
   	if(indx == n){
       return 0;
   	}
   	if(dp[indx][prev+1]!=-1){
       return dp[indx][prev+1];
   	}

   	int inc = 0;
   	if(prev ==-1 or v[indx].first > v[prev].second){
        inc=1+solve(indx+1,indx,v,n,dp);
   	}
   	int exc=solve(indx+1,prev,v,n,dp);
  	return dp[indx][prev+1]=max(inc,exc);
   
}
int maxChainLen(struct val p[],int n)
{
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
	   	v.push_back({p[i].first,p[i].second});
	}
	sort(v.begin(),v.end());
	vector<vector<int>> dp(n,vector<int>(n,-1));
	return solve(0,-1,v,n,dp);
}
