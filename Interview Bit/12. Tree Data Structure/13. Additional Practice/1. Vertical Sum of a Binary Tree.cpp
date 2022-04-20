// You are given the root of a binary tree A.
// You have to find the vertical sum of the tree.
// A vertical sum denotes an array of sum of the different verticals of a binary tree,
// where the leftmost vertical sum is the first element of the array and rightmost vertical is the last.

// Input 1:
// A =     1
//       /   \
//      2     3
//     / \   / \
//    4   5 6   7

// Input 2:
// A =     1
//        /
//       2
//      /
//     3

// Output 1: [4, 2, 12, 3, 7]
// Output 2: [3, 2, 1]

// Explanation 1:
// The element 4 is present in the leftmost vertical. 
// The middle vertical consists of 3 elements 1, 5, 6.
// The resultant array is [4, 2, 12, 3, 7].

// Explanation 2:
// The leftmost vertical is the element 3. The next verticals are 2 and 1.
// Hence, the resultant array is [3, 2, 1].


//Hint :-
How do we decide which element is present in which vertical?
How do we number the verticals?

//Solution Approach :- 
We need to check the Horizontal Distances from the root for all nodes. 
If two nodes have the same Horizontal Distance (HD), then they are on the same vertical line. 
HD for root is 0, a right edge (edge connecting to right subtree) is considered as 
+1 horizontal distance and a left edge is considered as -1 horizontal distance.

So, we just need to have a map, where we add elements to the HD value, then return the array in the end.
Refer to the complete solution for more details.


//First Solution :-
vector<int> Solution::verticalSum(TreeNode* A) {
	vector<int> ans;
	if (!A)
		return ans;
	map<int,int> m;
	queue<pair<TreeNode *, int>> q;
	q.push({A, 0});
	while (!q.empty()){
		TreeNode *curr = q.front().first;
		int h = q.front().second;
		q.pop();
		if (curr->left)
			q.push({curr->left, h - 1});
		if (curr->right)
			q.push({curr->right, h + 1});

		m[h]+=curr->val;
	}
	for (auto e : m){
		ans.push_back(e.second);
	}
	
	return ans;
}

//Second Solution :-
void find(TreeNode*root,map<int,int>&mp,int level)
{
     if(root==NULL)
     {
         return ;
     }
     mp[level]+=root->val;
     find(root->left,mp,level-1);
     find(root->right,mp,level+1);
 }
vector<int> Solution::verticalSum(TreeNode* root) 
{
    map<int,int>mp;
    find(root,mp,0);
    vector<int>ans;
    for(auto it:mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}



//Third Solution :- 
void recursive(TreeNode* A, int mid, int* arr){
    if(A==NULL)
        return;
    arr[mid]+=A->val;
    recursive(A->left, mid-1, arr);
    recursive(A->right, mid+1, arr);

}
vector<int> Solution::verticalSum(TreeNode* A) {
    int mid = 5000;
    int arr[10000]={0};
    int i=0;
    recursive(A, mid, arr);
    while(i< 10000 && arr[i]==0){
        i++;
        continue;        
    }
    vector<int> v;
    while(i<10000 && arr[i]!=0){
        v.push_back(arr[i]);
        i++;
    }
    return v;

}
