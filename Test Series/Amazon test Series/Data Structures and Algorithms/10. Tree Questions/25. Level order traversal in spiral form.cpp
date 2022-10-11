https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1




//Solution Approach :-
vector<int> findSpiral(Node *root){   
    if(root == NULL){
        return {};
    }
    vector<int> ans;
    queue<Node*> nodes;
    nodes.push(root);

    int prevsize =  0;
    int flag = 0;

    while(!nodes.empty()){
        int size = nodes.size();

        for(int i = 0; i < size; i++){
            Node*first = nodes.front();
            nodes.pop();

            ans.push_back(first->data);
            if(first->left!= NULL) nodes.push(first->left);
            if(first->right!= NULL) nodes.push(first->right);
        }
        if(flag == 0 ){
            reverse(ans.begin()+prevsize, ans.end());
            flag = 1;
        }
        else{
            flag = 0;
        }
        prevsize += size;
    }
    return ans;
}



//Second Solution :-
// Algorithm- 
// 1. push root to stack s1.
// 2. while any of two is not empty
//    while s1 not empty
//    a) take out a node and store it.
//    b) push children of taken out node into s2.
//    while s2 not empty
//    a) take out a node and store it.
//    b) push children of taken out node into s1 in reverse order.

//    ------------------------------------------------------//
vector<int> findSpiral(Node *root)
{ 
    if(root==NULL){
    	return {};
    }
    vector<int> v;
 	stack<Node *>s1,s2;
    s1.push(root);
    
    while(!s1.empty()|| !s2.empty()){
        while(!s1.empty()){
	        Node *curr=s1.top();
	        s1.pop();
	        v.push_back(curr->data);

	        if(curr->right!=NULL){
	        	s2.push(curr->right);
	        }
	        if(curr->left!=NULL){
	        	s2.push(curr->left);
	        }
        }

        while(!s2.empty()){
        	Node *curr=s2.top();
	        s2.pop();
	        v.push_back(curr->data);

	        if(curr->left!=NULL){
	        	s1.push(curr->left);
	        }
	        if(curr->right!=NULL){
	        	s1.push(curr->right);
	        }
        }
        
    }
    return v;
}



//Third Solution :-
// Algorithm-
// 1. Find height of tree
// 2. store all nodes of each level in vector v using concept of print nodes at k distance.
// 3. if(level is odd) store elements of v in p in left→ right order.
// 4. else store elements of v in p in right → left order.
// ----------------------------------------------------------------------------

vector<int> v;
int height(Node *root){
   	if(root==NULL){
   		return 0;
   	}
   	else{
   		return 1+ max(height(root->left),height(root->right));
   	}
}

void get_node(Node *root,int k){
   	if(root==NULL){
   		return;
   	}
   	if(k==0){
   		v.push_back(root->data);
   	}
   	else{
       	get_node(root->left,k-1);
       	get_node(root->right,k-1);
   	}
}

vector<int> findSpiral(Node *root){
   	vector<int> p;
   	if(root==NULL){
   		return {};
   	}
    int h=height(root),i;
   	
   	for(i=0;i<h;i++){
       	get_node(root,i);
       
    	if(i%2!=0){
   			for (int j = 0; j < v.size(); j++){
   				p.push_back(v[j]);
   			}
    	}
   		else{	
   			reverse(v.begin(), v.end());
   			for (int j = 0; j < v.size(); j++){
   				p.push_back(v[j]);
   			}
   		}
      	v.clear();
    }
	     
   	return p;
}



//Fourth Solution :-
vector<int> findSpiral(Node *root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    queue<Node*> qq;
    qq.push(root);
    bool dir=false;        //dir = false means right to left traversal,    //dir = true means left to right traversal

    while(!qq.empty()){
        int sz=qq.size();
        vector<int> v;
        
        for(int ii=0; ii<sz; ii++){
            Node* temp=qq.front();
            qq.pop();
            v.push_back(temp->data);
            
            if(temp->left){
                qq.push(temp->left);
            }
            if(temp->right){
                qq.push(temp->right);
            }
        }
        
        //Changing the direction of traversal
        if(!dir){
            reverse(v.begin(), v.end());
        }
        for(int &it : v){
            ans.push_back(it);
        }
        dir=!dir;
    }
    return ans;
}