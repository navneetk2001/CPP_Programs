https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1



//Solution Approach :-
void convertToDLL(Node *root, Node *(&head), Node *(&pre)){
   	if(!root){
       return;
   	}
   	convertToDLL(root->left, head, pre);
   	if(pre==NULL){
       head = root;
   	}
   	else{
       	root->left = pre;
       	pre->right = root; 
   	}
   	pre = root;
   	convertToDLL(root->right,head,pre);
}

vector<int> merge(Node *root1, Node *root2)
{
	Node *pre1=NULL,*pre2=NULL;
	Node *h,*hh;
	convertToDLL(root1,h,pre1);
	convertToDLL(root2,hh,pre2);
  	vector<int> v;
   
  	while(h or hh){
      	if(h and hh){
          	if(h->data>hh->data){
              	v.push_back(hh->data);
              	hh = hh->right;
          	}
          	else{
              	v.push_back(h->data);
              	h = h->right;
          	}
      	}
      	else if(h){
          	v.push_back(h->data);
         	h = h->right;
      	}
      	else{
          	v.push_back(hh->data);
          	hh = hh->right;
      	}
  	}	 
  	return v;
}



//Second Solution :-
class Solution{
    private:
        void inorder(Node *r1,vector<int> &in){
            if(r1==NULL) return;
            inorder(r1->left,in);
            in.push_back(r1->data);
            inorder(r1->right,in);
        }

        Node* mergeTree(vector<int> &in,int start,int end){
            if(start>end) return NULL;
            
            int mid = (start+end)/2;
            Node * root = new Node(in[mid]);
            root->left = mergeTree(in,start,mid-1);
            root->right = mergeTree(in,mid+1,end);
            return root;
        }
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> in;
       
       inorder(root1,in);
       inorder(root2,in);
       
       sort(in.begin(),in.end());
       Node * root = mergeTree(in, 0, in.size()-1);
       vector<int> newIN;
       inorder(root,newIN);
       return newIN;
    }
};



//Third Solution :-
vector<int> ans;
void traverse(Node *root){
	if(root==NULL) return;
	ans.push_back(root->data);
	traverse(root->left);
	traverse(root->right);
}

vector<int> merge(Node *root1, Node *root2)
{
	traverse(root1);
	traverse(root2);
	sort(ans.begin(),ans.end());
	return ans;
}



//Fourth Solution :-
class Solution{
    public:
    void convertBST2LL(Node* root,Node* &head){
        if(root==NULL){
            return ;
        }
        convertBST2LL(root->right,head);
       
        root->right=head;
        if(head!=NULL){
        head->left=root;
        }
        head=root;
        convertBST2LL(root->left,head);
        
    }
    
    Node* mergeLL(Node* head1,Node* head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        
        Node* head=NULL;
        Node* tail=NULL;
        while(head1 && head2){
            if(head1->data<head2->data){
                if(head==NULL){
                    head=head1;
                    tail=head1;
                    
                }
                else{
                    tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    
                }
                head1=head1->right;
            }
            else{
                if(head==NULL){
                    head=head2;
                    tail=head2;
                }
                else{
                    tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                }
                head2=head2->right;
            }
        }
        while(head1){
          
                tail->right=head1;
                head1->left=tail;
                tail=head1;
            
            head1=head1->right;
        }
        while(head2){
         
        
                tail->right=head2;
                head2->left=tail;
                tail=head2;
            
            head2=head2->right;
        }
        return head;
    }

     void getNodesData(Node* head,vector<int> &ans){
        // if(head==NULL){
        //     return ;
        // }
        
        while(head){
            ans.push_back(head->data);
            head=head->right;
            
        }
      
    }
   
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //covert first bst into linked list
      	Node* head1=NULL;
      	convertBST2LL(root1,head1);
      	head1->left=NULL;
      	//convert second bst into linked list
      	Node* head2=NULL;
      	convertBST2LL(root2,head2);
      	head2->left=NULL;
       
       	//merge two doubly linked list
       	Node* resultedLL=mergeLL(head1,head2);
       	vector<int> ans;
   
      	getNodesData(resultedLL,ans);
       	return ans;
    }
};




