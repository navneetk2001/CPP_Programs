// Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

// Example 1:
// Input:
// N = 4
// X[] = 5,15,1,3
// Output:
// 5
// 10
// 5
// 4
// Explanation:Flow in stream : 5, 15, 1, 3 
// 5 goes to stream --> median 5 (5) 
// 15 goes to stream --> median 10 (5,15) 
// 1 goes to stream --> median 5 (5,15,1) 
// 3 goes to stream --> median 4 (5,15,1 3) 
 

// Example 2:
// Input:
// N = 3
// X[] = 5,10,15
// Output:
// 5
// 7.5
// 10
// Explanation:Flow in stream : 5, 10, 15
// 5 goes to stream --> median 5 (5) 
// 10 goes to stream --> median 7.5 (5,10) 
// 15 goes to stream --> median 10 (5,10,15) 




//Solution Approach :-
priority_queue<int> maxHeap; //creating a maxHeap
priority_queue<int, vector<int>, greater<int>> minHeap; //creating a min Heap

void insertHeap(int &x){
    if(maxHeap.size() == 0 || maxHeap.top() >= x){ 
        maxHeap.push(x);
    }
    else{
        minHeap.push(x);
    }
    balanceHeaps();
}

//Function to balance heaps.
void balanceHeaps(){
    if(maxHeap.size() > minHeap.size() + 1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(minHeap.size() > maxHeap.size()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

//Function to return Median.
double getMedian(){
    if(maxHeap.size() == minHeap.size()){
        return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
    }
    return (double)maxHeap.top();
}




//Second Solution :- For LeetCode Submission
#include<bits/stdc++.h>
class MedianFinder {
public:
    priority_queue<int> maxpq; //maxHeap
    priority_queue<int, vector<int>, greater<int>> minpq; //minHeap
    
    void addNum(int num) {
        if(maxpq.empty() || maxpq.top() > num){
            maxpq.push(num);
        }
        else{
            minpq.push(num);
        }
        
        if(maxpq.size() > minpq.size() + 1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size() > maxpq.size() + 1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        
    }
    
    double findMedian() {
       	if(maxpq.size() == minpq.size()){
           	return (maxpq.top() + minpq.top()) / 2.0;
       	}
        else{
            if(maxpq.size() > minpq.size()){
                return maxpq.top();
            }else{
                return minpq.top();
            }
        }
    }
};

