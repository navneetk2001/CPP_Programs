// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
// For example, given array S = {-1 0 1 2 -1 -4},
// A solution set is:
//   (-1, 0, 1)
//   (-1, -1, 2)

//Hint 
// When the array is sorted, try to fix the least integer by looping over it.
// Let us say the least integer in the solution is arr[i].
// Now we need to find a pair of integers j and k such that :
// arr[j] + arr[k] is -arr[i].
// To do that, let us try the 2 pointer approach.
// If we fix the two pointers at the end ( that is, i+1 and end of array ),
// we look at the sum.
// If the sum is smaller than 0, we increase the first pointer to increase the sum.
// If the sum is bigger than 0, we decrease the end pointer to reduce the sum.


//Solution Approach :-
// Getting a Time Limit exceeded or Output Limit exceeded?
// Make sure you handle case of empty input [].
// In C++/C, usually if you run a loop till array.size() - 2,
// it can lead to the program running indefinitely as array.size() is unsigned int, and the subtraction just makes it wrap over to a big integer.
// Make sure you are not processing the same triplets again.
// Skip over the duplicates in the array.
// Try a input like :-1 -1 -1 -1 0 0 0 0 1 1 1 1
// Ideally, you should get only 2 pairs : {[-1 0 1], [0 0 0]}


//First Solution
vector<vector<int>> Solution::threeSum(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    set<vector<int>> s;

    long long int n=A.size();

    for(int i=0;i<n-2;i++){
        long long int l=i+1;
        long long int r=n-1;
        while(l<r){
            long long int sum=long(A[i]) + long(A[l]) + long(A[r]);
            if(sum==0){
                s.insert({A[i], A[l], A[r]});
                l++;
                r--;
            }
            else if(sum<0){
                l++;
            }
            else{
                r--;
            }
        }
    }
    for(auto x:s){
        ans.push_back(x);
    }
    return ans;
}


//Second Solution
vector<vector<int>> Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    vector<vector<int>> ans;
    
    for(int i = 0; i < n - 2; ++i){
        if(i > 0 && A[i] == A[i - 1]){
            continue;
        }
        int l = i + 1, r = n - 1;
        while(l < r){
            // long long sum = A[i] + (long long)A[l] + (long long)A[r];
            long long sum = 0LL + A[i] + A[l] + A[r];
            if(sum == 0){
                ans.push_back({A[i], A[l], A[r]});
                while(l < n - 1 && A[l] == A[l + 1]){
                    ++l;
                }
                while(r > 0 && A[r] == A[r - 1]){
                    --r;
                }
                ++l, --r;
            }
            else if(sum > 0)
                --r;
            else
                ++l;
        }
    }
    return ans;
}


//Third Solution
vector<vector<int> > Solution::threeSum(vector<int> &AA) {
    vector<long long int> A; 
    for(auto it:AA) A.push_back(it);
    
    sort(A.begin(), A.end());
    vector<vector<int> > fans;
    long long int n = A.size();
    for(int i=2;i<n;i++){
        if(i!=n-1 && A[i] == A[i+1]) continue;
        long long int l = 0, r = i - 1;
        long long int target = -1 * A[i];
        while(l < r){
            if(A[l] + A[r] < target) l++;
            else if(A[l] + A[r] > target) r--;
            else{
                vector<int> ans = {A[l], A[r], A[i]};
                fans.push_back(ans);
                while(l<r && A[l] == A[l+1]) l++; l++;
                while(l<r && A[r] == A[r-1]) r--; r--;
            }
        }
    }
    return fans;
}



