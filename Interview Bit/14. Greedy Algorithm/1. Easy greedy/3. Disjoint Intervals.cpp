// Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the length of maximal set of mutually disjoint intervals.
// Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.
// Return a integer denoting the length of maximal set of mutually disjoint intervals.

// Input 1:
//  A = [
//        [1, 4]
//        [2, 3]
//        [4, 6]
//        [8, 9]
//      ]

// Output 1: 3
// Explanation 1:
//  Intervals: [ [1, 4], [2, 3], [4, 6], [8, 9] ]
//  Intervals [2, 3] and [1, 4] overlap.
//  We must include [2, 3] because if [1, 4] is included thenwe cannot include [4, 6].
//  We can include at max three disjoint intervals: [[2, 3], [4, 6], [8, 9]]

// Input 2:
//  A = [
//        [1, 9]
//        [2, 3]
//        [5, 7]
//      ]
// Output 2: 2
// Explanation 2:
//  Intervals: [ [1, 9], [2, 3], [5, 7] ]
//  We can include at max two disjoint intervals: [[2, 3], [5, 7]]


//Hint :-
//Sort the given intervals with respect to their end points and choose greedily.

//Solution Approach :- 
// We will solve this using greedy approach.
// 	-> Sort the intervals, with respect to their end points.
// 	-> Now, traverse through all the intervals, if we get two overlapping intervals, then greedily choose the interval with lower end point since, choosing it will ensure that intervals further can be accommodated without any overlap.
// 	-> Apply the same procedure for all the intervals and return the count of intervals which satisfy the above criteria.


//First Solution :-
bool comp(vector<int>& a, vector<int> &b){
    if(a[1]==b[1]){ 
        return a[0]<b[0];
    }
    return a[1] < b[1];
}

int Solution::solve(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), comp);     // sort the intervals

    int maxLength = 1;       // maximum length of the disjoint intervals set
    int lastIntervalSelected = 0;     // reference vector using which we compare the next intervals , if it has to be included in the interval set 

    for(int i=1;i<intervals.size(); ++i){
        if(intervals[lastIntervalSelected][1] < intervals[i][0]){
            maxLength++;                    // increment removed intervals count
            lastIntervalSelected=i;
        }
    }

    return maxLength;
}



//Second Solution :-
bool compare(vector<int> a,vector<int> b){
    return a[1]<b[1];
}

int Solution::solve(vector<vector<int> > &a) {
    sort(a.begin(),a.end(),compare);
    int count=1;
    int endpos=a[0][1];
    for(int i=1;i<a.size();i++)
    {
        if(endpos<a[i][0])
        {
            count++;
            endpos=a[i][1];
        }
    }
    return count;
}


//Third Solution :- 
int Solution::solve(vector<vector<int> > &A) {
	 vector<tuple <int,int>> end_ind_vec;
	 
	for(auto & vec: A){
	    end_ind_vec.push_back(tuple<int, int> {vec[1], vec[0]});
	}
	
	std::sort(end_ind_vec.begin(), end_ind_vec.end());
	int cur_end = -1;
	int cur_num_of_seg = 0;
	
	for(auto & end_ind_tuple : end_ind_vec){   
		int & start = std::get<1>(end_ind_tuple);
	    if(start > cur_end){
	        cur_end = std::get<0>(end_ind_tuple);
	        cur_num_of_seg++;
	    }
	}

    return cur_num_of_seg;

}


