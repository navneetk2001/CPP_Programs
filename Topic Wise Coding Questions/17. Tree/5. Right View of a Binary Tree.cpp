One Approach :-
//We can do BFS and we can print the last element of each level after traversing level-order wise

Another Approach :-
//We can do DFS and using recursion we can print right view using maxlevel and curr_level

void printRightView(node *root, int level, int &maxlevel){
	if(root==NULL){
		return;
	}

	if(maxlevel<level){
		//have discovered a new level
		cout<<root->data<<" ";
		maxlevel=level;
	}

	printRightView(root->right,level+1,maxlevel);
	printRightView(root->left,level+1,maxlevel);
}

int main(){
	int maxlevel=-1;
	printRightView(root,0,maxlevel);
}

