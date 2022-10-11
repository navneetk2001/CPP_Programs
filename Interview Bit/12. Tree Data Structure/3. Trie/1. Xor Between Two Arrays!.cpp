// Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.
// Return this maximum xor value.

// Input 1:
//  A = [1, 2, 3]
//  B = [4, 1, 2]
// Output 1: 7
// Explanation 1: Pick A[2] and B[0] because their xor value is maximum. 3 ^ 4 = 7


//Hint :-
// We can use trie to get maximum xor of any element with other elements already inserted in trie.
// Try to use the above fact to find a solution to the problem.

//Solution Approach :- 
// You should use a Trie data structure here:
// Create a binary trie using all the elements of the second array. Start with the Most Significant Bit and head towards the Least Significant Bit.
// Each non-leaf node of the trie has 1-2 children. Going down the left child is like getting a bit equal to zero, right means getting a one.
// Initialise result to zero, maximum to -infinity.
// For each element of the first array
// Set BIT = MSB of this element. Go to the root of the trie.
// If there is only one child, follow it.
// Else
// If the element_bit is 1, follow the left child. This will give the maximum xor.
// Else, follow the right child.
// When following a child pointer, set the bit at BIT of result to (child_pointer ^ element_BIT_bit).
// Decrement BIT and go back to point a, as long as BIT>=0.
// If the result is greater than maximum, set maximum to result.
// Output maximum.
// The time complexity is O(max(A.size(),B.size())).


//First Solution :-
struct Trie
{
    int val;
    Trie *child[2];
    Trie()
    {
        val=0;
        child[0]=NULL;
        child[1]=NULL;
    }
};

void insert(Trie *root,int n)
{
    Trie *p=root;
    for(int i=31;i>=0;i--)
    {
        int bit=1&(n>>i);
        if(!p->child[bit])
          p->child[bit]=new Trie();
        p=p->child[bit];  
    }
    p->val=n;
}

int query(Trie *root,int n){
    Trie *p=root;
    for(int i=31;i>=0;i--)
    {
        int bit=1&(n>>i);
        if(bit==0)
        {
            if(p->child[1])
              p=p->child[1];
            else
              p=p->child[0];
        }
        else
        {
            if(p->child[0])
              p=p->child[0];
            else
              p=p->child[1];
        }
    }
    return n^p->val;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    Trie *root=new Trie();
    for(auto x:A){
      insert(root,x);
    }
    int res=0;  
    for(auto x:B){
        res=max(res,query(root,x));
    }  
    return res;
}


//Second Solution :-
struct Node {
    Node* left;
    Node* right;
};

class MaxXorHelper{
  private : Node* root;    
  public :
    MaxXorHelper() {
        root = new Node();
    }

    void addElements(vector<int> &arr) {
        for(int i=0; i<arr.size(); i++) {
            Node* node = root;
            int val = arr[i];
            for(int j=31; j>=0; j--) {
                int bit = (val >> j) & 1;

                if(bit == 0) {
                    if(!node->left) {
                        node->left = new Node();
                    }
                    node = node->left;
                } 
                else {
                    if(!node->right) {
                        node->right = new Node();
                    }
                    node = node->right;
                }
            }
        }
    }

    int findMaxXor(vector<int> &arr) {
        int maxXor = INT_MIN;
        for(int i=0; i<arr.size(); i++) {
            Node* node = root;
            int val2 = 0;
            int val1 = arr[i];
            for(int j=31; j>=0; j--) {
                int bit = (val1 >> j) & 1;

                if(bit == 0) {
                    if(node->right) {
                        val2 |= (1 << j);
                        node = node->right;
                    }
                    else{
                        node = node->left;
                    } 
                }
                else {
                    if(node->left) {
                        node = node->left;
                    } 
                    else{
                        val2 |= (1 << j);
                        node = node->right;
                    }
                }
            }
            int curXor = val1 ^ val2;
            maxXor = max(maxXor, curXor);
        }
        return maxXor;
    }
};

int Solution::solve(vector<int> &A, vector<int> &B) {
    MaxXorHelper helper;
    helper.addElements(A);
    return helper.findMaxXor(B);
}



//Third Solution :- 
#include&lt;bitset&gt;

int Solution::solve(vector&lt;int&gt; &amp;A, vector&lt;int&gt; &amp;B) {
    int ans = 0;
    int A_or, A_and, B_or, B_and;

    A_or = A[0];
    A_and = A[0];
    B_or = B[0];
    B_and = B[0];

    for(int i=1; i&lt;A.size(); i++) {
        A_or = A_or | A[i];
        A_and = A_and &amp; A[i];
    }

    for(int i=1; i&lt;B.size(); i++) {
        B_or = B_or | B[i];
        B_and = B_and &amp; B[i];
    }

    for(int i=0; i&lt;32; i++) {
        int a = B_or&amp;(1&lt;&lt;i);
        int b = A_or&amp;(1&lt;&lt;i);
        int c = B_and&amp;(1&lt;&lt;i);
        int d = A_and&amp;(1&lt;&lt;i);
        
        if(a==(1&lt;&lt;i) &amp;&amp; d==0) {
        	ans +=(1&lt;&lt;i);
        }
        else if(b==(1&lt;&lt;i) &amp;&amp; c==0) {
        	ans+=(1&lt;&lt;i);
        }
    }
    
    return ans;
}





