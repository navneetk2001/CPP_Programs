// You are given a 1D integer array B containing A integers.
// Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.
// Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n]) 


// Hint 1
First think when this condition is possible.
For dividing array in 3 part we have a condition on the sum that it should be divisible by 3.
Then think how can we access sum of ranges to check the condition for equal sum.


// Solution Approach
If the sum of all the elements of the array is not divisible by 3 return 0. Else it is obvious that the sum of each part of each contiguous part will be equal to the sum of all elements divided by 3.
Create an array of the same size as a given array whose i-th index holds the value of the sum of elements from indices 0 to i of the given array. Let’s call it prefix array
Create another array of the same size as a given array whose i-th index the value of sum of elements from indices i to A-1 of the given array. Let’s call it suffix array.The idea is simple, we start traversing the prefix array and suppose at the i-th index of the prefix array the value of prefix array is equal to (sum of all elements of given array)/3.
For i found in the above step we look into the suffix array from (i+2)-th index and wherever the value of suffix array is equal to (sum of all elements of given array)/3, we increase the counter variable by 1.
To implement step 4 we traverse suffix array and wherever the value of suffix array is equal to the sum of all elements of given array/3 we push that index of suffix array into the vector. And we do a binary search in the vector to calculate the number of values in suffix array which are as according to step 4.
We search in suffix array because there should be at least 1 element between the first and third part.
Time Complexity is O(Alog A)


//Efficient Approach [ O(A) solution ] :
If sum of all the elements of the array is not divisible by 3, return 0.
It is obvious that the sum of each part of each contiguous part will be equal to the sum of all elements divided by 3.
Let’s create an array cnt[ ], where cnt[ i ] equals 1, if the sum of elements from ith to Ath equals Array_Sum/3 else 0. Now, calculate the cumulative sum of the cnt array from the last index.
Thus, we receive very simple solution: for each prefix of initial array 1…i with the sum that equals Array_Sum/3 we need to add to the answer sums[ i+2 ].


// First Method :- 
int Solution::solve(int A, vector<int> &B) {
    int sum=0;
    for(int i=0; i<A; i++)
    sum +=B[i];
    if(sum%3 != 0)
        return 0;
    
    sum /= 3;
    int s = 0;
    int count =0;
    int left = 0; //left patition

    for(int i=0; i<A-1; i++){
        s += B[i];
        if( s==(2*sum))
            count += left;
        if(s==sum)
            left++;
    }

    return count;
}




// Second Method :- 
int Solution::solve(int A, vector<int> &B) {
    int sum = 0;
    for(int i = 0; i < A; i++) sum += B[i];
    if(sum % 3 != 0 ) return 0;
    int sum13rd = sum/3;
    int sum23rd = 2 * sum13rd;
    int currSum = 0;
    int g13rd = 0;
    int count = 0;
    for(int i = 0; i < A - 1; i++) {
        currSum += B[i];
        if(currSum == sum23rd) count += g13rd;
        if(currSum == sum13rd) g13rd++;
    }
    //rumming till only A-1 is important for sum = 0. nd so is order of g13rd++.
    return count;
}



// Third Method :- 
int Solution::solve(int n, vector<int> &arr) 
{
    int presum[n];
    presum[0]=arr[0];
    for(int a=1;a<n;a++)
    {
        presum[a]=presum[a-1]+arr[a];
    }
    int tsum=presum[n-1];
    if(tsum%3!=0)
    return 0;
    if(tsum==0)
    {
        int ct=0;
        for(int a=0;a<n;a++)
        {
            if(presum[a]==0)
            ct++;
        }
        return ((ct-2)*(ct-1))/2;
    }
    else{
        int cs=tsum/3,tcs=2*cs;
        
        int sum=0,j=0;

        for(int a=n-1;a>=0;a--)
        {
            if(presum[a]==cs)
            {
                sum+= j;
            }
            else if(presum[a]==tcs)
            {
                j++;
            }
        }
        return sum;
    
    }
}



//Fourth Solution :-
#include <iostream>
#include <math.h>

using namespace std;

int a[1000010];
long long cnt[1000010];

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    long long s = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0)
        cout << "0\n";
    else {
        s /= 3;
        long long ss = 0;
        for(int i = n-1; i >= 0 ; --i)
        {
            ss += a[i];
            if (ss == s)
                cnt[i] = 1;
        }
        for(int i = n-2 ; i >= 0 ; --i)
            cnt[i] += cnt[i+1];
        
        long long ans = 0;
        ss = 0;
        for(int i = 0 ; i+2 < n ; ++i) {
            ss += a[i];
            if (ss == s)
                ans += cnt[i+2];
        }
        cout << ans << "\n";
    }
    return 0;
}