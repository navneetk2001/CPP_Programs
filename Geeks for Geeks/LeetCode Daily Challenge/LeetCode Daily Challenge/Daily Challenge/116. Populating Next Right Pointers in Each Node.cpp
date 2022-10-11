// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

// Example 1:
// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

// Example 2:
// Input: root = []
// Output: []




//First Solution :- Level Order with Queue
class Solution {
public:
    Node* connect(Node* root)   //level order using bfs
    {
        if(root == NULL) 
        	return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size(); // get size of queue 
            for(int i=0 ; i<size ; i++){
                Node* item = q.front(); 
                if(size - 1 == i){ // checking the last value of the level
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
        return root;
    }
};


//Second Solution :- Using Recursion
//Recursively connect the left and right subtrees.
class Solution {
public:
    Node* connect(Node* root) 
    {
        // recursive approach
        if (!root) {
            return NULL;
        }

        if (root -> left) 
        {
            root -> left -> next = root -> right;
            if (root -> next)
            {
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


