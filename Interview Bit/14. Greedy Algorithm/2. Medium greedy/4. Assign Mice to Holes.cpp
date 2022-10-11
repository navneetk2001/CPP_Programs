// There are N Mice and N holes that are placed in a straight line. Each hole can accomodate only 1 mouse.
// The positions of Mice are denoted by array A and the position of holes are denoted by array B.
// A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x − 1. Any of these moves consumes 1 minute.
// Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.


//Solution Approach :- 
// sort mice positions (in any order)
// sort hole positions 
// Loop i = 1 to N:
//     update ans according to the value of |mice(i) - hole(i)|

// Proof of correctness:
// Let i1 < i2 be the positions of two mice and let j1 < j2 be the positions of two holes.
// It suffices to show via case analysis that
// max(|i1 - j1|, |i2 - j2|) <= max(|i1 - j2|, |i2 - j1|) , 
//     where '|a - b|' represent absolute value of (a - b)
// since it follows by induction that every assignment can be transformed by a series of swaps into the sorted assignment, where none of these swaps increases the makespan


//First Solution :-
int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int mx=0;
    for(int i=0;i<A.size();i++){
        mx=max(mx,abs(A[i]-B[i]));
    }
    return mx;
}

