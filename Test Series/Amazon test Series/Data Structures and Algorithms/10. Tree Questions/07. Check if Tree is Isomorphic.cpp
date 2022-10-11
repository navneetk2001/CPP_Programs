https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1



//Solution Approach :-
class Solution{
 public:
   // Return True if the given trees are isomotphic. Else return False.
   	bool isIsomorphic(Node *root1,Node *root2){
	   	if(root1==NULL and root2==NULL){
	   		return true;
	   	}
	   	if(root1==NULL or root2==NULL){
	   		return false;
	   	}
	   	if(root1->data!=root2->data){
	       return false;
	   	}
	   	bool a = isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
	   	bool b = isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
	   	return a or b;
   	}
};



//Second Solution :-
bool isIsomorphic(Node *root1,Node *root2)
{
	if(!root1 and !root2) return 1;
	if(!root1 or !root2) return 0;

	if(root1->data != root2->data) return 0;

	int a = isIsomorphic(root1->left, root2->left);
	int b = isIsomorphic(root1->right, root2->right);

	int c = isIsomorphic(root1->left, root2->right);
	int d = isIsomorphic(root1->right, root2->left);

	return max(min(a,b), min(c,d));
	
}



//Third Solution :-
void Traverse(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
     
    Traverse(root->left, v);
    v.push_back(root->data);
    Traverse(root->right, v);
}

bool isIsomorphic(Node *root1,Node *root2){
	vector<int> v1;
	vector<int> v2;
	Traverse(root1, v1);
	Traverse(root2, v2);

	if(v1 == v2){
	   return true;
	}
	
	reverse(v2.begin(), v2.end());
	if(v1 == v2){
	   return true;
	}
	return false;
}