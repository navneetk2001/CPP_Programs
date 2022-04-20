// Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.
// Find the maximum number of chocolates that kid can eat in A units of time.
// NOTE: 
// floor() function returns the largest integer less than or equal to a given number.
// Return your answer modulo 10^9+7

// Input 1:
//  A = 3
//  B = [6, 5]

// Output 1:
//  14

// Explanation 1:
//  At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates. 
//  At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates. 
//  At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate. 
//  so, total number of chocolates eaten are 6 + 5 + 3 = 14


//Hint :-
It is quite trivial to figure out that the kid will always choose the bag with the maximum number of chocolates.
By knowing this fact, how would you solve the problem ?

//Solution Approach :- 
The solution to this problem can be found greedily. At any time t, the kid will always choose the bag with the maximum number of chocolates and consume all it’s chocolates.
So we need to maintain the current maximum size among all bags for every time t = 1, … , K and also updating the sizes of the bags.
This can be done using a max heap : https://en.wikipedia.org/wiki/Min-max_heap


//First Solution :-
const int mod = 1000000007;
int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int>g;

    for(int i=0;i<B.size();i++){
        g.push(B[i]);
    }

    int ans=0;
    int mod=1000000007;

    for(int i=0;i<A;i++){
        int x=g.top();
        ans=(ans%mod)+(x%mod);
        ans=ans%mod;
        g.pop();
        g.push(x/2);
    }
    return ans;
}


//Second Solution :-
long long int mod = 1000000007;
int Solution::nchoc(int A, vector<int> &B) {
	int N = B.size();
	int K = A;
	long long int ans = 0;
	priority_queue<int> heap(B.begin(),B.end());
	while(K--){
		long long int max_elem = heap.top();
		ans += max_elem;
		ans = ans % mod;
		heap.pop();
		heap.push((int)(max_elem/2));
	}   
	return ans;
}

