https://practice.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1




//Solution Approach :-
class Solution{
 public:
   	void rec(Node* node, int& globMax, int tempMax, int parent){
       	if(node == NULL){
       		return;
       	}
       	if(node->data == parent + 1){
       		tempMax++;
       	}
       	else{
       		tempMax = 1;
       	}
       	globMax = max(globMax,tempMax);
       	rec(node->left, globMax, tempMax, node->data);
       	rec(node->right,globMax, tempMax, node->data);
       	return;
   	}
   
   	int longestConsecutive(Node* root){
       	int globMax = 1;
       	rec(root->left,globMax,1,root->data);
       	rec(root->right,globMax,1,root->data);
       	if(globMax < 2){
       		return -1;
       	}
       	return globMax;
   	}
};




//Second Solution :-
class Solution{
public:
    int ans=0;
    int solve(Node* root){
        if(root==NULL){
        	return ans;
        }
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        int left=1;
        int right=1;
        if(root->left!=NULL && root->left->data == root->data+1){
            left = l + 1;
        }
        
        if(root->right!=NULL && root->right->data== root->data+1){
            right = r + 1;
        }
        
        int ttl = max(left,right);
        ans= max(ans,ttl);
        return max(left,right);
    }

    int longestConsecutive(Node* root){
        ans=0;
        solve(root);
        if(ans<2) return -1;
        return ans;
    }
};



//Third Solution :-
void traverse(Node* root,int cnt,int &max,int prev){
	if(root==NULL){
		return;
	}
	if(root->data==prev+1){
		cnt+=1;
		if(cnt>max){
			max=cnt;
		}
	}
	else{
		cnt=1;
		traverse(root->left,cnt,max,root->data);
		traverse(root->right,cnt,max,root->data);
	}
}

int longestConsecutive(Node* root){
	int prev = root->data;
	int max = 1;
	int cnt = 1;
	traverse(root,cnt,max,prev);
	if(max==1){
		return -1;
	}
	else{
		return max;
	}
}