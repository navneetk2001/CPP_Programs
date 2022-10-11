//Find the contiguous subarray within an array, A of length N which has the largest sum.


//First Method :-
int Solution::maxSubArray(const vector<int> &A) {
    int n=A.size();
    int currSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        currSum+=A[i];
        maxSum =max(maxSum,currSum);
        if(currSum<0){
           currSum=0;
        }
    }
    return maxSum;
}





//Second Method :-
int Solution::maxSubArray(const vector<int> &A) {
    auto i=A.begin();
    long long int m,s,flag=0;
    m=0;s=0;
    for(i=A.begin();i!=A.end();i++)
    {
        if(*i>0)
        {
            flag=1;
        }
        m=m+*i;
        if(m<0)
        m=0;
        if(m>s)
        {
            s=m;
        }
    }
    if(flag==0)
    {
        s=*max_element(A.begin(),A.end());
    }
    return s;
}




