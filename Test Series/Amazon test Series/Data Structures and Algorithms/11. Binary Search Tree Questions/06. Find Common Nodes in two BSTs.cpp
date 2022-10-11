https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1/




//Solution Approach :-
unordered_map<int,int> mp;
vector<int> ans;

vector <int> findCommon(Node *root1, Node *root2){
	traverse(root1);
	traverse(root2);
	sort(ans.begin(),ans.end());
	return ans;
}

void traverse(Node *root){
   	if(root==NULL){
       	return;
   	}
   	if(!mp[root->data]){    //if not present in map then insert it
       	mp[root->data]++;
   	}	
    else{       //else if present in mpa then insert it in ans vector
       	ans.push_back(root->data);
   	}
   	traverse(root->left);
   	traverse(root->right);
}



//Second SOlution :-
vector <int> findCommon(Node *root1, Node *root2){
    stack<Node *> s1,s2;
    Node *curr1 = root1 , *curr2 = root2;
    vector<int> v;

    while((curr1 != NULL || !s1.empty()) && (curr2 != NULL || !s2.empty() ))
    {
        while(curr1!=NULL){
            s1.push(curr1);
            curr1 = curr1 -> left; 
        }
           
        while(curr2!=NULL){
            s2.push(curr2);
            curr2 = curr2 -> left;     
        }
    
            
        Node *top1 = s1.top() , *top2 = s2.top();
        
        if(top1->data == top2 -> data){
            v.push_back(top1->data);
            
            s1.pop();
            s2.pop();
            curr1 = top1->right;
            curr2 = top2->right;
        }
        else if(top1->data < top2 -> data)
        {
            s1.pop();
            curr1 = top1 -> right;
        }
        else if(top1->data > top2 -> data)
        {
            s2.pop();
            curr2 = top2 -> right;
        }
    }
    return v;
}





//Third Solution :-
set<int> s;
vector<int> res;
void inorder(Node *root){
   	if(root!=NULL)
   	{
       	inorder(root->left);
       	s.insert(root->data);
       	inorder(root->right);
   	}
}

void help(Node *root){
   	if(root!=NULL)
   	{
       	if(s.find(root->data)!=s.end()){
        	res.push_back(root->data);
       	}
       	help(root->left);
       	help(root->right);
   	}
}

vector <int> findCommon(Node *root1, Node *root2)
{
	inorder(root1);
	help(root2);
	sort(res.begin(),res.end());
	return res;
}



//Fourth Solution :-
vector <int> findCommon(Node *root1, Node *root2)
{
	vector<int>v;
	if(root1==NULL and root2==NULL){
		return v;
	}

	map<int,int> m;
	queue<Node*>q,p;
	q.push(root1);
	p.push(root2);

	while(!q.empty()){
	    int n=q.size();

	    for(int i=1;i<=n;i++){
	        Node*temp=q.front();
	        q.pop();

	        m[temp->data]++;
	        if(temp->left){
	            q.push(temp->left);
	        }
	        if(temp->right){
	            q.push(temp->right);
	        }
	    }
	}

	while(!p.empty()){
	    int n=p.size();

	    for(int i=1;i<=n;i++){
	        Node*temp=p.front();
	        p.pop();
	        
	        if(m.find(temp->data)!=m.end()){
	            v.push_back(temp->data);
	        }
	        if(temp->left){
	            p.push(temp->left);
	        }
	        if(temp->right){
	            p.push(temp->right);
	        }
	    }
	}
	sort(v.begin(),v.end());
	return v;

}