//Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.
//Return 1 to denote that two such nodes exist. Return 0, otherwise.

//Input 1:
//          10
//          / \
//         9   20
// B = 19

// Input 2:
//           10
//          / \
//         9   20
// B = 40

// Output 1:
//  1
// Output 2:
//  0


//Hint :-
How would you solve with O(N) memory? Let’s say you are given a sorted array and you need to find two indices i < j, such that A[i] = A[j]. Can you relate between a sorted array and a BST? Can you avoid O(N) memory and do with O(height) memory?

//Solution Approach :- 
How would you solve with O(N) memory? Let’s say you are given a sorted array and you need to find two indices i < j, such that A[i] = A[j]. Can you relate between a sorted array and a BST? Can you avoid O(N) memory and do with O(height) memory?
If you do inorder traversal of BST you visit elements in increasing order. So, we use a two pointer approach, where we keep two pointers pt1 and pt2. Initially pt1 is at smallest value and pt2 at largest value.
Then we compare sum = pt1.value + pt2.value. If sum < target, we increase pt2, else we decrease pt2 until we reach target.
Using the same concept used in https://www.interviewbit.com/courses/programming/topics/trees/problems/treeiterator/ we can do this.


//First Solution :- Inorder traversal will give sorted array and then find 2 sum
vector<int>res;
unordered_map<int,int>m;
void dfs(TreeNode* x){
    if(x==NULL){
        return ;
    }
    else{
        dfs(x->left);
        res.push_back(x->val);
        dfs(x->right);
    }
}

int Solution::t2Sum(TreeNode* A, int B) {
    m.clear(); res.clear();
    dfs(A);

    int i=0;
    int j=res.size()-1;
    while(i<j)
    {
        if((res[i]+res[j])>B)
            j--;
        else if(res[i]+res[j]<B)
            i++;
        else 
            return 1;
    }
    return 0;
}


//Second Solution :-
int ans;
void help(TreeNode* A,unordered_map<int,int> &m,int B)
{
	if(A==NULL) 
		return;

	if(m.find(B-A->val) != m.end()) 
		ans=1; 
		return;

	m[A->val]++;
	help(A->left,m,B);
	help(A->right,m,B);
}

int Solution::t2Sum(TreeNode* A, int B)
{
	ans=0;
	unordered_map<int,int> m;
	help(A,m,B);
	return ans;
}


//Third Solution :- Using BST Iterator
class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true; 
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
};


//Fourth Solution :- Iterative
int Solution::t2Sum(TreeNode* A, int B) 
{
     unordered_map<int,int> m;
     queue<TreeNode*> q;
     q.push(A);
	 while(!q.empty())
	 {
	    TreeNode *p=q.front();
	    q.pop();
	    int x=B-(p->val);
	    if(x>=0)
	    {
	        if(m.find(x)!=m.end())
	        return 1;
	    }
	    m[p->val]++;
	    if(p->left!=NULL)
	    q.push(p->left);
	    if(p->right!=NULL)
	    q.push(p->right);
	 }
	 return 0;
}