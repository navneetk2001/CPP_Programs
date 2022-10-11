// This problem is to implement disjoint set union. There will be 2 incomplete functions namely union and find. You have to complete these functions. 
// Union: Join two subsets into a single set.
// isConnected: Determine which subset a particular element is in. This can be used for determining if two elements are in same subset.

// Note: Both function will contain two arrays par[] and ranks1[] along with two nodes. Initially par[i] = i and rank1[i] = 1 

// Example 1:
// Input:
// N = 5
// q = 4
// Queries = 
// Union(1,3)
// isConnected(1,2)
// Union(1,5)
// isConnected(3,5)
// Output:
// 0
// 1
// Explanation: Initially all nodes 1 2 3 4 5 are not connected. After Union(1,3), node 1 and 3 will be connected.
// When we do isConnected(1,2),  as node 1 and 2 are not connected it will return 0. After Union(1,5), node 1 and 5 will be connected.
// When we do isConnected(3,5),  as node 1 and 3 are connected, and node 1 and 5 are connected, hence 3 and 5 are connected. Thus it will return 1.

// Example 2:
// Input:
// N = 5
// q = 4
// Queries = 
// Union(1,4)
// Union(1,5)
// isConnected(2,3)
// Union(3,4)
// Output: 0




//Solution Approach :-
class Solution{
public:
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank[]) {
        a = checkParent(a,par);
        b = checkParent(b,par);
        
        if(rank[a] < rank[b]){
            par[a] = b;
        }
        else if(rank[a] > rank[b]){
            par[b] = a;
        }
        else{
            par[a] = b;
            rank[b]++;
        }
    }
    
    int checkParent(int ele, int par[]){
        if(par[ele] == ele){
            return ele;
        }
        return par[ele] = checkParent(par[ele],par);
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[]){
        return checkParent(x,par) == checkParent(y,par);     //check if the parent of x and y are same or not
    }
};



//Path Compression: Here, if we were given input Union(1,2), Union(2,3), Union(3,4)..instead of making 1←2←3←4 , we will make 1 parent of all 2,3,4. This compression would automatically be done when we call find as shown with par[c] = find(par,par[c]).
//Rank: Rank denotes the height of the tree from that element onwards. If you had to union 2 trees, making 1 parent of other could cause inefficiency if smaller one is made parent. Bigger trees element when accessed would take extra time to get to the final parent.
//isConnected: can be done by just checking if parents are same or not. Even this uses find, and while finding, it would also compress the path.

