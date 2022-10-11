https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1





//Solution Approach :-
void inorder(Node *root, vector<int> &v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

int isPairPresent(struct Node *root, int target){
    vector<int>v;
    inorder(root,v);
    
    int i=0, j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==target){
            return true;
        }
        else if(v[i]+v[j]>target){
        	j--;
        }
        else{
        	i++;
        }
    }
    return false;
}



//Second Solution :-
unordered_set<int> mp;
int isPairPresent(struct Node *root, int target){
    if(!root){
        return false;
    }
        
    if(isPairPresent(root->left,target)==1){
        return true;
    }
        
    if(mp.find(target-root->data)!=mp.end()){
        return true;
    }
        
    mp.insert(root->data);
    return isPairPresent(root->right,target);
}



//Approach 1 :) Simple Cpp Solution || (O(nlogn) approach ||Without Extra Space|
class Solution{
    Node *temp=NULL;
    bool check(Node *root,int val){
        if(!root){
            return false;
        }
        if(root->data==val){
            return true;
        }
        else if(root->data<val){
            return check(root->right,val);
        }
        return check(root->left,val);
   	}

    bool helper(Node *root, int s){
        if(!root){
            return false;
        }
        if(check(temp,s-root->data)){
            return true;
        }
        return helper(root->left,s) || helper(root->right,s);
    }
  public:
    // root : the root Node of the given BST    // target : the target sum
    int isPairPresent(struct Node *root, int target){
        temp = root;
        return helper(root,target);
    }
};
 

//Approach 2 :)  Simple Cpp Solution || (O(n) approach ||Using Extra Space|
class Solution{
    bool helper(Node *root, int s, map<int,int> &m){
        if(!root){
            return false;
        }
        if(m.find(s-root->data)!=m.end()){
            return true;
        }
        else{
            m[root->data];
        }
        return helper(root->left,s,m) || helper(root->right,s,m);
    }
  public:
    // root : the root Node of the given BST    // target : the target sum
    int isPairPresent(struct Node *root, int target){
        map<int,int>m;
        return helper(root,target,m);
    }
};




//Third Solution :- O(n) time and O(2*h) Space | BST Iterator
class Solution{
 public:
   // root : the root Node of the given BST   // target : the target sum
   stack<Node*> s1;
   stack<Node*> s2;
   
   int isPairPresent(struct Node *root, int target){
   		if(root==NULL){
   			return 0;
   		}
      	pushall(root,0);
      	pushall(root,1);
      	int i=s1.top()->data;
      	int j=s2.top()->data;
      	
      	while(!s1.empty() && !s2.empty()){
          	if(i+j==target){
          		return 1;
          	}
          	else if(i+j > target){
              	Node* temp=s2.top();
              	s2.pop();
              	pushall(temp->left,1);
              	if(!s2.empty()){
              		j=s2.top()->data;
              	}
              
          	}
          	else{
              	Node* temp=s1.top();
              	s1.pop();
              	pushall(temp->right,0);
              	if(!s1.empty()){
              		i=s1.top()->data;
              	}
          	}
      	}
      	return 0;
   	}

   	void pushall(Node* root,int i){
       	while(root!=NULL){
           	if(i==0){
               	s1.push(root);
               	root=root->left;
           	}
           	else{
               	s2.push(root);
               	root=root->right;
           	}
       	}
   	}
   
};