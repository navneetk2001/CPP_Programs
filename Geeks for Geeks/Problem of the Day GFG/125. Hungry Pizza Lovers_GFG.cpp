// Dominos Pizza has hungry customers waiting in the queue. Each unique order is placed by a customer at time x[i], and the order takes y[i] units of time to complete.
// You have information on all n orders, Find the order in which all customers will receive their pizza and return it. If two or more orders are completed at the same time then sort them by non-decreasing order number.

// Example 1:
// Input : arr[ ] = {{4,1}, {6,2}, {7,6}, {8,1}, {1,3}}
// Output : 5 1 2 4 3
// Explanation:
// Here an array can be transform to {5, 8, 13, 9, 4}. Here 5th index order 
// received first then 1st order, 2nd order... return {5, 1, 2, 4, 3}

// Example 2:
// Input : arr[ ] = {{1,1}, {1,1}, {1,1}} 
// Output :  1 2 3 



//Approach :-
// First we make an array of pairs in which we will store the sum of order time and making time in first and index of order +1 in second.
// After that we will sort the array if first value is not equal than we will sort in ascending order of first value , if it is equal than we will sort in descending order of second value which is the index of the order.
// Hence we will store the second value in a separate array and return it as the result.


//Solution Approach :-
vector<int> permute(vector<vector<int>> &arr, int n){
    vector<pair<int,int>>time;   //total time, index
        
    for(int i=0; i<n; i++) {
        int total_time=arr[i][0]+arr[i][1];
        time.push_back({total_time ,i});
    }
   
  	sort(time.begin(), time.end());
   
   	vector<int> ans;
   	for(auto it : time) {
	    ans.push_back(it.second+1);
    }
   
    return ans;
}


//Second Solution :-
vector<int> permute(vector<vector<int>> &arr, int n)
{
    vector<pair<int,int>>v;
    int i=1;
    for(auto it:arr){
        int x=it[0]+it[1];             //cout<<x<<endl;5 8 13 9 4
        v.push_back(make_pair(x,i));   //(5,1) (8,2) (13,3) (9,4) (4,5)
        i++;
    }
   
    sort(v.begin(),v.end());            //(4,5) (5,1) (8,2) (9,4)  (13,3) 
    vector<int>ans;
    for(auto it:v){
        ans.push_back(it.second);       //5 1 2 4 3
    }
    return ans;
}


//Third Solution :-
vector<int> permute(vector<vector<int>> &arr, int n){
    vector<int> order(n);
    iota(order.begin(),order.end(),1);
    sort(order.begin(),order.end(),[&](int id1,int id2){
        int t1 = arr[id1 - 1][0] + arr[id1 - 1][1] ;
        int t2 = arr[id2 - 1][0] + arr[id2 - 1][1] ;
        if(t1 == t2){
            return id1 < id2 ;
        }
        return t1 < t2 ;
    });
    return order;
}


