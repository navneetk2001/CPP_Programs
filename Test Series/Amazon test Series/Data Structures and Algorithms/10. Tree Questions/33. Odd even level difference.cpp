https://practice.geeksforgeeks.org/problems/odd-even-level-difference/1




//Solution Approach :-
class Solution{
public:
    int getLevelDiff(Node *root){
       int odd = 0;
       int even = 0;

       queue<Node*> q;
       q.push(root);
       bool isodd = true;

       while(!q.empty()){
           int sz = q.size();

           while(sz>0){
                Node* curr = q.front();
                q.pop();
               	
               	if(curr->left != NULL){
               		q.push(curr->left);
               	}
               	if(curr->right != NULL){
               		q.push(curr->right);
               	}
               	if(isodd){
                   odd+=curr->data;
               	}
               	else{
                   even+=curr->data;
               	}
               	
               	sz--;
           	}
           	isodd = !isodd;
       	}
       	return odd - even;
    }
};



//Second Solution :-
int sumeven=0;
int sumodd=0;
void solve(Node* root,int level){
    if(root==NULL){
    	return;
    }
    if(level%2==0){
    	sumeven+=root->data;
    }
    if(level%2==1){
    	sumodd+=root->data;
    }
    solve(root->left,level+1);
    solve(root->right,level+1);
}

int getLevelDiff(Node *root){
    solve(root,1);
    return sumodd - sumeven;
}



//Third Solution :-
class Solution{
public:
    int getLevelDiff(Node *root){
        if(root==NULL){
        	return 0;
        }
        
        int odd=0;
        int even =0;
       	
       	queue<Node*> q;
       	q.push(root);
       	int i=1;
       	
       	while(q.empty()==false){
           int size = q.size();
           
           	while(size--){
               	Node* temp = q.front();
               	q.pop();
               
               	if(i%2==1){
                   odd +=temp->data;
               	}
               	else{
                   even+=temp->data;
               	}
               
               	if(temp->left!=NULL){
                   	q.push(temp->left);
               	}
               	if(temp->right!=NULL){
                   	q.push(temp->right);
               	}
           	}
           	i++;
	    }
       	return odd - even;
    }
};

