// Given 2 integers A and B and an array of integars C of size N.
// Element C[i] represents length of ith board.
// You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.
// Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.
// 2 painters cannot share a board to paint. That is to say, a board
// cannot be painted partially by one painter, and partially by another.
// A painter will only paint contiguous boards. Which means a
// configuration where painter 1 paints board 1 and 3 but not 2 is invalid.
// Return the ans % 10000003


//Hint 1
Hint : Think binary search for the answer.
If you had a function bool isPossible which could tell you if its possible to paint the boards in time T or less, can you solve the problem ?

//Solution Approach
If you have already solved the problem corresponding to hint1, you are already halfway there.
You can do a binary search for the answer :

  start = 0, end = max_time_possible
  mid = (start + end) / 2
  if isPossible(mid): 
  	end = mid - 1
  else 
	start = mid + 1
Now, lets look into how isPossible would be implemented.
Keep assigning boards to painter greedily till the time taken < mid. If you run out of painters, isPossible = false.
else isPossible = true.



// First Method :-
typedef long long ll;
bool isPossible(vector<int> &C, ll mid, int B, int A){
    int n=C.size();
    ll sum=0;
    int p = 1;
    for(int i=0;i<n;i++){
        sum+=C[i];

        if(sum>mid){
            p++;
            sum=C[i];
        }

        if(p>A){
            return false;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n=C.size();
    int mx=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=C[i];
        mx=max(C[i],mx);
    }

    ll ans=-1;
    ll low=mx;
    ll high=sum*B;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(isPossible(C,mid,B,A)==true){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return (ans*B)%10000003;
}


//Second Method :-
int check(long long int mid,vector<int> C) // Returns no. of workers required to do the job in "mid" time.
{
    int count=1;
    long long int sum=0;
    for(int i=0;i<C.size();i++)
    {
        if(sum+C[i]>mid)  
        {
            sum=C[i];
            count++;
            if(C[i]>mid)  // If the dimension of a board is more than mid then it is impossible for a worker to complete the job in mid time so we will return INT_MAX;
            {
                return INT_MAX;
            }
        }
        else
        {
            sum+=C[i];
        }
    }
    return count;  // return no. of workers needed.
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int low=LONG_MAX;   // If a painter paints the smallest board then it will take the least time.
    long long int high=0;  // If a single painter paints all the board then it will take the highest time.
    for(int i=0;i<C.size();i++)
    {
        low=min(low,(long long)C[i]);  
        high+=C[i]; 
    }
    long long int ans;
    long long int mid;
    while(low<=high)    /* Binary Search */ 
    {
        mid=low+(high-low)/2;
        if(check(mid,C)<=A)  // If "mid" is the amount of time we have then check() function will return number of workers we need to complete the job in "mid" time.
        {
            ans=mid; 
            high=mid-1;  // We will check if we can do the job in time less than "mid".
        }
        else
        {
            low=mid+1; // if it is not possible to do the job in given time. We will increase our range.
        }
    }
    return (ans*B)%10000003;
}



