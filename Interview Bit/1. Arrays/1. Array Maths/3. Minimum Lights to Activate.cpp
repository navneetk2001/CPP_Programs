// There is a corridor in a Jail which is N units long. Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.
// All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].
// Initially all lights are off.
// Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

// Input 1:
// A = [ 0, 0, 1, 1, 1, 0, 0, 1].
// B = 3
// Output 1: 2
// Explanation 1: In the first configuration, Turn on the lights at 3rd and 8th index. 
// Light at 3rd index covers from [ 1, 5] and light at 8th index covers [ 6, 8].

// Input 2:
// A = [ 0, 0, 0, 1, 0].
// B = 3
// Output 2: -1
// Explanation 2: In the second configuration, there is no light which can light the first corridor.


int Solution::solve(vector<int> &A, int B) {
    int count =0;
    int i=0;
    int n=A.size();
    while(i<n){
        int right=min(i+B-1, n-1);
        int left=max(0,i-B+1);
        bool bulbfound=false;
        while(right>=left){
            if(A[right]==1){
                bulbfound = true;
                break;
            }
            right--;
        }
        if(!bulbfound) return -1;
        count++;
        i=right+B;
    }
    return count;
}


//First Method :- 
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int curr = 0;
    int count = 0;
    while(curr < n)
    {
        int next = curr+B-1;
        int ind = next;
        int prev = curr-B+1;
        if(prev<0)
            prev = 0;
        while(ind>=prev)
        {
            if(A[ind])
                break;
            ind--;
        }
        if(ind >= prev)
        {
            count++;
            curr = ind+B;
        }
        else
            return -1;
    }
    return count;
}




//Second Method :- 
int Solution::solve(vector<int> &A, int B) {
    int n = (int)A.size(), i = 0, ans = 0;
    if(B == 0){
        return -1;
    }
    
    while(i<n){    //Start from 0th index
        int idx = -1;
        //check range [X-B+1, X+B-1] and find rightmost bulb
        for(int j=max(0, i-B+1);j<min(n,i+B);j++){
            if(A[j] == 1)
                idx = j;
        }
        if(idx == -1){
            return -1;
        }
        ans++;
        
        i = idx+B;    //Start now from index which is outside the current selected bulb
    }
    return ans;
}





//Third Method :- 
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int i=0;
    int result=0;
    bool flag=false;
    while(i<n)
    {
        int a=max(0,i-B+1);
        int b=min(n-1,i+B-1);
        for(;b>=a;b--)
        {
            if(A[b]==1)
            {
                result++;
                flag=true;
                i=b+B;
            break;
            }
        }
        if(flag==false) 
            return -1;
        flag=false;
    }
    return result;
}