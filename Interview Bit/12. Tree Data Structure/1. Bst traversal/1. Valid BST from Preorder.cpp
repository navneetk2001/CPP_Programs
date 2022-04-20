// You are given a preorder traversal A, of a Binary Search Tree.
// Find if it is a valid preorder traversal of a BST.

// Input 1:
// A = [7, 7, 10, 10, 9, 5, 2, 8]
// Output 1:
//  0

//Hint :-
If A[i] is root of a subtree then if we find the first greater value on right side of current node.
Let the index of this node be j then A[i+1…j-1] will represent left subtree and A[j+1….N-1] will represent the right subtree.
Try to use the above fact to find a solution to the problem.

//Solution Approach :- 
A Simple Solution is to do following for every node A[i] starting from first one.
	Find the first greater value on right side of current node.
	Let the index of this node be j. Return true if following conditions hold. Else return false
		All values after the above found greater value are greater than current node.
		Recursive calls for the subarrays A[i+1..j-1] and A[j+1..n-1] also return true.

Time Complexity of the above solution is O(N2)

An Efficient Solution can solve this problem in O(N) time.
The idea is to use a stack. This problem is similar to Next (or closest) Greater Element problem.
Here we find the next greater element and after finding next greater, if we find a smaller element, then return false.
	Create an empty stack.
	Initialize root as INT_MIN.
	Do following for every element pre[i]
	If pre[i] is smaller than current root, return false.
	Keep removing elements from stack while pre[i] is greater then stack top. Make the last removed item as new root (to be compared next).
	At this point, pre[i] is greater than the removed root (That is why if we see a smaller element in step a), we return false)
	push pre[i] to stack (All elements in stack are in decreasing order)


//First Solution :-
//Intuition :- Use a stack 
//find the next greater element and after finding the next greater element, 
//if we find a smaller element , then return false else return true

int Solution::solve(vector<int> &preorder) {
    stack<int> st;
    int root = INT_MIN;

    for (int i=0; i < preorder.size(); i++)
    {
        while (!st.empty() && preorder[i] > st.top())
        {
            root = st.top();
            st.pop();
        }

        if (preorder[i] < root)
            return false;

        st.push(preorder[i]);
    }
    return true;
}

//Second Solution :-
int Solution::solve(vector<int> &a) {
    int mid_idx = 0 ;
    int root = a[0];

    for(int i=1;i<a.size();i++){
        if(root < a[i]){
            mid_idx = i ;
            break ;
        }
    }

    if(mid_idx != 1){
        for(int i=1;i<mid_idx;i++){
            if(a[i]>root)return 0 ;
        }
        for(int i=mid_idx;i<a.size();i++){
            if(a[i]<root)return 0 ;
        }
    }
    else 
    	return 0 ;
    return 1 ;
}



//Third Solution :- 


