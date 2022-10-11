https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1



//Solution Approach :-
class Solution {
public:
    pair<int, int> function(Node* root){
        if(root==NULL){
            return make_pair(0,0);
        }
            
        pair<int, int> l = function(root->left);
        pair<int, int> r = function(root->right);
        
        int height = max(l.first, r.first) + 1;
        int diameter = max(l.second, max(r.second, l.first + r.first + 1));
        
        return make_pair(height, diameter);
    }

    int diameter(Node* root){
        pair<int, int> p = function(root);
        return p.second;
    }
};



//Second Solution :-
// Either the parent root would be in the diameter or it will not be. But one thing is sure that the diameter would pass from one of the nodes which would be called with recursion.
// Let the result be h (diameter in this case);
// We recursively get the height of left sub tree and height of the right sum tree, and we do two things one is to store the maximum h (diameter ) for from the h already there and h now calculated for this root. 
// Then the second thing is we pass the height of this root to its parent root.  and thus parent root also does the same, doing this for each node, we update the maximum possible diameter that can be there, 
// Note here diameter is not defined as global variable because it is not a good practice.

class Solution {
 public:
   	int dia(Node*root,int &count){
       	if(root==NULL){
       		return 0;
       	}
       	int l = dia(root->left, count);
       	int r = dia(root->right, count);
       	count = max(l+r+1 , count);
       	
       	return 1 + max(l, r);
   	}

   	int diameter(Node* root) {
       	if(root==NULL){
       		return 0;
       	}
       	int count =0;
       	dia(root,count);
       	return count;
   	}
};



//Third Solution :- O(n^2)
class Solution {
public:
	int Height(Node* root){
		if(root==NULL){
			return 0;
		}

		int left_height=Height(root->left);
		int right_height=Height(root->right);

		return max(left_height,right_height)+1;
	}

	int Diameter(Node* root){
		if(root==NULL){
			return 0;
		}

		int dia_left = Diameter(root->left);
		int dia_right = Diameter(root->right);

		int current = Height(root->left) + Height(root->right) + 1;
		return max(current,max(dia_left,dia_right));
	}

	int diameter(Node* root){
		int dia=Diameter(root);
		return dia;
	}
};



//Fourth Solution :-
class Solution {
private:
	//first stores diameter, second stores the height
    pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int> p= make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first=max(opt1,max(opt2,opt3));
        ans.second=max(left.second,right.second)+1;
        
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       return solve(root).first;
    }
};