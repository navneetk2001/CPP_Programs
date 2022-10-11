https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1





//Solution Approach :-
class Solution{
public:
    void connect(Node *root){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){
                Node* x=q.front();
                q.pop();
                 
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
                if(i==n-1){
                    x->nextRight=NULL;
                }
                else{
                    x->nextRight=q.front();
                }
            }
        }
    }    
};




//Second Solution :-
class Solution{
public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        queue<Node*> pending_nodes;
    	Node* prev=NULL;
    	Node* end=root;
    	Node* next_end=NULL;
    	pending_nodes.push(root);

    	while(pending_nodes.size()){
    		Node* front_node=pending_nodes.front();
    		pending_nodes.pop();

    		if(front_node->left){                 //if left child is not null,push left node in queue and update next_end
    			pending_nodes.push(front_node->left);
    			next_end=front_node->left;
    		}
    		if(front_node->right){          //if right child is not null,push right node in queue and update next_end 
    			pending_nodes.push(front_node->right);
    			next_end=front_node->right;
    		}
    		if(prev!=NULL){     //when its prev exists
    			prev->nextRight=front_node;
    		}
    		if(front_node==end){
    			end=next_end;
    			prev=NULL;
    			next_end=NULL;
    		}
    		else{
    			prev=front_node;
    		}
    	}
    }    
};



//Third Solution :-
class Solution{
public:
    void connect(Node *root){
        queue<Node*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            int n = queue.size();
            Node* prev = NULL;
            
            for(int i=0; i<n; i++){
                Node* curr = queue.front();
                queue.pop();
                
                curr->nextRight = prev;
                prev = curr;
                
                if(curr->right){
                    queue.push(curr->right);
                }
                if(curr->left){
                    queue.push(curr->left);
                }
            }
        }
    }    
};



//Fourth Solution :-
void level(Node *root, int l, map<int,Node*> & mp) {
    if(root==NULL){
    	return;
    }
    
    if(mp.find(l)==mp.end()){
        mp[l]=root;
    }
    else{
        mp[l]->nextRight=root;
        mp[l]=root;
    }
    level(root->left,l+1,mp);
    level(root->right,l+1,mp);
}

void connect(Node *root){
   map<int, Node*> mp;
   level(root,0,mp);
}