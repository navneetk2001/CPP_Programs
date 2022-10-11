// In a city water tanks are connected by pipeline(As a tree). Since people working at the city corporation are lazy they usually select one of the tank and pour complete amount of water into it, when the tank is filled, the excess water evenly flows to the connected tanks. The head of city corporation has instructed to pour minimum amount of water into the selected tank so that all other tank is filled. As the labours of the corporation are not intelligent enough to figure out the minimum amount of water required to fill all the tanks they have asked your help. Also Maximum amount of water available with city corporation is 1018
// NOTE: If the tank if full, the water flows to all of its connected tanks except the tank from which the water had come to it. i.e, to all tanks except the source for that particular tank. If it has no option to flow the water is considered to be wasted

// Example 1:
// Input:
// N = 4 and S = 1
// Edges = [[1, 2], [2, 3], [3, 4]]
// Cap = [1, 1, 1, 1]
// Output: 5
// Explanation: Initially 5 unit of water is poured into tank 1. 2 unit of it flows to tank 2 and 2 unit of it flows into tank 3. From 2 
// unit of water in tank 2 1 unit flows into tank 4 and 1 unit from tank 3 is wasted.

// Example 2:
// Input:
// N = 3 and S = 2
// Edges = [[1, 2], [2, 3]]
// Cap = [1, 1, 1]
// Output: 3




//Solution Approach :-
// I used binary search, cuz at first sight I realized its a binary search problem based on its resemblance to books allocation, painter allocation and all other such problems I have done in the past. So the main idea was to code the isPossible function. And I just wrote whatever the problem gave conditons on

// water will be evenly distributed among its neighbours, but not with the source. That is, if water is coming from TANK A to B, B can supply to C and D but not A because A is where the water came from B in the first place.  And if thought logically, BHARE HUE TANK MEI AUR KITNA HI PANI BHAROGE( Translation- Obviously you would not want to fill an already filled tank)
// 	long long waterRemaining=water-cap[startNode-1];  // after filling the current tank, remaining water is this
//     long long branches=adj[startNode].size();  // THIS TANK IS CONNECTED TO THESE MANY OTHER TANKS(INCLUDING THE SOURCE TANK FROM WHERE THE WATER CAME IN IT)
//     if(parent!=-1){  // If has parent, do not supply water in that branch
//         branches--;
//     }
// 2.  While iterating the neighbours, check for each neighbour of startNode tank, whether this neighbour can be filled by the water supplied to it, i.e. remainingWater/branches

class Solution {
public:
    bool isPossible(list<int> *adj, int parent, int startNode, long long water, int* cap){
        if(cap[startNode-1]>water){
            return false;
        }
        long long waterRemaining=water-cap[startNode-1];
        long long branches=adj[startNode].size();
        if(parent!=-1){
            branches--;
        }
        for(auto nei: adj[startNode]){
            if(nei==parent){
                continue;
            }
            if(isPossible(adj,startNode,nei,waterRemaining/branches,cap)==false){
                return false;
            }
        }
        return true;
    }
    
    long long minimum_amount(vector<vector<int>> &E, int num, int start, int *cap){
        list<int> adj[num+1];
        for(int i=0;i<E.size()-1;i++){
            adj[E[i][0]].push_back(E[i][1]);
            adj[E[i][1]].push_back(E[i][0]);
        }

        long long res=0;
        long long low=0;
        long long high=1e18;
        for(int i=0;i<num;i++){
            low+=cap[i];
        }
        
        while(low<=high){
            long long mid=(low+high)/2;
            if(isPossible(adj,-1,start,mid,cap)==true){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res==0 ? -1 : res;
    }
};



//Second Solution :-
long long Total = 1e18;
bool overDemand = false;
long long water(vector<int> adj[], int *Cap, int visited[], int source){
    visited[source] = 1;
    long long ans = 0;
    int count = 0;
    for (auto x : adj[source]){
        if (visited[x]==0){
            count++;
            long long temp = water(adj, Cap, visited, x);
            ans = max(temp, ans);
        }
    }

    long long waterReq = count * ans + Cap[source-1];
    if(waterReq > Total){
        overDemand = true;
    }
    return waterReq;
}

long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
    int visited[N + 1] = {0};
    vector<int> adj[N+1];
    for(int i=0;i<Edges.size();i++){
        adj[Edges[i][0]].push_back(Edges[i][1]);
        adj[Edges[i][1]].push_back(Edges[i][0]);
    }

    long long  ans = water(adj, Cap, visited, S);
    return overDemand==true ? -1 : ans;
}



//Third Solution :-
// To fill our current node and its successive family in the tree, we will first fill the current node, then equal amount of water flows to ALL its children, and flows till all its children and their family gets full.
// Suppose the child-1 takes X1 water to fill itself and its whole family, child-2 takes X2 ……. child-k takes Xk, then the highest amongst (X1,X2…Xk) water will be used to fill all its K children.
// Answer for our current node is → capacity(current) + max(x1,x2…xk) * k.

long long getAns(int cur, int* &c, int &n, int prev, vector<vector<int>>& adj){
    long long ans = c[cur-1] , maxans = 0, children = 0 ;
    for(auto &x: adj[cur]){
        if(x == prev){
            continue ;
        }
        children++ ;
        long long tans = getAns(x,c,n,cur,adj) ;
        if(tans == -1){
            return -1 ;
        }
        maxans = max(maxans,tans) ;
    }
    ans += children*maxans ;
    return ( ans > 1e18 ? -1 : ans ) ;
}

long long minimum_amount(vector<vector<int>> &edges, int n, int s, int *c){
    vector< vector<int> > adj(n+1) ;
    for(auto &e: edges){
        adj[e[0]].push_back(e[1]) ;
        adj[e[1]].push_back(e[0]) ;
    }
    return getAns(s,c,n,-1,adj) ;
}