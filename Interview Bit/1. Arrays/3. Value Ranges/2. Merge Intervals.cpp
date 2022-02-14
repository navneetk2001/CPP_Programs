// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.


//Hint 1
This problem has a lot of corner cases which need to be handled correctly.
Let us first talk about the approach.
Given all the intervals, you need to figure out the sequence of intervals which intersect with the given newInterval.
Lets see how we check if interval 1 (a,b) intersects with interval 2 (c,d):
//Overlap case :
    a---------------------b                      OR       a------b
                c-------------------d                c------------------d
//Non overlap case :
    a--------------------b   c------------------d
Note that if max(a,c) > min(b,d), then the intervals do not overlap. Otherwise, they overlap.


//Solution Approach
Have you covered the following corner cases :

1 Size of interval array as 0.

2 newInterval being an interval preceding all intervals in the array.

    Given interval (3,6),(8,10), insert and merge (1,2)
3 newInterval being an interval succeeding all intervals in the array.

    Given interval (1,2), (3,6), insert and merge (8,10)
4 newInterval not overlapping with any interval and falling in between 2 intervals in the array.

    Given interval (1,2), (8,10) insert and merge (3,6) 
5 newInterval covering all given intervals.

    Given interval (3, 5), (7, 9) insert and merge (1, 10)


//First Solution :-
/*
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool mycomp(Interval a,Interval b){
     return a.start<b.start;
 }

vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    A.push_back(newInterval);
    sort(A.begin(),A.end(),mycomp);
    vector<Interval> res;
    int n=A.size();
    res.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(A[i].start<=res[res.size()-1].end)
         res[res.size()-1].end=max(res[res.size()-1].end,A[i].end);
        else
         res.push_back(A[i]);
    }
    return res;
}




//Second Solution :-
/*
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &A, Interval newarr) {
    int n = A.size();

    if(newarr.start>newarr.end){
        auto t=newarr.start;
        newarr.start=newarr.end;
        newarr.end=t;
    }

    if(n==0) return {newarr};

    int i=0;
    while(A[i].start < newarr.start && i<n)
        i++;
    A.insert(A.begin()+i, newarr);

    vector<Interval> res;
    for(i=0; i < n; i++){
        if(A[i].end >= A[i+1].start){
            A[i+1].start = A[i].start;
            A[i+1].end = max(A[i+1].end, A[i].end);
        }
        else res.push_back(A[i]);
    }
    res.push_back(A[n]);
    return res;
}



//Second Solution :-
/*
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(Interval a, Interval b)
 {
     return a.start<=b.start;
 }
vector<Interval> Solution::insert(vector<Interval> &A, Interval B) {
    A.push_back(B);
     sort(A.begin(),A.end(),cmp);
    int j=0,i=0,k;
    for(i=0;i<A.size();i++)
    {
        int mn = A[i].start;
        int mx = A[i].end;
        k=i+1;
        for(;k<A.size();k++)
        {
            if(A[k].start<=mx)
            {
                mx = max(mx,A[k].end);
                mn = min(A[i].start,mn);
            }
            else
            {
                k--;
                break;
            }
        }
        
        i = k;
        
        A[j].start = mn;
        A[j].end = mx;
        j++;
    }
    
    A.erase(A.begin()+j,A.end());
    return A;
}







// Another solution :- using stack
// A C++ program for merging overlapping intervals
#include<bits/stdc++.h>
using namespace std;

// An interval has start time and end time
struct Interval
{
    int start, end;
};

// Compares two intervals according to their starting time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
    // Test if the given set has at least one interval
    if (n <= 0)
        return;

    // Create an empty stack of intervals
    stack<Interval> s;

    // sort the intervals in increasing order of start time
    sort(arr, arr+n, compareInterval);

    // push the first interval to stack
    s.push(arr[0]);

    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < n; i++)
    {
        // get interval from stack top
        Interval top = s.top();

        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < arr[i].start)
            s.push(arr[i]);

        // Otherwise update the ending time of top if ending of current
        // interval is more
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }

    // Print contents of stack
    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}

// Driver program
int main()
{
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}