// Given a BST, transform it into greater sum tree where each node contains sum of all nodes greater than that node.

// Example 1:
// Input:
//            2
//          /    \
//         1      6
//               /  \
//              3    7
// Output: 18 16 13 7 0
// Explanation: Every node is replaced with the sum of nodes greater than itself. 
// The resultant tree is:
//                16
//              /    \
//            18       7
//                   /   \
//                  13    0

// Example 2:
// Input:
//           2
//          /
//         1
// Output: 2 0
// Explanation: The resultant tree is :
//              0
//             /
//           2



//Solution Approach :-
//we are going right most element first because in bst the largest element will be on the right most side after that we are updating the total sum and move on to the left direction.
class Solution{
public:
    int sum = 0;
    void transformTree(struct Node *root)
    {
        if(!root) return;
        transformTree(root->right);       //start with right
        int currSum = root->data + sum;   //then find the current sum, i.e. sum of root and sum till now
        root->data = sum;                 //assign curr root as sum(which u have previously calculated)
        sum = currSum;                    //update sum as curr_sum
        transformTree(root->left);        //move on to left now
    }
};




//Second Solution :-
class Solution
{
   public:
       int prvSum = 0;
       int currSum = 0;
   void transformTree(struct Node *root)
   {
       //code here
       if(!root) return ;
       
       
       
       transformTree(root->right);
       
       currSum = currSum + root->data;
       root->data = prvSum;
       prvSum = currSum;
       
       transformTree(root->left);
       
       
   }
};




//Third Solution :-
void findSol(Node* root,int &sum,bool isAdd){
    if(root==NULL)
        return;
    
    findSol(root->left,sum,isAdd);
    if(isAdd){
        sum+=root->data;
    }else{
        sum-=root->data;
        root->data = sum;
    }
    findSol(root->right,sum,isAdd);
}

void transformTree(struct Node *root)
{
    int sum=0;
    findSol(root,sum,true);
    findSol(root,sum,false);
    //code here
}