https://practice.geeksforgeeks.org/problems/vertical-sum/1



//Solution Approach :-
//time complexity nlog(hd) where hd is the  horizontal distance used to store value in map data structure.

class Solution{
public:
  	void check(Node *root, int hd, map<int,int>&m){
      	if(root==NULL){
      		return;
      	}
      	check(root->left,hd-1,m);
      	m[hd] += root->data;
      	check(root->right,hd+1,m);
  	}
  
    vector<int> verticalSum(Node *root) {
        map<int,int>m;
        int hd=0;
       	check(root,hd,m);

       	vector<int>v;
       	for(auto i:m){
         	v.push_back(i.second);  
       	}
       	return v; 
    }
};



//Second Solution :-
vector<int> verticalSum(Node *root) {
   	vector<int> ans;
   	if(root == NULL){
       return ans;
   	}

   	map<int,int> mp;
   	queue<pair<Node*,int>> q;

   	q.push({root,0});
   
   	while(!q.empty())
   	{
       	auto temp = q.front();
       	q.pop();
       
       	Node* curr = temp.first;
       	int val = temp.second;
       
       	mp[val] = mp[val]+curr->data;
       
       	if(curr->left) q.push({curr->left,val-1});
       	if(curr->right) q.push({curr->right,val+1});
   	}
   	
   	for(auto x:mp){
       ans.push_back(x.second);
   	}
   	return ans;
}


