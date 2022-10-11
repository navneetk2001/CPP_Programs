https://practice.geeksforgeeks.org/problems/median-of-bst/1




//Solution Approach :-
void Inorder(Node* root, vector<int>&ans){
    if(!root) return;
    Inorder(root->left,ans);
    ans.push_back(root->data);
    Inorder(root->right,ans);
}

float findMedian(struct Node *root)
{
    vector<int> v;
    Inorder(root,v);
      
    if(v.size()%2==0){      //even case
        return (double)(v[v.size()/2] +v[v.size()/2 -1])/2;
	}
	return v[v.size()/2];
}




//Second SOlution :- O(1) Space Complexity, Using Morris Traversal
int count(struct Node *root){
    if(root==0){
    	return 0;
    }
    return 1 + count(root->left)+count(root->right);
}

int pre,curr;
void fun(Node* root,int &k){
    if(root==0){
    	return;
    }
    
    fun(root->left,k);
    k--;
    
    if(k==1){
      	pre=root->data;
    }

    if(k==0){
        curr=root->data;
    }
    
    fun(root->right,k);
}

float findMedian(struct Node *root){
	int n = count(root);
	if(n==1){
		return root->data;
	}

	pre=-1, curr=-1;
	int k=n/2+1;

	fun(root,k);

	if(pre==-1||curr==-1){
		return -1;
	}

	if(n%2==0){
		return (pre+curr)/2.0;
	}
	return curr;
}




//Third Solution :-
float findMedian(struct Node *root){
    int n = 0;
    
    Node* curr = root;
    while(curr){
        if(!curr->left){
            n++;
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            
            while(prev->right and prev->right != curr){
                prev = prev->right;
            }
            
            if(!prev->right){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                n++;
                curr = curr->right;
            }
        }
    }
    
    int count = 0;
    
    curr = root;
    Node* m1;
    Node* m2;
    
    while(curr){
        if(!curr->left){
            if(count == n/2){
                m2 = curr;
            }
            if(count == n/2 - 1){
                m1 = curr;
            }
            count++;
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            
            while(prev->right and prev->right != curr){
                prev = prev->right;
            }
            
            if(!prev->right){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                if(count == n/2){
                    m2 = curr;
                }
                if(count == n/2 - 1){
                    m1 = curr;
                }
                count++;
                curr = curr->right;
            }
        }
    }
    
    if(n%2){
        return m2->data;
    }
    else{
        return (m1->data + m2->data)/((float)2);
    }
}
