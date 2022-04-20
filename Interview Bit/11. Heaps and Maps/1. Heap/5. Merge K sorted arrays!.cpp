// You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.
// You need to merge them into a single array and return it.

// Input 1:
//  A = [  [1, 2, 3]
//         [2, 4, 6]
//         [0, 9, 10]
//      ]
// Output 1:
//  [0, 1, 2, 2, 3, 4, 6, 9, 10]

//Hint :-
Input arrays are sorted so try to pick all the array first element and push the minimum to output ,push the next element of the array which contained the minimum element.
Think of data structure which can maintain the minimum all the way along.

//Solution Approach :- 
An efficient solution is to use heap data structure. The time complexity of heap based solution is O(N Log k). where N is count of all elements
Create an output array.
Create a min heap of size k and insert 1st element in all the arrays into the heap
Repeat following steps while priority queue is not empty.
Remove minimum element from heap (minimum is always at root) and store it in output array.
Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.


//First Solution :-
// first element in p is the element value 
// second element in p is the index of the current array in the main matrix
// third element in p is the index of the current element in the selected array
typedef pair<int, pair<int, int>> pip;
vector<int> Solution::solve(vector<vector<int> > &a){
    int k = a.size(), n = a[0].size();
    priority_queue<pip, vector<pip>, greater<pip>> minh;
    
    for(int i=0; i<k; i++){
        minh.push({a[i][0], {i,0}});
    }
    
    vector<int> res;
    while(!minh.empty()){
        res.push_back(minh.top().first);
        auto p = minh.top().second;
        minh.pop();
        
        int i = p.first, j = p.second;
        if(j+1<A[i].size())
        {
            q.push({A[i][j+1],{i,j+1}});
        }
    }
    return res;
}


//Second Solution :-
vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<int, vector<int>, greater<int>> p;
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[i].size(); j++){
            p.push(A[i][j]);
        }
    }
    
    vector<int> res;
    while(!p.empty()){
        res.push_back(p.top());
        p.pop();
    }
    
    return res;
}


//Third Solution :- 
vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> v;
    int i,j,n=A.size(),m=A[0].size();
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        v.push_back(A[i][j]);
    }
    sort(v.begin(),v.end());
    return v;
}


