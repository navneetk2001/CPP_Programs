Given an array of integers A, sort the array into a wave like array and return it, In other words, arrange the elements into a sequence such that 
a1 >= a2 <= a3 >= a4 <= a5.
NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.



//Solution Approach
Lets take an example:
array = {5, 1, 3, 4, 2}
Sort the above array. 
array = {1, 2, 3, 4, 5}
Now swap adjacent elemets in pairs.
swap(1, 2)
swap(3, 4)
Now, our array = {2, 1, 4, 3, 5}
and voila!, the array is in the wave form. 



// First Method :-
vector<int> Solution::wave(vector<int> &a) {
    sort(a.begin(), a.end());
    int n =a.size();
    for(int i=0;i<n-1;i+=2)
    {
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
    }
    return a;
}


//Second Method :-
vector<int> Solution::wave(vector<int> &A) {
   int n = A.size();
   sort(A.begin(),A.end());
   if(n%2==0){
       for(int i=0;i<n;i+=2){
           cout<<A[i+1]<<" "<<A[i]<<" ";
       }
   }
   if(n%2==1){
       for(int i=0;i<n-1;i+=2){
           cout<<A[i+1]<<" "<<A[i]<<" ";
       }
       cout<<A[n-1]<<" ";
   }
   vector<int> V;
   return V;
}



//Third Solution :-
vector Solution::wave(vector &A) {
	int n=A.size();
	int i=0;
	sort(A.begin(),A.end());
	while(i<n){
		if(i>0 && A[i-1]>A[i]){
		    swap(A[i],A[i-1]);
		}
		if(i<n-1 && A[i]<A[i+1]){
		    swap(A[i],A[i+1]);
		}
		if(n%2==0){
		    A[n-1]=A[n-1];
		}
		i=i+2;
    }
	return A;
}
