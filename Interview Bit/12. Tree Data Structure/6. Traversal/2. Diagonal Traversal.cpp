// Consider lines of slope -1 passing between nodes.
// Given a Binary Tree A containing N nodes, return all diagonal elements in a binary tree belonging to same line.

// NOTE:
// See Sample Explanation for better understanding.
// Order does matter in the output.
// To get the same order as in the output traverse the tree same as we do in pre-order traversal.

// Input 1:
//             1
//           /   \
//          4      2
//         / \      \
//        8   5      3
//           / \    /
//          9   7  6
// Input 2:
//              11
//           /     \
//          20      12
//         / \       \
//        1   15      13
//           /  \     /
//          2    17  16
//           \   /
//           22 34

// Output 1: [1, 2, 3, 4, 5, 7, 6, 8, 9]
// Output 2: [11, 12, 13, 20, 15, 17, 16, 1, 2, 22, 34]


//Hint :-
Try to think in terms of hashing. Like hashing nodes at each slope and traversing the tree.
Perform a pre-order traversal of the tree A and keep hashing the nodes.

//Solution Approach :- 
// The idea is to use map. We use different slope distances and use them as key in map. Value in map is vector (or dynamic array) of nodes. We traverse the tree to store values in map. Once map is built, we print contents of it.

// Suppose slope at current node is x then:
// a) The slope of it’s right child remains same i.e x
// b) The slope of it’s left child becomes x + 1

// As the order in the output matters so we have to move in the pre-order traversal format in the tree A i.e
// 1)Process the root push root to map[slope(root)].push(root)
// 2)Go to left child
// 3)Go to right child
// Keep repeating the above steps until the whole tree is traversed.

// Time Complexity : O(N)


//First Solution :- Using Queue
vector<int> Solution::solve(TreeNode* root) {
    vector<int>ans;
    if(!root){ 
        return ans;
    }

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        while(temp){
            if(temp->left){
                q.push(temp->left);  //Push left of curr node in queue 
            }
            ans.push_back(temp->val); //Push data of each node in vector
            temp=temp->right;         //Move to right of current node for diagonal traversal
        }
    }
    return ans;
}


//Second Solution :- Using Map (Recursion)
void diagonalView(TreeNode* root, int d, map<int,vector<int>>& m){
    if(!root){
        return;
    }
    m[d].push_back(root->val);
    diagonalView(root->left,d+1,m);
    diagonalView(root->right,d,m);
}

vector<int> Solution::solve(TreeNode* root) {
    vector<int>v;
    if(root==NULL){
        return v;
    }

    map<int,vector<int>> m;
    diagonalView(root,0,m);

    for(auto& it:m){
        for(auto& data:it.second){
            cout<<data<<" ";
        }
    }
}


//Third Solution :- Using Stack
vector<int> Solution::solve(TreeNode* A) {
    vector<int> v;
    if(A == nullptr) 
    	return v;

    map<int, vector<int>> mp;

    stack<pair<TreeNode*, int>> st;
    st.push({A, 0});

    while(!st.empty()) {
        TreeNode* temp = st.top().first;
        int count = st.top().second;
        
        mp[count].push_back(temp->val);

        st.pop();

        if(temp->right != nullptr || temp->left != nullptr) {
            if(temp->right != nullptr) {
                st.push({temp->right, count});
                temp->right = nullptr;
            }

            if(temp->left != nullptr) {
                st.push({temp->left, count + 1});
                temp->left = nullptr;
            }
        }

        free(temp);
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            v.push_back(it->second[i]);
        }
    }
    return v;    
}


