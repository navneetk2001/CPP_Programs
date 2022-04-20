In an online game, N blocks are arranged in a hierarchical manner. All the blocks are connected together by a total of N-1 connections. Each block is given an ID from 1 to N. A block may be further connected to other blocks. Each block is also assigned a specific point value.
A player starts from Block 1. She must move forward from each block to a directly connected block until she reaches the final block, which has no further connection. When the player lands on a block, she collects the point value of that block. The players score is calculated as the product of point values that the player collects.
Find the maximum score a player can achieve.
Note: The answer can always be represented with 64 bits.


Example 1:
Input:
     4
    / \
   2   8
  / \ / \
 2  1 3  4
Output: 128
Explanation: Path in the given tree goes like 4, 8, 4 which gives the maxscore of 4x8x4 = 128.

Example 2:
Input:
     10
   /    \
  7      5
          \
           1
Output: 70
Explanation: The path 10, 7 gives a score of 70 which is the maximum possible.



//Solution Approach :-
class Solution {
  public:
    //Function to return maximum path product from any node in a tree.
    long long findMaxScore(Node* root)
    {
        if(root==NULL)
        	return 1;
        
        long long v1=root->data*(findMaxScore(root->right));
        long long v2=root->data*(findMaxScore(root->left));
        return max(v1,v2);
    }
};



//Second Solution :-
long long findMaxScore(Node* root)
{
   long long ans=0;
   
   queue<pair<Node*, long long>> q;
   q.push({root,root->data});
   
   ans = root->data;
   
   while(!q.empty()){
       pair<Node*,long long> cur = q.front();
       q.pop();
       
       if(cur.first->left){
           q.push({cur.first->left,cur.second*cur.first->left->data});
           ans = max(ans,cur.second*cur.first->left->data);
       }
       if(cur.first->right){
           q.push({cur.first->right,cur.second *cur.first->right->data});
           ans=max(ans,cur.second*cur.first->right->data);
       }
   }
   return ans;
}


