// Geek is at the geek summer carnival. To unlock discounts on exclusive courses he is given a card with a binary tree, a target node and a positive integer k on it. 
// He needs to find the sum of all nodes within a max distance k from target node such that the target node is included in sum.

// Example 1:
// Input:
// target = 9 
// k = 1
// Binary Tree = 
//             1
//            /  \
//           2    9
//         /     /  \
//        4     5    7
//       /  \       /  \
//      8    19    20   11
//     /   /   \
//   30   40   50

// Output: 22
// Explanation: Nodes within distance 1 from 9 => 9 + 5 + 7 + 1 = 22

// Example 2:
// Input:
// target = 40 
// k = 2
// Binary Tree = 
//             1
//            /  \
//           2    9
//         /     /  \
//        4     5    7
//       /  \       /  \
//      8    19    20   11
//     /   /   \
//   30   40   50

// Output: 113
// Explanation: Nodes within distance 2 from 40, => 40 + 19 + 50 + 4 = 113




//Solution Approach :-        
class Solution{
public:
    void add_subtree(Node* curr, int dis, int *sum){
      if(curr==NULL || dis<0){
        return;
      }
      *sum+=curr->data;
      add_subtree(curr->left,dis-1,sum);
      add_subtree(curr->right,dis-1,sum);
    }


    int traverse(Node* curr,int target,int k,int *sum){
        if(curr==NULL){
          return -1;
        }
        if(curr->data==target){
          add_subtree(curr,k,sum);
          return k-1;
        }

        int dis=traverse(curr->left,target,k,sum);
        if(dis>-1){    //target is found in left subtree
          *sum+=curr->data;
          add_subtree(curr->right,dis-1,sum);
          return dis-1;
        }  

        dis=traverse(curr->right,target,k,sum);
        if(dis>-1){   //target is found in right subtree
          *sum+=curr->data;
          add_subtree(curr->left,dis-1,sum);
          return dis-1;
        }
        return -1;
    }


    int sum_at_distK(Node* root, int target, int k)
    {
        int sum=0;
        traverse(root,target,k,&sum);
        return sum;
    }
};



//Second Solution :-
int sum_at_distK(Node* root, int target, int k)
{
    vector<vector<int>> adj(10001);
    stack<Node*> stk;
    stk.push(root);

    while(!stk.empty()){
        Node *t = stk.top();
        stk.pop();

        if(t->right){
            stk.push(t->right);
            adj[t->data].push_back(t->right->data);
            adj[t->right->data].push_back(t->data);
        }
        if(t->left){
            stk.push(t->left);
            adj[t->data].push_back(t->left->data);
            adj[t->left->data].push_back(t->data);
        }
    }

    int res = 0;
    stack<pair<int,int>> st;
    st.push({target,0});
    bool vis[100001]={false};

    while(!st.empty()){
        pair<int,int> top = st.top();
        st.pop();
        vis[top.first] = true;
        res+=top.first;

        for(int i=0;i<adj[top.first].size();i++){
            if(top.second+1>k || vis[adj[top.first][i]]==true)
              continue;
            st.push({adj[top.first][i],top.second+1});
        }
    }
    return res;
}



//Third Solution :-
class Solution{
  unordered_map<Node*,Node*>Map;
  unordered_map<Node*, bool>vis;

  Node* node;
  int sum = 0;
public:
  void getTargetNode(Node* p, Node* root,int target){
      if(!root) return;
      
      Map[root] = p;
      if(root->data == target){
          node = root;
          return;
      }
      
      getTargetNode(root,root->left, target);
      getTargetNode(root,root->right,target);
      
      return;
  }

  void getTheSumofAllKthNode(Node* root,int k){
      if(!root || k < 0) return;

      if(vis.find(root) != vis.end()) return;
      
      vis[root] = true;
      sum += root->data;
      
      getTheSumofAllKthNode(Map[root] ,k-1);
      getTheSumofAllKthNode(root->left,k-1);
      getTheSumofAllKthNode(root->right,k-1);
      
      return;
  }

  int sum_at_distK(Node* root, int target, int k)
  {
      getTargetNode(NULL,root,target);
      getTheSumofAllKthNode(node,k);
      return sum;
  }
};



//Fourth Solution :-
 void compute(Node* root, int t,unordered_map<Node*, Node*> &parent, Node* &target, Node* &p){
    if(root == NULL)
        return;
    
    if(root->data == t) 
        target = root;
        
    parent[root] = p;
    
    compute(root->left, t, parent, target, root);
    compute(root->right, t, parent, target, root);
    
}
  
void dfs(Node* target, int k, unordered_map<Node*, Node*> &parent, unordered_set<int> &visited, int &ans) {
    
    if(k < 0) 
        return;
    
    ans += target->data;
    visited.insert(target->data);
    
    if(target->left != NULL && visited.find(target->left->data) == visited.end()){
      dfs(target->left, k-1, parent, visited, ans);
    }
      
    if(target->right != NULL && visited.find(target->right->data) == visited.end()){
      dfs(target->right, k-1, parent, visited, ans);
    }
    
    if(parent[target] != NULL && visited.find(parent[target]->data) == visited.end()){
      dfs(parent[target], k-1, parent, visited, ans);
    }
}
    
int sum_at_distK(Node* root, int t, int k) {
   unordered_map<Node*, Node*> parent;
   Node* target = NULL;
   Node *p = NULL;
   
   compute(root, t, parent, target, p);
  
   unordered_set<int> visited;
   
   int ans = 0;
   dfs(target, k, parent, visited,  ans);
   
   return ans;
}