// Given a binary tree, return the reverse level order traversal of its nodes values. (i.e, from left to right and from last level to starting level).

// Input 1:
//     3
//    / \
//   9  20
//     /  \
//    15   7

// Output 1: [15, 7, 9, 20, 3] 

// Explanation 1:
//  Nodes as level 3 : [15, 7]
//  Nodes at level 2: [9, 20]
//  Nodes at level 1: [3]
//  Reverse level order traversal will be: [15, 7, 9, 20, 3]
 

//Hint :-
//Try modifying the normal level order travereal, think of using queue and stack.

//Solution Approach :- 
// Normal level order traversal can be easily modified to print level order traversal in reverse order.
// The idea is to use a stack to get the reverse level order.
// Suppose the Tree is:
//             1
//            / \
//           2   3
//          / \
//         4   5
// If we do normal level order traversal and instead of printing a node, push the node to a stack and then output contents of stack, we get “5 4 3 2 1” for above example tree, but output should be “4 5 2 3 1”.
// So to get the correct sequence (left to right at every level), we process children of a node in reverse order, we first push the right subtree to stack, then left subtree.


//First Solution :- Iterative and using reverse
void levelorder(TreeNode *root, vector<int> &ans){
	if(root==NULL){
		return;
	}

	queue<TreeNode *> q;
	q.push(root);

	while(!q.empty()){
		int count=q.size();
		for(int i=0;i<count;i++){
			TreeNode curr=q.front();
			q.pop();

			ans.push_back(curr->val);
			if(curr->right!=NULL){
				q.push(curr->right);
			}
			if(curr->left!=NULL){
				q.push(curr->left);
			}
		}
	}
}

vector Solution::solve(TreeNode* A) {
	vector<int> ans;
	TreeNode *root=A;
	levelorder(root,ans);
	reverse(ans.begin(),ans.end());
	return ans;
}


//Second Solution :-  Recursive and using map
void fxn(TreeNode* A, map<int,vector<int>> &m, int k){
	if(A==NULL){
		return;
	}

	m[k].push_back(A->val);
	fxn(A->left,m,k+1);
	fxn(A->right,m,k+1);
}

vector<int> Solution::solve(TreeNode* A) {
	vector<int>ans;
	map<int, vector<int>>m;
	
	fxn(A,m,0);
	int n=m.size();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m[n-1-i].size();j++){
			ans.push_back(m[n-1-i][j]);
		}
	}
	return ans;
}


//Third Solution :- without map, without reverse function
vector<int> Solution::solve(TreeNode* A) {
	vector<int>ans,subv;
	queue<pair<int, TreeNode*>> q;
	
	int x = 0;
	q.push({0, A});

	while(!q.empty()){
		TreeNode* n = q.front().second;
		int level = q.front().first;
		q.pop();
		
		if(level>x){
			x++;
			ans.insert(ans.begin(), subv.begin(), subv.end());
			subv.clear();
		}

		if(n->left){
			q.push({level+1, n->left});
		}

		if(n->right){
			q.push({level+1, n->right});
		}

		if(level==x){
			subv.push_back(n->val);
		}
	}

	ans.insert(ans.begin(), subv.begin(), subv.end());
	return ans;
}



//Fourth Solution :- Using 2 Queues
vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*> s,t;
    vector<int> v,vv;

    s.push(A);
    while(!s.empty()){
        TreeNode* temp = s.front();
        s.pop();

        v.push_back(temp->val);
        
        if(temp->left) {
        	t.push(temp->left);
        }

        if(temp->right) {
        	t.push(temp->right);
        }
        
        if(s.empty()){
            s.swap(t);
            vv.swap(v);

            for(int i=0;i<v.size();i++){
                vv.push_back(v[i]);
            }
            v.clear();
        }
    }
    return vv;
}



//Fifth Solution :-
// Do something like normal level order traversal order. Following are the
// differences with normal level order traversal
// 1) Instead of printing a node, we push the node to stack
// 2) Right subtree is visited before left subtree

vector<int> Solution::solve(TreeNode* A) {
    stack <TreeNode *> S;
    vector <TreeNode *> Q;
    Q.push_back(A);
    
    while (Q.size() != 0)
    {
        /* Dequeue node and make it root */
        TreeNode *temp = Q[0];
        //Q.pop();
        Q.erase(Q.begin());
        S.push(temp);

        /* Enqueue right child */
        if (temp->right){
            Q.push_back(temp->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
        }

        /* Enqueue left child */
        if (temp->left){
            Q.push_back(temp->left);
        }
    }

    // Now pop all items from stack one by one and print them
    vector<int> ans;
    while (S.empty() == false)
    {
        TreeNode *temp = S.top();
        ans.push_back(temp->val);
        S.pop();
    }
    return ans;
}