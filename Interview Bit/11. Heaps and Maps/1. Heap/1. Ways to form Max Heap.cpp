// Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes.
// Find the number of distinct Max Heap can be made from A distinct integers.
// In short, you have to ensure the following properties for the max heap :
// Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
// Every node is greater than all its children.
// NOTE:  If you want to know more about Heaps, please visit this link. Return your answer modulo 109 + 7.

// Input 1:             Output 1:
//  A = 4                  3

// Input 2:        Output 2:
//  A = 10           3360

// Explanation 1:
//  Let us take 1, 2, 3, 4 as our 4 distinct integers
//  Following are the 3 possible max heaps from these 4 numbers :
//       4           4                     4
//     /  \         / \                   / \ 
//    3    2   ,   2   3      and        3   1
//   /            /                     /

//  1            1                     2

// Explanation 2:
//  Number of distinct heaps possible with 10 distinct integers = 3360.

//Hint :-
Verify if the following is true :
The structure of the heap tree will be fixed.
Given the numbers in a subtree, the root value is going to be fixed.
Are the numbers in left and right subtree independent of each other?

//Solution Approach :- 
Suppose there are n distinct elements to be used in Max heap. Now it is for sure that the maximum element among this n distinct element will surely be placed on the root of the heap.
Now there will be remaining (n-1) elements to be arranged.
Now point to be remembered here is that the structure of the heap will remain the same. That is only the values within the node will change however the overall structure remaining the same.
As structure of the heap remains the same, the number of elements that are present in the left sub-tree of the root (L) will be fixed. And similarly the number of the elements on the right sub-tree (R) of the root. And also following equality holds .
L + R = (n-1)
Now as all the remaining (n-1) elements are less than the element present at the root(The Max Element), whichever L elements among ‘n-1` elements we put in the left sub-tree, it doesn’t matter because it will satisfy the Max Heap property.
So now there are (n-1)CL ways to pickup L elements from (n-1) elements. And then recurse the solution.
So final equation will be as follows :
(n-1)CL * getNumberOfMaxHeaps(L) * getNumberOfMaxHeaps(R)

So now the question remains only of finding L for given n. It can be found as follows:
Find the height of the heap h = log2(n)
Find the max number of elements that can be present in the hth level of any heap . Lets call it m. m = 2h
Find the number of elements that are actually present in last level(hth level) in heap of size n. Lets call it p. p = n - (2h - 1)
Now if the last level of the heap is more than or equal to exactly half filled, then L would be 2h - 1
However if it is half filled then it will reduced by the number of elements in last level left to fill exactly half of the last level.
So final equation for L will be as follows :
L = 2h - 1 if p >= m/2
                    = 2h - 1 - (m/2 - p) if p<(m/2)



//First Solution :-
int dp[101];
long ncr[101][101];
int lg2[101];
int mod=1e9 +7;

long findncr(int n,int r){
    if(r>n)return 0;
    if(n<=1)return 1;
    if(r==0)return 1;
    if(r==1)return n;
    if(ncr[n][r]!=-1)return ncr[n][r];
    return ncr[n][r]=(findncr(n-1,r-1) + findncr(n-1,r) )%mod;
}

int findl(int n){
    if(n==1)return 0;
    int h=lg2[n];
    int node=(1<<h);
    int realnode=(n-((1<<h) -1));
    if(realnode>= (node/2))
    return node-1;
    return node-1-(node/2-realnode);
}

int func(int n){
    if(n<=1)return 1;
    if(dp[n]!=-1)return dp[n];
    int l=findl(n);
    long mul=findncr(n-1,l)%mod;
    long res= ( ( (mul * func(l) )%mod ) *func(n-l-1) )%mod;
    return dp[n]=res;
}

int Solution::solve(int A) {
    if(A==1)return 1;
    memset(dp,-1,sizeof dp);
    memset(ncr,-1,sizeof ncr);
    int currlog=1,currval=-1;
    for(int i=1;i<=A;i++){
        if(i==currlog){
            currlog*=2;
            currval++;
        }
        lg2[i]=currval;
    }
    return func(A);
}


//Second Solution :-
#define MOD ((int)1e9 + 7)
#define ll long long

int Solution::solve(int n) {
    ll ans[n + 1] = {0};
    memset(ans, 0, sizeof(ans));
    ll c[n][n];
    memset(c, 0, sizeof(c));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0){
            	c[i][j] = 1;
            	continue;
            }
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
        }
    }
    ans[0] = 1;
    for(int i = 1; i <= n; i++){
        ll total_nodes = 0; // all the nodes assuming perfect and complete binary tree
        ll level = 1;
        ll complete_nodes = 0; // all the nodes with full levels
        ll current_nodes = i - 1; // leaving the top element, as it is the largest
        while(total_nodes < current_nodes){
            complete_nodes = total_nodes;
            total_nodes += (1 << level);
            level++;    
        }
        ll left_nodes = 0, right_nodes = 0;
        ll last_nodes = current_nodes - complete_nodes;
        ll last_full_nodes = (total_nodes - complete_nodes);
        if(last_nodes >= last_full_nodes/2){
            left_nodes = last_full_nodes/2;
            right_nodes = (current_nodes - complete_nodes - last_full_nodes/2);
        }
        else{
            left_nodes = current_nodes - complete_nodes;
            right_nodes = 0;
        }
        left_nodes += complete_nodes / 2;
        right_nodes += complete_nodes / 2;
        ans[i] = c[current_nodes][left_nodes];
        ans[i] = (ans[i] * ans[left_nodes])%MOD;
        ans[i] = (ans[i] * ans[right_nodes])%MOD;
    }
    return ans[n];
}


//Third Solution :- 


