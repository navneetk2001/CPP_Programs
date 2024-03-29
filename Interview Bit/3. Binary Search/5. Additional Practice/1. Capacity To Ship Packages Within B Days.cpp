// A conveyor belt has packages that must be shipped from one port to another within B days.
// The ith package on the conveyor belt has a weight of A[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within B days.

// Input 1:
// A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// B = 5
// Output 1: 15
// Explanation 1:
// A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10
// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and 
// splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

// Input 2:
// A = [3, 2, 2, 4, 1, 4]
// B = 3
// Output 2: 6
// Explanation 2:
// A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
// 1st day: 3, 2
// 2nd day: 2, 4
// 3rd day: 1, 4

//Solution Approach
// Binary search on the answer. We need a function possible(capacity) which returns true if and only if we can do the task in D days.
// Given the number of bags, return the minimum capacity of each bag, so that we can put items one by one into all bags. We binary search the final result. The left bound is max(A), The right bound is sum(A).


// First Method :-
bool isPossible(vector<int>&A, int mid, int B){
    int d=1;  //No.of days required
    int sum=0;  
    for(int i=0;i<A.size();i++){
        sum+=A[i];

        if(sum>mid){
            d++;
            sum=A[i];
        }
    }
    return d<=B;
}


int Solution::solve(vector<int> &A, int B) {
    int mx=0;
    int sum=0;

    for(int val:A){
        sum+=val;
        mx=max(val,mx);
    }

    if(A.size()==B){
        return mx;
    }

    int lo=mx;
    int hi=sum;
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(isPossible(A,mid,B)==true){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}




//Second Method :-
bool sol_possible(vector<int> &A, int B, int ans){
    int n = A.size();
    int sum = 0;
    int days_req = 1;
    for(int i=0; i<n; i++){
        sum+=A[i];
        if (sum>ans){
            days_req++;
            sum=A[i];
        }
        if (days_req>B) return false;
    }
    return true;
    
}
int Solution::solve(vector<int> &A, int B) {
    
    int maxelem = INT_MIN;
    int sum = 0;
    int n = A.size();
    for(int i=0; i<n; i++){
        maxelem = max(maxelem, A[i]);
        sum += A[i];
    }
    int lo = maxelem, hi = sum;
    int res = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if (sol_possible(A, B, mid)){
            hi = mid-1;
            res = mid;
        }
        else lo = mid+1;
    }
    return res;
}

