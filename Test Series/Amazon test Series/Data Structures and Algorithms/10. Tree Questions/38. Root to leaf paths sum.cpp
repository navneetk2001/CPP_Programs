https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1



//Solution Approach :-
long long pathsum(Node *root, int i){
  	if(!root){
  		return 0;
  	}
  	i = (i*10) + root->data;
  	if(!(root->left) and !(root->right)){
  		return i;
  	}
  	return pathsum(root->left,i) + pathsum(root->right,i);
}

long long treePathsSum(Node *root){
   	return pathsum(root,0);
}



//Second Solution :-
void leafPathSum(Node *root , vector<long long> & result, long long sum){
    sum = sum*10 + root->data ;
    if(root->left){
        leafPathSum(root->left,result,sum) ;
    }
    if(root->right){
        leafPathSum(root->right,result,sum) ;
    }
    if(root->left == NULL && root->right == NULL){
        result.push_back(sum) ;
    }
}

long long treePathsSum(Node *root){
    long long sum = 0 ;
    vector<long long> result ;
    leafPathSum(root,result,sum) ;
    return accumulate(result.begin(),result.end(),0) ;
}




//Third Solution :-
void solve(Node* root,string s,long long &ans){
    if(!root){
        return;
    }
    s += to_string(root->data);
    if(!root->left and !root->right){
        ans += (long long)stoi(s);
        return;
    }
    solve(root->left,s,ans); 
    solve(root->right,s,ans);
}

long long treePathsSum(Node *root){   
    string s="";
    long long ans = 0;
    solve(root, s, ans);
    return ans;
}


//Fourth Solution :-
void solve(Node*root,long long &sum,long long k,long long level ){
   if(root==NULL)return;
   if(level==1){
       k=0;
   }
   k=(k*10)+root->data;
   if(!root->left and !root->right){
       sum+=k;
   }
   solve(root->left,sum,k,level+1);
   solve(root->right,sum,k,level+1);
}

long long treePathsSum(Node *root)
{
   if(!root)return 0;
   long long sum=0;
   long long k=0,level=1;
   solve(root,sum,k,level);
   return sum;
   
}