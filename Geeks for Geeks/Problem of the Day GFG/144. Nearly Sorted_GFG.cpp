// Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

// Example 1:
// Input:
// n = 7, k = 3
// arr[] = {6,5,3,2,8,10,9}
// Output: 2 3 5 6 8 9 10
// Explanation: The sorted array will be 2 3 5 6 8 9 10

// Example 2:
// Input:
// n = 5, k = 2
// arr[] = {3,1,4,2,5}
// Output: 1 2 3 4 5 



//Solution Approach :-
vector<int> nearlySorted(int arr[], int num, int K){
    priority_queue<int> pq;
    vector<int> ans;

    for(int i = 0; i < num; i++){
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}



//Second Solution :-
vector <int> nearlySorted(int arr[], int n, int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans(n);
    int i,j=0;
    
    for(i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()==k+1){
            ans[j++]=pq.top();
            pq.pop();
        }
    }

    while(!pq.empty()){
        ans[j++]=pq.top();
        pq.pop();
    }
    return ans;
}





//Third Solution :-
vector <int> nearlySorted(int a[], int n, int K){
   	map<int, int> mp;
   
    for(int i = 0; i < n; i++){
       mp[a[i]] = 1;
    }
   
   	int i = 0;
   	vector<int> ans(n);
   	for(auto x: mp){
	    ans[i++] = x.first;
   	}
   	return ans;
}
