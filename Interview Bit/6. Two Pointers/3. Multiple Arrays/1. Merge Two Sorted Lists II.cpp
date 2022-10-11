// Given two sorted integer arrays A and B, merge B into A as one sorted array.
// Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
// TIP: C users, please malloc the result into a new array and return the result.
// If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

// Example :
// Input : 
//          A : [1 5 8]
//          B : [6 9]
// Modified A : [1 5 6 8 9]


//Hint 
// Use of additional space is allowed. So, maybe you should try collecting the output in a separate array.
// Note: You need 2 pointers at the head of each array and you just need to compare the values at the head of the arrays to get the current minimum.

// Since A is sorted, all values after the pointer are going to be bigger.
// Since B is sorted, all values after the pointer are going to be bigger.
// All values before the pointer have already been put in the result array.
// So, all you need to do is to choose the smaller value from the 2 heads and move on.


//First Solution
void Solution::merge(vector<int> &A, vector<int> &B) {
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }

    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }
    A.clear();
    while(!pq.empty()){
        A.push_back(pq.top());
        pq.pop();
    }
}

//Second Solution
void Solution::merge(vector<int> &A, vector<int> &B)
{
    // O(1) space
    // If all elements of B are placed in array
    // then elements of A are already in place
    
    int i = A.size() - 1; // i pointing to last index of A
    int j = B.size() - 1; // j pointing to last index of B
    
    int lastPos = A.size() + B.size() - 1; // lastPos pointing to last index of merged array A and B
    
    A.resize(A.size() + B.size());
    
    while(j >= 0)
    {
        if(i >= 0 and A[i] > B[j]){
            A[lastPos--] = A[i--];
        }
        else{
            A[lastPos--] = B[j--];
        }
    }
    
}


//Third Solution
void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> C = A;
    A.clear();
    int p1 = 0 , p2 = 0;
    while(true){
        if(p1 == C.size() || p2 == B.size())
            break;
        if(C[p1] < B[p2]){
            A.push_back(C[p1]);
            p1++;
        }
        else if(C[p1] > B[p2]){
            A.push_back(B[p2]);
            p2++;
        }else if(C[p1] == B[p2]){
            A.push_back(C[p1]);
            A.push_back(B[p2]);
            p1++;
            p2++;
        }
    }
    if(p1 == C.size() && p2 < B.size()){
        while(p2 < B.size()){
            A.push_back(B[p2]);
            p2++;
        }
    }
    if(p2 == B.size() && p1 < C.size()){
        while(p1 < C.size()){
            A.push_back(C[p1]);
            p1++;
        }
    }
}



