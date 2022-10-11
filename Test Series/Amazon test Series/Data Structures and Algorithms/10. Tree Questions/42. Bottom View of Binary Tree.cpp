https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/




//Solution Approach :-
vector<int> bottomView(Node *root){
    vector<int> ans;
    if(root==NULL){
    	return ans;
    }

    map<int,int> mpp;
   	queue<pair<Node*,int>> q;
   	q.push({root,0});
   
   	while(!q.empty()){
       	auto it = q.front();
       	q.pop();
       
       	Node* node = it.first;
       	int line = it.second;
       
       	mpp[line] = node->data;
       
       	if(node->left){
           q.push({node->left,line-1});
       	}
       	if(node->right){
           q.push({node->right,line+1});
       	}
   	}
   
   	for(auto it : mpp){
       	ans.push_back(it.second);
   	}
   	return ans;
}



//Second Solution :- DFS code passed :
class Solution {
public:
   	void hlp(Node* root, int hd, int lvl, map<int,pair<int,int>> &mp){
       	if(!root){
       		return;
       	}

       	if(!mp.count(hd) or lvl >= mp[hd].first){
           	mp[hd] = {lvl, root->data};            
       	}
       	hlp(root->left,hd-1,lvl+1,mp);
       	hlp(root->right,hd+1,lvl+1,mp);
   	}

   	vector <int> bottomView(Node *root) {
       	if(!root){
       		return {};
       	}
       
       	vector<int>ans;
       	map<int,pair<int,int>>mp;
       	if(!root->left and !root->right){
       		return {root->data};
       	}
       	hlp(root,0,0,mp);
       	for(auto &el : mp){
           	ans.push_back(el.second.second);
       	}
       	return ans;
   	}
};	



//Third Solution :-
void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m){
    if (root == NULL){    // Base case
        return;
    }
    
    // If node for a particular horizontal distance is not present, add to the map.
    if (m.find(hd) == m.end()){
        m[hd] = make_pair(root -> data, curr);
    } 
    else{                           // Compare height for already present node at similar horizontal distance
        pair<int,int> p = m[hd];
        if(p.second <= curr){
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }
    
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);    
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}

void printBottomView(Node * root) {
    map<int, pair<int,int>> m;       // Map to store Horizontal Distance, Height and Data.
    
    printBottomViewUtil(root, 0, 0, m);    
    for(auto it = m.begin(); it != m.end(); ++it){
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}