https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1




//Solution Approach :-
void printCorner(Node *root)
{
	if(!root){
		return;
	}
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
	   	int n=q.size();
	   	
	   	for(int i=0;i<n;i++){
	       	Node* temp = q.front();
	       	q.pop();

	       	if(i==0 or i==n-1){
	           	cout << temp->data <<" ";
	       	}
	       	if(temp->left){
	           q.push(temp->left);
	       	}
	       	if(temp->right){
	           q.push(temp->right);
	       	}
   		}
   	}
}



//Second Solution :-
void leftRightMostNode(Node *root, int level, map<int, vector<int="">> &mp){
    if(root){
        mp[level].push_back(root->data);
        
        leftRightMostNode(root->left,  level + 1, mp);
        leftRightMostNode(root->right, level + 1, mp);
    }
}

void printCorner(Node *root)
{
    map<int, vector<int="">> mp;
    int level = 0;
    
    leftRightMostNode(root, level, mp);
    
    for(auto x: mp){
        vector<int> val = x.second;
        
        if(val.size() == 1) {
            cout << val[0] << " ";
        }
        else{
            cout << val[0] << " " << val[val.size() - 1] << " ";
        }
    }
}




//Third Solution :-
void inoder(Node *root,map<int,vector<int>> &m,int l)
{
	if(!root){
		return;
	}
	m[l++].push_back(root->data);
	inoder(root->left,m,l);
	inoder(root->right,m,l);
}

void printCorner(Node *root){
	map<int,vector<int>> m;
	int l=0;
	
	inoder(root,m,l);
	
	for(auto i=m.begin();i!=m.end();i++){
		if(i->second.size()==1){
			cout<<i->second[0]<<" "; 
		}
		else{ 
			cout<<i->second[0]<<" "<<i->second[i->second.size()-1]<<" ";
		}
	}
}




//Fourth Solution :-
void helper(Node* root,int& ld,int &rd,int dist){
	if(!root){
		return;
	}
	if(dist<ld){ 
		cout<<root-="">data<<" ";
		ld=dist;
	}
	if(dist>rd){
		cout<<root->data<<" ";
		rd=dist;
	}
	helper(root->left,ld,rd,dist-1);
	helper(root->right,ld,rd,dist+1);
}	

void printCorner(Node *root)
{
	if(!root){
		return;
	}
	int ld=0, rd=-1;
	helper(root,ld,rd,0);
}

