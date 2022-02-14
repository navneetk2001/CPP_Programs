

// 2 parts of this Question :-
// a. Print at Level K(Target, K)
// b. we need to note the ancestors of target Node
// c. We also need to find how far the target node is from its ancestors
// d. And then traverse k-2-l steps towards another side


void printAtLevelK(node *root, int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
	return;
}



int printAtDistanceK(node *root,node *target, int k){
	//base case
	if(root==NULL){
		return -1;
	}

	//while traversing , reach the target node
	if(root==target){
		printAtLevelK(target,k);
		return 0;
	}
	//next step :- we are going to the ancestor of target
	int DL = printAtDistanceK(root->left,target,k);
	
	if(DL!=-1){
		//Again there are 2 cases
		//Ancestor itself or you need to go to the right ancestor
		if(DL+1==k){
			cout<<root->data<<" ";
		}
		else{
			printAtLevelK(root->right,k-2-DL);
		}
		return 1+DL;
	}

	int DR = printAtDistanceK(root->right,target,k);
	
	if(DR!=-1){
		//Again there are 2 cases
		//Ancestor itself or you need to go to the right ancestor
		if(DR+1==k){
			cout<<root->data<<" ";
		}
		else{
			printAtLevelK(root->left,k-2-DR);
		}
		return 1+DR;
	}

	return -1;   //node was not present in either subtree (left or right)
}