https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1




//Solution Approach :-
class Solution{
    public:
    /* Should return minimum distance between a and b in a tree with given root*/
    Node* lca(Node* root, int a, int b){
        if(root == NULL) return NULL;
        if(root->data == a || root->data == b){
        	return root;
        }
        
        Node* left = lca(root->left,a,b);
        Node* right = lca(root->right,a,b);

        if(left != NULL && right != NULL){
        	return root;
        }
        if(left != NULL){
            return lca(root->left,a,b);
        }
        return lca(root->right,a,b);
    }

    long getDist(Node* root,int a){
        if(root == NULL){
        	return INT_MAX;
        }
        if(root->data == a){
        	return 0;
        }
        long left = getDist(root->left,a);
        long right = getDist(root->right,a);
        return 1 + min(left,right);
    }

    int findDist(Node* root, int a, int b) {
        Node* lc = lca(root,a,b);
        return getDist(lc,a) + getDist(lc,b) ;
    }
};



//Second Solution :- A different approach (Unique one 😎😎)
void pyata(Node* root, int x, string &s, string curr){
    if(!root){
    	return;
    }
    if(root->data==x){
        s = curr;
        return;
    }
    pyata(root->left,x,s,curr+"L");
    pyata(root->right,x,s,curr+"R");
}

int findDist(Node* root, int a, int b) {
    string str1 = "", str2 = "";
    pyata(root, a, str1, "");
    pyata(root, b, str2, "");
    
    int i,j,l1 = str1.size(), l2 = str2.size();
    for(i=0,j=0; i<l1 && j<l2; i++,j++){
        if(str1[i]!=str2[j]){
            break;
        }
    }
    
    return (l1-i+l2-j);
}




//Third Solution :-
bool route(Node * node,int goal,vector<int> & vec){
    if(node != NULL){
        vec.push_back(node->data);
        if(node->data==goal){
            return true;
        }
        bool res1=route(node->left,goal,vec);
        if(res1){
            return true;
        }
        bool res2=route(node->right,goal,vec);
        if(res2){
            return true;
        }
        vec.pop_back();
    }
    return false;
}

int findDist(Node* root, int a, int b) {
    vector<int> r1;
    route(root,a,r1);

    vector<int> r2;
    route(root,b,r2);

    unordered_map<int,int> mp,mp1;
    for(auto v:r1){
        mp[v]++;
    }
    for(auto v:r2){
        mp[v]++;
    }

    for(int i=r1.size()-1;i >=0;i--){
        if(mp[r1[i]] > 1){
            mp1[r1[i]]=r1.size()-i-1;
        }
    }

    int res=INT_MAX;
    for(int i=r2.size()-1;i >=0;i--){
        if(mp[r2[i]] > 1){
            int temp=r2.size()-i-1+mp1[r2[i]];
            res=std::min(res,temp);
        }
    }
    return res;
}



//Fourth Solution :- FIND ANS BY TRACKING PARENT C++ EASY SOLUTION
class Solution{
    public:
    void mark_parents(Node* root,unordered_map<Node*,Node*>&parent_track,int a,Node* &start)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *current=q.front();
            q.pop();
            if(current->data==a)
            {
                start=current;
            }
            if(current->left)
            {
                parent_track[current->left]=current;
                q.push(current->left);
            }
            if(current->right)
            {
                parent_track[current->right]=current;
                q.push(current->right);
            }
        }
        
    }

    int findDist(Node* root, int a, int b) {
        Node* start=NULL;
        unordered_map<Node*,Node*>parent_track;

        mark_parents(root,parent_track,a,start);
        
        int dis=0;
        unordered_map<Node*,bool>visited;
        queue<pair<Node*,int>>q;
        q.push({start,0});
        
        visited[start]=true;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *current=q.front().first;
                int dist=q.front().second;
                q.pop();
                
                if(current->data==b)
                {
                    
                    return dist;
                }
                if(current->left && !visited[current->left])
                {
                    q.push({current->left,dist+1});
                    visited[current->left]=true;
                    
                }
                if(current->right && !visited[current->right])
                {
                    q.push({current->right,dist+1});
                    visited[current->right]=true;
                   
                }
                if(parent_track[current] && !visited[parent_track[current]])
                {
                    q.push({parent_track[current],dist+1});
                    visited[parent_track[current]]=true;
                    
                }
                
            }
           
        }
        return -1;
    }
};