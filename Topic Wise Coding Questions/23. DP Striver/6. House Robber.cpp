https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


//Pre-Requisite :- Maximum Sum of non-adjacent elements

//Solution Approach :- Space Optimized Solution 
long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1){
            pick += prev2;
        }
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    vector<int> arr1;
    vector<int> arr2;
    if(n==1){
        return valueInHouse[0];
    }
	for(int i=0; i<n; i++){
	    if(i!=0) arr1.push_back(valueInHouse[i]);
	    if(i!=n-1) arr2.push_back(valueInHouse[i]);
	}
    
    long long int ans1 = solve(arr1);  //first excluding first element and then computing as it is
    long long int ans2 = solve(arr2);  //now excluding last element and then computing as it is
    
    return max(ans1,ans2);          //now take maximum between both 
}
