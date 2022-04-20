// Given a string A and integer B, what is maximal lexicographical string that can be made from A if you do atmost B swaps.
// Input 1:
// A = "254"
// B = 1
// Input 2:
// A = "254"
// B = 2

// Output 1:
//  524
// Output 2:
//  542

//Hint :-
The idea is to consider every digit and swap it with digits
following it one at a time and see if it leads to the maximum number.
The process is repeated B times.

//Solution Approach :- 
1) Create a global variable which will store the maximum string or number.
2) Define a recursive function that takes the string as number and value of k
3 Run a nested loop, the outer loop from 0 to length of string -1 and inner loop from i+1 to end of string.
4) Swap the ith and jth character and check if the string is now maximum and update the maximum string.
5) Call the function recursively with parameters: string and k-1.
6 Now again swap back the ith and jth character.


//First Solution :-
//We can think of recursion
//We will use backtraacking
string ans="";
void find(string a,int k){
    if(k==0){    //if no swaps left
        if(ans<a) 
        	ans=a;
        return;
    }

    //Check for all the available test cases and backtrack and get required answer
    for(int i=0;i<a.length();i++){
        for(int j=i+1;j<a.length();j++){
            swap(a[i],a[j]);
            find(a,k-1);
            swap(a[i],a[j]);
        }
    }
}

string Solution::solve(string A, int B) {
    ans="";
    find(A,B);
    return ans;
}


//Second Solution :- Using-Iterative-Method
string Solution::solve(string A, int B)
{
	string s=A;
	int i=0;
	int index=-1;

	while(B--){
		int maxi=0;
		for(int j=i;j<A.length();j++){
			if(A[j]-'0'>maxi){
				index=j;
				maxi=A[j]-‘0’;
			}
		}
		swap(A[index],A[i]);
		if(A[i]==s[i]){
			B++;
		}
		i++;
	}
	return A;
}


//Third Solution :- 
string generate (string &A, int B, int index){
    if(B == 0)              return A;
    string temp = A;
    for(int i=0; i<A.length(); i++) {
        if( i == index )    continue;
        swap(A[index], A[i]);
        temp = max(temp, generate(A, B-1, i));
    }
    return temp;
}

string Solution::solve(string A, int B) {
    string temp = A;
    for(int i=0; i<A.length(); i++)
        temp = max(temp, generate(A, B, i));
    return temp;
}

