//Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.



//Hint 1
The straightforward approach is to for every element find how many integers are greater than that, and if that matches our given statement then we have our answer.
Will sorting the array help?

//Solution Approach 
First we sort the input array.
Now, all we have to do is to traverse through each element of the array and check whether it matches our given statement, since the array is sorted we directly know how many elements are greater than that number in the array.
Note: Please take care of cases, when certain element repeats many times.






//First Method :-
int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    if(A[A.size()-1]==0) return 1;

    for(int i=0;i<A.size()-1;i++){
        if(A[i]==(A.size() -(i+1)) && i+1<A.size()  && A[i]<A[i+1]){
            return 1;
        }
    }
    return -1;
}


//Second Method :-
int Solution::solve(vector &A) {
	int n=A.size();
	sort(A.begin(),A.end());
	if(A[n-1]==0)
	    return 1;
	
	for(int i=1;i<n;i++)
	{
	  while(A[i-1]==A[i] && i<n)
	  {
	      i++;
	  }
	  if(i<n && n-i==A[i-1])
	     return 1;
	}
	return -1;
}


//Third Method :-
int Solution::solve(vector<int> &A) {
    map<int,int>mp; 
    for(int i=0;i<A.size();++i){
       mp[A[i]]++;
    }

    int intial_count = 0; 
    for(auto it:mp){
        intial_count += it.second;
    }

    for(auto it:mp){
        intial_count -= it.second;
        if(intial_count == it.first) return 1;
    }
    return -1;
}
