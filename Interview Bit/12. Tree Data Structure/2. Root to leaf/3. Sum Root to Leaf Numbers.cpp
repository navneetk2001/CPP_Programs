// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers % 1003.
// Example :
//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.


//Hint :-
Can you traverse the tree while keeping the number%1003 from root to current node?
How can you check if you have reached the leaf or not?

//Solution Approach :- 
Think recursion.
Carrying along the number formed from root to the node when calling the function for node, will make stuff easier for you. When you encounter a new digit, you can append it to existing one as newNum = oldNum * 10 + newDigit.


//First Solution :-
void dfs(TreeNode *root,int curr, int &ans)
{
    if(!root)
        return;
    curr = (curr * 10 + root->val)%1003;
    if(!root->left && !root->right)
    {
        ans+=curr;
        ans%=1003;
        return;
    }
    dfs(root->left,curr,ans);
    dfs(root->right,curr,ans);
}

int Solution::sumNumbers(TreeNode* A) {
    if(!A)
        return 0;
    int ans=0;
    dfs(A,0,ans);
    return ans;
}

//Second Solution :-
class Solution {
    public:
        int sumNumbers(TreeNode *root, int curSum) {
            if (root == NULL) return curSum;
            curSum = (curSum * 10 + root->val) % 1003;
            if (root->left == NULL && root->right == NULL) return curSum;
            if (!root->left) return sumNumbers(root->right, curSum);
            if (!root->right) return sumNumbers(root->left, curSum);
            return (sumNumbers(root->left, curSum) + sumNumbers(root->right, curSum)) % 1003;
        }
        
        int sumNumbers(TreeNode *root) {
            return sumNumbers(root, 0); 
        }
};


//Third Solution :- Iterative using Stack
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) 
        	return 0;
        
        int t = 0, res = 0;
        stack<pair<TreeNode*, int>> s;
        auto node = root;
        s.push({node,0});
        while(!s.empty()){
            node = s.top().first;
            t = s.top().second;
            s.pop();
            if(node){
                t = t*10 + node->val;
                if(!node->left && !node->right) res+=t;
                else{
                    if(node->right) s.push({node->right, t});
                    if(node->left) s.push({node->left, t});
                }
            }
        }
        return res;
    }
};


//Fourth Solution :- Iterative using Queue
int sumNumbers(TreeNode* root) {
    int answer=0;
    queue<TreeNode*> q; // standard bfs queue
    q.push(root); // initialize queue
	
    while(q.size()) {
        int size=q.size();
        while(size--) { // iterating through elements in the current level
            TreeNode* top=q.front();
            q.pop();
            if(!top->left && !top->right) { // if leaf
				answer+=top->val; // add the value to answer
			}
            if(top->left) { // if has left (i.e., not leaf)
				top->left->val+=top->val*10; // left = curr * 10 + left (appending the digit)
				q.push(top->left);
			}
            if(top->right) { // if has right (i.e., not leaf)
				top->right->val+=top->val*10; // right = curr * 10 + right (appending the digit)
				q.push(top->right);
			}
        }
    }
    return answer;
}