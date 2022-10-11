https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1




//Solution Approach :-
class Solution{
public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *A)
    {
        queue<pair<int, Node*>> q;
        vector<int> ans;
        map<int, vector<int>> mp;
    
        if(A == NULL){
        	return ans;
        }
    
        q.push({0,A});
        while(!q.empty()){
            auto top_elem = q.front();
            q.pop();

            auto lev = top_elem.first;
            auto node = top_elem.second;

            mp[lev].push_back(node->data);    //push element in map level wise
    
            if(node->left){
              	q.push({lev-1, node->left});  
            }
    
            if(node->right){
                q.push({lev+1, node->right});
            }
        }
    
        for(auto it : mp){
        	for(auto iter : it.second){
        		ans.push_back(iter);
        	}
        }
        return ans;
    }
};





//Second Solution :-
// we need to keep track of the levels so i am using y to for that 
// BFS method is better for this problem still if someone wants to try DFS
// i am doing x*100 + y to generate unique key in our key both x and y should be there because we are maintaining both left->right and to->bottom order
    
void dfs(Node *root, int x, int y, map<int,vector<int>> &mp){
    if(!root){
    	return;
    }
  
    mp[x*100+y].push_back(root->data);
    
    dfs(root->left,x-1,y+1,mp);
    dfs(root->right,x+1,y+1,mp);
     
}

vector<int> verticalOrder(Node *root){
    vector<int> ans;
    map<int, vector<int>> mp;
    
    dfs(root, 0, 0, mp);
    for(auto it:mp){
        for(auto x:it.second){
        	ans.push_back(x);
        }
    }
    return ans;
}



//Second Approach :-
map<pair<int, int>, vector<int>> m;
void help(Node* root, int x, int y)
{
   	if(!root){
   		return;
   	}
   	m[{x, y}].push_back(root->data);
   	help(root->left, x-1, y+1);
   	help(root->right, x+1, y+1);
}

vector<int> verticalOrder(Node *root){
   	vector<int> ans;
   	if(!root)return ans;
   	help(root, 0, 0);
   	
   	for(auto i:m){
       	for(auto j:i.second){
           	ans.push_back(j);
       	}
   	}
   	return ans;
}




//Third Solution :-
class Solution{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>q;
        vector<int>ans;
        
        if(root==NULL){
            return ans;
        }
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            //front value of queue
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd=temp.second.first;
            int level=temp.second.second;
            
            nodes[hd][level].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,level+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,level+1)));
            }
            
        }
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};