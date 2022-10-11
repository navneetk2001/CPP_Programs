Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]



//Solution Approach :-
class Solution {
public:
	//helper funtion to in-order traverse a BST
    void inOrderTraverse(TreeNode *root, vector<int>& vec){
        if(root){
		    inOrderTraverse(root->left, vec);
		    vec.push_back(root->val);
		    inOrderTraverse(root->right, vec);
	    }
    }

	//helper function to merge two sorted vectors into one sorted vector
    void mergeVectors(vector<int> vec1, vector<int> vec2, vector<int>& mergedVectors){
        int i = 0, j = 0, k = 0; 

        while (i < vec1.size() && j < vec2.size()) { 
            if (vec1[i] < vec2[j]){ 
                mergedVectors[k++] = vec1[i++]; 
            }
            else{
                mergedVectors[k++] = vec2[j++]; 
            }
        } 
  
        while (i < vec1.size()){ 
            mergedVectors[k++] = vec1[i++]; 
        }
    
        while (j < vec2.size()){ 
            mergedVectors[k++] = vec2[j++]; 
        }        
    } 
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> tree1, tree2;
        inOrderTraverse(root1, tree1);
        inOrderTraverse(root2, tree2);
        
        vector<int> mergedVectors(tree1.size() + tree2.size());
        mergeVectors(tree1, tree2, mergedVectors);

        return  mergedVectors;        
    }
};




//Second Solution :-
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
	      stack<TreeNode *> s1, s2;

	      while (root1 || root2 || !s1.empty() || !s2.empty())
	      {
	           while (root1 != NULL)
	           {
	                s1.push(root1);
	                root1 = root1->left;
	           }
	          
	           while (root2 != NULL)
	           {
	                s2.push(root2);
	                root2 = root2->left;
	           }
	          
	           if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val))
	           {
	                root1 = s1.top();
	                s1.pop();
	                res.push_back(root1->val);
	                root1 = root1->right;
	           }
	           else
	           {
	                root2 = s2.top();
	                s2.pop();
	                res.push_back(root2->val);
	                root2 = root2->right;
	           }
	      }
	      return res;
    }
};




