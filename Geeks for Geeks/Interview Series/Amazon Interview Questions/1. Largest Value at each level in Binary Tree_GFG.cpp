Given a binary tree, find the largest value in each level.
Example 1:
Input :
        1
       / \
      2   3 

Output : 1 3
Explanation : 
There are two levels in the tree :
1. {1}, max = 1
2. {2, 3}, max = 3

Example 2:
Input :
        4
       / \
      9   2
     / \   \
    3   5   7 

Output : 4 9 7
Explanation : 
There are three levels in the tree:
1. {4}, max = 4
2. {9, 2}, max = 9
3. {3, 5, 7}, max=7


//Approach :-
//If we are traversing any node for first time simply insert it 
//else check for max level and curr level and also max between two


void solver(Node *root, vector<int>&res, int level){
	if(root==NULL)   //base case
			return ;

	if(res.size()==level){   //If you are traversing that level for the first time
		res.push_back(root->data);
	}
	else{                    //else if you are traversing that level again
		res[level]=max(res[level],root->data);   //then choose the max between curr max and curr node data
	}

	solver(root->left,res,level+1);  //call for left with 1 level up
	solver(root->right,res,level+1); //call for right with 1 level up
}

class Solution
{
    public:
    vector<int> largestValues(Node* root)
    {
        vector<int>res;
        int level=0;
        solver(root,res,level);
        return res;
    }
};



//Another Approach :-
//you can also use a queue and '#' after every level ends and
//store the elements now take max and start storing max value
void largestValueInEachLevel(Node* root)
{
    // if tree is empty
    if (!root)
        return;
 
    queue<Node*> q;
    int nc, max;
 
    // push root to the queue 'q'
    q.push(root);
 
    while (1) {
        // node count for the current level
        nc = q.size();
 
        // if true then all the nodes of
        // the tree have been traversed
        if (nc == 0)
            break;
 
        // maximum element for the current
        // level
        max = INT_MIN;
 
        while (nc--) {
 
            // get the front element from 'q'
            Node* front = q.front();
 
            // remove front element from 'q'
            q.pop();
 
            // if true, then update 'max'
            if (max < front->data)
                max = front->data;
 
            // if left child exists
            if (front->left)
                q.push(front->left);
 
            // if right child exists
            if (front->right)
                q.push(front->right);
        }
 
        // print maximum element of
        // current level
        cout << max << " ";
    }
}
