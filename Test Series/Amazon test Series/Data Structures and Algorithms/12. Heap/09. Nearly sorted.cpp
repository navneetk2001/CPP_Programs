// Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

// Example 1:
// Input:n = 7, k = 3
// arr[] = {6,5,3,2,8,10,9}
// Output: 2 3 5 6 8 9 10
// Explanation: The sorted array will be 2 3 5 6 8 9 10

// Example 2:
// arr[] = {3,1,4,2,5}
// Output: 1 2 3 4 5 




//Solution Approach :-
//In this Question, we can use the fact that each element might be at most k positions away. 
// And hence we can go on pushing the elements into the priority queue(implemented using minheap) 
// until its size is not greater than k, if its size is greater than k , we simply push the element 
// at the top into the vector. at last until the queue is empty, we push the elements in to the vector.

class Solution{
public:
    //Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int num, int k){
        vector<int> v;
        priority_queue<int,vector<int>,greater<int>>q;
    
        for(int i=0;i<num;i++){
            q.push(arr[i]);
            if(q.size()>k){
                v.push_back(q.top());
                q.pop();
            }
        }
        
        while(!q.empty()){
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};