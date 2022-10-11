https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1


//Solution Approach :- // same logic as level order traversing
// just push the right node 1st, then left node
// and reverse the final ans vector, it will be reverse level order
vector<int> reverseLevelOrder(Node *root){
    vector<int> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* t = q.front();
        q.pop();

        ans.push_back(t->data);
        if(t->right){
        	q.push(t->right);
        }
        if(t->left){
        	q.push(t->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



//Second Solution :-
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
 
        if(lheight > rheight){
            return(lheight + 1);
        }
        else{
            return(rheight + 1);
        }
    }
}

void printGivenLevel(Node* root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->data<<" ";
    }
    else if(level > 1){
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

vector<int> reverseLevelOrder(Node *root){
    vector<int>output;
    int h = height(root);
    
    for (int i = h; i >= 1; i--){
        printGivenLevel(root, i);
    }
    return output;
}



//Third Solution :-
vector<int> reverseLevelOrder(Node *root){
   	vector<int> v;
   	if(root==NULL){
   		return v;
   	}
   	queue<Node*>s;
   	s.push(root);

   	while(!s.empty()){
       	int h=s.size();
       	for(int i=1;i<=h;i++){
           	Node*temp=s.front();
           	s.pop();
           	v.push_back(temp->data);

           	if(temp->right){
               s.push(temp->right);
           	}
           	if(temp->left){
           	    s.push(temp->left);
           	}
       	}
   	}
   	reverse(v.begin(),v.end());
   	return v;
}