// Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.
// Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.

// Input 1:
// A = [2, 3]
// B = 3

// Input 2:
// A = [1, 4]
// B = 2

// Output 1:
// 7
// Output 2:
// 7

// Explanation 1:
// 	First you serve the seat with number = 3. Then with 2 and then with 2. hence answer = 3 + 2 + 2 = 7.
// Explanation 2:
//  	You give bith tickets from the row with 4 seats. 4 + 3 = 7.

//Hint :-
You see that at each time, you need to give out the seat
from the row woth maximum number of people. how can this be simulated??

//Solution Approach :- 
You can use a heap or a priority_queue to maintain the number of seats left in each of the
rows. Then you can for each person to be served, pop the item
and add this to the cost and update the number of seats left in this row.
All the persons can be sold a seat ticket until there are vacant seats.


//First Solution :-
int Solution::solve(vector<int> &A, int B) {
	int ans=0;
	priority_queue<int>pq;

	for(int i=0;i<A.size();i++){
		pq.push(A[i]);
	}

	while(B!=0){
	    int k = pq.top();
	    pq.pop();
	    ans+=k;
	    k--;
	    pq.push(k);
	    B--;
	}

	return ans;
}


//Second Solution :-
int Solution::solve(vector<int> &A, int B) {
	sort(A.begin(), A.end());
	auto it = A.end();
	int res = 0;
	for(int i=0;i<B;++i) {
		if (it == A.end())
			it = lower_bound(A.begin(), A.end(), A.back());

			auto& val = *it;
			res += val;
			--val;
			++it;
	}
	return res;
}

//Third Solution :- 
int Solution::solve(vector<int> &A, int B) {
    make_heap(A.begin(), A.end());
    int cnt = 0, prof = 0;
    while(cnt < B){
        pop_heap(A.begin(), A.end());
        int l = A.back();
        A.pop_back();
        prof += l;
        cnt++;
        if(l > 0){
            A.push_back(l-1);
            push_heap(A.begin(), A.end());
        }
    }
    return prof;
}

