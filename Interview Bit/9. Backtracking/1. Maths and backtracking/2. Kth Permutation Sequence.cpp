// The set [1,2,3,…,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3 ) :
// 1. "123"
// 2. "132"
// 3. "213"
// 4. "231"
// 5. "312"
// 6. "321"
// Given n and k, return the kth permutation sequence.
// For example, given n = 3, k = 4, ans = "231"
// Good questions to ask the interviewer :
// What if n is greater than 10. How should multiple digit numbers be represented in string?
// In this case, just concatenate the number to the answer.
// so if n = 11, k = 1, ans = "1234567891011"
// Whats the maximum value of n and k?
// In this case, k will be a positive integer thats less than INT_MAX.
// n is reasonable enough to make sure the answer does not bloat up a lot.

//Hint :-
// Note: Generating all permutation wont help here.
// What you can do is try out elements which can you keep at any position. If the permutation resulting from keeping this element does not becomes >= k you keep incrementing the element to be put.
// Can you see now how recursion and maths can help us here now?

//Solution Approach :- 
// This involves a little bit of maths and recursion for simplicity.
// Number of permutation possible using n distinct numbers = n!
// Lets first make k 0 based.
// Let us first look at what our first number should be.
// Number of sequences possible with 1 in first position : (n-1)!
// Number of sequences possible with 2 in first position : (n-1)!
// Number of sequences possible with 3 in first position : (n-1)!
// Hence, the number at our first position should be k / (n-1)! + 1 th integer.
// Can we reduce the k and modify the set we pick our numbers from ( initially 1 2 3 … n ) to call the function for second position onwards ?


//Best Solution : For Interviewbit
int fact(int n){
    if(n>12){
        return INT_MAX;
    }
    return (n==1 || n==0) ? 1: n * fact(n - 1);
}

string Solution::getPermutation(int N, int B) {
    vector<int> C;
    for(int i=1;i<=N;i++){
        C.push_back(i);
    }
    
    string ans="";
    int block;
    for(int i=0;i<N;i++)
    {
        int p=fact(N-1-i);
        block=B/p;
        if(B%p==0)  
            block--;
        ans+=to_string(C[block]);
        C.erase(C.begin()+block);
        B=B-(block)*p;
    }
    return ans;
}


//First Solution :-
// here is the optimal solution
string Solution::getPermutation(int n, int k) {
    if(n>12) {
        return to_string(INT_MAX);
    }
    vector<int> nums;
    int fact = 1;    // taking factorial that is all the number of factorial;
    
    // also we take factorial till n-1 only because we have to calculate only on the specific permutions after taking the first element out that is k / fact on line 21
    for(int i = 1; i < n; i++) {
        nums.push_back(i);   // storing number in nums vec 
        fact *= i;
    }
    nums.push_back(n);   // storing last number also in nums vec 
    k--;                 // reducing k by 1 because of 0 based indexing
    string ans = "";
    
    while(true) {
        ans += to_string(nums[k / fact]);    // now add the the top number for current iteration
        nums.erase(nums.begin() + k / fact);  // now remove that top number to get the permutation of remaining nums elements
        
        if(nums.size() == 0)  // if the vector size get 0 then it means all the elements used in permutationa 
            break;            // and all the we go the desired permutation

        // if not then go for next iteration and for that set new k
        // new k will be the nubmer of permutation required with the left out element in the
        // nums array and k will be k % fact and so with the factorial it will the 
        // factorial of nums.size()-1 elements that is fact will be fact / nums.size();
        k %= fact;
        fact /= nums.size();
    }
    return ans; 
}



//Second Solution :-
class Solution {
public:
	string getPermutation(int n, int k) {
		string s;
		for(int i=1;i<=n;i++) 
            s.push_back(i+'0');
		while(k-->1){
			next_permutation(s.begin(),s.end());
		}
		return s;
	}
};

//Third Solution :- 
// this is the brute force solution with a result of TLE and it simply finds all the premutaiton then sort them and return the require k-1th permutation
class Solution {
    void getPermutations(vector<string> &ans, string s, int index, int n) {
        if(index == n) {
            ans.push_back(s);
            return;
        }
        for(int i = index; i < n; i++) {
            swap(s[index], s[i]);
            getPermutations(ans, s, index+1, n);
            swap(s[index], s[i]);
        }
    }
public:
    string getPermutation(int n, int k) {
        vector<string> ans;
        string s;
        int i = 1;
        for(char ch = '1'; i <= n; ch++, i++) {
            s.push_back(ch);
        }
        getPermutations(ans, s, 0, n);
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};


//Fourth Solution :- Using next permutation Code
bool nextPermutation(vector<int>& A){
	int n = A.size();
	int i = n - 2, j = n - 1;

	while (i >= 0 && A[i] >= A[i + 1]) 
		i--;

	if(i == -1) 
		return false;

	if (i != -1){
		while (j >= 0 && A[i] >= A[j]) 
			j--;
		swap(A[i], A[j]);
	}

	reverse(A.begin() + i + 1, A.end());
	return true;
}

string Solution::getPermutation(int A, int B) {
	vector<int> v;
	for(int i=1;i<=A;i++)
		v.push_back(i);

	if(B==1){  //If we do not write this then code will not run on N=2 and B=1
	    string s="";
	    for(auto i: v){
	        s += to_string(i); 
	    }
	    return s;
	}

	do{
	    B--;
	}
	while(nextPermutation(v) && B!=1);

	string s="";
	for(auto i: v){
	    s += to_string(i); 
	}

	return s;
}


//Fifth Solution :-
string Solution::getPermutation(int A, int B) {
    vector<int> numbers;
    if (A==0) return "";
    long long fact=1;
    int i_t=A+1,i;
    for (i=1;i<=A;i++){
        numbers.push_back(i);
        if (fact<=INT_MAX) fact*=i;
        else i_t=min(i,i_t);
    }
    i=i_t;
    B--;
    string ans="";
    for (int j=i;j<=A;j++){
        ans+=to_string(j-i+1);
        numbers.erase(numbers.begin());
    }
    for (i=i-1;i>0;i--){
        fact=fact/i;
        long long t=(long long)(B/fact);
        ans=ans+to_string(numbers[t]);
        numbers.erase(numbers.begin()+t);
        B=B%fact;
    }
    return ans;
}