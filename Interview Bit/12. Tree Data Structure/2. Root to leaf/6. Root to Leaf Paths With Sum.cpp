// Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.
// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

//Hint :-
Hint : Think recursion.
What if in your recursive function, you already know about the sum till the current node.
GOTCHAS :
If you are using C++, make sure to pass the array by reference.

//Solution Approach :- 
Recursion might make this problem much easier to solve.
You just need to keep a track of :
1) the sum from the root to the current node.
2) The elements encountered from the root to this node.
Then it becomes a question of just checking if the current node is a leaf node, and if so, do the sum match.
If sums match, then you append the current elements from root to this node to the answer list.

Check for a node being a leaf :
  node->left == NULL && node->right == NULL


//First Solution :-
void DFS(TreeNode* A ,vector<int> val,vector<vector<int>> &final){
    if(!A){
        return ;
    }
    val.push_back(A->val);
    if(!A->left && !A->right){
        final.push_back(val);
    }
    DFS(A->left,val,final);
    DFS(A->right,val,final);
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> final;
    if(!A){
        return final;
    }
    vector<int> val;
    DFS(A,val,final);
    vector<vector<int>> ans;
    for(auto x:final){
        int sum = 0;
        for(auto y:x){
            sum+=y;
        }
        if(sum==B){
            ans.push_back(x);
        }
    }
    return ans;
}

//Second Solution :-
void helper(TreeNode *root,int curr,int B,vector<int>tmp,vector<vector<int>>&ans)
{
    if(!root)
    {
        return;
    }
    curr+=root->val;
    tmp.push_back(root->val);
    if(!root->left && !root->right && curr==B)
    {
        ans.push_back(tmp);
        return;
    }
    helper(root->left,curr,B,tmp,ans);
    helper(root->right,curr,B,tmp,ans);
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<int>>v;
    helper(A,0,B,{},v);
    return v;
}


//Third Solution :- 
Stack temp=new Stack();
public void sum(TreeNode A, int B, ArrayList<ArrayList> ans)
{
	if(A==null)
	{
	return;
	}
	ArrayList inter=new ArrayList();
	temp.push(A.val);
	//System.out.println(A.val);
	sum(A.left,B,ans);
	int sum1=0;
	if(A.left==null && A.right==null)
	{
	Iterator value = temp.iterator();
	while (value.hasNext()) {
	sum1+=value.next();
	}
	// System.out.println(“sum”+sum1);
	if(sum1==B)
	{
	for (Integer item: temp)
	{
	inter.add(item);
	}
	ans.add(inter);
	}
	}
	sum(A.right,B,ans);
	temp.pop();

}

   
public ArrayList<ArrayList<Integer>> pathSum(TreeNode A, int B) {
     ArrayList<ArrayList<Integer>> ans=new ArrayList<ArrayList<Integer>>();
    
    sum( A,B,ans);
    return ans;
}

