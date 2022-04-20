Given an array a of length n, find the minimum number of operations required to make it non-increasing. You can select any one of the following operations and preform it any number of times on an array element.
	increment the array element by 1.
	decrement the array element by 1. 

Example 1:
Input:
N = 4 
array = {3, 1, 2, 1}
Output: 1
Explanation: Decrement array[2] by 1. New array becomes {3,1,1,1} which is non-increasing. Therefore, only 1 step is required. 

Example 2:
Input:
N = 4 
array = {3, 1, 5, 1}
Output: 4



//Approach :-
//every number will depend on previous elements present before it
//we assume the previous elements before current elements are sorted in non increasing order
//thus we need to modify curr element such that it also is in non increasing order


//Solution Approach :-
class Solution{
public:
    int minOperations(int *arr,int n)
    {
         priority_queue <int,vector <int>,greater <int>> pq;
         int ans=0;
         for(int i=0;i<n;i++){
              if(pq.empty()!=1 and pq.top()<arr[i]){
                  ans+=(arr[i]-pq.top());
                  pq.push(arr[i]);
                  pq.pop();
              }
                  pq.push(arr[i]);
                 
          }
          
         return ans;
    }
};







