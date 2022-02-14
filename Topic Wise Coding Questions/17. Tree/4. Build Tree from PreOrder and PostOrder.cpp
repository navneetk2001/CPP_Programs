
//Build Tree from PreOrder and InOrder :- 
//Preorder :- [1 2 3 4 8 5 6 7]
//Inorder :- [3 2 8 4 1 6 7 5]


//Steps :-
//1. Iterative pick one data from inorder , create a node
//2. Search for i
//3. fun(s,i-1)      fun(i+1,e)


node* createTreefromInAndPre(int *in, int *pre, int s, int e){
	static int i=0;
	//Base case
    if(s>e){
    	return NULL;
    }	
    //Rec Case
    node *root=new node(pre[i]);

    int index=-1;
    for(int j=s;j<=e;j++){
    	if(in[j]==pre[i]){
    		index=j;
    		break;
    	}
    }

    root->left=createTreefromInAndPre(in,pre,s,index-1);
    root->right=createTreefromInAndPre(in,pre,index+1,e);
    return root;
}


