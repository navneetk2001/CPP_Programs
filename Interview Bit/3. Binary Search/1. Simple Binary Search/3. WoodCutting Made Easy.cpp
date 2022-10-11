// There is given an integer array A of size N denoting the heights of N trees.
// Lumberjack Ojas needs to chop down B metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Ojas is only allowed to cut a single row of trees.
// Ojas's machine works as follows: Ojas sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Ojas then takes the parts that were cut off. 
//For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Ojas raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Ojas will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).
// Ojas is ecologically minded, so he doesn't want to cut off more wood than necessary. That's why he wants to set his sawblade as high as possible. Help Ojas find the maximum integer height of the sawblade that still allows him to cut off at least B metres of wood.
// NOTE:
// The sum of all heights will exceed B, thus Ojas will always be able to obtain the required amount of wood.

// Input 1:
//  A = [20, 15, 10, 17]
//  B = 7
// Output 1: 15
// Explanation 1:
//  If you the height parameter to 15 then you can chop:
//   5 metres from first tree
//   0 metres from second tree
//   0 metres from third tree
//   2 metres from fourth tree
//   So in total you chopped 7 metres of wood.
// Input 2:
//  A = [4, 42, 40, 26, 46]
//  B = 20
// Output 2: 36
// Explanation 2:
//  If you the height parameter to 36 then you can chop:
//   0 metres from first tree
//   6 metres from second tree
//   4 metres from third tree
//   0 metres from fourth tree
//   10 metres from fifth tree
//   So in total you chopped 20 metres of wood.

//Hint 1
// If you set a height parameter to something let’s say x and you are able to remove atleast B metres amount of wood then for every parameter less than x you can remove atleast B metres of wood.
// Try to use the above fact and find a solution to the problem.

//Solution Approach
// The Problem is based on Binary Search
// So let’s start with thinking of monotonicity.
// If you set a height parameter to something let’s say x and you are able to remove atleast B metres amount of wood then for every parameter less than x you can remove atleast B metres of wood.
// This means you need to find the last x such that for every height parameter greater than x you cannot remove atleast B metres of wood.
// So we just to binary search for this x.
// Time Complexity: O(NlogN)
// Space Complexity: O(1)


//First Method :-
int Solution::solve(vector<int> &A, int B) {
    int l = 1,h = 1e6;
    while(l<=h){
        int mid = (l+h)/2;
        int cur = 0;
        for(int i = 0;i<A.size();i++) {  
            cur+=max(0,A[i]-mid);
        }
        if(cur>=B){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return h;
}



//Second Method :-
bool ispossible(vector<int>&A,int ht,int B){  
    long long int sum=0;
    for(long long int i:A){
        if(i>=ht){
            sum+=i-ht;
            if(sum>=B){
                return true;
            }
        }
    }
    if(sum>=B){
        return true;
    }
    return false;
}

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    long long int e=0;
    long long int s=0;
    int ans=0;
    
    for(long long int i:A){
        s=min(s,i);
        e+=i;
    }

    while(s<=e){
        long long int mid=s+(e-s)/2;
        if(ispossible(A,mid,B)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}


//Third Method :-
int Solution::solve(vector<int> &A, int B) {
    int hi = 0,ans, n = A.size();
    for(int i = 0; i < n; i++){
       hi = max(hi,A[i]);
    }
    int lo = 0;
    while(lo <= hi)
    {
        long long int mid = (lo+hi)/2,sum = 0;
        for(int i = 0; i < n; i++){
            if(A[i] > mid){
                sum += A[i] - mid;
            }
        }
        
        if(sum > B){
            ans = mid;
            lo = mid+1;
        }
        else if(sum < B){
            hi = mid-1;
        }
        else{
            return mid;
        }
    }
    return ans;
}


//Fourth Method :-
long long int fun(vector<int>&A, long long int mid){
    long long int wood=0;
    for(int i=0;i<A.size();i++){
        if(A[i]>=mid){
            wood+=A[i]-mid;
        }
    }
    return wood;
}

int Solution::solve(vector<int> &A, int B) {
    long long int start=0, end=INT_MIN, mid;
    for(int i=0;i<A.size();i++){
        end=max(end, 1ll*A[i]);
    }

    while(start<end){
        mid=(start+end)/2;
        long long int x=fun(A,mid);
        if(x==B || start==mid){
            return mid;
        }
        else if(x>B){
            start=mid;
        }
        else{
            end=mid;
        }
    }
    return mid;
}
