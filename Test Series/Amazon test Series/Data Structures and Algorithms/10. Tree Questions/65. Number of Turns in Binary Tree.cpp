https://practice.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1




//Solution Approach :-
Node* lca(Node* root,int a,int b){
   	if(root==NULL){
       	return NULL;
   	}
   	if(root->data==a || root->data==b){
       return root;
    }

   	Node* l1=lca(root->left,a,b);
   	Node* l2=lca(root->right,a,b);
   
   	if(l1!=NULL&&l2!=NULL){
       	return root;
   	}
   	if(l1==NULL){
       return l2;
   	}
   	return l1;
}

int get(Node* root,int a,int prev,int res)
{
   	if(root==NULL){
       	return 1e7;
   	}
   	if(root->data == a){
       return res;
   	}

   	int ans=1e7;
   	if(prev==-1){
       	ans=min(ans,min(get(root->left,a,1,1),get(root->right,a,0,1)));
   	}
   	else{
       	if(prev==1){
           ans=min(ans, get(root->right,a,0,res+1));
           ans=min(ans, get(root->left,a,1,res));
       	}
       	else{
           ans=min(ans,get(root->left,a,1,res+1));
           ans=min(ans,get(root->right,a,0,res));
       	}
   	}
   	return ans;
}

int NumberOFTurns(Node* root, int a,int b){
 	Node* r = lca(root,a,b);
 	
 	if(r==NULL){
     	return -1;
 	}
 
 	int x=get(r,a,-1,0);
 	int y=get(r,b,-1,0);
 	
 	return (x+y)-1;
}




//Second Solution :-
//Function to find LCA
Node *lcaf(Node *root,int f,int s){
	if(!root){
		return NULL;
	}
	if(root->data == f || root->data == s){
		return root;
	}
	Node *lf = lcaf(root->left,f,s);
	Node *rf = lcaf(root->right,f,s);

	if(lf && rf) return root;
	else if(lf) return lf;
	else return rf;
}

//Function to find no of turns
int func(Node *root,bool lft,bool rht,int a,int b){
	if(!root){
		return -100000;
	}
	if(root->data == a || root->data == b){
		return 0;
	}
	int lv = func(root->left,true,false,a,b) + (lft ? 0:1);
	int rv = func(root->right,false,true,a,b) + (rht? 0:1);

	if(lv >=0 && rv>=0) return lv+rv;
	return lv >=0 ? lv:rv;
}

//Driver Code
int NumberOFTurns(struct Node* root, int first, int second)
{
	if(first == second){
		return -1;
	}
	
	Node *lca = lcaf(root,first,second);
	
	if(lca->data == first || lca->data == second){
		int k = (lca->data == first ? second : first);
		int a = func(lca->left,true,false,k,k);
		if(a >=0 ){
			return (a == 0 ? -1 : a);
		}
		else{
			int b = func(lca->right,false,true,k,k);
			return b == 0 ? -1 : b;
		}
	}
	else{
		return func(lca,true,true,first,second) + 1;
	}
}



//Third Solution :-
/* Ques:- Given a binary tree and data value of two of its nodes. Find the number of turns needed to reach from one node to another in the given binary tree.
Concept:- 1)First we try to find LCA of given nodes
          2)Than from LCA, we find the location of both nodes, and try to find out how many turns are required to reach the both nodes from LCA
          3)Here , we will describes two terms ie. turns and the bend. The bend is a place where LCA is there(but it will calculated as turn in the question too)
          4)Special Case :- if any of the element is equal to LCA, than there will be no bend
                            if any element is not equal to LCA, than we will make answer + 1 ,as bend is there and thus calculated as turn
                            
Time - O(n)
Space - O(height)
*/

Node* lca(Node* root,int &first,int &second) //simple function to find the LCA of two nodes in a binary tree
{
    if(root == NULL)
    return NULL;
    
    if(root->data == first || root->data == second)
    return root;
    
    Node *l1 = lca(root->left,first,second);
    Node *l2 = lca(root->right,first,second);
    
    if(l1 == NULL && l2 == NULL)
    return NULL;
    else if(l1 != NULL && l2 != NULL)
    return root;
    else if(l1 != NULL)
    return l1;
    else
    return l2;
}

void calcu(Node *root,int &ele,int &ans,int turns,int val) // { current root, target element , answer , type of turn (-1 :- left , 1 :- right) , current number of turns }
{
    if(root == NULL)
    return;
    
    if(root->data == ele) //if tree data matches, add the number of turns 
    ans += val;
    
    if(turns == -1) //if currently at left path
    {
        calcu(root->left,ele,ans,-1,val); //turns remains same for left path
        calcu(root->right,ele,ans,1,val+1); // turns increased by 1 for right path
    }
    else //if currently at right path
    {
        calcu(root->left,ele,ans,-1,val+1); //turns increased by 1 for left path 
        calcu(root->right,ele,ans,1,val); //turns remains same for right path
    }
    
}

int NumberOFTurns(struct Node* root, int first, int second)
{
  // Your code goes here
  Node* ances = lca(root,first,second); //finding the LCA
  
  int ans = 0; //our answer
  
  //left subtree of LCA node..
  calcu(ances->left,first,ans,-1,0);  
  calcu(ances->left,second,ans,-1,0);
  
  //right subtree of LCA node...
  calcu(ances->right,first,ans,1,0);
  calcu(ances->right,second,ans,1,0);
  
  
  
  if(ances->data != first && ances->data != second) //if LCA is similar to one of the element
  ++ans;
  
  if(ans == 0)
  return -1;
  else
  return ans;
}