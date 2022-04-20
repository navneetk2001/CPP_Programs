// Geek is in a maze of size N * M. Each cell in the maze is made of either '.' or '#'. An empty cell is represented by '.' and an obstacle is represented by '#'. If Geek starts at cell (R, C), find how many different empty cells he can pass through while avoiding the obstacles. He can move in any of the four directions but he can move up at most U times and he can move down atmost D times.

// Example 1:
// Input: 
// N = 3, M = 3
// R = 1, C = 0
// U = 1, D = 1
// mat = {{'.', '.', '.'},
//        {'.', '#', '.'},
//        {'#', '.', '.'}}
// Output: 5
// Explanation: Geek can reach (1, 0), (0, 0), (0, 1), (0, 2), (1, 2) 


// Example 2:
// Input: 
// N = 3, M = 4
// R = 1, C = 0
// U = 1, D = 2 
// mat = {{'.', '.', '.'}, 
//        {'.', '#', '.'}, 
//        {'.', '.', '.'},
//        {'#', '.', '.'}} 
// Output: 10
// Explanation: Geek can reach all the cells except for the obstacles.


//Approach :- BFS.
// Mind the order of direction, for some unknown reasons, 
// if the BFS checks up → down → left → right, it will fail some test case, 
// while left → right → up → down works.
// Besides from this crucial detail, the rest of the code is typical BFS. 
// And also mind that I modified the maze to avoid allocate spaces for visited[][], which is not always a good idea.




//Solution Approach :- Using BFS
class Solution{
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat){
		queue<vector<int>> q;
		q.push({r,c,0,0});

		if(mat[r][c]=='#') 
			return 0;

		mat[r][c] = 1;
		int count=1;
		while(!q.empty()){
		    int x = q.front()[0];
		    int y = q.front()[1];
		    int up = q.front()[2];
		    int down = q.front()[3];
		    
		    // right
		    if(y+1<m && mat[x][y+1]=='.'){
		        q.push({x,y+1,up,down});
		        mat[x][y+1]='1';
		        count++;
		    }
		    //left
		     if(y-1>=0 && mat[x][y-1]=='.'){
		        q.push({x,y-1,up,down});
		        mat[x][y-1]='1';
		        count++;
		    }
		    // up
		     if(x-1>=0 && mat[x-1][y]=='.' &&up!=u){
		        q.push({x-1,y,up+1,down});
		        mat[x-1][y]='1';
		        count++;
		    }
		    //down..
		    if(x+1<n && mat[x+1][y]=='.' && down!=d){
		        q.push({x+1,y,up,down+1});
		        mat[x+1][y]='1';
		        count++;
		    }
		    q.pop();
		}
		return count;
	}
};


//Second Solution :- Using DFS
//I also tried to adopt DFS.
//It has it's own beauty in it, but this will eventually TLE when facing large test case, though the logic is correct, it's just impractical here.

void dfs(int n, int m, int r, int c, int u, int d, vector<vector<char>>& mat,vector<vector<vector<vector<bool>>>>& visited)
{
	if (r < 0 || n <= r || c < 0 || m <= c || mat[r][c] == '#' || u < 0 || d < 0 || visited[r][c][u][d])
		return;

	visited[r][c][u][d] = true;
	mat[r][c] = '1';

	dfs(n, m, r + 1, c, u, d - 1, mat, visited);
	dfs(n, m, r - 1, c, u - 1, d, mat, visited);
	dfs(n, m, r, c + 1, u, d, mat, visited);
	dfs(n, m, r, c - 1, u, d, mat, visited);
}

int numberOfCells_dfs(int n, int m, int r, int c, int u, int d,vector<vector<char>>& mat)
{
	vector<vector<vector<vector<bool>>>> visited(n,
		vector<vector<vector<bool>>>(m,
			vector<vector<bool>>(u + 1,
				vector<bool>(d + 1))));

	dfs(n, m, r, c, u, d, mat, visited);

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cnt += mat[i][j] == '1';

	return cnt;
}



//Third Solution :- BFS
class Solution{
public:

bool isValid(vector<vector<char>> &mat,int n, int m, int r, int c){
    if(r<0 || c<0 || r>=n || c >=m || mat[r][c]!='.' ) return false;
    return true;
}

int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
{
 vector<vector<bool>> vis(n,vector<bool>(m,false));
 vector<vector<pair<int,int>>> pts(n,vector<pair<int,int>>(m,{-1,-1}));
    vis[r][c]=true;
    pts[r][c]={u,d};
    queue<pair<pair<int,int>,pair<int,int>>> nodes;
    nodes.push({{r,c},{u,d}});
    
    while(!nodes.empty()){
        int x=nodes.front().first.first,y=nodes.front().first.second,up=nodes.front().second.first,down=nodes.front().second.second;
        nodes.pop();
        
           //RIGHT
           if(isValid(mat,n,m,x,y+1) && (!vis[x][y+1] || (up>pts[x][y+1].first || down>pts[x][y+1].second))){
               vis[x][y+1]=true;
               pts[x][y+1]={up,down};
               nodes.push({{x,y+1},{up,down}});
           }
           //LEFT
           if(isValid(mat,n,m,x,y-1) && (!vis[x][y-1] || (up>pts[x][y-1].first || down>pts[x][y-1].second))){
               vis[x][y-1]=true;
               pts[x][y-1]={up,down};
               nodes.push({{x,y-1},{up,down}});
           }
        //UP
           if(isValid(mat,n,m,x-1,y) && up>0 && (!vis[x-1][y] || (up>pts[x-1][y].first || down>pts[x-1][y].second))) {
               vis[x-1][y]=true;
               pts[x-1][y]={up,down};
               nodes.push({{x-1,y},{up-1,down}});
           }
           //DOWN
           if(isValid(mat,n,m,x+1,y) && down>0 && (!vis[x+1][y] || (up>pts[x+1][y].first || down>pts[x+1][y].second))) {
               vis[x+1][y]=true;
               pts[x+1][y]={up,down};
               nodes.push({{x+1,y},{up,down-1}});
           }
    }

	int noOfCells=0;
	for(int i=0;i<n;i++){
	  	for(int j=0;j<m;j++){
	   		if(vis[i][j]) 
	   			noOfCells++;
	  	}
	}
    return noOfCells;
}
};



