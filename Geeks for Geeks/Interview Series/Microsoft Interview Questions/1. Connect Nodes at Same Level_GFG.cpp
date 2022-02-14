Given a binary tree, connect the nodes that are at same level. You will be given an addition nextRight pointer for the same.
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

    10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

 

Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
        3 ------> NULL
     /    \
    1-----> 2 ------ NULL
Example 2:

Input:
      10
    /   \
   20   30
  /  \
 40  60
Output:
10 20 30 40 60
40 20 60 10 30
Explanation:The connected tree is
         10 ----------> NULL
       /     \
     20 ------> 30 -------> NULL
  /    \
 40 ----> 60 ----------> NULL


 

Steps :-
//1.Here we have to do a level order traversal and update nextright pointer
//2.We need to store previous pointer also
//3.We also need to take care of first node
//4.We also need to take care of end/last node
//5.We will also take a nextend node which store the next end


void connect(Node* root){
	queue<Node*> pending_nodes;
	Node* prev=NULL;
	Node* end=root;
	Node* next_end=NULL;
	pending_nodes.push(root);
	while(pending_nodes.size()){
		Node* front_node=pending_nodes.front();
		pending_nodes.pop();
		if(front_node->left){   //if left child is not null,push left node in queue and update next_end
			pending_nodes.push(front_node->left);
			next_end=front_node->left;
		}
		if(front_node->right){  //if right child is not null,push right node in queue and update next_end 
			pending_nodes.push(front_node->right);
			next_end=front_node->right;
		}
		if(prev!=NULL){     //when its prev exists
			prev->nextRight=front_node;
		}
		if(front_node==end){
			end=next_end;
			prev=NULL;
			next_end=NULL;
		}
		else{
			prev=front_node;
		}
	}
}




// Sets nextRight of all nodes of a tree
void connect(struct Node* root)
{
    queue<Node*> q;
    q.push(root);

    // null marker to represent end of current level
    q.push(NULL); 

    // Do Level order of tree using NULL markers
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        if (p != NULL) {

            // next element in queue represents next 
            // node at current Level 
            p->nextRight = q.front();

            // push left and right children of current
            // node
            if (p->left)
                q.push(p->left); 
            if (p->right)
                q.push(p->right);
        } 
       
        // if queue is not empty, push NULL to mark 
        // nodes at this level are visited
        else if (!q.empty()) 
            q.push(NULL); 
    }
}
