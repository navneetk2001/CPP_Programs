https://practice.geeksforgeeks.org/problems/sum-tree/1



//Solution Approach :-
int treeSum(Node* root){
    if(!root){
    	return 0;
    }
    queue<Node*>q;
    q.push(root);
    int sum = 0;

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        sum+=temp->data;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return sum;
}

bool isSumTree(Node* root){
    if(!root) return true;
    if(!root->right && !root->left) return true;
    if(root->left || root->right)
    return ((root->data == treeSum(root->left) + treeSum(root->right)) && isSumTree(root->left) && isSumTree(root->right));
}




//Second Solution :-
int sum(Node* root){
    if(root==NULL){ 
    	return 0;
    }
    if(root->right==NULL && root->left==NULL){
    	return root->data;
    }
    return root->data + sum(root->left)+ sum(root->right);
}

bool isSumTree(Node* root){
    if(root==NULL){
    	return true;
    }
     
    if(root->right==NULL && root->left==NULL){
    	return true;
    }
     
    int s1 = sum(root->left);
    int s2 = sum(root->right);
     
    if(root->data != s1+s2){
    	return false;
    }
     
    //   for every node check
    bool ans1 = isSumTree(root->right);
    bool ans2 = isSumTree(root->left);
     
    return ans1 && ans2;
}




//Third Solution :-
class Solution{
private:
    pair<bool,int> solve(Node* root) {
        if(root == NULL) {
            pair<bool,int> p = {true, 0};
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = {true, root->data};
            return p;
        }
        
        pair<bool,int> leftAns = solve(root->left);
        pair<bool,int> rightAns = solve(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool sum = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        if(left && right && sum) {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum ;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
public:
    bool isSumTree(Node* root)
    {
        return solve(root).first;
    }
};



//Fourth Solution :-
int check(Node* root, bool &isTrue){
    if(root == NULL){
       return 0;
    }
    int left = 0;
    int right = 0;
    left = check(root->left, isTrue);
    right = check(root->right, isTrue);
    if((left != 0 || right != 0) && left + right != root->data){
        isTrue = false;
    }
    return left + right + root->data;
}

bool isSumTree(Node* root){
   	bool isTrue = true;
    int final = check(root, isTrue);
    return isTrue;
}
