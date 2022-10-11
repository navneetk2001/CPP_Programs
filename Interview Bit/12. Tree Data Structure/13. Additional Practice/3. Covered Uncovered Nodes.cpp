// You are given the root of a binary tree A, you need to return the absolute difference between sum of all covered elements and the sum of all uncovered elements.
// In a binary tree, a node is called Uncovered if it appears either on left boundary or right boundary. Rest of the nodes are called covered.

// Input 1:
//     2
//    / \
//   1   4
//  /   / \
// 6  10   5
// Output 1: 8
// Explanation 1: The node with value 10 is the only covered node. All other nodes are uncovered. Therefore, the absolute difference is |(10) - (2 + 1 + 4 + 6 + 5)| = 8

// Input 2:
//       1
//      /
//     2
//    /
//   3

// Output 2: 6
// Explanation 2: All the given nodes are uncovered. Hence, the answer is sum of given nodes - 6.


//Solution Approach :- 
// If we perform a level order traversal or a breadth first search,
// we can see that the first and last node of each level are uncovered nodes, the rest are covered.
// So, we keep two counters, one for uncovered and covered. Then, simply add the value in each counter
// respectively for each level, then return the absolute difference of the two.


//First Solution :-
long Solution::coveredNodes(TreeNode * A) {
    long cover = 0, uncover = 0;
    queue <TreeNode*>q;
    q.push(A);
    int level = 0;
    
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode * node = q.front();
            q.pop();
            
            if (i == 0 || i == n - 1) {
                uncover += node -> val;
            } 
            else {
                cover += node -> val;
            }
            if (node -> left != NULL){
                q.push(node -> left);
            }
            if (node -> right != NULL){
                q.push(node -> right);
            }
        }
    }
    return abs(cover - uncover);
}


//Second Solution :-
map<long, long> f, l;
long sum;
void rec(TreeNode* root, long lvl) {
    if(root==NULL) return;

    sum += root->val;

    if(f.find(lvl)==f.end()) {
    	f[lvl] = root->val;
    }
    else{ 
    	l[lvl] = root->val;
    }

    rec(root->left, lvl+1);
    rec(root->right, lvl+1);
}

long Solution::coveredNodes(TreeNode* A) {
    f.clear();
    l.clear();
    sum = 0;

    rec(A, 0);
    long usum = 0;
    for(auto i:f) {
    	usum += i.second;
    }
    for(auto i:l) {
    	usum += i.second;
    }

    return abs(sum-(2*usum));
}



//Third Solution :- 
long Solution::coveredNodes(TreeNode *A){
	long sum1 = 0;
	long sum2 = 0;
	queue<TreeNode *> q;
	q.push(A);
	
	while (!q.empty())
	{
		int cnt = q.size();
		TreeNode *tem = q.front();
		q.pop();

		sum1 += tem->val;
		if (tem->left){
			q.push(tem->left);
		}
		if (tem->right){
			q.push(tem->right);
		}

		for (int i = 1; i < cnt - 1; i++)
		{
			tem = q.front();
			q.pop();

			sum2 += tem->val;
			if (tem->left){
				q.push(tem->left);
			}
			if (tem->right){
				q.push(tem->right);
			}
		}
		if (cnt != 1)
		{
			tem = q.front();
			q.pop();

			sum1 += tem->val;
			if (tem->left){
				q.push(tem->left);
			}
			if (tem->right){
				q.push(tem->right);
			}
		}
	}
	return abs(sum1 - sum2);
}
