https://www.interviewbit.com/problems/min-cost-path/




//Solution Approach :- Dijkstra using Priority Queue(Min-Heap)
struct Point {
public:
    int x;
    int y;
    int cost;
};

struct comp {
    bool operator()(Point const& p1, Point const& p2){   //sort on the basis of cost 
        return p1.cost > p2.cost;
    }
};
 
// R D L U
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int Solution::solve(int row, int column, vector<string> &mat){
    string s="RDLU";         //all for possilbe directions
    
    vector<vector<int>> dist(row,vector<int> (column,INT_MAX-1));        // to store distance 
    priority_queue<Point,vector<Point>,comp> pq;        //to get minimum cost path  

    pq.push({0,0,0});        //push the initial co-ordinates
    dist[0][0] = 0;
    
    while(!pq.empty()){
        Point currentPoint= pq.top();          //minimum cost co-ordinates
        pq.pop();
        
        // reach the destination
        if(currentPoint.x == row-1 && currentPoint.y == column-1){
            return dist[currentPoint.x][currentPoint.y];
        }
      
        for(int i=0;i<4;i++){           //go to all 4 possible directions
            int newx = currentPoint.x + dx[i];
            int newy = currentPoint.y + dy[i];

            int cost = dist[currentPoint.x][currentPoint.y];

            if(s[i] != mat[currentPoint.x][currentPoint.y]){              // increase cost by 1 (if path not matches)
                cost++;
            }
            
            if((newx>=0 && newy>=0 && newx<row && newy<column) && cost<dist[newx][newy]){            //check boundary condition and cost
                pq.push({newx, newy, cost});
                dist[newx][newy]=cost;
            }
        }
    }
    return dist[row-1][column-1];
}




//Second Solution :-  Using Dequee
const int INF = 1e9 + 10;

bool checkValid(int x , int y , int n , int m) {
    return (x >= 0 && x < n && y >= 0 && y < m); 
}

int Solution::solve(int A, int B, vector<string> &C) {
    vector<vector<int>> d(A , vector<int>(B , INF));
    deque<pair<int , int>> q;
    q.push_front({0 , 0});
    d[0][0] = 0;

    unordered_map<char , pair<int , int>> mp;
    mp['U'] = {-1 , 0};
    mp['L'] = {0 ,-1};
    mp['D'] = {1 , 0};
    mp['R'] = {0 , 1};

    string s = "URDL";
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        int wt;
        int dx , dy;

        for (char &c : s) {
            dx = mp[c].first;
            dy = mp[c].second;  
            wt = 1 - (c == C[x][y]); 

            if(checkValid(x + dx , y + dy , A , B)) {
                if(d[x][y] + wt < d[x + dx][y + dy]) {
                    d[x + dx][y + dy] = d[x][y] + wt;
                    if(wt) {
                        q.push_back({x + dx , y + dy}); 
                    } 
                    else {
                        q.push_front({x + dx , y + dy}); 
                    }
                }
            }
        } 
    }
    return d[A - 1][B - 1];
}



//Third Solution :-
// Intuition -> there is no dp , because a node or cell can be visited multiple times so what we have to do is , we update the distance value each time
// and also put that cost  and index into the pq , as it can afftect the cost of many path , it is possible that many path may conntains it in its way

#define vv vector<int>
int Solution::solve(int m , int n , vector<string> &grid) {
    // Dijkstra's Algorithm
    priority_queue<vv, vector<vv>, greater<vv>> pq;
    pq.push({0 , 0 , 0});
   
    int dx[4] = {-1 , 1 , 0 , 0};
    int dy[4] = {0 , 0  , -1 , 1};
            //  UP, DOWN, LEFT, RIGHT
   
    vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
    dist[0][0]=0;
   
    while(!pq.empty()){
        auto arr=pq.top();
        pq.pop();
       
        int cost=arr[0];
        int i=arr[1];
        int j=arr[2];
       
        int ind;
       
        if(grid[i][j]=='U'){
            ind=0;
        }
        if(grid[i][j]=='D'){
            ind=1;
        }
        if(grid[i][j]=='L'){
            ind=2;
        }
     
        if(grid[i][j]=='R'){
            ind=3;
        }
     
        for(int k=0; k<4; k++){
            int newi = i + dx[k];
            int newj = j + dy[k];
         
            if(newi<0 || newj<0 || newi>=m || newj>=n){
                continue;
            }
         
            if(k==ind && dist[newi][newj]>cost){
                dist[newi][newj]=cost;
                pq.push({cost , newi , newj});
            }
            else if(dist[newi][newj]>1+cost){
                dist[newi][newj]=cost+1;
                pq.push({cost+1 , newi , newj});
            }
        }
    }
    return dist[m-1][n-1];
}
