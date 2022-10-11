https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1




//First Solution :-
Node *createTree(int par[], int N){
   	vector<Node*> v;
   	for(int i=0; i<N; i++){
       	Node* temp = new Node(i);
       	v.push_back(temp);
   	}

   	Node *root = NULL;
   	for(int i=0;i<N;i++){
       	if(par[i]==-1){
       		root = v[i]; 
       		continue;
       	}
       	if(v[par[i]]->left == NULL){
       		v[par[i]]->left = v[i];
       	}
       	else{
       		v[par[i]]->right=v[i];
       	}
   	}
   	return root;
}





//Second Solution :-
Node *createTree(int parent[], int N){
   	map<int,Node*>m;
   	Node*root = NULL;
   	
   	for(int i=0;i<N;i++){
       Node*temp=new Node(i);
       m[i]=temp;
   	}

   	for(int i=0;i<N;i++){
       if(parent[i]==-1){
           root=m[i];
       }
       else{
           if(m[parent[i]]->left==NULL){
               m[parent[i]]->left=m[i];
           }
           else{
               m[parent[i]]->right=m[i];
           }
       }
   	}
   	return root;
}