https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1




//Solution Approach :-
map<int, pair<int, Node *>> mp;
void solve(Node *root, int h){
    if(root==NULL){
        return;
    }
    if(root->left){
        mp[root->left->data]={h+1,root};
    }
    if(root->right){
        mp[root->right->data]={h+1,root};
    }
    solve(root->left, h+1);
    solve(root->right,h+1);
}

bool isCousins(Node* root, int a, int b) {
    solve(root,1);
    bool ans=false;

    if(mp[a].first == mp[b].first){
        if(mp[a].second != mp[b].second){
            ans = true;
        }
    }
    mp.clear();
    return ans;
}




//Second Solution :-
bool isCousins(Node *root, int a, int b){
  	int f1=0,f2=0;
  	queue<Node*>q;
  	q.push(root);
  	
  	while(!q.empty()){
      	int n=q.size();
      	
      	for(int i=1;i<=n;i++){
          	Node*temp = q.front();
          	q.pop();

          	if(temp->left and temp->right){
              	if(temp->left->data==a and temp->right->data==b)return false;
              	if(temp->left->data==b and temp->right->data==a)return false;
          	}
	        if(temp->data == a)f1=1;
	        if(temp->data == b)f2=1;
	        if(temp->left) q.push(temp->left);
	        if(temp->right) q.push(temp->right);
      	}
      	if(f1 and f2){
          	return true;
      	}
      	if(f1 or f2){
          	return false;
      	}
  	}
  	return false;
}



//Third Solution :-
void helper(Node *root,int x,int level,pair<Node*,int> &dp){
    if(!root){
        return;
    }
    if(root->left and root->left->data == x){
        dp = {root,level};
    }
    if(root->right and root->right->data == x){
        dp = {root,level};
    }
    helper(root->left,x,level + 1,dp);
    helper(root->right,x,level + 1,dp);
}

bool isCousins(Node *root, int a, int b){
   	pair<Node*,int>a1; 
   	pair<Node*,int>b1;

   	helper(root,a,1,a1);
   	helper(root,b,1,b1);
  	if(a1.first != b1.first and a1.second == b1.second){
        return 1;
  	}
    return 0;
}




//Fourth Solution :-
bool isCousins(Node *root, int a, int b)
{
    Node* parent1;Node* parent2 ;
    int level1,level2 ;
    int level = 0 ;
    queue<Node*> q ;
    q.push(root) ;
    while(1)
    {
        int size = q.size() ;
        if(size==0)
            break ;
        while(size>0)
        {
            Node* node = q.front() ;
            q.pop() ;
            if(node->left)
            {
                if(node->left->data==a)
                {
                    parent1 = node ;
                    level1 = level ;
                }
                else if(node->left->data==b)
                {
                    parent2 = node ;
                    level2 = level ;
                }
                  q.push(node->left) ;
            }
            if(node->right)
            {
                if(node->right->data==a)
                {
                    parent1 = node ;
                    level1 = level ;
                }
                else if(node->right->data==b)
                {
                    parent2 = node ;
                    level2 = level ;
                }
                q.push(node->right) ;
            }
            size-- ;
        }
        level++ ;
    }
    if(level1 == level2)
        if(parent1 == parent2)
            return false ;
        else
            return true ;
    return false ;
}