// Absolute Difference of left subtree height and right subtree height should be less than 1

//PostOrder + Bottomup Approach :-

class HBPair{
public:
	int height;
	int balance;
};

HBPair isHeightBalanced(node *root){
	HBPair p;
	if(root==NULL){
		p.height=0;
		p.balance=true;
		return p;
	}

	//Recursive case
	HBPair left = isHeightBalanced(root->left);
	HBPair right = isHeightBalanced(root->right);

	p.height=max(left.height,right.height)+1;

	if(abs(left.height-right.height)<=1 && left.balance && right.balance){
		p.balance=true;
	}
	else{
		p.balance=false;
	}
	return p;
}


int main(){
	if(isHeightBalanced(root).balance){
		cout<<"Height Balanced Binary Tree"<<endl;
	}
	else{
		cout<<"Not a Height Balanced Binary Tree"<<endl;
	}
}