https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1



//Solution Approach :-
class Solution
{
public:
   	void printkdistanceNodeDown(Node *root, int k,vector<int> &v)
   	{
       	if (root == NULL || k < 0)  return;
       	if (k==0)
       	{
           v.push_back(root->data);
           return;
       	}
       	printkdistanceNodeDown(root->left, k-1,v);
       	printkdistanceNodeDown(root->right, k-1,v);
   	}
   int printkdistanceNode(Node* root, int target , int k,vector<int> &v)
   {
       if (root == NULL) return -1;
       if (root->data == target)
       {
           printkdistanceNodeDown(root, k,v);
           return 0;
       }
       int dl = printkdistanceNode(root->left, target, k,v);
       if (dl != -1)
       {
            if (dl + 1 == k)
               v.push_back(root->data);
            else
               printkdistanceNodeDown(root->right, k-dl-2,v);
            return 1 + dl;
       }
       int dr = printkdistanceNode(root->right, target, k,v);
       if (dr != -1)
       {
            if (dr + 1 == k)
               v.push_back(root->data);
            else
               printkdistanceNodeDown(root->left, k-dr-2,v);
            return 1 + dr;
       }
       return -1;
   }

   vector <int> KDistanceNodes(Node* root, int target , int k)
   {
       // return the sorted vector of all nodes at k dist
       vector<int> v;
       printkdistanceNode(root,target,k,v);
       sort(v.begin(),v.end());
       return v;
       
   }
};



//Approach :-
// find the root to node path.It will help in getting the resultant nodes.
// store this path in stack.
// Now we have to print the nodes at k distance for every node in the path 
// for the target node we have to print all nodes at distance k.
// for father of target we have to print all nodes at distance k-1 and remember we can't print nodes of target. so we have a blocker variable.
   
void printKlevelDown(Node* root,Node* blocker, vector<int> &res, int x)
{
   	if(!root || x<0 || root==blocker)
  		return;
   
   	if(x==0){
   		res.push_back(root->data);
   	}
   
   	printKlevelDown(root->left,blocker,res,x-1);
   	printKlevelDown(root->right,blocker,res,x-1);
}
void rootToNodePath(Node* root, int target, vector<Node*>&v, stack<Node*> &st)
{
   if(!root)
   return;
   
   v.push_back(root);
   
   if(root->data==target)
   {
       for(int i=0;i<v.size();i++)
       st.push(v[i]);
       return;
   }
   
   rootToNodePath(root->left,target,v,st);
   rootToNodePath(root->right,target,v,st);
   
   v.pop_back();
}

vector <int> KDistanceNodes(Node* root, int target , int k)
{
   	vector<int> res;
   	vector<Node*>v;
   	stack<Node*>st;
   	rootToNodePath(root,target,v,st);
   
   	Node* blocker=NULL;
   	int d=0;
   	while(!st.empty() && d<=k)
   	{
       	printKlevelDown(st.top(),blocker,res,k-d);
       	d++;
       	blocker=st.top();
       	st.pop();
   	}
   	sort(res.begin(),res.end());
   	return res;
}



//Second Solution :-
//Just convert the tree into graph and then apply bfs
class Solution{
public:
    int count(Node* root){
        if(!root){
          	return 0;
        }
        return 1+count(root->left)+count(root->right);
    }

    void dfs(Node* root,vector<vector<int>>&adj){
        if(!root){
        	return;
        }

        if(root->left){
            int u=root->data,v=root->left->data;
            adj[u].push_back(v);
            adj[v].push_back(u);        
        }

        if(root->right){
            int u=root->data,v=root->right->data;
            adj[u].push_back(v);
            adj[v].push_back(u);  
        }

        dfs(root->left,adj);
        dfs(root->right,adj);
    }

    vector<int>KDistanceNodes(Node* root,int target,int k)
    {
        // return the sorted vector of all nodes at k dist
        int n=count(root);
        vector<vector<int>>adj(10001);
        dfs(root,adj);

        queue<int>q;
        vector<int> v, visited(10001,0), dist(10001,0);

        if(!root->left&&!root->right){
            if(k==0){
                v.push_back(root->data);
            }
            return v;
        }
        if(k==0){
            v.push_back(target);
            return v;
        }

        q.push(target);
        visited[target]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();

            for(int i:adj[temp]){
                if(!visited[i]){
                    visited[i]=1;
                    dist[i]=1+dist[temp];
                    if(dist[i]==k){
                    	v.push_back(i);
                    }
                    else if(dist[i]<k){
                    	q.push(i);
                    }
                }
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};



//Third Solution :-
//very simple code just need to use a bit of graph theory of making a visited hash 

class Solution {
private:
    Node* T;
public:
    void markParents(Node* root, int target, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(root);
        parent[root] = nullptr;
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current -> data == target) {
                T = current;
            }
            if (current -> left) {
                parent[current -> left] = current;
                q.push(current -> left);
            }
            if (current -> right) {
                parent[current -> right] = current;
                q.push(current -> right);
            }
        }
    }
    vector<int> KDistanceNodes(Node* root, int target , int k) {
        unordered_map<Node*, Node*> parent;
        markParents(root, target, parent);

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(T);
        visited[T] = true;
        int currentLevel = 0;
        
        while (!q.empty()) {
            int size = q.size();
            if (currentLevel++ == k) {
                break;
            }
            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();
                if (current -> left && !visited[current -> left]) {
                    visited[current -> left] = true;
                    q.push(current -> left);
                }
                if (current -> right && !visited[current -> right]) {
                    visited[current -> right] = true;
                    q.push(current -> right);
                }
                if (parent[current] && !visited[parent[current]]) {
                    visited[parent[current]] = true;
                    q.push(parent[current]);
                }
            }
        }
        vector<int> output;
        while (!q.empty()) {
            output.push_back(q.front() -> data);
            q.pop();
        }
        sort(output.begin(), output.end());
        return output;
    }
};




