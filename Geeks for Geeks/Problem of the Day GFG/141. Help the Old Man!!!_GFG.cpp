// A poor old man works in a palace for a living. One day the old man's wife met with an accident. She needed an immediate operation but the old man's savings were not enough for the operation. He went running to the king to beg for money. The king told that he will not only pay the full amount for the operation but also double his salary. But for that the old man had to pass a test. The king showed him a pile of glass plates kept one above another, each one being smaller than the one beneath. The plates were kept in box 1. He had to transfer the plates to box 3 using box 2. However, there were some constraints. The old man could only take one plate at a time and he could only place a smaller plate on top of a larger plate. He could take a plate only from the top. Help the old man do so. There are N plates and he has to tell the nth move in the format (i, j) where a plate is being moved from ith box to jth box.

// Note:
// Given any number of plates, they can be transferred from box 1 to box 3 using box 2 using the following steps.
// Step 1: Transfer first N-1 plates from box 1 to box 2 using box 3.
// Step 2: Transfer the remaining plate from box 1 to box 3.
// Step 3: Transfer the first N-1 plates from box 2 to box 3 using box 1.

// Example 1:
// Input: N = 2, n = 2
// Output: 1 3
// Explaination:  The plate on top of box 1 is first transferred to box 2. The second plate from box 1 is transferred to box 3 and finally the plate from box 2 is transferred to box 3. 
// In each situation, all the constraints are satisfied. You are required to print the 2nd move which is "Move plate from box 1 to box 3", hence 1 3.

// Example 2:
// Input: N = 3, n = 4.
// Output: 1 3
// Explaination: The movements of plates will be from 1 to 3. Then from 1 to 2. Then from 3 to 2. And finally 4th move from 1 to 3.



//Solution Aproach :- This is simply tower of hanoi question
// Transferring plates from box1 to box3 has 3 steps:

// Transfer top (n-1) plates from box1 to box2.
// Transfer largest bottom plate on box1 to box3. As this is the largest plate, it wont bother other plates when placed over it.
// Transfer top (n-1) plates we put on box2 to box3.

// keep count of step no 2 we perform, when it is equal to n, push to answer and return.
// Base condition is if we have already found n steps or no of plates (np) is 0

class Solution{
public:
    vector<int> shiftPile(int N, int n){
        vector<vector<int>> v;
        help(1,3,2,v,N);
        return v[n-1];
    }

    void help(int src, int dest , int helper ,vector<vector<int>> &v ,int n ){
        if(n==0){
        	return;
        }
        help(src, helper, dest, v, n-1);
        v.push_back({src , dest});
        help(helper, dest, src, v, n-1);
    }
};



//Second Solution :-
int pvt;
vector<int>ans;

vector<int> shiftPile(int N, int n){
    pvt=n;
    
    toh(N,1,2,3);
    return ans;
    
}

void toh(int disc,int s, int m,int e){
    if(disc==0){
    	return;
    }
    if(disc>1){
    	toh(disc-1,s,e,m);
    }
    --pvt;
    if(pvt==0){
    	ans={s,e};
    }
    if(disc>1){
    	toh(disc-1,m,s,e);
    }
}


