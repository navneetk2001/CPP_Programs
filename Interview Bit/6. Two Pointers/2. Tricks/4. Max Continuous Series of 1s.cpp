// You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
// Find the position of zeros which when flipped will produce maximum continuous series of 1s.
// For this problem, return the indices of maximum continuous series of 1s in order.

// Example:
// Input : 
// Array = {1 1 0 1 1 0 0 1 1 1 } 
// M = 1

// Output :  [0, 1, 2, 3, 4] 
// If there are multiple possible solutions, return the sequence which has the minimum start index.

//Hint 
// Hint : Think in terms of 2 pointers.
// Would it help if you maintained the number of 0s in the current range ? When would you range become invalid ?

//Solution Approach :-
// N : 4
// lis : 1 0 1 0 
// M : 2
// pointer i and j 
// i = j = 0
// iterate till i < N:
//         if(Number_of_Zeros_in_Current_range > M) :
//                 increment j and reduce range till Number_of_Zeros_in_current_range < M
//         else :
//                 add element in range and update all variables

//First Solution
vector<int> Solution::maxone(vector<int> &A, int B) {
    int flips=0;   //no of flips done till yet
    int i=0;   //for moving forward
    int j=0;   // unflipping when required
    int ansl=0, ansr=0;    //for storing the index 
    int n=A.size();

    while(i<n){
        if(A[i]==0){
            flips++;
        }
        while(flips > B){
            if(A[j]==0){    //unflip previous 0 because you can't move forward
                flips--; 
            }
            j++;
        }

        if((ansr-ansl) < (i-j)){
        	ansr=i;
        	ansl=j;
        }
        
        i++;
    }
    vector<int> ans;
    for(i=ansl;i<=ansr;i++){
    	ans.push_back(i);
    }
    return ans;
}


//Second Solution
vector<int> Solution::maxone(vector<int> &a, int m) {
      
    int n = a.size();
    int currLeft = 0, currRight = 0; //Indexes for the Current Window
    int bestLeft = 0, bestRight = 0; // Indexes for the Best Window
    int count0 = 0;
    vector<int> result;
    
    while(currRight < n){
        
        if(count0 <= m){
            if(a[currRight] == 0) count0++; // Including new zeroes in the window.
            currRight++;
        }
        
        if(count0 > m){
            // Travelling till we find the leftmost zero to discard it from the window
            if(a[currLeft] == 0) count0--;
            currLeft++; 
        }
        
        if(currRight - currLeft > bestRight - bestLeft){
            bestLeft = currLeft;
            bestRight = currRight;
        }
    }
    
    for(int i = bestLeft; i<bestRight; i++){
        result.push_back(i);    
    }
    return result;
    
}


//Third Solution
vector<int> Solution::maxone(vector<int> &A, int B) {


    //int t[A.size()];
    //memset(t, 0, sizeof(t));
    int max_seq = 0;
    int start = 0;
    int i = 0;
    int j = 0;
    int n_zeros = 0;
    while (i+max_seq < A.size()) {
        if (j < i) j = i;
        while (j < A.size() && (n_zeros < B || A[j] == 1)) {
            if (B==0 && A[j] == 0) {
                break;
            }
            if (A[j] == 0) {
                n_zeros++;
            }
            j++;
        }
        //cout << "i: " << i << " j: " << j << " zeros: " << n_zeros << endl;
        
        if (j-i > max_seq) {
            max_seq = j-i;
            //cout << "i: " << i << " seq: " << max_seq << endl;
            start = i;
        }
        if (A[i] == 0 && n_zeros > 0) {
            n_zeros--;
        } 
        i++;
    }
    
    vector<int> ans;
    ans.resize(max_seq);
    for (int i = 0; i < max_seq; i++) {
        ans[i] = start+i;
    }
    return ans;
    
    
}



