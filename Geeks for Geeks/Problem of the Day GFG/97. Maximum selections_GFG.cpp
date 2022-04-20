// Geek wants to select the maximum number of course bundles at the Geek Summer Carnival. 

// You are given a finite number of courses and N range of numbers each depicting a bundle of courses. Select the maximum number of bundles such that no courses overlap in any of the bundle.
// Note: The ending of a range being the same as start of another isn't considered as an overlap.

// Example 1:
// Input:
// N = 4
// Bundles = 
// 1 5
// 2 3
// 1 8
// 3 5

// Output: 2
// Explanation: We can select 2 bundles at max while staying true to the condition. For this, we can pick the ranges (2,3) and (3,5) without any overlap. 
 

// Example 2:
// Input:
// N = 5
// Bundles = 
// 7 9 
// 2 8 
// 1 3 
// 10 11 
// 10 16

// Output: 3
// Explanation: We can pick the ranges (1,3), (7,9) and (10,11) without any overlap.


//Approach :-
//this is a standard problem in greedy aka Activity selection problem.
//here we just sort the activities in non decreasing order of
//their finishing times and then select the activities such that they do not overlap and always including the first activity.



//Solution Approach :-
class Solution{
public:
    int max_non_overlapping( vector< vector<int> >& ranges )
    {
        int n=ranges.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
        	v[i]={ranges[i][1],ranges[i][0]};
        }
        sort(v.begin(),v.end());
        int count=1;
        int curr_ending = v[0].first;
        for(int i=1;i<n;i++){
        	if(v[i].second>=curr_ending){
        		count++;
     			curr_ending=v[i].first;

        	}
        }
        return count;
    }
};


//Second Solution :-
static bool com(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}

int max_non_overlapping( vector< vector<int> >& ranges )
{
    sort(ranges.begin(),ranges.end(),com);
    
    int c=0,end=-1;
    for(int i=0;i<ranges.size();i++){
        if(ranges[i][0]>=end){
            c++;
            end=ranges[i][1];
        }
    }
    return c;
}