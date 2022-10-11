https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges




//Solution Approach :- Using BFS
//Why BFS ? Because we don't need to rot all oranges but we only need to rot oranges at a minimum time.
//So we have to traverse level wise here. That's why we use BFS

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x , int y , vector<vector<int>> &grid){
	int m = grid.size(), n = grid[0].size();
    if(x<0 || y<0 || x>=m || y>=n || grid[x][y]!=1){
    	return false;
    }
    return true;
}

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int , int>> q;
    for(int i = 0 ; i< grid.size() ; i++){
        for(int j = 0 ; j<grid[i].size() ; j++){
            if(grid[i][j] == 2){
                q.push({i,j});
            }
        }
    }

    int count = 0 ;
    while(!q.empty()){
        int k = q.size();
        bool flag = false;

        while(k--){
            auto p = q.front() ; 
            q.pop();

            int x = p.first, y = p.second;
            grid[x][y] == 0;

            for(int i = 0 ; i<4 ; i++){
                if(isValid(x+dx[i] , y+dy[i] , grid)){
                    flag = true;
                    grid[x+dx[i]][y+dy[i]] = 0;
                    q.push({x+dx[i] , y+dy[i]});
                }
            }
        }
        if(flag){
	        count++;
        }
    }

    for(int i = 0 ; i< grid.size() ; i++){
        for(int j = 0 ; j<grid[i].size() ; j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }
    return count;
}





//Second Solution :-
int orangesRotting(vector<vector<int>>& grid) {
    int m =grid.size();
    int n= grid[0].size();
    int count=0; 
    int result=-1;

    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    queue<vector<int>> q;

   	for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]>0){
                count++;
            }
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }

    while(!q.empty())
    {
        result++;
        int sz = q.size();
        for(int i=0; i<sz; i++)
        {
            vector<int> curr = q.front();
            count--;
            q.pop();
            for(int j=0; j<4; j++)
            {
                int x = curr[0]+dir[j][0];
                int y = curr[1]+dir[j][1];
                if(x>=m || x<0 || y<0 || y>=n || grid[x][y]!=1){
                    continue;
                }
                grid[x][y]=2;
                q.push({x,y});
            }
        }
    }

    if(count==0){
        return result;
    }
    return -1;
}




//Third Solution :-
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>>q;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
            
    //Push the index of all rotten oranges in the queue
    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    
    int count=0;
    
    while(!q.empty()){
        int sz = q.size();
        
        bool change = false;        // Initialize a bool change to check if any orange was turned from fresh to orange
        for(int i=0 ; i<sz; i++){
            pair<int,int>pp = q.front();
            q.pop();
            int x = pp.first;
            int y = pp.second;
            vis[x][y]=true;
            
            // Check for fresh oranges in each direction and rot them
            if(x+1<n and y<m and !vis[x+1][y] and grid[x+1][y]==1){
                change=true;
                grid[x+1][y]=2;
                q.push({x+1,y});
            }
            if(x<n and y+1<m and !vis[x][y+1] and grid[x][y+1]==1){
                change=true;
                grid[x][y+1]=2;
                q.push({x,y+1});
            }
            if(x-1>=0 and y<m and !vis[x-1][y] and grid[x-1][y]==1){
                change=true;
                grid[x-1][y]=2;
                q.push({x-1,y});
            }
            if(x<n and y-1>=0 and !vis[x][y-1] and grid[x][y-1]==1){
                change=true;
                grid[x][y-1]=2;
                q.push({x,y-1});
            }
            
        }
        if(change){
        	count++;
        }
        
    }
    
    //Check if any fresh orange is still left
    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    
    return count;
}



