// Given an array and a value, remove all the instances of that value in the array. 
// Also return the number of elements left in the array after the operation.
// It does not matter what is left beyond the expected length.
// Example:
// If array A is [4, 1, 1, 2, 1, 3] and value elem is 1, then new length is 3, and A is now [4, 2, 3]
// Try to do it in less than linear additional space complexity.


//Hint 
You need to modify the original array itself. So you need to keep current like pointer which will point to the index of the array where you can store the next value.

//Solution Approach :-
Maybe you should try maintaining 2 pointers in the array:
One pointer iterates over the array
Other pointer only moves when it finds an element different from ‘elem’.
In other words, the second pointer only moves when the first pointer is on an element worth keeping in the final array.


//First Solution
int Solution::removeElement(vector<int> &A, int B) {
    int st=0;
    for(auto ele:A){
        if(ele!=B){
            A[st]=ele;
            st++;
        }
    }
    return st;
}


//Second Solution
int Solution::removeElement(vector<int> &A, int B) {
    int N = A.size();
    int i = 0, j = N-1, count = 0;
    
    while(i <= j){
        if(A[i] != B){
            A.push_back(A[i]);
            i++;
            count++;
        }
        else i++;
    }
    
    A.erase(A.begin(), A.begin()+j+1);
    return A.size();
}

//Third Solution
int Solution::removeElement(vector<int> &A, int B) {
    auto read_it = A.begin();
    int count = 0;
    while(read_it != A.end() && *read_it != B){
        ++read_it;
        ++count;
    }
    auto write_it = read_it;
    for(;read_it != A.end(); ++read_it ){
        if(*read_it != B){
            *write_it = *read_it;
            ++write_it;
            ++count;
        }
    }
   return count;
}


