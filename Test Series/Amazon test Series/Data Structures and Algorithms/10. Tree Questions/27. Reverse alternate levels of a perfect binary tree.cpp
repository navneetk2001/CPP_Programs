https://practice.geeksforgeeks.org/problems/reverse-alternate-levels-of-a-perfect-binary-tree/1




//Solution Approach :-
void helper(Node* root1, Node* root2, int level){
	if(!root1 || !root2){
		return;
	}
	if(level % 2 == 0){
		swap(root1->data, root2->data);
	}
	helper(root1->left, root2->right, level+1);
	helper(root1->right, root2->left, level+1);
}

void reverseAlternate(Node *root){
   	if(root==NULL){
   		return;
   	}
	helper(root->left,root->right,0);
}



//Second Solution :-
void reverseAlternate(Node *root){
	if(!root){
		return;
	}

	queue<node *=""> q;
	q.push(root);
	int l = 0;
	while(!q.empty()){
		vector<int> v;
		vector<node *="">level;

		int len = q.size();
		while(len--){
			Node *t = q.front();
			q.pop();
			level.push_back(t); v.push_back(t->data);

			if(t->left) q.push(t->left);
			if(t->right) q.push(t->right);
			}

			if(l%2 == 1){
			int i=0 , j=v.size()-1;
			while(i<v.size()){ 
				level[i]-="">data = v[j];
				i++; 
				j--;
			}
		}
		l++;
	}
}


//Third Solution :-
void reverseAlternate(Node *root){
    queue<Node *> q;
    q.push(root);
    int flip=1;
    vector <int> r;
    vector<Node*> v;

    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node * curr=q.front();
            q.pop();

            if(flip==1){
            	v.push_back(curr);
            }
            else{
                r.push_back(curr->data);
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }

        if(flip==0){
            reverse(r.begin(),r.end());int l=0;
            for(auto o:v){
                o->left->data=r[l++];
                o->right->data=r[l++];
            }
            v.clear();
            r.clear();
        }
        flip=!flip;
    }
}