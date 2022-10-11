https://practice.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order/1/



//Solution Approach :-
class Solution{
  public:
    /* Function to print nodes of extreme corners of each level in alternate order */
    vector<int> ExtremeNodes(Node* root){
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool flag=false;

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* node=q.front();
                q.pop();

                if(!flag and i==sz-1){
                    ans.push_back(node->data);
                }
                else if(flag and i==0){
                    ans.push_back(node->data);
                }
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            flag=!flag;
        }
        return ans;
    }
};



//Second Solution :-
vector<int> ExtremeNodes(Node* root)
{
   	vector<int>v;
   	if(!root){
   		return v;
   	}
   	queue<Node*>q;
   	q.push(root);
   	int level=1;

   	while(!q.empty()){
       	int n=q.size();
       	for(int i=0;i<n;i++){
           	Node*temp=q.front();
           	q.pop();
           	if(level%2==1 && i==n-1){
                   v.push_back(temp->data);
           	}
           	if(level%2==0 && i==0){
                v.push_back(temp->data);
           	}
           	if(temp->left){
               	q.push(temp->left);
           	}
           	if(temp->right){
               	q.push(temp->right);
           	}
       	}
       	level++;
   	}
   	return v;
}




//Third Solution :- 
class Solution{
public:
    /* Function to print nodes of extreme corners of each level in alternate order */
    vector<int> ans ;
    void findValues(Node *node, int level)
    {
        if(node == nullptr){
        	return;
        }
        
        if(ans.size() == level){           // Then we have to insert the value.
            ans.push_back(node->data) ;
        }
        else{                             // We will have to check whether it is the even or odd level
            if(level%2 == 0){             // If it is a even level then the value needs to be updated each and every time
            	ans[level] = node->data ;
            }
        }
        
        findValues(node->left, level+1) ;
        findValues(node->right, level+1) ;
    }
    
    vector<int> ExtremeNodes(Node* root){
        // For EVEN levels we have to find the LAST entry Right View,  // for the ODD levels we have to find the LEFT view/ FIRST entry
        ans.clear() ;
        findValues(root, 0) ;
        return ans ;
    }
};