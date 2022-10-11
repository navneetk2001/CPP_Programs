https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1





//Solution Approach :-
class Solution{
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>&grid) {
       	if (i<0 || j<0 || i>=n || j>=m){
       		return;
       	}
       	if (grid[i][j]=='O'){
       		return;
       	}
       	
       	grid[i][j] = 'O';
       	
       	dfs(i+1,j,n,m,grid);
       	dfs(i-1,j,n,m,grid);
       	dfs(i,j+1,n,m,grid);
       	dfs(i,j-1,n,m,grid);
   	}

   	int xShape(vector<vector<char>>& grid) {
       	int n = grid.size();
       	int m = grid[0].size();
       	int ct = 0;
       	
       	for (int i = 0; i<n; i++){
           	for (int j = 0; j<m; j++){
               	if (grid[i][j]=='X'){
                   	dfs(i,j,n, m,grid);
                   	ct++;
               	}
           	}
       	}
       	return ct;
   }
};



//Second Solution :- BFS
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int xShape(vector<vector<char>>& grid) {
    int m=grid.size(); int n=grid[0].size(); 

  	queue<pair<int,int>>q;  
    int ans=0; 

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='X'){ 
            	ans++; 

                q.push({i,j}); 
                grid[i][j]='O'; 

                while(!q.empty()){
              		pair<int,int> p = q.front();  
                    q.pop(); 

                    for(int k=0;k<4;k++){
                        int x=p.first;
                        int y=p.second;

                        int newx=x+dx[k]; 
                        int newy=y+dy[k]; 

                        if(newx>=0 and newy>=0 and newx<m and newy<n and grid[newx][newy]=='X'){  
                        	q.push({newx,newy}); 
  							grid[newx][newy]='O'; 
  						}
                    }
                }
            }
        }
    }   
    return ans;
}




//Third Solution :-
class Solution{
public:
    vector<pair<int,int>> dir;
    
    Solution(){
        dir={{0,1},{1,0},{0,-1},{-1,0}};
    }
    
    void dfs(vector<vector<char>> & grid, int i, int j){
        int m= grid.size(), n= grid[0].size();
        for(int x=0;x<4;x++){
            int newI= i+dir[x].first;
            int newJ= j+dir[x].second;
            
            if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]=='X'){
                grid[newI][newJ]='O';
                dfs(grid, newI, newJ);
            }
        }
    }
    
    int xShape(vector<vector<char>>& grid) {
        int m= grid.size(), n= grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O') continue;
                cnt++;
                dfs(grid, i, j);
            }
        }
        return cnt;
    }
};