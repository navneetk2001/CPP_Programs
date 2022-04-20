// Given a Binary Tree A containing N nodes.
// You need to find the path from Root to a given node B.
// NOTE:
// No two nodes in the tree have same data values.
// You can assume that B is present in the tree A and a path always exists.

// Input 1:
// A =
//            1
//          /   \
//         2     3
//        / \   / \
//       4   5 6   7 
// B = 5
// Output 1:
//  [1, 2, 5]

//Hint :-
Create a recursive function that traverses the different path in the binary tree to find the required node x.
If node x is present then it returns true and accumulates the path nodes in some array arr[]. Else it returns false.

This recursive function can be accessed from other function to check whether node x is present or not and if it is present, then the path nodes can be accessed from arr[].
You can define arr[] globally or pass its reference to the recursive function.

//Solution Approach :- 
Approach: Create a recursive function that traverses the different path in the binary tree to find the required node x.
If node x is present then it returns true and accumulates the path nodes in some array arr[]. Else it returns false.

Following are the cases during the traversal:
If root = NULL, return false.
Push the root’s data into arr[].
if root’s data = x, return true.
if node x is present in root’s left or right subtree, return true.
Else remove root’s data value from arr[] and return false.
This recursive function can be accessed from other function to check whether node x is present or not and if it is present, then the path nodes can be accessed from arr[].
You can define arr[] globally or pass its reference to the recursive function.
Time complexity: O(N) in worst case, where N is the number of nodes in the binary tree.


//First Solution :-
void helper(TreeNode* A, int B, vector<int>&ans){
    if(A==NULL) return;
    ans.push_back(A->val);
    helper(A->left,B,ans);

    if(ans.back()==B) return;
    helper(A->right,B,ans);
    if(ans.back()==B) return;
    ans.pop_back();
    return;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    helper(A,B,ans);
    return ans;
}


//Second Solution :-
bool getPath(TreeNode *root, vector<int> &arr, int x) {
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root->val);   
     
    // if it is the required node
    // return true
    if (root->val == x)   
        return true;
     
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;
     
    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
    arr.pop_back();
    return false;  
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr; 
    if(A == NULL) {
        return arr; 
    }
    getPath(A, arr, B);
    return arr; 
}


//Third Solution :-
bool check(TreeNode* root,stack<int> &st,int B){
    if(root==NULL){
        return false;
    }
    st.push(root->val);
    if(root->val==B){
        return true;
    }
    if(check(root->left,st,B) || check(root->right,st,B)){
        return true;
    }
    st.pop();
    return false;
} 

vector<int> Solution::solve(TreeNode* A, int B) {
    stack<int> st;
    check(A,st,B);
    vector<int> res(st.size());
    int i=st.size()-1;
    while(st.empty()!=true){
        res[i]=st.top();
        st.pop();
        i--;
    }
    return res;
    
}


//Fourth Solution :- 
vector<int> ans;
int val;

bool dfs(TreeNode* cur){
    if(cur == nullptr) return false;

    if(dfs(cur->left) || dfs(cur->right) || cur->val == val){
        ans.push_back(cur->val);
        return true;
    }

    return false;
}

void clear(TreeNode* cur){
    if(cur){
        clear(cur->left);
        clear(cur->right);
        delete cur;
    }
}

vector<int> Solution::solve(TreeNode* A, int B) {
    ans.clear();
    val = B;
    dfs(A);
    clear(A);
    reverse(ans.begin(), ans.end());
    return ans;
}


