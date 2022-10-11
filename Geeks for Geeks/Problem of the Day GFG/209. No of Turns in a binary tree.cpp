https://practice.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1




//Solution Approach :- 
class Solution{
  public:
    Node* lca(Node* root,int f,int s){
        if(!root){
        	return nullptr;
        }
        if(root->data == f || root->data == s){
        	return root;
        }
        Node* l = lca(root->left,f,s);
        Node* r = lca(root->right,f,s);
        
        return l && r ? root : l ? l : r;
    }
    
    long turns(Node* root,char dir,int value){
        if(!root){
        	return INT_MAX;
        }
        if(root->data == value){
        	return 0;
        }

        long leftCount = turns(root->left, 'l', value);
        long rightCount = turns(root->right, 'r', value);
        return dir == '#'? min(leftCount, rightCount) : dir == 'l' ? min(leftCount, 1 + rightCount) : min(1 + leftCount, rightCount);
    }
    
    // function should return the number of turns required to go from first node to second node 
    int NumberOFTurns(struct Node* root, int first, int second)
    {
        Node* lower = lca(root,first,second);
        long f = turns(lower, '#', first);
        long s = turns(lower, '#', second);

        return (lower->data == first || lower->data == second) ? f + s : f + s + 1;
    }
};




//Second Solution :-
/*Approach:-Applying the concept of the lowest common ancestor;
-->This question is little bit similar to question 'Minimum distance btween two nodes in binary tree' of gfg.

-->Algorithms :- We will first find the lowest common ancestor of the first and second node;
-->After finding the lowest common ancestor ,we will go to node first and node second from lca node;
-->This is beacuse we have to find the number of turns;

-->There is a turn function that will calculate the number of turns;
-->It have a sign parameter;(Sign wiil either ‘L’ or either ‘R’);
-->This we keep track of the sign in which we have taken turn from particular node;

-->If from same sign ,we are moving in same sign direction ,then we we not add 1 to our turn count;
-->if we are going to another direction to sign then we will add 1 to our turn count;

-->From this we will calculate the number of turns to reach the first node and second node from lca;
-->If our lca is equal to one of the node and turn1+ turn2 count==0 then we return -1;


-->If our lca is equal to one of the node then we just return turn1 +turn2;
-->Otherwise if our lca is not equal to any of the node first and second then add 1 extrat to turn1 + turn 2
-->This is because we have take take extra turn at lca node;

-->Time Complexity:- O(n);
-->Space Complexity:- O(height of binary tree);   */

class Solution{
public:
	int turn(Node* root, int n, char sign) //This function will calculate the number of turns btween any node to any node wth data as n
	{
		if(root==nullptr){
			return INT_MAX-1000;
		}
		if(root->data == n){
			return 0;
		}

		int h1=0, h2=0;
		if(sign =='L')
		{
		 	h1 = turn(root->left, n, 'L');          //if we are goin in the same direction that of the sign ;
		 	h2 = 1 + turn(root->right, n, 'R');     //if we are changing direction means we hav etakenturn
		}
		else if(sign=='R')                         //Do same as above;
		{
		   	h1 = 1 + turn(root->left, n, 'L');
		   	h2 = turn(root->right, n, 'R');
		}
		return min(h1, h2);                          //take minimum of them; //veacuse 1 value will be INT_MAX-1000 kind of hing
	}

	Node* lca(Node* root ,int n1 ,int n2 )           //Step1:- Find the lca of the node n1 and node n2;
	{
		if(root==nullptr) return nullptr;

		if(root->data==n1|| root->data==n2) return root;

		Node* h1= lca(root->left,n1,n2);
		Node* h2= lca(root->right,n1,n2);

		if(h1==nullptr){
			return h2;
		}
		if(h2==nullptr){
			return h1;
		}

		if((h1->data==n1 || h2->data==n2) || (h1->data==n2 || h2->data==n1)){
			return root;
		}
	}

	int NumberOFTurns(struct Node* root, int first, int second)
	{
		Node* lc=lca(root,first,second);                                    //Step1:- Find the lca of the nodes

		int turn1 = min(turn(lc, first, 'L'), turn(lc, first, 'R'));               //Find the turns for first node;
		int turn2 = min(turn(lc, second, 'L'), turn(lc, second, 'R'));             //Find the turna for the second node

		if(turn1 + turn2==0 && (lc->data == first || lc->data == second)){        //both turn is zero and one node is lca
			return -1;
		}

		if((lc->data == first || lc->data == second)){                     //if one node is lca then just return turn1+turn 2
			return turn1 + turn2;
		}
		return turn1 + turn2 + 1;                                          //otherwise add extra 1 to take turn at lca node;
	}
};



