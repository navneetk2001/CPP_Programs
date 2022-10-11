// Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.
// Where:
// A[i][0] = start time of the ith meeting.
// A[i][1] = end time of the ith meeting.
// Find the minimum number of conference rooms required so that all meetings can be done.

// Input 1:
// A = [      
// 	    [0, 30]
//      [5, 10]
//      [15, 20]
//     ]
// Output 1: 2
// Explanation 1:
//  Meeting one can be done in conference room 1 form 0 - 30.
//  Meeting two can be done in conference room 2 form 5 - 10.
//  Meeting three can be done in conference room 2 form 15 - 20 as it is free in this interval.

// Input 2:
// A= [[1, 18]
//     [18, 23]
//     [15, 29]
//     [4, 15]
//     [2, 11]
//     [5, 13]
//   ]
// Output 2: 4
// Explanation 2:
//  Meeting one can be done in conference room 1 from 1 - 18.
//  Meeting five can be done in conference room 2 from 2 - 11.
//  Meeting four can be done in conference room 3 from 4 - 15.
//  Meeting six can be done in conference room 4 from 5 - 13.
//  Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
//  Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.


//Hint :-
//The idea is to consider all events in sorted order.
//Once the events are in sorted order, trace the number of meetings at any time keeping track of meetings that have started, but not ended.


//Solution Approach :- 
// Solution 1: Use min heap to store the meeting rooms end time. If new meeting start time is greater or equal than least element, update it.
// If not, open a new meeting room. Report the min heap size at the end.
// Time Complexity : O(NlogN).

// Solution 2: Two sorted array of start time and end time. Two pointers to iterator start array and end array. Iterate the time line, the current time active meeting is num of start minus num of end.
// Since need sort, still O(nlogn) solution, but fast than solution 1.


//First Solution :-
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end());  //sort by start time 

    //Now maintain end time in a data structure and compare with meet starting time
    priority_queue<int,vector<int>,greater<int>> pq;  //for pushing end time and then comparing
    for(int i=0;i<A.size();i++){
        if(pq.empty()){
            pq.push(A[i][1]);   //[start time, end time] ->then push end time
        }
        else{
            if(pq.top()<=A[i][0]){
                pq.pop();
                pq.push(A[i][1]);  //push current meeting ending time 
            }
            else{
                pq.push(A[i][1]);
            }
        }
    }
    return pq.size();
}


//Second Solution :-  
int Solution::solve(vector<vector<int> > &mat) {
    vector<int> startTime;   //we just want timeline
    vector<int> endTime;
    for(int i=0;i<mat.size();i++){
        startTime.push_back(mat[i][0]);
        endTime.push_back(mat[i][1]);
    }
    
    sort(startTime.begin(),startTime.end());
    sort(endTime.begin(),endTime.end());
	
	// if starttime and endtime are same we use two different classroom
	// if endtime is less than the starttime of next meeting we got one empty room
	int i=1,j=0,classroom=1;
	int mx=1;
	
	while(i<startTime.size() && j<endTime.size()){
	    if(startTime[i]<=endTime[j]){
	    	classroom++;
	    	i++;
	    }
	    else if(startTime[i]>endTime[j]){
	        classroom--;
	        j++;
	    }
	    mx=max(mx,classroom);  // ek time p max classroom allotted to make meeting done
	}
	return mx;
}



//Third Solution :- 
int Solution::solve(vector<vector<int> > &A) {
	map<int,int> mp;

	for(auto v:A){
	    mp[v[0]]++;
	    mp[v[1]]--;
	}

	int sum=0,cnt=0;
	for(auto x:mp){
	    sum += x.second;
	    cnt = max(cnt,sum);
	}
	return cnt;
}



//Fourth Solution :-
int Solution::solve(vector<vector<int> > &A) {
    int ans = 0;
    vector<pair<int,int>> v;
    for(int i=0;i<A.size();i++)
    {
        v.push_back({A[i][1],-1});
        v.push_back({A[i][0],1});
    }
    
    sort(v.begin(),v.end());
    
    int c=0;
    for(int i=0;i<v.size();i++)
    {
        c = c + v[i].second;
        if(c>ans)
        ans=c;
    }
    
    return ans;
}