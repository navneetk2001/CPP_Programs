// You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.
// Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.
// NOTE:  if B > N, return an empty array.

// Input 1:
//  A = [1, 2, 1, 3, 4, 3]
//  B = 3

// Output 1:
//  [2, 3, 3, 2]
// Explanation 1:
//  A=[1, 2, 1, 3, 4, 3] and B = 3
//  All windows of size B are
//  [1, 2, 1]
//  [2, 1, 3]
//  [1, 3, 4]
//  [3, 4, 3]
//  So, we return an array [2, 3, 3, 2].
 
//Hint :-
If you have solution for window [i, i+k-1], can you quickly build solution for window [i+1, i+k], using some data structure?
What could be this data structure? A data structure which can store distinct elements(and their count?)?

//Solution Approach :- 
If you have solution for window [i, i+k-1], can you quickly build solution for window [i+1, i+k]?
If we have a data structure where we can maintain count of all keys and number of distinct keys, then we just have to reduce count of key A[i] and increasing count of A[i+k]. If count of some key has been reduced to zero, we need to remove that key.
This structure is a hashmap. All operations that we have said a constant time in it.


//First Solution :-
vector<int> Solution::dNums(vector<int> &A, int B) {
	unordered_map<int,int> m;
	vector<int> ans;
	for(int i=0;i<B;i++){
	    m[A[i]]++;
	} 

	ans.push_back(m.size());
	for(int i=B;i<A.size();i++){
	    m[A[i-B]]–;
	    if(m[A[i-B]]==0) m.erase(A[i-B]);
	    m[A[i]]++;
	    ans.push_back(m.size());
	}

	return ans;
}


//Second Solution :-
vector<int> Solution::dNums(vector<int> &A, int B) {
    assert(B<=A.size());
    int n=A.size();
    vector<int> ret;
    unordered_map <int, int> m;
    for(int i=0; i<n; i++){
        m[A[i]]++;   //increase key
        if(i-B+1>=0){
            ret.push_back(m.size());   //decrease key
            m[A[i-B+1]]--;
            
            if(m[A[i-B+1]]==0)     //remove if count becomes 0
            	m.erase(A[i-B+1]);   
        }
    }
    return ret;
}


//Third Solution :- 
vector<int> Solution::dNums(vector<int> &A,int B) {
	vector<int>ans;
	unordered_map<int,int>map;
	int i=0;
	int j=0;
	int n=A.size();
    while(j<n){
        map[A[j]]++;

        if(j-i+1<B){
            j++;
        }
        else if(j-i+1==B){
            ans.push_back(map.size());
            if(map.find(A[i])!=map.end()){
                map[A[i]]--;
                if(map[A[i]]==0)
                    map.erase(A[i]);
                    i++;
            }
            j++;
        }
    }
    return ans;
}



