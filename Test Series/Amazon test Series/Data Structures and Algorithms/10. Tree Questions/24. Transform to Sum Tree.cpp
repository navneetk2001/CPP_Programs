https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1



//Solution Approach :-
int solve(Node *node){
    if(!node){
    	return 0;
    }
    
    int temp = node->data;
    node->data = solve(node->right) + solve(node->left);
    return temp + node->data;
}

void toSumTree(Node *node){
    solve(node);
}



//Second Solution :-
void toSumTree(Node *root)
{
  	int count=helper(root); 
  	return;
}


int helper(Node* root){
    int left_sum=0, right_sum=0;
    int a = root->data;
    
    if(root->left!=NULL){
    	left_sum=helper(root->left);
    }
    if(root->right!=NULL){
    	right_sum=helper(root->right);
    }

    root->data = left_sum + right_sum;
    return root->data + a;
}



//Third Solution :-
int sum(Node*root){
   	if(root==NULL){
   		return 0;
   	}
   	int ans = root->data;
   	if(root->left){
   		ans+=sum(root->left);
   	}
   	if(root->right){
   		ans+=sum(root->right);
   	}
   	return ans;
}

void toSumTree(Node *root){
   	if(root==NULL){
   		return;
   	}
   	root->data = sum(root->left) + sum(root->right);
   	if(root->left){
   		toSumTree(root->left);
   	}
   	if(root->right){
   		toSumTree(root->right);
   	}
}



//Fourth Solution :-
class Solution {
public:
    // Convert a given tree to a tree where every node contains sum of values of nodes in left and right subtrees in the original tree
    pair<int,int> solve(Node* root){
        if(!root) return {0,0};
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        int sum = 0;
        sum += left.first + left.second + right.first + right.second;
        pair<int,int> curr = make_pair(sum,root->data);
        root->data = sum;
        return curr;
    }
    void toSumTree(Node *root){
        solve(root);
    }
};



//Fifth Solution :-
int sum(Node* root){
    if(root == NULL)return 0;
    return sum(root->left)+sum(root->right)+root->data;
}

void toSumTree(Node *root){
    if(root == NULL)return;
    
    int s = sum(root)-root->data;
    root->data = s;
    
    toSumTree(root->left);
    toSumTree(root->right);
}