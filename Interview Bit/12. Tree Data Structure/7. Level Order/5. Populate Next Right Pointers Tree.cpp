// Given a binary tree
//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.
// Note:
// You may only use constant extra space.
// Example :
// Given the following binary tree,
//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL
// Note 1:  that using recursion has memory overhead and does not qualify for constant space.
// Note 2: The tree need not be a perfect binary tree.


//Solution Approach :- 
// Lets say you have already created next pointers till level L. To create next pointer for level L+1, start with the first node on level L.

//         1   ->  2   ->  3  -> 4
//        /         \           / \
//       /           \         /    \ 
//      5            6        7      8 
        
//         1   ->  2   ->  3  -> 4
//        /         \           / \
//       /           \         /   \ 
//      4     ->      7   ->  8 ->  9 
// Keep track of the previous node you encountered on the next level. For the current node, explore the left and right child if they are not null in that order. If the prev is not set, that means we are looking at the leftmost node on the next level ( Lets store it because we will begin the next iteration from this node ). Else you can assign prev->next as the current node in next level you are exploring and update the prev node.


//First Solution :-
void Solution::connect(TreeLinkNode* root) {
    if(root == NULL){ 
        return;
    }

    queue<TreeLinkNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size(); // get size of queue 

        for(int i=0 ; i<size ; i++){
            TreeLinkNode* item = q.front(); 
            if(size - 1 == i){                    // checking the last value of the level
                    item -> next = NULL; 
            }
            q.pop();
            
            if(size - 1 != i){ // if this is not the last value then previous value will point to next one
                    item -> next = q.front(); 
            }

            if(item -> left != NULL){
                q.push(item -> left);
            }

            if(item -> right != NULL){
                q.push(item -> right);
            }
        }
    } 
    return;
}


//Second Solution :- Using Recursion
//Recursively connect the left and right subtrees.
class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root) {
            return NULL;
        }

        if (root -> left) {
            root -> left -> next = root -> right;
            
            if (root -> next){
                root -> right -> next = root -> next -> left;
            }
            connect(root -> left);
            connect(root -> right);
        }
        return root;
    }
};



//Third Solution :- Level Order without Queue
class Solution {
public:
/*Similar to a level-order traversal,
even you are not allowed to use a queue, the next pointer 
provides you with a way to move to the next node in the same level.*/
    Node* connect(Node* root) 
    {
        Node *pre = root, *cur;
        while (pre)
        {
            cur = pre;
            while (cur && cur -> left) 
            { 
                cur -> left -> next = cur -> right;
                if (cur -> next) 
                {
                    cur -> right -> next = cur -> next -> left;
                }
                cur = cur -> next;
            }
            pre = pre -> left;
        }
        return root;
    }
};


