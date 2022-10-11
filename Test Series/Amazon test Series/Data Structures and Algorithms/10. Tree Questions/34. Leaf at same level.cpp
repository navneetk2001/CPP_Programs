https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1




//Solution Approach :-
unordered_map<int,int>mp;
void help(Node*root , int lvl){
   	if(root==NULL){
   		return;
   	}
   	if(root->left ==NULL and root->right==NULL){
       mp[lvl]++;
       return;
   	}
   	help(root->right,lvl+1);
   	help(root->left,lvl+1);
}

bool check(Node *root){ 
	mp.clear();
	int lvl=0;
 	help(root,lvl);

 	if(mp.size()>1){
 		return false;
 	}
 	return true;
}



//Second Solution :-
//This is the simple solution which passes all the test cases .It uses the concept that if their is a difference in the height of left and right subtree \
//then ,it is the case when the leaf nodes of the subtrees are not on the same level.
class Solution{
public:
    int traverse(Node *root,int &flag){
        if(root==NULL){
        	return 0;
        }
        int hl=traverse(root->left, flag);
        int hr=traverse(root->right,flag);
 
        if(root->left && root->right){       // used because we cant take leaf nodes into the consideration 
            if(hl != hr){
            	flag=1;
            }
        }
        return 1 + max(hl, hr);
    }
    bool check(Node *root)
    {
        int flag=0;
        int k=traverse(root, flag);
        return flag ? 0 : 1;
    }
};



//Third Solution :-
bool check(Node *root){
   	queue<Node*>q;
   	q.push(root);
 
   	while(!q.empty()){
       	int sz=q.size();
       	int cnt=0;

       	for(int i=0;i<sz;i++){
           Node *cur=q.front();
           q.pop();

           	if(cur->left==NULL && cur->right==NULL){
           		cnt++;
           	}
           	if(cur->left)q.push(cur->left);
           	if(cur->right)q.push(cur->right);
       	}
       	if(cnt&&cnt!=sz)return false;
   	}
   	return true;
}



//Fourth Solution :-
set<int> s;
bool check(Node *root, int l = 0){
    if(root == NULL) return true;
    if(!root->left && !root->right){
    	s.insert(l);
    }
    
    check(root->left, l+1);
    check(root->right, l+1 );
    
    return s.size() == 1;
}