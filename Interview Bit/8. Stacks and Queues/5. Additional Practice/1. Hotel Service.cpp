// You are travelling to Neverland. After a long journey, you decided to take rest in a hotel for a night.
// You have the map of Neverland in the form of 2D matrix A with dimensions N x M. 
// The rows are numbered from 1 to N, and the columns are numbered from 1 to M.
// You can travel from one cell to any adjacent cell. Two cells are considered adjacent if they share a side.
// In the map, there are only two digits, 0 and 1, 
// where 1 denotes a hotel in that cell, and 0 denotes an empty cell.
// You are also given another 2D array B with dimension Q x 2,
// where each row denotes a co-ordinate (X, Y) on the map (1 - indexed). 
// For each coordinate you have to find the distance to the nearest hotel.
// Return an array denoting the answer to each coordinate in the array B.

// Input 1:
// A = [[0, 0],
//      [1, 0]]
// B = [[1, 1],
//      [2, 1],
//      [1, 2]]
// Output 1:
// [1, 0, 2]

// Input 2:
// A = [[1, 0, 0 1]]
// B = [[1, 2],
//      [1, 3]]
// Output 2:
// [1, 1]

// Explanation 1:
// (1, 1) is adjacent to a hotel. (2, 1) has a hotel. (1, 2) is two cells away from the hotel on (2, 1).

// Explanation 2:
// (1, 2) is adjacent to a hotel on (1, 1). (1, 3) is adjacent to a hotel on (1, 4).

//Solution Approach :-
We will first precalculate the distance to the nearest hotel for all the cells in the matrix.
Think of the given matrix as a graph, where each cell is a node and two adjacent nodes are connected by an edge.
Then, we can simply run a multisource BFS on the graph to find the depth of all the nodes.

To simplify, we will push all the coordinates of the hotels in a queue, which will have distance 0.
Then, we will pop each element one by one, and all the adjacent nodes with distance + 1.
Be sure to not add a node twice.
Then, simply iterate through the array B, and easily get the answer from the array where we are storing our distances.


//First Solution :-
bool isSafe(int n, int m, int x, int y){
    return (x>=0 && y>=0 && x<n && y<m);
}

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n=A.size();
    int m=A[0].size();
    queue<pair<int,int>>q;
    vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }

    vector<pair<int,int>> moves = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    while(!q.empty()){
    	int size=q.size();
    	while(size--){
    		auto curr=q.front();
    		q.pop();

    		int x=curr.first;
    		int y=curr.second;

    		for(auto it:moves){
    			int newX=x+it.first;
    			int newY=y+it.second;
    			if(isSafe(n,m,newX,newY)==true){
    				if(dist[newX][newY] > dist[x][y]+1){
    					dist[newX][newY] = dist[x][y]+1;
    					q.push({newX,newY});
    				}
    			}
    		}
    	}
    }

    vector<int>res;
    for(auto it:B){
    	int x=it[0]-1;
    	int y=it[1]-1;
    	res.push_back(dist[x][y]);
    }
    return res;
}



//Second Solution :-
vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B)
{
    vector<vector<int>>dp(A.size(),vector<int>(A[0].size()));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            dp[i][j]=10000000;
            if(A[i][j]==1)
                dp[i][j]=0;
            if(i>0)
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            if(j>0)
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    }
    for(int i=A.size()-1;i>=0;i--){
        for(int j=A[i].size()-1;j>=0;j--){
            if(i<A.size()-1)
                dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
            if(j<A[i].size()-1)
                dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
        }
    }
    vector<int>ans(B.size());
    for(int i=0;i<B.size();i++)
        ans[i]=dp[B[i][0]-1][B[i][1]-1];
    return ans;  
}


//Third Solution :-
vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) 
{
    int n=A.size();
    int m=A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
        {
            if(A[i][j]==1) A[i][j]=0;
            else A[i][j]=100000;
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>0) A[i][j]=min(A[i][j],A[i-1][j]+1);
            if(j>0) A[i][j]=min(A[i][j],A[i][j-1]+1);
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i<n-1) A[i][j]=min(A[i][j],A[i+1][j]+1);
            if(j<m-1) A[i][j]=min(A[i][j],A[i][j+1]+1);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i>0) A[i][j]=min(A[i][j],A[i-1][j]+1);
            if(j<m-1) A[i][j]=min(A[i][j],A[i][j+1]+1);
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(i<n-1) A[i][j]=min(A[i][j],A[i+1][j]+1);
            if(j>0) A[i][j]=min(A[i][j],A[i][j-1]+1);
        }
    }

    vector<int> ans;
    for(int i=0;i<B.size();i++)
    {
        ans.push_back(A[B[i][0]-1][B[i][1]-1]);
    }
    return ans;
}
