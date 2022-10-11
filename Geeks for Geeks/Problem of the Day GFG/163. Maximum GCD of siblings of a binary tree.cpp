// Given a 2d list that represents the nodes of a Binary tree with N nodes, the task is to find the maximum GCD of the siblings of this tree without actually constructing it.
// Note: If there are no pairs of siblings in the given tree, print 0. Also, if given that there's an edge between a and b in the form of {a,b} in the list, then a is the parent node.

// Example 1:
// Input:
// N = 7
// arr = {{4, 5}, {4, 2}, {2, 3}, {2, 1}, {3, 6}, {3, 12}}
// Output: 6
// Explanation: For the above tree, the maximum GCD for the sibilings is 6, formed for the nodes 6 and 12 for the children of node 3.

// Example 2:
// Input: N = 3
// arr[] = {{1,2}, {1,4}} 
// Output : 2
// Explanation: For the above tree, the maximum GCD for the sibilings is 2, formed for the nodes 2 and 4 for the children of node 1.



//Solution Approach :-
class Solution {
public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        if(N==1 or N==2) return 0;
        
        int maxi = 0;
        sort(arr.begin(),arr.end());   //sort on the basis of first element
        
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i][0]==arr[i+1][0]){    //if its a sibling 
                int res = __gcd(arr[i][1],arr[i+1][1]);
                maxi = max(maxi,res);
            }
        }
        return maxi;
    }
};



//Second Solution :-

int gcd(int a, int b){
    if (a < b) return gcd(b, a);
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int maxBinTreeGCD(vector<vector<int>> arr, int N) {
    unordered_map<int,int> map;
    int res = 0;
    
    for(int i = 0; i < arr.size(); i++){
        if (map.count(arr[i][0])){
            res = max(res, gcd(map[arr[i][0]], arr[i][1]));
        } 
        else{
            map[arr[i][0]] = arr[i][1];
        }
    }
    return res;
}
