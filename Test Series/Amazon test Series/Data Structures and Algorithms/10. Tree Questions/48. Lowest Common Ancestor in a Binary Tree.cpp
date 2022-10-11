https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1




//Solution Approach :-
// The question is simply asking to find the subtree's root which will contain both n1 and n2, right?! So we do the same,
// 1. Well, if there is no root, you gotta return null/root. if(root==nullptr) { return root; }  
// 2. if your root data contains either n1 or n2, you return that root. WHY?? because it will be used in calculation of two different answer A.K.A. left and right side of tree.
// 3. Now save your Left answer of the left side of tree in a variable, this variable with either have a null or a valid node depending on recursive calls if it finds the required node, Do the same for the Right side make a variable and save the answer.
// 4. Now, we have two different variables namely left and right. Both contains answer either null or a valid node, now we check three conditions
// 5. If Left answer is not null and right answer is also not null, then the answer is the root itself, since left and right are subtrees of the root and if both are not null it clearly means the values n1 and n2 lies in right as well as left side, For example, Example test case 1 is the perfect example for this case
// 6. If left answer is not null but right answer is null, then it means both n1 and n2 lies on the left side of tree inside the subtree with root as left answer, return left answer. For example, Example test case 2 is the perfect example for this case
// 7. If right answer is not null but left answer is null, then it means both n1 and n2 lies on the right side of tree inside the subtree with root as right answer, return right answer.


Node* lca(Node* root ,int n1 ,int n2 ) {
    if(root==nullptr){
        return root;
    }
    
    if(root->data==n1 || root->data==n2){
        return root;
    }
    
    Node* LEFTSIDE  =lca(root->left,n1,n2);
    Node* RIGHTSIDE =lca(root->right,n1,n2);
    
    if(LEFTSIDE!=nullptr && RIGHTSIDE!=nullptr){
        return root;
    } 
    else if(LEFTSIDE!=nullptr){
        return LEFTSIDE;
    }
    else{
        return RIGHTSIDE;
    }
}





//Second Solution :-
class Solution{
public:
   	bool findPath(Node* root, vector<Node*> &v, int key)
   	{
       	if(root==NULL){
       		return false;
       	}
       	v.push_back(root);
       
       	if(root->data==key){
        	return true;
       	}
       	if(findPath(root->left,v,key) || findPath(root->right,v,key)){
        	return true;
       	}
       	v.pop_back(); 
       	return false;
   	}
   	
   	Node* lca(Node* root ,int n1 ,int n2 ){      
      	vector<Node*> v1, v2;
      	Node* ans=NULL;
      	if(findPath(root,v1,n1)==false || findPath(root,v2,n2)==false){
        	return NULL;
      	}
     	for(int i=0;i<v1.size() && i<v2.size() ;i++){
	       	if(v1[i]->data == v2[i]->data){
	         	ans=v1[i]; 
	       	}
	    }
    	return ans;
   	}
};




