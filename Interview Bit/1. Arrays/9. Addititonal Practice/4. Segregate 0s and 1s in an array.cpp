// You are given an array of 0s and 1s in random order. 
// Segregate 0s on left side and 1s on right side of the array 
// [Basically you have to sort the array]. Traverse array only once. 


// First Method :-
vector<int> Solution::solve(vector<int> &A) {
    int Zeros=0, Ones=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            Zeros++;
        }
        else{
            Ones++;
        }
    }
    int i=0;
    vector<int> v;
    while(i<Zeros){
        v.push_back(0);
        i++;
    }
    int j=0;
    while(j<Ones){
        v.push_back(1);
        j++;
    }
    return v;
}


//Second Method :-
vector<int> Solution::solve(vector<int> &arr) {
    int count = 0; // Counts the no of zeros in arr
    int n=arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count++;
    }
 
    // Loop fills the arr with 0 until count
    for (int i = 0; i < count; i++)
        arr[i] = 0;
 
    // Loop fills remaining arr space with 1
    for (int i = count; i < n; i++)
        arr[i] = 1;
    return arr;
}


//Third Solution :-
vector<int> Solution::solve(vector<int> &A) {
    vector<int> v;
    int zero=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            zero+=1;
        }
        v.push_back(1);
    }
    int k=0;
    while(zero--){
        v[k]=0;
        k+=1;
    }
    return v;
}
