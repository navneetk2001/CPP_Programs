// Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.
// The above figure details the movements for a knight ( 8 possibilities ).
// If yes, then what would be the minimum number of steps for the knight to move to the said point.
// If knight can not move from the source point to the destination point, then return -1.
// Note: A knight cannot go out of the board.

// Input 1:
//     A = 8
//     B = 8
//     C = 1
//     D = 1
//     E = 8
//     F = 8
    
// Output 1:
//     6

// Explanation 1:
//     The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
//     The minimum number of moves required for this is 6.

//Hint :-
Assume this problem as searching in graph where each block of chess board is vertex.
How would you define edges in such a graph ?
When can you travel from vertex i to vertex j ?

Once you have the graph, then it reduces to finding the shortest path in an unweighted graph.
How do you find the shortest path in an unweighted graph ?

//Solution Approach :- 
A knight can move to 8 positions from (x,y). 
(x, y) -> 
    (x + 2, y + 1)  
    (x + 2, y - 1)
    (x - 2, y + 1)
    (x - 2, y - 1)
    (x + 1, y + 2)
    (x + 1, y - 2)
    (x - 1, y + 2)
    (x - 1, y - 2)

// Corresponding to the knight's move, we can define edges. 
// (x,y) will have an edge to the 8 neighbors defined above. 
// To find the shortest path, we just run a plain BFS.


//First Solution :-
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int pos[8][2]={{-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,-1}, {2,1}, {-1,-2}, {1,-2}};
    bool vis[A+1][B+1];      //visited Array
    memset(vis,0,sizeof(vis));

    vis[C][D]=1;   //Marking initial pos as true
    queue<pair<int,int>> q;      //Queue for BFS Traversal
    q.push({C,D});
    int steps=0;

    while(!q.empty()){   
        int sz=q.size();
        while(sz--){
            pair<int,int>p=q.front();
            q.pop();
            int x=p.first, y=p.second;
            if(x==E && y==F)
                return steps;

            for(int k=0;k<8;k++){
                int a=x+pos[k][0], b=y+pos[k][1];
                if(a>0 && a<=A && b>0 && b<=B && !vis[a][b]){
                    q.push({a,b});
                    vis[a][b]=1;
                }
            }
        }
        steps++;
    }
    return -1;
}

//Second Solution :-
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int dx[]={1,2,1,2,-1,-2,-1,-2};
    int dy[]={-2,-1,2,1,-2,-1,2,1};
    
    bool vis[A+2][B+2]={};
    queue<array<int,3>> q;
    q.push({C,D,0});
    vis[C][D]=1;
    while(q.size())
    {
        auto [x,y,moves]=q.front();
        q.pop();
        
        if(x==E and y==F)
            return moves;
        
        for(int ii=0;ii<8;ii++)
        {
            int i=x+dx[ii];
            int j=y+dy[ii];
            if(i>=1 and j>=1 and i<=A and j<=B and !vis[i][j])
            {
                vis[i][j]=1;
                q.push({i,j,moves+1});
            }
        }
    }
    
    return -1;
}


//Third Solution :- 
int getL(int i, int j, int M){
    return i * M + j;
}
int getX(int L, int M){
    return L / M;
}
int getY(int L, int M){
    return L % M;
}
int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    if(x1 == x2 && y1 == y2) return 0;
    if(N == 0 || M == 0) return -1;
    vector<bool> visited(N*M, 0); 
    int steps = 1;
    visited[0] = 1;
    int arrX[8] = {-1,1,-2,2,-2,2,-1,1};
    int arrY[8] = {-2,-2,-1,-1,1,1,2,2};
    queue<int> Q;
    Q.push(getL(x1-1, y1-1, M));
    Q.push(-1);
    while(1){
        int c = Q.front();
        Q.pop();
        int cX = c/M, cY = c%M;
        if(Q.empty()) return -1;
        if(c == -1){
            Q.push(-1);
            steps++;
            continue;
        }
        for(int i = 0; i < 8; i++){
            int x = cX + arrX[i];
            int y = cY + arrY[i];
            if(x == x2-1 && y == y2-1) return steps;
            int l = getL(x,y,M);
            if(x < 0 || x >= N || y < 0 || y >= M || visited[l]) continue;
            visited[l] = 1;
            Q.push(l);
        }
    }
    return 0;
}


     