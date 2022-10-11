https://practice.geeksforgeeks.org/problems/complete-binary-tree/1




//Solution Approach :- 
bool isCompleteBT(Node* root){
    queue<Node*> q;
    q.push(root);
    
    bool f = 0;
    while(q.size()){
        auto it = q.front(); 
        q.pop();

        if(!it){
            f = 1;
            continue;
        }
        
        if(f) return 0;         // Check if a NUll pointer had already traversed before a not Null Node
        q.push(it->left);
        q.push(it->right);
    }
    return 1;
}




//Second Solution :-
bool isCompleteBT(Node* root){
    if(!root){
        return true;
    }
    
    queue<Node*> q;
    q.push(root);
    bool flag = true;
    
    while(q.size()){
        
        
        
        int n = q.size();
        
        while(n--){
            
            auto x  = q.front();
            q.pop();
            
            if(!x->left && x->right){
                return false;
            }
            
            if((x->left || x->right) && !flag){
                return false;
            }
            
            if(!x->left || !x->right){
                flag = false;
            }
            
            if(x->left){
                q.push(x->left);
            }
            
            if(x->right){
                q.push(x->right);
            }
        }
    }
    
    return true;
}




//Third Solution :- 
bool isCompleteBT(Node* root){
    //Declare q queue
    queue<Node*> q;
    
    //Push first root node inside the q
    q.push(root);
    
    //Declare flag as false 
    bool flag=false;
    
    //declare loop that will run until q became empty
    while(!q.empty()){
        
        //store current front node inside the temp 
        Node* temp=q.front();
        
        //delete top of q node
        q.pop();
        
        //check if temp node is null then update flag true
        if(temp==NULL) flag=true;
        else{
            
            //else check flag if true it means we got null value earlier but still there is some node so we can't call this Tree as complete BST then return false
            if(flag) return false;
            
            //Push left and right node of temp node inside the q
            q.push(temp->left);
            q.push(temp->right);
        }
        
    }
    
    //if we reach here it means this Tree is Complete BST then return true
    return true;
}



//Fourth Solution :- 
int total_nodes(Node* root){
   	if(root==NULL){
   		return 0;
   	}
   	return 1+total_nodes(root->left)+total_nodes(root->right);
}

bool complete(Node* root,int index,int total_node){
 	if(root==NULL){
   		return true;
 	}
   
   	if(index > total_node){
   		return false;
   	}
   
   	return complete(root->left,2*index,total_node) && complete(root->right,2*index+1,total_node);
}

bool isCompleteBT(Node* root){
	if(root==NULL){
		return true;
	}
	int index=1;
	return complete(root,index,total_nodes(root));
}
