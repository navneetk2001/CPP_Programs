The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.

//Hint :-
The bruteforce method would be to start with 0, change any of the bits, keeping track of the numbers already constructed. When you run into a number where there is no way forward possible, you backtrack, and try to change some other bit instead.
This might however be inefficient.
You need to come up with something smart this time.
You can notice that if a sequence is gray code, then its reverse is also a gray code. How can you use this to construct the solution?

//Solution Approach :- 
Note the following :

Let G(n) represent a gray code of n bits.
Note that reverse of G(n) is also a valid sequence.
Let R(n) denote the reverse of G(n).

Note that we can construct
G(n+1) as the following :
0G(n)
1R(n)

Where 0G(n) means all elements of G(n) prefixed with 0 bit and 1R(n) means all elements of R(n) prefixed with 1.
Note that last element of G(n) and first element of R(n) is same. So the above sequence is valid.

Example G(2) to G(3) :
0 00
0 01
0 11
0 10
1 10
1 11
1 01
1 00


//First Solution :-
vector<string> generate(int n){
    if(n==1){
        return {"0","1"};
    }

    vector<string> ans;
    vector<string> temp = generate(n-1);   //store the graycode value of n-1 in temp and then add first 1 at beginning and then 0 at the beginning
    
    for(int i=0;i<temp.size();i++)     //add 0 at beginning
    {
        ans.push_back("0"+temp[i]);
    }
    
    for(int i=temp.size()-1;i>=0;i--)    //add 1 at beginning
    {
        ans.push_back("1"+temp[i]);
    }
    return ans;
}


vector<int> Solution::grayCode(int n) {
    vector<string> grayString = generate(n);
    vector<int> ans;
    for(auto i:grayString)
    {
        ans.push_back(stoi(i,0,2));
    }
    return ans;
}



//Second Solution :-
vector<int> grayCode(int n)
{
    int size = 1 << n;
    vector<int> result(size);
    for(int i = 0; i < size; ++i)
    {
        result[i] = i;
    }
    
    for(int i = 2; i < size; i*=2)
    {
        for(int j = i; j < size; j += i*2)
            reverse(result.begin() + j, result.begin() + j + i);            
    }
    return result;
}


//Third Solution :- 
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1) return {0,1};
        
        vector<int> p= grayCode(n-1);
        vector<int> q=p;reverse(q.begin(),q.end());
        int inc= 1<<(n-1);
        for(auto &i : q) i+=inc;
        p.insert(p.end(),q.begin(),q.end());
        
        return p;
    }
};


//Fourth Solution :-
class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int>result;
        result.push_back(0);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=result.size()-1;j>=0;j--)
            {
                result.push_back(1<<(i-1)|result[j]);
            }
        }
        
        return result;
    }
};