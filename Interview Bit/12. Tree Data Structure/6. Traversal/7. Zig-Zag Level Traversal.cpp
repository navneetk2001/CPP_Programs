Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:
Input:
        3
      /   \
     2     1
Output: 3 1 2

Example 2:
Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output: 7 7 9 8 8 6 9 10


//Solution Approach :- 
vector <int> zigZagTraversal(Node* root)
{
    vector<int>ans;
	queue<pair<Node*,char>>q;
	q.push({root,'l'});
	stack<int>st;
	while(q.size()>0)
	{
	    int n=q.size();
	    
	    while(n)
	    {
	        Node* temp=q.front().first;
	        char dir=q.front().second;
	        q.pop();
	        if(dir=='r')
	        st.push(temp->data);
	        else
	        ans.push_back(temp->data);
	        char ndir;
	        if(dir=='l')
	          ndir='r';
	        else
	          ndir='l';
	        if(temp->left)
	           q.push({temp->left,ndir});
	        if(temp->right)
	           q.push({temp->right,ndir});
	        
	        
	        n--;
	    }
	    while(st.size()>0)
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	}
	return ans;
}


//Second Solution :-
vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans;

	queue<Node*> q;
	q.push(root);
	
	int row=0;
	while(!q.empty()){
	    int size=q.size();
	    vector<int> temp;
	    for(int i=0; i<size; i++){
	        auto val= q.front();
	        q.pop();

	        if(val->left) q.push(val->left);
	        if(val->right) q.push(val->right);

	        temp.push_back(val->data);
	    }

	    if(row & 1) 
	    	reverse(temp.begin(), temp.end());

	    for(auto i: temp) 
	    	ans.push_back(i);

	    row++;
	}
	return ans;
}


//Third Solution :-
vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans;
	stack<Node*> currLevel;
	currLevel.push(root);

	stack<Node*> nextLevel;
	bool rightTOleft=0;

	while(!currLevel.empty()){
	    Node* temp=currLevel.top();
	    currLevel.pop();

	    if(temp!=NULL){
	        ans.push_back(temp->data);

	        if(rightTOleft){
	            if(temp->right!=NULL)
	                nextLevel.push(temp->right);
	            if(temp->left!=NULL)
	                nextLevel.push(temp->left);
	        }
	        else{
	            if(temp->left!=NULL)
	                nextLevel.push(temp->left);
	            if(temp->right!=NULL)
	                nextLevel.push(temp->right);
	        }
	    }
        if(currLevel.empty()){
            rightTOleft=!rightTOleft;
            swap(currLevel, nextLevel);
        }
	}
	return ans;
}




//Solution :- Check this (What is Wrong here?)
void func(map<int,vector<int>>&mp, TreeNode*root, int level){
    if(root == NULL) 
    	return;

    mp[level].push_back(root->val);
    func(mp, root->left, level+1);
    func(mp, root->right, level+1);
}

vector<int> Solution::solve(TreeNode* root) {
    vector<int>ans;
    if(!root) return ans;

    map<int,vector<int>>mp;
    func(mp,root,0);

    int n = mp.size();
    for(int i = n-1; i >= 0; i--){
        for(auto num: mp[i]) 
       		ans.push_back(num);
    }

    return ans;
}
