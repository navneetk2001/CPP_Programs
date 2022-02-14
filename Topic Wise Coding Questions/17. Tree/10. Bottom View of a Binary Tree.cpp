//Approach :- Using Vertical Order traversal

//we will use a queue of pair type which will store <node, line> value
//And we will also use map of type <line, node> which will store node on a particular line with line number of root as 0.

//Iterative Solution
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
};



//Recursive Solution :-
int l = 0, r = 0;
int N;

// Function to generate bottom view of binary tree
void Bottom(Node* root, int arr[], int arr2[], int x, int p, int mid)
{
	// Base case
	if (root == NULL) {
		return;
	}

	if (x < l) {
		// To store leftmost value of x in l
		l = x;
	}

	// To store rightmost value of x in r
	if (x > r) {
		r = x;
	}

	// To check if arr is empty at mid+x
	if (arr[mid + x] == INT_MIN) {
		// Insert data of Node at arr[mid+x]
		arr[mid + x] = root->data;
		// Insert priority of that Node at arr2[mid+x]
		arr2[mid + x] = p;
	}

	// If not empty and priotiy of previously inserted Node is less than current*/
	else if (arr2[mid + x] < p) {
		// Insert current Node data at arr[mid+x]
		arr[mid + x] = root->data;

		// Insert priotiy of that Node at arr2[mid +x]
		arr2[mid + x] = p;
	}

	// Go right first then left
	Bottom(root->right, arr, arr2, x + 1, p + 1, mid);
	Bottom(root->left, arr, arr2, x - 1, p + 1, mid);
}


// Utility function to generate bottom view of a biany tree
void bottomView(struct Node* root)
{
	int arr[2 * N + 1];
	int arr2[2 * N + 1];

	for (int i = 0; i < 2 * N + 1; i++) {
		arr[i] = INT_MIN;
		arr2[i] = INT_MIN;
	}

	int mid = N, x = 0, p = 0;

	Bottom(root, arr, arr2, x, p, mid);

	for (int i = mid + l; i <= mid + r; i++) {
		cout << arr[i] << " ";
	}
}
