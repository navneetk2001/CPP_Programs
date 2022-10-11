// Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.
// Go through the example and image for more details.

// NOTE:
// 	If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the level-order traversal of tree comes first in the output.
// 	Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the nodes on the rightmost vertical line.

// Input 1:
//       6
//     /   \
//    3     7
//   / \     \
//  2   5     9

// Output 1:
//  [
//     [2],
//     [3],
//     [6, 5],
//     [7],
//     [9]
//  ]

// Explanation 1:
//  Nodes on Vertical Line 1: 2
//  Nodes on Vertical Line 2: 3
//  Nodes on Vertical Line 3: 6, 5
//     As 6 and 5 are on the same vertical level but as 6 comes first in the level-order traversal of the tree so we will output 6 before 5.
//  Nodes on Vertical Line 4: 7
//  Nodes on Vertical Line 5: 9


//Hint :- Intuition
First of all, we need to assign a vertical and a level to every node. Once we assign them, we need to figure out a suitable data structure to store them. This data structure should give us the nodes with left-side vertical first and in every vertical, top-level node should appear first.

//Solution Approach :- 
We will perform a tree traversal and assign a vertical and level to every node. Based on this vertical and node, we store the node in our special data structure. For easy understanding, we break it into these steps:
	Step-1: Assigning vertical and level to every node
	Step-2: Storing Verticals and levels to our data structure
	Step 3: Printing vertical order traversal from our data structure


//First Solution :-
//Key is to take note of horizontal distances from one end of the tree
//The nodes with same horizontal distance will overlap so group them together

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    queue<pair<int,TreeNode*>>q;
    vector<vector<int>>v;
    map<int,vector<int>>m;

    if(!A){
    	return v;
    }

    q.push({0,A});
    while(!q.empty())
    {
        pair<int,TreeNode*>pr = q.front();
        q.pop();
        m[pr.first].push_back(pr.second->val);

        if(pr.second->left){
          q.push({pr.first-1, pr.second->left});  
        }

        if(pr.second->right){
            q.push({pr.first+1, pr.second->right});
        }
    }

    for(auto i:m)
    	v.push_back(i.second);
    return v;
}


//Second Solution :-
map<int,vector<int>> m;
void traverse(TreeNode* root,int h){
    if(!root)return;
    m[h].push_back(root->val);
    
    traverse(root->left,h-1);
    traverse(root->right,h+1);
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> ans;
    if(!A)
    	return ans;
    
    traverse(A,0);
    for(auto e:m){
        ans.push_back(e.second);
    }
    
    return ans;
}



//Third Solution :- 
vector<vector<int>> findVertical(node * root){
	map<int, map<int, multiset<int>>> nodes;   //first-> vertical second->level third->nodes
	queue<pair<node *,pair<int,int>>> todo;

	todo.push({root,{0,0}});   //initial vertical and level

	while (!todo.empty()) {
		auto p = todo.front();
		todo.pop();
		node * temp = p.first;

		int x = p.second.first, y = p.second.second;   //x -> vertical , y->level
		nodes[x][y].insert(temp -> data); //inserting to multiset

		if(temp -> left){
		    todo.push({temp -> left, {x - 1 , y + 1}});
		}

		if (temp -> right) {
		    todo.push({temp -> right, {x + 1, y + 1}});
		}
	}

	vector<vector<int>>ans;

	for (auto p: nodes) {
		vector<int>col;
		for (auto q: p.second) {
		    col.insert(col.end(), q.second.begin(), q.second.end());
		}
		ans.push_back(col);
	}

	return ans;
}



//Fourth Solution :- Recursive
map< int,map<int,vector<int>> >m;
    
void dfs(Node *root,int row,int col){
    if(!root)
    	return;

    m[col][row].push_back(root->data);
    dfs(root->left,row+1,col-1);
    dfs(root->right,row+1,col+1);
}

vector<int> verticalOrder(Node *root)
{
    vector<int>ans;
    if(!root)
    	return ans;

    dfs(root,0,0);   
    for(auto fir:m){
        auto col=fir.first;
        auto innermap=fir.second;
        for(auto vals:innermap){
            auto row=vals.first;
            auto values=vals.second;
            for(int x:values){
                ans.push_back(x);
            }
        }
    }
    return ans;
}