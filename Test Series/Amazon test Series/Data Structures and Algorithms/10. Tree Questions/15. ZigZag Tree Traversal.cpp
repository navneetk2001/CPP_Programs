https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1




//Solution Approach :-
vector<int> zigZagTraversal(Node* root){ 
   	vector<int> ans;
   	if(root == NULL){
        return ans;
    }

   	int count =0;
   	queue<Node*> q;
   	q.push(root);

   	while(!q.empty()){
       	vector<int> level;
       	count++;
       	
       	int h=q.size();
       	for(int i = 0;i<h; i++)
       	{
           	Node* temp = q.front();
           	q.pop();
           	level.push_back(temp->data);

	        if(temp->left){
	           	q.push(temp->left);
	        }
           	if(temp->right){
           		q.push(temp->right);
           	}
       	}

       	if(count%2==0){
        	reverse(level.begin(),level.end());
       	}
       	for(int i=0;i<level.size();i++){
        	ans.push_back(level[i]);
       	}
   	}
   	return ans;
}






//Second Solution :-
vector <int> zigZagTraversal(Node* root){
    map<int,vector<int>> mpp;
    go(mpp, root, 0);
    
    vector<int> answer;
    int ctr=0;
    for(auto itr:mpp){
        if(ctr%2!=0){
          reverse(itr.second.begin(),itr.second.end());
        }
        for(int x : itr.second){
            answer.push_back(x);
        }
       	ctr++;
    }
    return answer;
}
   
void go(map<int,vector<int>>& mpp, Node* root, int depth){
    if(root==NULL){
    	return;
    }
    mpp[depth].push_back(root->data);
    go(mpp,root->left,depth+1);
    go(mpp,root->right,depth+1);
}



//Third Solution :-
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root){
        vector<int>ans;
        if(!root){
            return ans;
        }
    
        stack<struct Node*> currentlevel;        // declare two stacks
        stack<struct Node*> nextlevel;
    
        currentlevel.push(root);        // push the root
        bool lefttoright = true;

        while(!currentlevel.empty()){        // check if stack is empty   
            struct Node* temp = currentlevel.top();
            currentlevel.pop();             // pop out of stack
    
            if(temp){            // if not null
                ans.push_back(temp->data);                // print the data in it

                if(lefttoright) {                 // store data according to current order.
                    if(temp->left){
                        nextlevel.push(temp->left);
                    }
                    if(temp->right){
                        nextlevel.push(temp->right);
                    }
                }
                else{
                    if(temp->right){
                        nextlevel.push(temp->right);
                    }
                    if(temp->left){
                        nextlevel.push(temp->left);
                    }
                }
            }
    
            if(currentlevel.empty()){
                lefttoright = !lefttoright;
                swap(currentlevel, nextlevel);
            }
        }
    }
};





//Fourth Solution :-
int height(Node*root){
   	if(root==NULL)return 0;
   	int lh=height(root->left);
   	int rh=height(root->right);
   	return 1 + max(lh,rh);
}

void solve(Node* root, vector<int> &v, int c, int level){
    if(root==NULL){
    	return;
    }
    if(level==1){
        v.push_back(root->data);
        return;
    }
    else{
        if(c%2==1){
            solve(root->right,v,c,level-1);
            solve(root->left,v,c,level-1);
        }
        else{
            solve(root->left,v,c,level-1);
            solve(root->right,v,c,level-1);
        }
    }
}

vector <int> zigZagTraversal(Node* root){
    vector<int>v;
    if(root==NULL){
    	return v;
    }
    int h=height(root);
    int c=0;
    for(int i=1;i<=h;i++){
        solve(root,v,c,i);
        c++;
    }
    return v;
}



//Fifth Solution :-
vector <int> zigZagTraversal(Node* root)
{
   	int leftToRight = 1;
   	vector<int> v;
   	if(!root){
       	return v;
   	}
   	stack<Node*> s;
   	stack<Node*> s1;
   	s.push(root);
   	while(!s.empty()){
       Node* temp = s.top();
       s.pop();
       if(temp){
           v.push_back(temp->data);
           if(leftToRight){
               if(temp->left){s1.push(temp->left);}
               if(temp->right){s1.push(temp->right);}
           }
           else{
               if(temp->right){s1.push(temp->right);}
               if(temp->left){s1.push(temp->left);}
           }
       }
       if(s.empty()){
           leftToRight = 1- leftToRight;
           swap(s,s1);
       }        
   }
   return v;
}
