// Geek has developed an effective vaccine for Corona virus and he wants each of the N houses in Geek Land to have access to it. Given a binary tree where each node represents a house in Geek Land, find the minimum number of houses that should be supplied with the vaccine kit if one vaccine kit is sufficient for that house, its parent house and it's immediate child nodes.  

// Example 1:
// Input:
//     1
//    / \
//   2   3 
//         \
//          4
//           \
//            5
//             \
//              6

// Output:
// 2
// Explanation:
// The vaccine kits should be supplied to house numbers 1 and 5. 

// Example 2:
// Input:
//     1
//    / \
//   2   3 
// Output:
// 1
// Explanation:
// The vaccine kits should be supplied to house number 1.



//Solution Approach :-
//We have 3 conditions here :- either we need vaccine or vaccination has been done or someone in my family is providing the vaccine
// we can rewrite as :-   :-> need :- +1   ->  -1
//                        :-> done :- 0    ->   0
//                        :-> fam jam :- 0 ->   1

class Solution{
public:

    // 1 --> giving Vaccine
    // -1 --> need Vaccine
    // 0 --> Dont need Vaccine

    int helper(Node *root , int &count){
        
        if(root == NULL) return 0;
        
        int left = helper(root->left , count);
        int right = helper(root->right , count);
        
        if(left == -1 or right == -1){   //if left or right is not vaccinated then vaccinate them and return 1
            count++;
            return 1;
        }
        if(left == 1 or right == 1 ){    //if left or right is vaccinated then return 0;
          return 0;
        }
        
        return -1;
    }

    int supplyVaccine(Node* root){
        int count =0;
        int cnt = helper(root , count);
        if(cnt == -1){
            count++;
        }
        return count;
    }
};


//Another Approach :-
//I have a DP solution which is a bit different from the other solutions. 
int supplyVaccine(Node* root){
        const int inf = 1e9;
        function<array<int, 3>(Node*)> dfs = [&](Node * node) {
            array<int, 3> curr = {1, inf, 0};
            if(node->left == nullptr && node->right == nullptr) {
                // leaf node
                curr[2]=0;
                return curr;
            }
            array<int, 3> lft, rht;
            lft = rht = {inf,0,0};
            if(node->left) {
                lft = dfs(node->left);
                curr[0] += min({lft[0], lft[1], lft[2]});
            }
            if(node->right) {
                rht = dfs(node->right);
                curr[0] += min({rht[0], rht[1], rht[2]});
            }
            curr[2] = lft[1]+rht[1];
            curr[1] = min(lft[0]+min(rht[0],rht[1]), rht[0]+min(lft[0], lft[1]));
            // cout << node->data << endl;
            // cout << curr[0] << ' ' << curr[1] << ' ' << curr[2] << endl;
            return curr;
        };
        auto ans = dfs(root);
        // 0 -> putting a vaccine on myself
        // 1 -> getting vaccintaed from child
        // 2 -> not getting vaccinated
        return min(ans[0], ans[1]);
    }