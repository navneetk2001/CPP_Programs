https://practice.geeksforgeeks.org/problems/check-if-subtree/1



//Solution Approach :-
bool isIdentical(Node* a, Node* b)
{
   	if(!a && !b){
   		return true;
   	}
    if(!a||!b){
    	return false;
    }
       
    if(a->data!=b->data){
       	return false;
    }
       
    return isIdentical(a->left, b->left) && isIdentical(a->right,b->right);
}

bool isSubTree(Node* T, Node* S) {
	if(!T){
		return false;
	}
	if(isIdentical(T,S)){
		return true;
	}
	return isSubTree(T->left,S) || isSubTree(T->right,S);
}



//Second Solution :-
bool isIdentical(Node*t, Node*s){
	if(t==NULL && s==NULL){
		return true;
	}
	if(t==NULL){
		return false;
	}
	if(s==NULL){
		return false;
	}
	if(t->data == s->data){
		return (isIdentical(t->left,s->left)&&isIdentical(t->right,s->right));
	}
	return false;
}

bool isSubTree(Node* t, Node* s)  {
   	if (t==NULL) return false;
   	if (s==NULL) return true;
   	if (isIdentical(t,s)) return true;
   	return (isSubTree(t->left,s) || isSubTree(t->right,s));
}




//Third Solution :- Solution based on serialization of tree;
string serialize(Node* root){
    if(!root){
        return "$";
    }
    if(root->left == NULL && root->right == NULL){
        return to_string(root->data);
    }
    string s = "";
    s = s+ to_string(root->data);
    s = s+ serialize(root->left);
    s = s+serialize(root->right);
    return s;
}

string countandS(Node* root, unordered_map <string, int> &m){
    if(!root){
        return "$";
    }
    if(root->left == NULL && root->right == NULL){
        string temp = to_string(root->data);
        m[temp]++;
        return temp;
    }
    string s = "";
    s = s+ to_string(root->data);
    s = s+ countandS(root->left,m);
    s = s+countandS(root->right,m);
    m[s]++;
    return s;
}

bool isSubTree(Node* T, Node* S) 
{
    unordered_map <string,int> m;
    string s = serialize(S);
    countandS(T,m);
    // for(auto ele : m){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }
    if(m[s]>=1){
        return true;
    }
    return 0;
    
}