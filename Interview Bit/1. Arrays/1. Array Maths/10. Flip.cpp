// You are given a binary string A(i.e. with characters 0 and 1) consisting of characters A1, A2, ..., AN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters AL, AL+1, ..., AR. By flipping, we mean change character 0 to 1 and vice-versa.
// Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.
// If you don't want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.
// NOTE: Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.

//Input 1: A = "010"
// Output 1: [1, 1]
// Explanation 1:
// A = "010"
// Pair of [L, R] | Final string
// ____________|__________
// [1 1]          | "110"
// [1 2]          | "100"
// [1 3]          | "101"
// [2 2]          | "000"
// [2 3]          | "001"
// We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

// Input 2: A = "111"
// Output 2: []
// Explanation 2: No operation can give us more than three 1s in final string. So, we return empty array [].


//Hint 1 :- 
// Note what is the net change in number of 1s in string S when we flip bits of string S.
// Say it has A 0s and B 1s. Eventually, there are B 0s and A 1s.

//Solution Approach :- 
// Note what is the net change in number of 1s in string S when we flip bits of string S.
// Say it has A 0s and B 1s. Eventually, there are B 0s and A 1s.
// So, number of 1s increase by A - B. We want to choose a subarray which maximises this. Note, if we change 1s to -1 and change 0 to 1, then sum of values will give us A - B. Then, we have to find a subarray with maximum sum, which can be done via Kadane’s Algorithm.





// First Method :-
vector<int> Solution::flip(string A) {
    //we need a subarray where the cnt of zeroes - cnt of ones is maximum
    //we use kadane's algo variation for this  
    int n = A.size() , curr = 0 , maxSofar = 0 ;    
    int l = -1 , r = -1 , si = 0 ;
    for (int i=0 ; i<n ; i++) {
        if (A[i] == '0') curr++ ;
        else curr-- ;

        if (curr > maxSofar) {
            maxSofar = curr ;
            l = si , r = i ;
        }
        
        if (curr < 0) {
            si = i+1 ;
            curr = 0 ;
        }
    }
    
    if (l == -1) return {} ;  
    else return {l+1 , r+1} ;
}


//Second Method :-
vector<int> Solution::flip(string A) {
    int n=A.length();

    //build new array of 1s and -1s
    vector<int> ar(n);
    for(int i=0; i<n; i++)
        if(A[i]=='1')ar[i]=-1;
        else ar[i]=1;

    //pair storing the answer
    pair<int, int> ans=make_pair(INT_MAX, INT_MAX);

    //basic kadane's algorithm implementation
    //we also storing the begin point for best till now
    int best_till_now=0,best_ending_here=0,l=0;
    for(int i=0; i<n; i++){
        if(best_ending_here+ar[i]<0){
            l=i+1;
            best_ending_here=0;
        }
        else best_ending_here+=ar[i];
        if(best_ending_here>best_till_now){
            best_till_now=best_ending_here;
            ans.first=l;
            ans.second=i;
        }
    }

    //if no valid subarray found
    if(ans.first==INT_MAX)return vector<int>();

    //return answer
    vector<int> ret;
    ret.push_back(ans.first+1);
    ret.push_back(ans.second+1);
    return ret;
}

