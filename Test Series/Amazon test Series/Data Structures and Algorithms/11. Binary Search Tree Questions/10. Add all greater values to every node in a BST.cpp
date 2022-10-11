https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1




//Solution Approach :-
void solve(Node* root,int& sum){
    if(!root){
    	return;
    }
    
    solve(root->right,sum);

    sum+=root->data;
    root->data=sum;

    solve(root->left,sum);
}

Node* modify(Node *root){
    int sum=0;
    solve(root,sum);
    return root;
}



//Second SOlution :-
void inot(vector<pair<int,int>> &v, Node* root)
{
    if(root==NULL)
        return;
    inot(v,root->left);
    v.push_back(make_pair(root->data,root->data));
    inot(v,root->right);
}

void assign(Node* root, vector<pair<int,int>> &v)
{
    if(root==NULL)
        return;
    assign(root->left,v);
    for(int i=0;i<v.size();i++)
    {
        if(root->data == v[i].first)
        {
            root->data = v[i].second;
            break;
        }
    }
    assign(root->right,v);
}

Node* modify(Node *root)
{
    vector<pair<int,int>> vp;
    inot(vp,root);
    int i;
    for(i=vp.size()-1;i>0;i--)
        vp[i-1].second += vp[i].second;
    assign(root,vp);
    return root;
}





//Third Solution :-
int fun(Node *root, int add) {
    if(!root) return add;
    root->data += fun(root->right, add);
    return fun(root->left, root->data);
}

Node* modify(Node *root) {
    fun(root, 0);
    return root;
}
